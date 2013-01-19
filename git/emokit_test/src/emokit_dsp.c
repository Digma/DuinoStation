#include "emokit/emokit_dsp.h"	
#include <math.h>

emokit_dsp* emokit_dsp_create()
{
	emokit_dsp* dsp = (emokit_dsp*)malloc(sizeof(emokit_dsp));
	memset(dsp,0,sizeof(emokit_dsp));
	int i,j,k;
	for(i=0; i<NB_CHANNEL; i++){
		for(j=0; j<W_SIZE; j++){
			dsp->channels[i][j][0] = 0;
		}
	}
	
	
	//chose window
    	//no_window(dsp->window);
	hamming_window(dsp->window);
	dsp->counter = 0;
	return dsp;
}

int emokit_dsp_free(emokit_dsp* dsp){
	free(dsp);
}

void fft(emokit_dsp* dsp, int channel){
	fftw_plan p;
	
	//Pointer to the channels data
    //fftw_complex* channelValue = dsp->channels[channel];
    fftw_complex* channelValue = dsp->channels[channel];

    //Window the measurements 
    int i=0;
    for(i=0;i<W_SIZE;i++)
    {
        dsp->windowed[i][0] = dsp->window[i]*channelValue[i][0];
        //dsp->windowed[i][1] = dsp->window[i]*channelValue[i][1];
    }
 
    //FFT the frame
	p = fftw_plan_dft_1d(W_SIZE, dsp->windowed, dsp->f_channels[channel], FFTW_FORWARD, FFTW_ESTIMATE);
	fftw_execute(p);
	fftw_destroy_plan(p);

}


void free_fft(emokit_dsp* dsp){
	int i;
	for(i=0; i<NB_CHANNEL; i++){
		free(dsp->channels[i]); 
		free(dsp->f_channels[i]);
	}
}

//Hamming_windows : default window
void hamming_window(double* w){
	int i = 0;
    for(i=0;i<W_SIZE;i++)
        *(w+i) = 0.54 - 0.46*cos(2*M_PI*((double)i/(W_SIZE+1)));
}

//Flat top window : not used in this program
void flat_top_window(double* w){
	int j = 0;
    for(j=0;j<W_SIZE;j++)
		*(w+j) = 1-1.93*cos(2*M_PI*((double)j/(W_SIZE+1)))+1.29*cos(4*M_PI*((double)j/(W_SIZE+1)))-0.388*cos(6*M_PI*((double)j/(W_SIZE+1)))+0.032*cos(8*M_PI*((double)j/(W_SIZE+1)));
}

//set the windows to a rectangular window
void no_window(double* w){
	int i=0;
    for(i=0;i<W_SIZE;i++)
    {
        *(w+i) = 1;
    }
}

double compute_power_band_wave(emokit_dsp* dsp, int channel, int f_start, int f_end){
	int j=0;
	//frequency = k/T, where T is your total sampling period (T=1/128*W_SIZE = 1sec)
	//The frequency k/n is the same as the frequency (n-k)/n - Only one entry for k=0 and k=n/2

	long double power = 0;
	int start = floor(f_start*(W_SIZE/2)/64);
	int end = ceil(f_end*(W_SIZE/2)/64);
	for(j=start; j<=end; j++){
		power += (dsp->f_channels[channel][j][0]*dsp->f_channels[channel][j][0]+dsp->f_channels[channel][j][1]*dsp->f_channels[channel][j][1]);
		power += (dsp->f_channels[channel][W_SIZE-j][0]*dsp->f_channels[channel][W_SIZE-j][0]+dsp->f_channels[channel][W_SIZE-j][1]*dsp->f_channels[channel][W_SIZE-j][1]);
    }
    return (double)power;
}

void compute_frame(emokit_dsp* dsp, struct emokit_frame frame){
	int c;
	dsp->counter++;
	for(c=0;c<NB_CHANNEL;c++)
    {
        //Shift all the frames back
        int i;
        for(i=1;i<W_SIZE;i++)
        {
            (dsp->channels[c])[i-1][0] = (dsp->channels[c])[i][0];
        }
        
        //we update the NB_CHANNEL sensor - value is set between -1 and 1
		double temp;
        switch(c){
			case 0:
				temp = (double)(frame.F3)/(double)MAX_SENSOR_VALUE;
				break;
			case 1:
				temp = (double)(frame.FC6)/(double)MAX_SENSOR_VALUE;
				break;
			case 2:
				temp = (double)(frame.P7)/(double)MAX_SENSOR_VALUE;
				break;
			case 3:
				temp = (double)(frame.T8)/(double)MAX_SENSOR_VALUE;
				break;
			case 4:
				temp = (double)(frame.F7)/(double)MAX_SENSOR_VALUE;
				break;
			case 5:
				temp = (double)(frame.F8)/(double)MAX_SENSOR_VALUE;
				break;
			case 6:
				temp = (double)(frame.T7)/(double)MAX_SENSOR_VALUE;
				break;
			case 7:
				temp = (double)(frame.P8)/(double)MAX_SENSOR_VALUE;
				break;
			case 8:
				temp = (double)(frame.AF4)/(double)MAX_SENSOR_VALUE;
				break;
			case 9:
				temp = (double)(frame.F4)/(double)MAX_SENSOR_VALUE;
				break;
			case 10:
				temp = (double)(frame.AF3)/(double)MAX_SENSOR_VALUE;
				break;
			case 11:
				temp = (double)(frame.O2)/(double)MAX_SENSOR_VALUE;
				break;
			case 12:
				temp = (double)(frame.O1)/(double)MAX_SENSOR_VALUE;
				break;
			case 13:
				temp = (double)(frame.FC5)/(double)MAX_SENSOR_VALUE;
				break;

			default:
				printf("Error in compute_frame().");
				break;
		}

        (dsp->channels[c])[W_SIZE-1][0] = temp;

        //we only compute the FFT every 64 frame or 2Hz because of the Hamming window
        if(dsp->counter%INTERVAL == 0){
			fft(dsp,c);
			compute_power_band(dsp,c);
		}
    }
    dsp->counter++;
}

//Compute the mean of the channel 
/*void mean(emokit_dsp* dsp, int channel){
	dsp->mean[channel] = 0;
	int i;
	for(i=0; i<W_SIZE; i++){
		dsp->mean[channel] += dsp->value[channel][i]/(1.0*W_SIZE);
	}
}*/

//compute the power in every band
void compute_power_band(emokit_dsp* dsp, int channel){
	int j;
	for(j=0; j<W_SIZE; j++){
		dsp->band_power[channel][j] = (dsp->f_channels[channel])[j][0]*(dsp->f_channels[channel])[j][0]+(dsp->f_channels[channel])[j][1]*(dsp->f_channels[channel])[j][1];
	}
}

//compute the alpha power 8-12 HZ
/*void compute_alpha_power(emokit_dsp* dsp, int channel){
		dsp->alpha_power[channel][dsp->counter%HISTORY] = compute_power_band_wave(dsp, channel, ALPHA_START, ALPHA_END);
}*/

//compute the beta power 16-24Hz
/*void compute_beta_power(emokit_dsp* dsp, int channel){
	dsp->beta_power[channel][dsp->counter%HISTORY] = compute_power_band_wave(dsp, channel, BETA_START, BETA_END);
}*/
