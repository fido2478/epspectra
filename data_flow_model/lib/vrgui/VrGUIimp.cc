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

#include <stdio.h>
#include <iostream>
using namespace std;
#include <qapplication.h>
#include <qlayout.h>
#include "VrGUI_int.h"
#include "VrGUI.h"

VrGUI::VrGUI(int argc, char *argv[])
{
	app = new QApplication(argc, argv);		/* this must be executed before any calls to Qt */
	QWidget *qw = new QWidget();

	top = new VrGUILayout(qw, new QVBoxLayout(qw));
	app->setMainWidget(top->widget);
	(void) new VrLogoFrame(top);
	top->layout->addSpacing(10);
}

void VrGUI::processEvents(int arg_param)
{
	app->processEvents(arg_param);
}

void vrgui_exit_app()
{
	exit(0);
}

void VrGUI::start()
{
	top->layout->addSpacing(10);
	(void) new VrGUIButton(top, "Quit", vrgui_exit_app);
	top->widget->show();
}

VrGUIPlot::VrGUIPlot(VrGUILayout *layout, char *xaxis_name, char *yaxis_name,
	int lines, int xmin, int xmax, int ymin, int ymax, int arg_points, int arg_divisions)
{
QWidget *qw = new QWidget(layout->widget, 0, 0);
QBoxLayout *scopeLayout = new QVBoxLayout(qw);

	display = new VrPlot(qw, arg_points, arg_divisions, xaxis_name, yaxis_name,
		lines, xmin, xmax, ymin, ymax);
	scopeLayout->addWidget(display);
	layout->layout->addWidget(qw);
}

VrGUISlider::VrGUISlider(VrGUILayout *layout, void (*arg_callback)(double),
	char *slider_name, float arg_min, float arg_max)
{
VrGUILayout *this_layout = layout->vertical();

	VrSlider *tpdSlider = new VrSlider(layout->widget, VrSlider::Horizontal,
		VrSlider::Bottom, arg_min, arg_max, arg_min + (arg_max - arg_min) / 2);
	this_layout->layout->addWidget(tpdSlider);

	(void) new VrGUILabel(this_layout, slider_name);
	QObject::connect(tpdSlider, SIGNAL(valueChanged(double)),
		new VrGUICallback(arg_callback, arg_min, arg_max), SLOT(callback_slot(double)));
}

void VrGUIPlot::data(double *x, double *y, int arg_points)
{
	display->data(x, y, arg_points);
}

void VrGUIPlot::clear()
{
	display->clear();
}

void VrGUIPlot::set_persistent(int arg_persistent)
{
	display->set_persistent(arg_persistent);
}

VrGUINumber::VrGUINumber(VrGUILayout *layout, char *arg_title, char *arg_units,
	void (*arg_callback)(double), float arg_max, float arg_default)
{
QFrame *qf = new QFrame(layout->widget, "VrGUINumber");
VrGUILayout *this_layout = new VrGUILayout(qf, new QVBoxLayout(qf, 20));

	qf->setFrameStyle(QFrame::Box | QFrame::Raised);
	qf->setLineWidth(4);
	qf->setMidLineWidth(7);
	(void) new VrGUILabel(this_layout, arg_title);

	VrCounter *freqSetter = new VrCounter(this_layout->widget, 0, arg_max, 1, arg_default);
	this_layout->layout->addWidget(freqSetter);

	(void) new VrGUILabel(this_layout, arg_units);
	QObject::connect(freqSetter, SIGNAL(buttonReleased(double)),
		new VrGUICallback(arg_callback, 0.0, arg_max), SLOT(callback_slot(double)));
	layout->layout->addWidget(this_layout->widget);
}

VrGUIButton::VrGUIButton(VrGUILayout *layout, char *arg_title, void (*arg_callback)())
{
QPushButton *qpb = new QPushButton(arg_title, layout->widget);

	qpb->setFont(QFont("times", 14, QFont::Bold));
	qpb->setFixedSize(qpb->sizeHint());
	QObject::connect(qpb, SIGNAL(clicked()),
		new VrGUICallback(arg_callback), SLOT(callback_void_slot()));
	layout->layout->addWidget(qpb);
}

VrLogoFrame::VrLogoFrame(VrGUILayout *layout) : QFrame(layout->widget, "VrLogoFrame")
{
	setLineWidth(2);
	setMargin(10);
	if (!pmap.load(LOGO_FILE))
		printf ("could not load logo file '%s'\n", LOGO_FILE);
	else
		setFixedSize(pmap.width(), pmap.height());
	layout->layout->addWidget(this);
}

void VrLogoFrame::paintEvent(QPaintEvent *e)
{
QRect r = contentsRect();
QPainter p;

	p.begin(this);
	p.drawPixmap(r.x(), r.y(), pmap, 0, 0, pmap.width(), pmap.height());
	p.end();
}

VrGUICallback::VrGUICallback(void (*arg_callback)(double), float arg_min, float arg_max)
{
	callback = arg_callback;
	local_min = arg_min;
	local_max = arg_max;
}

VrGUICallback::VrGUICallback(void (*arg_callback)())
{
	callback_void = arg_callback;
}

void VrGUICallback::callback_void_slot() {
	(*callback_void)();
}

void VrGUICallback::callback_slot(double f) {
	if (f < local_min)
		f = local_min;
	else if (f > local_max)
		f = local_max;
	(*callback)(f);
}

VrGUILayout::VrGUILayout(QWidget *arg_widget, QBoxLayout *arg_layout)
{
	widget = arg_widget;
	layout = arg_layout;
}

VrGUILayout *VrGUILayout::vertical(int arg_width)
{
VrGUILayout *newlayout;

	if (arg_width > 0) {
		QFrame *qf = new QFrame(this->widget);
		qf->setFrameStyle(QFrame::Box | QFrame::Raised);
		qf->setLineWidth(arg_width);
		newlayout = new VrGUILayout(qf, new QVBoxLayout(qf, 20));
		this->layout->addWidget(qf);
	}
	else {
		newlayout = new VrGUILayout(this->widget, new QVBoxLayout());
		this->layout->addLayout(newlayout->layout);
	}
	return newlayout;
}

VrGUILayout *VrGUILayout::horizontal(int arg_width)
{
VrGUILayout *newlayout;

	if (arg_width > 0) {
		QFrame *qf = new QFrame(this->widget);
		qf->setFrameStyle(QFrame::Box | QFrame::Raised);
		qf->setLineWidth(arg_width);
		newlayout = new VrGUILayout(qf, new QHBoxLayout(qf, 20));
		this->layout->addWidget(qf);
	}
	else {
		newlayout = new VrGUILayout(this->widget, new QHBoxLayout());
		this->layout->addLayout(newlayout->layout);
	}
	return newlayout;
}

VrGUILabel::VrGUILabel(VrGUILayout *layout, char *arg_value, int arg_center, int arg_size)
{
	QLabel *lab = new QLabel(arg_value, layout->widget);
	if (arg_center)
		lab->setAlignment(AlignCenter);
	lab->setFont(QFont("times", arg_size, QFont::Bold));
	lab->setFixedSize(lab->sizeHint());
	layout->layout->addWidget(lab);
}

VrGUISpace::VrGUISpace(VrGUILayout *layout, int arg_space)
{
	layout->layout->addSpacing(arg_space);
}
