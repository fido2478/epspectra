/* -*- Mode: c++ -*-
 *
 *  Copyright 1999 Massachusetts Institute of Technology
 * 
 *  Permission to use, copy, modify, distribute, and sell this software and its
 *  documentation for any purpose is hereby granted without fee, provided that
 *  the above copyright notice appear in all copies and that both that
 *  copyright notice and this permission notice appear in supporting
 *  documentation, and that the name of M.I.T. not be used in advertising or
 *  publicity pertaining to distribution of the software without specific,
 *  written prior permission.  M.I.T. makes no representations about the
 *  suitability of this software for any purpose.  It is provided "as is"
 *  without express or implied warranty.
 * 
 *    Create May 25, 1998 Matthew L. Welborn
 */

const float pi = M_PI;

/*  constellations:  0=BPSK, 1=4-PAM, 2=8-PAM, 3=QPSK, 4=8-PSK, 5=16-QAM 

for 16-QAM:  phase= pi*{

    2.3562    1.8925    1.2490    0.7854
    2.8198    2.3562    0.7854    0.3218
   -2.8198   -2.3562   -0.7854   -0.3218
   -2.3562   -1.8925   -1.2490   -0.7854
}

ampl = {
 
    1.0607    0.7906    0.7906    1.0607
    0.7906    0.3536    0.3536    0.7906
    0.7906    0.3536    0.3536    0.7906
    1.0607    0.7906    0.7906    1.0607
}

*/

float symbol_phase[6][16] = {{0,pi,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			     {0,0,pi,pi,0,0,0,0,0,0,0,0,0,0,0,0},
			     {0,0,0,0,pi,pi,pi,pi,0,0,0,0,0,0,0,0},
			     {0,pi/2,pi,3*pi/2,0,0,0,0,0,0,0,0,0,0,0,0},
			     {0,0.25*pi,0.5*pi,0.75*pi,pi,1.25*pi,1.5*pi,1.75*pi,
			      0,0,0,0,0,0,0,0},
			     {2.3562, 1.8925, 1.2490, 0.7854, 2.8198, 2.3562, 0.7854, 0.3218,
			      -2.8198,-2.3562,-0.7854,-0.3218,-2.3562,-1.8925,-1.2490,-0.7854}};




float symbol_amplitude[6][16] = {{1.000, 1.000, 0.000, 0.000, 0,0,0,0,0,0,0,0,0,0,0,0},
				 {0.250, 0.750, 0.250, 0.750, 0,0,0,0,0,0,0,0,0,0,0,0},
				 {0.125, 0.375, 0.625, 0.875, 0.125, 0.375, 0.625, 0.875,
				  0,0,0,0,0,0,0,0},
				 {1.000, 1.000, 1.000, 1.000, 0,0,0,0,0,0,0,0,0,0,0,0},
				 {1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000,
				  0,0,0,0,0,0,0,0},
				 {1.0607, 0.7906, 0.7906, 1.0607, 0.7906, 0.3536, 0.3536, 0.7906,
				  0.7906, 0.3536, 0.3536, 0.7906, 1.0607, 0.7906, 0.7906, 1.0607}};
