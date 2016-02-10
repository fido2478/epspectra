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

#ifndef _VRCOMPLEX_H_
#define _VRCOMPLEX_H_

#include <cmath>

class VrComplex {
public:
  VrComplex(float r,float i) :re(r),im(i) {}
  VrComplex(float r) :re(r),im(0) {}
  VrComplex() :re(0),im(0) {}
  VrComplex& operator = (const VrComplex&);
  VrComplex& operator = (const float&);
  VrComplex& operator = (const double&);
  VrComplex& operator = (const int&);
  VrComplex& operator += (const VrComplex&);
  VrComplex& operator -= (const VrComplex&);
  VrComplex& operator *= (const VrComplex&);
  VrComplex& operator /= (const VrComplex&);
  float real () const { return re; }
  float imag () const { return im; }
  void real(float x) {re = x;}
  void imag(float x) {im = x;}
private:
  float re, im;

  // These functions are specified as friends for purposes of name injection;
  // they do not actually reference private members.
  friend float real (const VrComplex&);
  friend float imag (const VrComplex&);
  friend VrComplex operator + (const VrComplex&, const VrComplex&);
  friend VrComplex operator + (const VrComplex&, float);
  friend VrComplex operator + (float, const VrComplex&);
  friend VrComplex operator - (const VrComplex&, const VrComplex&);
  friend VrComplex operator - (const VrComplex&, float);
  friend VrComplex operator - (float, const VrComplex&);
  friend VrComplex operator * (const VrComplex&, const VrComplex&);
  friend VrComplex operator * (const VrComplex&, float);
  friend VrComplex operator * (float, const VrComplex&);
  friend VrComplex operator / (const VrComplex&, const VrComplex&);
  friend VrComplex operator / (const VrComplex&, float);
  friend VrComplex operator / (float, const VrComplex&);
  friend bool operator == (const VrComplex&, const VrComplex&);
  friend bool operator == (const VrComplex&, float);
  friend bool operator == (float, const VrComplex&);
  friend bool operator != (const VrComplex&, const VrComplex&);
  friend bool operator != (const VrComplex&, float);
  friend bool operator != (float, const VrComplex&);
  friend VrComplex polar (float, float);
  friend VrComplex pow (const VrComplex&, const VrComplex&);
  friend VrComplex pow (const VrComplex&, float);
  friend VrComplex pow (const VrComplex&, int);
  friend VrComplex pow (float, const VrComplex&);
  //  friend istream& operator>> (istream&, VrComplex&);
  //  friend ostream& operator<< (ostream&, const VrComplex&);
};

inline VrComplex&
VrComplex::operator = (const VrComplex& r)
{
  re = r.re;
  im = r.im;
  return *this;
}

inline VrComplex&
VrComplex::operator = (const float& r)
{
  re = r;
  im = 0;
  return *this;
}

inline VrComplex&
VrComplex::operator = (const double& r)
{
  re = r;
  im = 0;
  return *this;
}

inline VrComplex&
VrComplex::operator = (const int& r)
{
  re = r;
  im = 0;
  return *this;
}


inline VrComplex&
VrComplex::operator += (const VrComplex& r)
{
  re += r.re;
  im += r.im;
  return *this;
}

inline VrComplex&
VrComplex::operator -= (const VrComplex& r)
{
  re -= r.re;
  im -= r.im;
  return *this;
}

inline VrComplex&
VrComplex::operator *= (const VrComplex& r)
{
  float f = re * r.re - im * r.im;
  im = re * r.im + im * r.re;
  re = f;
  return *this;
}

inline float
imag (const VrComplex& x) 
{
  return x.imag ();
}

inline float
real (const VrComplex& x) 
{
  return x.real ();
}

inline VrComplex
operator + (const VrComplex& x, const VrComplex& y) 
{
  return VrComplex (real (x) + real (y), imag (x) + imag (y));
}

inline VrComplex
operator + (const VrComplex& x, float y) 
{
  return VrComplex (real (x) + y, imag (x));
}

inline VrComplex
operator + (float x, const VrComplex& y) 
{
  return VrComplex (x + real (y), imag (y));
}

inline VrComplex
operator - (const VrComplex& x, const VrComplex& y)
{
  return VrComplex (real (x) - real (y), imag (x) - imag (y));
}

inline VrComplex
operator - (const VrComplex& x, float y) 
{
  return VrComplex (real (x) - y, imag (x));
}

inline VrComplex
operator - (float x, const VrComplex& y) 
{
  return VrComplex (x - real (y), - imag (y));
}

inline VrComplex
operator * (const VrComplex& x, const VrComplex& y) 
{
  return VrComplex (real (x) * real (y) - imag (x) * imag (y),
			   real (x) * imag (y) + imag (x) * real (y));
}

inline VrComplex
operator * (const VrComplex& x, float y) 
{
  return VrComplex (real (x) * y, imag (x) * y);
}

inline VrComplex
operator * (float x, const VrComplex& y) 
{
  return VrComplex (x * real (y), x * imag (y));
}

inline VrComplex
operator / (const VrComplex& x, float y) 
{
  return VrComplex (real (x) / y, imag (x) / y);
}

inline VrComplex
operator + (const VrComplex& x) 
{
  return x;
}

inline VrComplex
operator - (const VrComplex& x) 
{
  return VrComplex (-real (x), -imag (x));
}

inline bool
operator == (const VrComplex& x, const VrComplex& y) 
{
  return real (x) == real (y) && imag (x) == imag (y);
}

inline bool
operator == (const VrComplex& x, float y) 
{
  return real (x) == y && imag (x) == 0;
}

inline bool
operator == (float x, const VrComplex& y) 
{
  return x == real (y) && imag (y) == 0;
}

inline bool
operator != (const VrComplex& x, const VrComplex& y) 
{
  return real (x) != real (y) || imag (x) != imag (y);
}

inline bool
operator != (const VrComplex& x, float y) 
{
  return real (x) != y || imag (x) != 0;
}

inline bool
operator != (float x, const VrComplex& y) 
{
  return x != real (y) || imag (y) != 0;
}

// Some targets don't provide a prototype for hypot when -ansi.
extern "C" double hypot (double, double);

inline float
abs (const VrComplex& x) 
{
  return hypot (real (x), imag (x));
}

inline float
arg (const VrComplex& x) 
{
  return atan2 (imag (x), real (x));
}

inline VrComplex
polar (float r, float t) 
{
  return VrComplex (r * cos (t), r * sin (t));
}

inline VrComplex
conj (const VrComplex& x)  
{
  return VrComplex (real (x), -imag (x));
}

inline float
norm (const VrComplex& x) 
{
  return real (x) * real (x) + imag (x) * imag (x);
}

// Declarations of templates in VrComplex.cc
VrComplex operator / (const VrComplex& x, const VrComplex& y);
VrComplex operator / (float x, const VrComplex& y);
VrComplex cos (const VrComplex&);
VrComplex cosh (const VrComplex&);
VrComplex exp (const VrComplex&);
VrComplex log (const VrComplex&);
VrComplex pow (const VrComplex&, const VrComplex&);
VrComplex pow (const VrComplex&, float);
VrComplex pow (const VrComplex&, int);
VrComplex pow (float, const VrComplex&);
VrComplex sin (const VrComplex&);
VrComplex sinh (const VrComplex&);
VrComplex sqrt (const VrComplex&);

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
istream& operator >> (istream&, VrComplex&);
ostream& operator << (ostream&, const VrComplex&);

#endif



