/* ----------------------------------------------------------------------
 * Project:      CMSIS Stream
 * Title:        xxx.c
 * Description:  
 *
 * $Date:        15 February 2023
 * $Revision:    V0.0.1
 * -------------------------------------------------------------------- */
/*
 * Copyright (C) 2010-2023 ARM Limited or its affiliates. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 */

#ifdef __cplusplus
 extern "C" {
#endif
   
    
#ifdef _MSC_VER 
#include "../stream_al/platform_computer.h"
#include "../stream_src/stream_const.h"      
#include "../stream_src/stream_types.h"  
#else
#include "platform_computer.h"
#include "stream_const.h"      
#include "stream_types.h"  
#endif


/* -----------------------------------
    Nodes are delivered source-code
      or binary with code generation made for �position independent execution�. 
      This is the reason for having standard C library access through LINK.
    https://developer.arm.com/search#q=Position%20Independent%20Executables&sort=relevancy
    https://en.wikipedia.org/wiki/Position-independent_code
--------------------------------------
*/

/* 

1. arm_script
Operation : interpreter of byte-codes
Parameters : address of the byte-codes

2.	stream_split / demux
Operation : deinterleave an input arc to several output arcs (mono). Split manages up to 8 output arcs.
Parameters : none (stream details are shared during the reset sequence)

3.	stream_merge / mux
Operation : receives several mono or multichannel streams and produces one interleaved output arc. 
Merge manages up to 8 input arcs. One input arc can be tagged as �High QoS� and manage with priority : 
whatever the data content on the other arcs data is flowing synchronized by this one. 
The other arcs are using interpolations scheme, defined in the detailed YAML file format. 
Parameters : name of the High QoS arc or �none�

4.	stream_route
Operation : copy the content of one stream to another stream. One input stream can be replicated to 
several output. Route can manage up to 8 input and 8 output arcs.
Parameters : list of input arc names and corresponding output arc names (or �none� is unused).

5.	stream_format_converter
Operation : converter raw data format and interleaving to the format of the output arc. 
interpolate the input stream format to the output stream format. For example for the 
rescaling of images, the audio sampling-rate conversion, the interpolation of an asynchronous stream, 
and time-stamped samples from a motion sensor to a synchronous data rate.
Parameters : Preset give the operations to do : interleaving, format, (a)synchronous rate conversion
reuse of the arc format given in the parmeters at reset, and the filling state of the output buffer to 
adjust the drift. 

6.	stream_frequency_estimator
Operation : input signal frequency estimator. Best-effort accuracy on time-stamped streams. Use of DC
removal, zero-crossing rate, second-order autoregression.
Parameters : allowed convergence time for optimal accuracy and offset removal, known range of the 
frequency (optional) known drift/sweep characteristics of the input signal, the signal is square

7.	stream_amplitude
Operation : control of the amplitude of the input stream with controlled time of ramp-up and ramp-down. 
The gain control �mute� is used to store the current gain setting, being reloaded when the command �unmute� is sent
Parameters :  new gain/mute/unmute, ramp-up/down slope, delay before starting the slope.

8.	stream_mixer
Operation : receives several mono or multichannel streams and produces several mixed output identical arcs. 
Mixer manages up to 8 input arcs. One input arc can be tagged as �High QoS� and manage with priority : 
whatever the data content on the other arcs data is flowing synchronized by this one. 
The other arcs are using interpolations scheme, defined in the detailed YAML file format. 
Parameters : input arcs names, their associated gain and time-constant in [ms], name of the 
output arc and an extra mixing gain, name of the High QoS arc, or �none�

9.	stream_dsp_filter
Operation : receives one multichannel stream and produces one filtered multichannel stream. 
Filtering is identical on each channel.
Parameters : number of biquad filters used in cascade, filter coefficients
    or let SET_PARAM compute the coefficients https://www.w3.org/TR/audio-eq-cookbook/

10.	stream_detector
Operation : provides a boolean output stream from the detection of a rising (of falling) edge above 
a tunable signal to noise ratio. A time constant in [ms] is used for the detection. 
A tunable delay allows to maintain the boolean value for a minimum amount of time 
for debouncing and LED / user-interface).
Parameters : select rising/falling detection, signal to noise ratio in voltage decibels, 
time-constant in [ms] for the energy integration time, time-constant to gate the output.

11.	stream_codec, stream_decompression
Operation : wave compression using IMADPCM(4bits/sample) and LPC10(1bit/sample) de/encoding.
Parameters : coding scheme 

12.	data conditioning
Operation : applies y=aX+b and more generally y=interp1(X,Y,input,'method')
Following https://fr.mathworks.com/help/matlab/ref/interp1.html
Parameters : X,Y vectors and interpolation method

13.	signal generator
Operation : sine, noise, sweep, square
Parameters : type of wave, amplitude, VCO, phase of multichannel

14.	frequency estimator 
Operation : frequency estimation of the input signal (second order AR analysis)
Parameters : number of average, length of the analysis buffer 

*/
extern p_stream_node arm_script; 
extern p_stream_node arm_stream_split; 
extern p_stream_node arm_stream_merge; 
extern p_stream_node arm_stream_route; 
extern p_stream_node arm_stream_converter; 
//extern p_stream_node arm_stream_frequency_estimator;
extern p_stream_node arm_stream_amplitude; 
extern p_stream_node arm_stream_mixer; 
extern p_stream_node arm_stream_dsp_filter; 
extern p_stream_node arm_stream_detector; 
extern p_stream_node arm_stream_codec; 
extern p_stream_node arm_stream_decompression; 
extern p_stream_node arm_stream_data_conditioning;
extern p_stream_node arm_stream_generator;
//extern p_stream_node arm_stream_command_interpreter;

#define TBD 0

/* 
    this table will be extended with pointers to nodes loaded 
    dynamically and compiled with position independent execution options
*/
p_stream_node node_entry_point_table[NB_NODE_ENTRY_POINTS] =
{
    /*--------- ARM ---------*/
    /*  0*/ (void *)0,
    /*  1*/ (void *)&arm_script, 
    /*  2*/ (void *)&arm_stream_split,                        
    /*  3*/ (void *)&arm_stream_merge,                        
    /*  4*/ (void *)&arm_stream_route, 
    /*  5*/ (void *)&arm_stream_converter,                        
    /*  6*/ (void *)0,//&arm_stream_frequency_estimator,                        
    /*  7*/ (void *)&arm_stream_amplitude,                        
    /*  8*/ (void *)&arm_stream_mixer, 
    /*  9*/ (void *)&arm_stream_dsp_filter,                        
    /* 10*/ (void *)&arm_stream_detector,                        
    /* 11*/ (void *)&arm_stream_codec,                        
    /* 12*/ (void *)&arm_stream_data_conditioning,  
    /* 13*/ (void *)&arm_stream_generator, 
    /* 14*/ TBD, //(void *)&arm_stream_command_interpreter, 
    /* 15*/ TBD, 
    /* 16*/ TBD, 
    /* 17*/ TBD, 
    /* 18*/ TBD, 
    /* 19*/ TBD, 

    /*------ COMPANY #1 -----*/
    TBD,                           
    /*------ COMPANY #2 -----*/
    TBD,TBD,TBD,
    /*------ COMPANY #3, etc ... -----*/
                
};
 
#ifdef __cplusplus
}
#endif
 