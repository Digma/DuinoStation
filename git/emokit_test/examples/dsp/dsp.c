#include <stdio.h>
#include <string.h>

#include "emokit/emokit.h"
#include "emokit/emokit_dsp.h"



int main(int argc, char **argv)
{
	struct emokit_device* d;
	d = emokit_create();
	
	//*** DSP struct ***
	emokit_dsp* dsp;
	dsp = emokit_dsp_create();
	
	//*** Check epoc connected
	printf("Current epoc devices connected: %d\n", emokit_get_count(d, EMOKIT_VID, EMOKIT_PID));
	int r = emokit_open(d, EMOKIT_VID, EMOKIT_PID, 1);
	if(r != 0)
	{
		printf("CANNOT CONNECT: %d\n", r);
		return 1;
	}
	printf("Connected\n");
	
	double theta;
	double alpha;
	double beta;
	double gamma;
	//** MAIN LOOP **
	int counter=0;
	while(1)
	{
		if(emokit_read_data(d) > 0)
		{
			struct emokit_frame c;
			c = emokit_get_next_frame(d);
			compute_frame(dsp, c);
			counter++;
			
			if(counter%INTERVAL == 0);{
				fflush(stdout);
				//double compute_power_band_wave(emokit_dsp* dsp, int channel, int f_start, int f_end)
				printf("Power | Theta : %f  - Alpha : %f  -  Beta : %f  -  Gamma : %f\n", theta, alpha, beta, gamma);
			}
		}
	}

	emokit_close(d);
	emokit_delete(d);
	return 0;
}
