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

#ifndef _VRAUDIOSOURCE_H_
#define _VRAUDIOSOURCE_H_

#define AUDIOINCHUNKSIZE 200

extern "C" {
#include <sys/soundcard.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
}

#include <StrlSource.h>
#include <fstream.h>

template<class oType>
class StrlAudioSource : public StrlSource<oType> {
protected:
  int audiofd;
  long format;
public: 
  virtual const char *name() { return "StrlAudioSource";}
  virtual int work(VrSampleRange output, void *o[]);
  virtual void initialize() {
      int temp = 0x7fff0004;
    if(audiofd==-1) {
      if ((audiofd = open("/dev/audio", O_RDONLY)) < 0) {
	fprintf (stderr, "StrlAudioSource: Audio device busy.\n");
	exit(1);
      }
      // formerly commented out till
      if ((ioctl(audiofd,SNDCTL_DSP_SETFRAGMENT,&temp)) < 0) {
	fprintf (stderr, "StrlAudioSource: set fragment returned %d\n", errno);
	exit(1);
      }
      //don't have to specify anything because /dev/audio uses mu-law encoding by default
      if(sizeof(oType)==1) {
	format=AFMT_MU_LAW;
	//format=AFMT_A_LAW;
	//format = AFMT_S8;
	//Not sure if /dev/dsp likes signed values!!!
      } else if(sizeof(oType)==2) {
	printf("setting to 16 bits \n");
	format = AFMT_S16_LE;
      } else {
	fprintf (stderr, "StrlAudioSource: cannot handle data type %d\n", errno);
	exit(1);
      }
      ioctl(audiofd,SNDCTL_DSP_RESET);
      int origf=format;
      if((ioctl(audiofd,SNDCTL_DSP_SETFMT,&format)) < 0) {
	fprintf (stderr, "StrlAudioSource: /dev/dsp IOCTL failed with %d\n", errno);
	exit(1);
      }
      if(origf!=format) {
	fprintf (stderr, "StrlAudioSource: Warning: unable to support format %d\n",origf);
	fprintf (stderr, "  card requested %ld instead.\n", format);
      }
      // till here
      int sf = (int)getSamplingFrequency();
      //cout <<"Sampling frequency = "<<sf<<endl;
      if ((ioctl(audiofd,SNDCTL_DSP_SPEED,&sf)) < 0) {
	fprintf (stderr, "/dev/dsp: invalid sampling frequency...defaulting to 8 Khz\n");
	sf = 8000;
	if ((ioctl(audiofd,SNDCTL_DSP_SPEED,&sf)) < 0) {
	  fprintf (stderr, "Couldn't even manage that...aborting\n");
	  exit(1);
	}
      }
      if(sf!=getSamplingFrequency())
	fprintf(stderr, "StrlAudioSource Warning: soundcard defaulted to %d Hz\n", sf);
    }
  }
  StrlAudioSource() : audiofd(-1) { setOutputSize (AUDIOINCHUNKSIZE); }
  virtual ~StrlAudioSource() {close(audiofd);}
};

template<class oType> int StrlAudioSource<oType>::work(VrSampleRange output, void *ao[])
{
  unsigned units=output.size;
  int count = 0;
  oType **o= (oType **)ao;
  oType *curPos=o[0];

  while(units>0) {
    int  this_read = units;
    int bytes =  this_read*sizeof(oType);
  
    count =  read(audiofd,curPos,bytes);
    curPos +=  this_read;
    if(count<0) {
      fprintf(stderr, "AudioSource read error, errno:%d\n", errno);
      exit(1);
    } else {
      if(count!=bytes)
	fprintf(stderr, "AudioSource: warning: not all bytes read!\n");
      units-= this_read;
    }
  }
  return output.size/sizeof(oType);
}
#endif
