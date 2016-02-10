
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

#ifndef VRGUI_INT_H_
#define VRGUI_INT_H_

#include <math.h>
#include <qglobal.h>
#include <qwidget.h>
#include <qframe.h>
#include <qpainter.h>
#include <qpixmap.h>
#include <qstring.h>
#include <qpushbt.h>
#include <qdatetm.h>
#include <qrect.h>
#include <qlabel.h>

#define LOGO_FILE	"title.bmp"

class VrGUICallback : public QObject {
	Q_OBJECT
public:
	VrGUICallback(void (*arg_callback)(double), float arg_min, float arg_max);
	VrGUICallback(void (*arg_callback)());
private:
	float local_min;
	float local_max;
	void (*callback)(double);
	void (*callback_void)();
private slots:
	void callback_slot(double f);
	void callback_void_slot();
};

class VrGUILayout;
class VrLogoFrame : public QFrame {
    Q_OBJECT
public:
    VrLogoFrame (VrGUILayout *layout);
signals:
    void pixmapResized();
    void plotMousePressed(const QMouseEvent &e);
    void plotMouseReleased(const QMouseEvent &e);
    void plotMouseMoved(const QMouseEvent &e);
protected:
    void paintEvent(QPaintEvent *e);
private:
    QPixmap pmap;
};

class VrScale;
class VrScaleDraw {
public:
    VrScaleDraw();
    enum Orientation { Bottom, Top, Left, Right, Round }; 
    Orientation d_orient; 
    double d_lBound; double d_hBound; double d_majStep;
    QArray<double> d_minMarks, d_majMarks;
    int d_maxMajor;			// max. no. of scale divisions
    int d_maxMinor;			// max. number of minor intervals 
    int d_y1,d_y2;      // integer interval boundaries
    double d_cnv;       // conversion factor
    void setGeometry(int xorigin, int yorigin, int length, Orientation o);
    int maxWidth(const VrScale *arg_widget) const;
    int zzmaxHeight(const QWidget *arg_widget) const;
    int maxLabelWidth(QPainter *p) const;
    void scaledraw(QPainter *p) const;
    void rebuild(double step); 
    int d_prec; 
    char d_fmt;
private: 
    static const int minLen; 
    int d_xorg, d_yorg, d_len, d_pad; 
    int d_medLen, d_majLen, d_minLen; 
    void drawTick(QPainter *p, int val, int len) const;
};

class VrScale : public QWidget {
public: 
	VrScale( VrScaleDraw::Orientation ori, QWidget *parent,
		char *title_name, double arg_min, double arg_max, double arg_scalemin,
		double arg_scalemax, int arg_divisions);
    ~VrScale(); 
    int minBorderDist() const; 
    QSize sizeHint() const; 
    VrScaleDraw d_scale;
    int zyd_y1;
    double zyd_cnv;       // conversion factor
    int d_borderDist;
    QString d_title;
protected: 
    void paintEvent(QPaintEvent *e);
    void resizeEvent(QResizeEvent *e);
private:
    int d_baseDist, d_titleDist, d_titleOffset;
    void setRange(double x1, double x2); 
};
class VrPlotPixFrame : public QFrame {
    Q_OBJECT
public:
    VrPlotPixFrame (QWidget *parent);
    QPixmap d_pix;
signals:
    void pixmapResized();
    void plotMousePressed(const QMouseEvent &e);
    void plotMouseReleased(const QMouseEvent &e);
    void plotMouseMoved(const QMouseEvent &e);
protected:
    virtual void resizeEvent(QResizeEvent *e);
    virtual void paintEvent(QPaintEvent *e);
};
class VrPlot: public QFrame {
    Q_OBJECT
public:
	VrPlot::VrPlot(QWidget *p, int nPoints, int divisions, char *xaxis_name,
		char *yaxis_name, int lines, int xmin, int xmax, int ymin, int ymax);
    virtual ~VrPlot();
    void plotPressed(QMouseEvent *e);
    void plotReleased(QMouseEvent *e);
    void plotMoved(QMouseEvent *e);
    void data(double *x, double *y, int size);
    void clear();
	void set_persistent(int arg_persistent);
private:
    VrPlotPixFrame *d_frmPlot;
    VrScale *yyd_bottom, *yyd_left;
	int d_lines;
	int persistent;
protected:
    void redrawPixmap();
    void updateAxes(VrScale *arg_scale, int arg_dist, QRect *arg_rect, int arg_offset);
    void resizeEvent(QResizeEvent *e);
};

class VrSlider: public QWidget{
	Q_OBJECT
public: 
	enum { ScrNone, ScrMouse, ScrPage };
	enum Orientation{Vertical, Horizontal};
	enum ScalePos {	None, Left, Right, Top, Bottom };
	Orientation d_orient;
	QRect d_sliderRect;
	int d_thumbLength, d_thumbHalf, d_thumbWidth, d_borderWidth, d_bwTrough;
	int markerPos, d_pageSize, d_tracking;
    double d_value, d_step, d_prevValue;
	VrSlider(QWidget *parent, Orientation orient, ScalePos scalePos,
		     double vmin, double vmax, double arg_val, double arg_step = 1.0);
	~VrSlider();
	void stopMoving();
    void setNewValue(double x,int align = 0); 
 protected:
	VrScaleDraw yyd_scale;
	int d_scrollMode, d_direction;
	double d_mouseOffset;
	void timerEvent(QTimerEvent *e);
	void mousePressEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	virtual void drawSlider (QPainter *p, const QRect &r);
	double getValue(const QPoint &p);
	void paintEvent (QPaintEvent *e);
	void valueChange();
	void resizeEvent(QResizeEvent *e) { } 
	void scaleChange();
 private:
	int d_tmrID, d_updTime, d_timerTick;
	QTime d_time;
	void buttonReleased();
 public slots: 
	void setValue(double val);
 signals:
	void valueChanged(double value);
	void sliderPressed();
	void sliderReleased();
	void sliderMoved(double value);
};

class VrCounter;
class VrArrowButton : public QPushButton {
    Q_OBJECT
public:
    VrArrowButton(VrCounter *parent, int num, int dir, int arg_height, int arg_width);
private:
    int d_num, d_dir, d_increment;
	VrCounter *d_parent;
protected:
    void drawButtonLabel(QPainter *p);
private slots:
	void button_pressed();
	void button_released();
};
class VrCounter : public QWidget {
    Q_OBJECT
public: 
    VrCounter(QWidget *parent, double vmin, double vmax, double vstep, double arg_default);
    ~VrCounter();
	void update_value();
    double d_minValue, d_maxValue, d_prevValue;
    void setNewValue(double x,int align = 0); 
    double d_value, d_step;
    int tmrID, d_tmrIntv, d_tick, d_nButtons, d_incValue, d_Inc[3];
private:
    QLabel *lblValue;
    void valueChange();
protected:
    void resizeEvent(QResizeEvent *e);
    void timerEvent(QTimerEvent *e);
 signals:
    void valueChanged(double);
    void buttonReleased(double);
};
#endif
