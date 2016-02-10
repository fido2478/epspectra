/*  Modified 2000, 2001 INRIA */

/* -*- Mode: c++ -*-
 *
 *  Copyright 1997 Massachusetts Institute of Technology
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
*/

#ifndef _VRAUDIOSINK_H_
#define _VRAUDIOSINK_H_

#define AUDIOOUTCHUNKSIZE 64

extern "C" {
#include <sys/soundcard.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
}
#include <StrlSink.h>
#include <fstream.h>

template<class iType>
class StrlAudioSink : public StrlSink<iType> {
protected:
  int audiofd;
  long format;
  iType *mixArray;
public:
  virtual const char *name() { return "StrlAudioSink"; }
  virtual int work(VrSampleRange output,
			VrSampleRange inputs[], void *i[]);
  virtual void initialize() {
      int temp = 0x7fff0004;

    if(audiofd==-1) {
      if ((audiofd = open("/dev/audio", O_WRONLY/*|O_NONBLOCK*/)) < 0) {
	fprintf(stderr, "StrlAudioSink: Audio device busy.\n");
	exit(1);
      }
      if ((ioctl(audiofd,SNDCTL_DSP_SETFRAGMENT,&temp)) < 0) {
	fprintf(stderr, "StrlAudioSink: set fragment returned %d\n", errno);
	exit(1);
      }
      if(sizeof(iType)==1)
	format = AFMT_MU_LAW;
      if(sizeof(iType)==2)
	format = AFMT_S16_LE;
	//use u-law encoding for use with encoder
	//format=AFMT_A_LAW;
	//format = AFMT_S8;
	//Not sure if /dev/dsp likes signed values!!!
    }
    else if(sizeof(iType)==2)
      format = AFMT_S16_LE;
    else {
      fprintf(stderr, "StrlAudioSink: cannot handle data type %d\n", errno);
      exit(1);
    }
    ioctl(audiofd,SNDCTL_DSP_RESET);

    int origf=format;
    if((ioctl(audiofd,SNDCTL_DSP_SETFMT,&format)) < 0) {
      fprintf(stderr, "StrlAudioSink: /dev/dsp IOCTL failed with %d\n", errno);
      exit(1);
    }
    if(origf!=format) {
      fprintf(stderr, "StrlAudioSink: Warning: unable to support format %d\n", origf);
      fprintf(stderr, "  card requested %ld instead.\n", format);
    }

    if(getNumberInputs()==2) {		//Stereo
      int channels=2;
      if((ioctl(audiofd,SNDCTL_DSP_CHANNELS,&channels)) < 0 || channels!=2) {
	fprintf(stderr, "StrlAudioSink: could not set STEREO mode %d\n", errno);
	exit(1);
      }
      //      fprintf(stderr, "StrlAudioSink: Stereo mode enabled.\n");
      mixArray=new iType[getOutputSize()*2];
      if(getInputSamplingFrequencyN(0)!=getInputSamplingFrequencyN(1))
	fprintf(stderr, "StrlAudioSink Warning: left and right at different freq\n");
    } else
      mixArray = NULL;
    int sf = (int) getSamplingFrequency();
    if (sf==0){//it doesn't get to be any more of a hack than this.... ;)
      sf=22000; //why does it return 0 for the sampling frequency?
      setSamplingFrequency(sf);
    }
    sf=8000; //why does it return 0 for the sampling frequency?//hkim
    setSamplingFrequency(sf);
    printf("sampling frequency is %d\n",sf);
    if ((ioctl(audiofd,SNDCTL_DSP_SPEED,&sf)) < 0) {
      fprintf(stderr, "/dev/dsp: invalid sampling frequency...defaulting to 8 Khz\n");
      sf = 8000;
      if ((ioctl(audiofd,SNDCTL_DSP_SPEED,&sf)) < 0) {
	fprintf(stderr, "Couldn't even manage that...aborting\n");
	exit(1);
      }
    }
    if(sf!=(int) getSamplingFrequency())
      fprintf(stderr, "StrlAudioSink Warning: soundcard defaulted to %d Hz\n", sf);
  }
  StrlAudioSink() : audiofd(-1) { setOutputSize (AUDIOOUTCHUNKSIZE); }
  virtual ~StrlAudioSink() {close(audiofd);}
};

template<class iType> int
StrlAudioSink<iType>::work(VrSampleRange output, VrSampleRange inputs[], void *ai[])
{
  iType **i = (iType **)ai;
  int count = 0;
  unsigned size = output.size;
  int bytes = getOutputSize()*sizeof(iType);
  iType *myPtr;

  if(getNumberInputs()==2)		//Stereo
      bytes*=2;
  while(size > 0) {
    myPtr = i[0];
    if(getNumberInputs()==2) {	//Stereo
      for(unsigned int ii=0;ii<getOutputSize();ii++) {
	mixArray[ii*2]=*i[0]++;
	mixArray[ii*2+1]=*i[1]++;
      }
      myPtr=mixArray;
    }
    count =  write(audiofd,myPtr,bytes);
    if(count<0) {
      printf("StrlAudioSink write error(%d), errno: %d\n",count, errno);
      exit(1);
    } else {
      if(count!=bytes)
      	printf("StrlAudioSink: warning: not all bytes written!\n");
    }
    size-=getOutputSize();
    i[0]+=getOutputSize();
  }
  return output.size;///sizeof(iType);
}
#endif
