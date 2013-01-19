#ifndef LIBEMOKIT_DSP_H_
#define LIBEMOKIT_DSP_H_

#include "emokit.h"
#include <fftw3.h>
#include <math.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef max
	#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
#endif

#ifndef min
	#define min( a, b ) ( ((a) < (b)) ? (a) : (b) )
#endif


#define NB_CHANNEL 14
//sampling frequency in Hz
#define FS 128
//window size
#define W_SIZE 128
//max value from sensor (-8192 ; 8192)
#define MAX_SENSOR_VALUE 8192
//number of frame between every FFT
#define INTERVAL 64



typedef struct
{
    //Channel history
    fftw_complex channels[NB_CHANNEL][W_SIZE];
    //Channel fourier transform
    fftw_complex f_channels[NB_CHANNEL][W_SIZE];


    double band_power[NB_CHANNEL][W_SIZE];

    //Array to save the input to fftw
    fftw_complex windowed[W_SIZE];
    //Window function coefficients
    double window[W_SIZE];
    int counter;
} emokit_dsp;


emokit_dsp* emokit_dsp_create();
int emokit_dsp_free(emokit_dsp* dsp);

//FFT
void fft(emokit_dsp* dsp, int channel);
void free_fft(emokit_dsp* dsp);

//windows
void hamming_window(double* w);
void flat_top_window(double* window);
void no_window(double* w);

//Power computation
double compute_power_band_wave(emokit_dsp* dsp, int channel, int start, int end);
void compute_frame(emokit_dsp* s, struct emokit_frame f);
void compute_power_band(emokit_dsp* dsp, int channel);



#ifdef __cplusplus
};
#endif

#endif //LIBEMOKIT_H_
