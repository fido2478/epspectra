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
// Based on the C++ implementation
// Written by Jason Merrill based upon the specification in the 27 May 1994
// C++ working paper, ANSI document X3J16/94-0098.

#ifndef _STRLCOMPLEX_H_
#define _STRLCOMPLEX_H_

#include <cmath>

class StrlComplex {
public:
  StrlComplex(float r,float i) :re(r),im(i) {}
  StrlComplex(float r) :re(r),im(0) {}
  StrlComplex() :re(0),im(0) {}
  StrlComplex& operator = (const StrlComplex&);
  StrlComplex& operator = (const float&);
  StrlComplex& operator = (const double&);
  StrlComplex& operator = (const int&);
  StrlComplex& operator += (const StrlComplex&);
  StrlComplex& operator -= (const StrlComplex&);
  StrlComplex& operator *= (const StrlComplex&);
  StrlComplex& operator /= (const StrlComplex&);
  float real () const { return re; }
  float imag () const { return im; }
  void real(float x) {re = x;}
  void imag(float x) {im = x;}
private:
  float re, im;

  // These functions are specified as friends for purposes of name injection;
  // they do not actually reference private members.
  friend float real (const StrlComplex&);
  friend float imag (const StrlComplex&);
  friend StrlComplex operator + (const StrlComplex&, const StrlComplex&);
  friend StrlComplex operator + (const StrlComplex&, float);
  friend StrlComplex operator + (float, const StrlComplex&);
  friend StrlComplex operator - (const StrlComplex&, const StrlComplex&);
  friend StrlComplex operator - (const StrlComplex&, float);
  friend StrlComplex operator - (float, const StrlComplex&);
  friend StrlComplex operator * (const StrlComplex&, const StrlComplex&);
  friend StrlComplex operator * (const StrlComplex&, float);
  friend StrlComplex operator * (float, const StrlComplex&);
  friend StrlComplex operator / (const StrlComplex&, const StrlComplex&);
  friend StrlComplex operator / (const StrlComplex&, float);
  friend StrlComplex operator / (float, const StrlComplex&);
  friend bool operator == (const StrlComplex&, const StrlComplex&);
  friend bool operator == (const StrlComplex&, float);
  friend bool operator == (float, const StrlComplex&);
  friend bool operator != (const StrlComplex&, const StrlComplex&);
  friend bool operator != (const StrlComplex&, float);
  friend bool operator != (float, const StrlComplex&);
  friend StrlComplex polar (float, float);
  friend StrlComplex pow (const StrlComplex&, const StrlComplex&);
  friend StrlComplex pow (const StrlComplex&, float);
  friend StrlComplex pow (const StrlComplex&, int);
  friend StrlComplex pow (float, const StrlComplex&);
  //  friend istream& operator>> (istream&, StrlComplex&);
  //  friend ostream& operator<< (ostream&, const StrlComplex&);
};

inline StrlComplex&
StrlComplex::operator = (const StrlComplex& r)
{
  re = r.re;
  im = r.im;
  return *this;
}

inline StrlComplex&
StrlComplex::operator = (const float& r)
{
  re = r;
  im = 0;
  return *this;
}

inline StrlComplex&
StrlComplex::operator = (const double& r)
{
  re = r;
  im = 0;
  return *this;
}

inline StrlComplex&
StrlComplex::operator = (const int& r)
{
  re = r;
  im = 0;
  return *this;
}


inline StrlComplex&
StrlComplex::operator += (const StrlComplex& r)
{
  re += r.re;
  im += r.im;
  return *this;
}

inline StrlComplex&
StrlComplex::operator -= (const StrlComplex& r)
{
  re -= r.re;
  im -= r.im;
  return *this;
}

inline StrlComplex&
StrlComplex::operator *= (const StrlComplex& r)
{
  float f = re * r.re - im * r.im;
  im = re * r.im + im * r.re;
  re = f;
  return *this;
}

inline float
imag (const StrlComplex& x) 
{
  return x.imag ();
}

inline float
real (const StrlComplex& x) 
{
  return x.real ();
}

inline StrlComplex
operator + (const StrlComplex& x, const StrlComplex& y) 
{
  return StrlComplex (real (x) + real (y), imag (x) + imag (y));
}

inline StrlComplex
operator + (const StrlComplex& x, float y) 
{
  return StrlComplex (real (x) + y, imag (x));
}

inline StrlComplex
operator + (float x, const StrlComplex& y) 
{
  return StrlComplex (x + real (y), imag (y));
}

inline StrlComplex
operator - (const StrlComplex& x, const StrlComplex& y)
{
  return StrlComplex (real (x) - real (y), imag (x) - imag (y));
}

inline StrlComplex
operator - (const StrlComplex& x, float y) 
{
  return StrlComplex (real (x) - y, imag (x));
}

inline StrlComplex
operator - (float x, const StrlComplex& y) 
{
  return StrlComplex (x - real (y), - imag (y));
}

inline StrlComplex
operator * (const StrlComplex& x, const StrlComplex& y) 
{
  return StrlComplex (real (x) * real (y) - imag (x) * imag (y),
			   real (x) * imag (y) + imag (x) * real (y));
}

inline StrlComplex
operator * (const StrlComplex& x, float y) 
{
  return StrlComplex (real (x) * y, imag (x) * y);
}

inline StrlComplex
operator * (float x, const StrlComplex& y) 
{
  return StrlComplex (x * real (y), x * imag (y));
}

inline StrlComplex
operator / (const StrlComplex& x, float y) 
{
  return StrlComplex (real (x) / y, imag (x) / y);
}

inline StrlComplex
operator + (const StrlComplex& x) 
{
  return x;
}

inline StrlComplex
operator - (const StrlComplex& x) 
{
  return StrlComplex (-real (x), -imag (x));
}

inline bool
operator == (const StrlComplex& x, const StrlComplex& y) 
{
  return real (x) == real (y) && imag (x) == imag (y);
}

inline bool
operator == (const StrlComplex& x, float y) 
{
  return real (x) == y && imag (x) == 0;
}

inline bool
operator == (float x, const StrlComplex& y) 
{
  return x == real (y) && imag (y) == 0;
}

inline bool
operator != (const StrlComplex& x, const StrlComplex& y) 
{
  return real (x) != real (y) || imag (x) != imag (y);
}

inline bool
operator != (const StrlComplex& x, float y) 
{
  return real (x) != y || imag (x) != 0;
}

inline bool
operator != (float x, const StrlComplex& y) 
{
  return x != real (y) || imag (y) != 0;
}

// Some targets don't provide a prototype for hypot when -ansi.
extern "C" double hypot (double, double);

inline float
abs (const StrlComplex& x) 
{
  return hypot (real (x), imag (x));
}

inline float
arg (const StrlComplex& x) 
{
  return atan2 (imag (x), real (x));
}

inline StrlComplex
polar (float r, float t) 
{
  return StrlComplex (r * cos (t), r * sin (t));
}

inline StrlComplex
conj (const StrlComplex& x)  
{
  return StrlComplex (real (x), -imag (x));
}

inline float
norm (const StrlComplex& x) 
{
  return real (x) * real (x) + imag (x) * imag (x);
}

// Declarations of templates in StrlComplex.cc
StrlComplex operator / (const StrlComplex& x, const StrlComplex& y);
StrlComplex operator / (float x, const StrlComplex& y);
StrlComplex cos (const StrlComplex&);
StrlComplex cosh (const StrlComplex&);
StrlComplex exp (const StrlComplex&);
StrlComplex log (const StrlComplex&);
StrlComplex pow (const StrlComplex&, const StrlComplex&);
StrlComplex pow (const StrlComplex&, float);
StrlComplex pow (const StrlComplex&, int);
StrlComplex pow (float, const StrlComplex&);
StrlComplex sin (const StrlComplex&);
StrlComplex sinh (const StrlComplex&);
StrlComplex sqrt (const StrlComplex&);

//Functions to support templates...
inline char real(const char& c) {return c;}
inline char imag(const char&) {return 0;}
//inline uchar real(const uchar& c) {return c;}
//inline uchar imag(const uchar& c) {return 0*c;}
inline short real(const short& s) {return s;}
inline short imag(const short&) {return 0;}
inline int real(const int& i) {return i;}
inline int imag(const int&) {return 0;}
inline float real(const float& f) {return f;}
inline float imag(const float&) {return 0;}

class istream;
class ostream;
istream& operator >> (istream&, StrlComplex&);
ostream& operator << (ostream&, const StrlComplex&);

#endif



