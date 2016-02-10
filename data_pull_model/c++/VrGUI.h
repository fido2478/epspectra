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
 */

#ifndef VRGUI_H_
#define VRGUI_H_

class QApplication;
class QWidget;
class QBoxLayout;
class VrPlot;

class VrGUILayout {
public:
	VrGUILayout(QWidget *arg_widget, QBoxLayout *arg_layout);
	VrGUILayout *vertical(int arg_width = -1);
	VrGUILayout *horizontal(int arg_width = -1);
	QBoxLayout *layout;
	QWidget *widget;
};

class VrGUI {
public:
	VrGUI(int argc, char *argv[]);
	void start();
	void processEvents(int arg_param);
	VrGUILayout *top;
private:
	QApplication *app;
};

class VrGUIPlot {
public:
	VrGUIPlot(VrGUILayout *layout, char *xaxis_name, char *yaxis_name,
		int lines, int xmin, int xmax, int ymin, int ymax,
		int arg_points, int arg_divisions);
	void data(double *x, double *y, int arg_points);
	void clear();
	void set_persistent(int arg_persistent);
private:
	VrPlot *display;
};

class VrGUISlider {
public:
	VrGUISlider(VrGUILayout *layout, void (*arg_callback)(double),
		char *slider_name, float arg_min, float arg_max);
};

class VrGUINumber {
public:
	VrGUINumber(VrGUILayout *layout, char *arg_title, char *arg_units,
		void (*arg_callback)(double), float arg_max, float arg_default);
};

class VrGUIButton {
public:
	VrGUIButton(VrGUILayout *layout, char *arg_title, void (*arg_callback)());
};

class VrGUILabel {
public:
	VrGUILabel(VrGUILayout *layout, char *arg_value, int arg_center = 1, int arg_size = 14);
};

class VrGUISpace {
public:
	VrGUISpace(VrGUILayout *layout, int arg_space);
};
#endif
