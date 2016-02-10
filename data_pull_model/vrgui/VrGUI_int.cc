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

#include <qdrawutl.h>

#include "VrGUI_int.h"

static const double MinEps=1.0e-10;
static const double WorstCase = -8.8888888888888888888888e-88;
#define qwtMax(x,y) ( (x) > (y) ? (x) : (y) )
#define qwtMin(x,y) ( (x) < (y) ? (x) : (y) )
#define qwtAbs(x) ( (x) > 0 ? (x) : -(x) )

VrPlot::VrPlot(QWidget *p, int nPoints, int divisions, char *xaxis_name, char *yaxis_name,
	int lines, int xmin, int xmax, int ymin, int ymax) : QFrame(p, "VrPlot")
{
    QRect rBottom, rLeft, rPlot;
    int hDist, vDist, h, w;
    QPainter p;
    int d_margin = 10;

	set_persistent(0);
	d_lines = lines;
	setFixedSize(530, 280);
	setFrameStyle(QFrame::Box | QFrame::Raised);
	setLineWidth(4);
	setMidLineWidth(7);

    d_frmPlot = new VrPlotPixFrame(this);
    vDist = hDist = d_frmPlot->frameWidth() + 2;

    yyd_left = new VrScale(VrScaleDraw::Left,this, yaxis_name, -127.0, 127.0, ymin, ymax, 256);
    yyd_bottom = new VrScale(VrScaleDraw::Bottom,this, xaxis_name, 0, nPoints, xmin,
		xmax, divisions);

    p.begin(yyd_bottom);
    QFontMetrics fm = p.fontMetrics();
    QString s;
	s.setNum(WorstCase, yyd_bottom->d_scale.d_fmt, yyd_bottom->d_scale.d_prec);
	w = (fm.width(s) + 1) / 2;
	if (hDist < w)
		hDist = w;
    w = (fm.ascent() + fm.descent() + 1) / 2;
    if (vDist < w)
		vDist = w;
    p.end();

    h = yyd_bottom->sizeHint().height();	/* height of bottom axis legend */
    rPlot = this->contentsRect();
    rPlot.setTop(rPlot.top() + d_margin + 1);
	rPlot.setBottom(rPlot.bottom() - h - d_margin);

	rLeft = rPlot;
	rLeft.setWidth(yyd_left->sizeHint().width());

    rPlot.setLeft(rLeft.right() + 1);
	rPlot.setRight(rPlot.right() - qwtMax(d_margin, hDist));
    d_frmPlot->setGeometry(rPlot);

    yyd_bottom->zyd_y1 = qwtMax(0,vDist - d_frmPlot->frameWidth());
    w = 2*d_frmPlot->frameWidth() + yyd_bottom->zyd_y1;
    yyd_left->zyd_y1 = rPlot.height() - w;
	updateAxes(yyd_left, vDist, &rLeft, yyd_bottom->zyd_y1);

    rBottom.setTop(rPlot.bottom() + 1);
	rBottom.setHeight(h);
    rBottom.setLeft(rPlot.x() + vDist - hDist);
	rBottom.setRight(rPlot.right() + hDist - vDist);
	updateAxes(yyd_bottom, hDist, &rBottom, rPlot.width() - w);
	d_frmPlot->show();
}

void VrPlot::updateAxes(VrScale *arg_scale, int arg_dist, QRect *arg_rect, int arg_offset)
{
    arg_scale->d_borderDist = arg_dist;
	arg_scale->setGeometry(*arg_rect);
	arg_scale->show();
    arg_scale->d_scale.rebuild(0.0);
	arg_scale->d_scale.d_cnv = 0.0;
	arg_scale->zyd_cnv = 0.0;
	float diff = arg_scale->d_scale.d_hBound - arg_scale->d_scale.d_lBound;
    if (diff != 0) {
       arg_scale->d_scale.d_cnv = double(arg_scale->d_scale.d_y2 - arg_scale->d_scale.d_y1) / diff;
       arg_scale->zyd_cnv = double(arg_offset - arg_scale->zyd_y1) / diff;
	}
}

VrPlot::~VrPlot()
{
    delete d_frmPlot;
    delete yyd_left;
    delete yyd_bottom;
}

void VrPlot::set_persistent(int arg_persistent)
{
	persistent = arg_persistent;
}
void VrPlot::resizeEvent(QResizeEvent *e)
{
    QFrame::resizeEvent(e);
}
#define REMAP(BASE, VALUE) (BASE->zyd_y1 + int(rint( ((VALUE) - BASE->d_scale.d_lBound) * BASE->zyd_cnv )) )
void VrPlot::data(double *xdat, double *ydat, int size)
{
    QPainter p;
    QPointArray this_pa;
    int i, x, y, x1, x2, y1, y2, u1,v1;

	if (!persistent)
    	clear(); //jca d_frmPlot->d_pix.fill(black);

    p.begin(&d_frmPlot->d_pix);
    p.setClipping(TRUE);
    p.setClipRect(d_frmPlot->d_pix.rect());
    x1 = d_frmPlot->d_pix.rect().left();
    x2 = d_frmPlot->d_pix.rect().right();
    y1 = d_frmPlot->d_pix.rect().top();
    y2 = d_frmPlot->d_pix.rect().bottom();
    p.setPen(QPen(white.dark(300), 0, SolidLine)); // SolidLine, DashLine, DotLine, DashDotLine, DashDotDotLine
	for (i=0;i<(int)yyd_bottom->d_scale.d_majMarks.size();i++) {
		x = REMAP(yyd_bottom, yyd_bottom->d_scale.d_majMarks[i]);
		if (x >= x1 && x <= x2)
			p.drawLine(x, y1, x, y2);
	}
	for (i=0;i<(int)yyd_left->d_scale.d_majMarks.size();i++) {
		y = REMAP(yyd_left, yyd_left->d_scale.d_majMarks[i]);
		if (y >= y1 && y <= y2)
			p.drawLine(x1, y, x2, y);
	}
	if (this_pa.size() == uint(size) || this_pa.resize(uint(size)) )
		this_pa.resize(uint(size));
	p.setPen(green);
	u1 = REMAP(yyd_bottom, xdat[0]);
	v1 = REMAP(yyd_left, ydat[0]);
	if (!d_lines)
		p.drawEllipse(u1, v1, 2, 2);
	for (i=1; i < size; i++)
		if (d_lines)
			this_pa.setPoint(i, REMAP(yyd_bottom, xdat[i]), REMAP(yyd_left, ydat[i]));
		else
			p.drawEllipse(REMAP(yyd_bottom, xdat[i]), REMAP(yyd_left, ydat[i]), 2, 2);
	if (d_lines) {
		p.moveTo(u1,v1);
		this_pa.setPoint(0,u1,v1);
		p.drawPolyline(this_pa);
	}
	p.end();
    d_frmPlot->repaint(d_frmPlot->contentsRect(), FALSE);
}

void VrPlot::clear()
{
   	d_frmPlot->d_pix.fill(black);
}

VrPlotPixFrame::VrPlotPixFrame(QWidget *parent) : QFrame(parent, "VrPlotPixFrame")
{
    setFrameStyle(QFrame::Panel|QFrame::Sunken);
    setLineWidth(2);
    setMidLineWidth(0);
    setCursor(crossCursor);
}
void VrPlotPixFrame::resizeEvent(QResizeEvent *e)
{
    QFrame::resizeEvent(e);
    if (contentsRect().size() != d_pix.size()) {
		d_pix.resize(contentsRect().size());
	d_pix.fill(backgroundColor());
    }
	emit pixmapResized();
}
void VrPlotPixFrame::paintEvent(QPaintEvent *e)
{
    QRect r = contentsRect();
    QPainter p;

    p.begin(this);
    drawFrame(&p);
	p.drawPixmap(r.x(), r.y(), d_pix, 0, 0, d_pix.width(), d_pix.height());
    p.end();
}

VrScale::VrScale( VrScaleDraw::Orientation ori, QWidget *parent,
	char *title_name, double arg_min, double arg_max, double arg_scalemin,
	double arg_scalemax, int arg_divisions)
: QWidget(parent, "VrScale")
{
    d_borderDist = 0;
    d_baseDist = 4;
    d_titleOffset = 0;
    d_titleDist = 8;
    d_scale.setGeometry(0,0,10,ori);
    setMinimumSize(30,30);
	d_title = QString(title_name);
	setFont(QFont("Helvetica", 10));
    d_scale.d_maxMajor = 8;
    d_scale.d_maxMinor = 5;
	d_scale.d_lBound = arg_scalemin;
	d_scale.d_hBound = arg_scalemax;
    d_scale.rebuild((double)(arg_scalemax - arg_scalemin)/arg_divisions);
}

VrScale::~VrScale() { }
void VrScale::paintEvent(QPaintEvent *e)
{
    QRect r = this->rect();
    QPainter p;

    p.begin(this);
    int ta = p.fontMetrics().ascent();
    int th = p.fontMetrics().height();
    int ttop = ta + d_titleOffset;
    d_scale.scaledraw(&p);
    p.setFont(QFont("Helvetica", 12, QFont::Bold));
    if (d_scale.d_orient == VrScaleDraw::Left) {
		p.rotate(-90.0);
		ttop = qwtMin(ttop + (r.width() - ttop) / 4, r.width());
		p.drawText(-r.bottom(), r.right() - ttop, r.height(), 2*th,AlignHCenter|AlignTop, d_title);
	}
    else
		p.drawText(r.x(), r.top() + d_titleOffset, r.width(), 2*th, AlignHCenter|AlignTop,d_title);
    p.end();
}
void VrScale::resizeEvent(QResizeEvent *e)
{
    QRect r = this->rect();
	d_titleOffset = d_titleDist + d_baseDist + d_scale.zzmaxHeight(this);
    if (d_scale.d_orient == VrScaleDraw::Left) {
		d_scale.setGeometry(r.right() - d_baseDist, r.y() + d_borderDist,
			r.height() - 2 * d_borderDist, d_scale.d_orient);
		d_titleOffset = d_baseDist + d_titleDist + d_scale.maxWidth(this);
    }
	else
		d_scale.setGeometry(r.x() + d_borderDist, r.y() + d_baseDist,
			r.width() - 2 * d_borderDist, d_scale.d_orient);
}
QSize VrScale::sizeHint() const
{
    QPainter p;
    QSize rv;

    p.begin(this);
    p.setFont(QFont("Helvetica", 12, QFont::Bold));
    QFontMetrics fm = p.fontMetrics();
	int fa = fm.ascent();
	int fh = fm.height();
    p.end();
    if (d_scale.d_orient == VrScaleDraw::Left) {
		rv.setWidth(d_scale.maxWidth(this) + d_baseDist + fa);
		rv.setHeight(d_scale.d_majMarks.size() * 2 * d_scale.zzmaxHeight(this));
	}
    else {
		rv.setHeight(d_scale.zzmaxHeight(this) + d_baseDist + fh + d_titleDist);
		rv.setWidth(d_scale.d_majMarks.size()  * d_scale.maxWidth(this));
    }
    return rv;
}

static const double step_eps = 1.0e-3;
static const double border_eps = 1.0e-10;
int const VrScaleDraw::minLen = 10;
const double jcastep_eps = 1.0e-6;
VrScaleDraw::VrScaleDraw()
{
    d_pad = 6;
    d_majLen = 8;
    d_minLen = 4;
    d_medLen = 6;
    d_fmt = 'g';
    d_prec = 4;
    d_lBound = 0.0;
    d_hBound = 0.0;
    d_majStep = 0.0;
    setGeometry(0,0,100,Bottom);
}
#define REMAPN(VALUE) (d_y1 + int(rint( ((VALUE) - d_lBound) * d_cnv )) )
void VrScaleDraw::scaledraw(QPainter *p) const
{
    double val,hval,majTick;
    int i,k,kmax, bw2, tval;
    static QString label;
    QFontMetrics fm = p->fontMetrics();

	kmax = d_majMarks.size() - 1;
	k = 0;
    for (i=0; i <= kmax; i++) {
		val = d_majMarks[i];
		tval = REMAPN(val);
		drawTick(p, tval, d_majLen);
		if (qwtAbs(val) < qwtAbs(jcastep_eps * d_majStep))
			val = 0.0;
		label.setNum(val, d_fmt, d_prec);
		if (d_orient == Left)
			p->drawText(d_xorg - d_majLen - d_pad - fm.width(label),
				tval + (fm.ascent() -1) / 2, label);
		else
			p->drawText(tval - (fm.width(label)-1) / 2,
				d_yorg + d_majLen + d_pad + fm.ascent(), label);
    }
	if (kmax > 0) {
		majTick = d_majMarks[0];
		hval = majTick - 0.5 * d_majStep;
		for (i=0; i< (int)d_minMarks.size(); i++) {
			val = d_minMarks[i];
			if  (val > majTick) {
				if (k < kmax)
				majTick = d_majMarks[++k];
				else
				majTick += d_majMarks[kmax] + d_majStep;
				hval = majTick - 0.5 * d_majStep;
			}
			bw2 = d_minLen;
			if (qwtAbs(val-hval) < jcastep_eps * d_majStep)
				bw2 = d_medLen;
			drawTick(p, REMAPN(val), bw2);
		}
	}
    bw2 = p->pen().width() / 2;
    if (d_orient == Left)
		p->drawLine(d_xorg - bw2, d_yorg, d_xorg - bw2, d_yorg + d_len - 1);
	else
		p->drawLine(d_xorg, d_yorg+bw2, d_xorg + d_len - 1, d_yorg+bw2);
}
void VrScaleDraw::drawTick(QPainter *p, int val, int len) const
{
	if (d_orient == Left)
		p->drawLine(d_xorg, val, d_xorg - len, val);
	else
		p->drawLine(val, d_yorg, val, d_yorg + len);
}
void VrScaleDraw::setGeometry(int xorigin, int yorigin, int length, Orientation o)
{
    d_xorg = xorigin;
    d_yorg = yorigin;
    if (length > minLen)
       d_len = length;
    else
       d_len = minLen;
    d_orient = o;
    if (d_orient == Left) {
		d_y1 = d_yorg + d_len - 1;
		d_y2 = d_yorg;
		d_pad = 6;
	}
    else {
		d_y1 = d_xorg;
		d_y2 = d_xorg + d_len - 1;
		d_pad = 3;
    }
    if (d_hBound != d_lBound)
       d_cnv = double(d_y2 - d_y1) / (d_hBound - d_lBound);
    else
       d_cnv = 0.0;
}
int VrScaleDraw::maxWidth(const VrScale *arg_widget) const
{
    QString s;
    QPainter p;
	s.setNum(WorstCase, d_fmt, d_prec);
    p.begin(arg_widget);
    int rv = p.fontMetrics().width(s);
    if (d_orient == Left)
		rv += p.pen().width() + d_pad + d_majLen;
	else
		rv += d_len;
	p.end();
    return rv;
}

int VrScaleDraw::zzmaxHeight(const QWidget *arg_widget) const
{
    QPainter p;
    p.begin(arg_widget);
    int rv = p.fontMetrics().height();
    if (d_orient == Left)
		rv = d_len + ((rv + 1) / 2);
	else
		rv += p.pen().width() + d_pad + d_majLen;
	p.end();
    return rv;
}

double qwtCeil125( double x)
{
    double lx, rv;
    double p10, fr;
    double sign = ( x > 0) ? 1.0 : -1.0;

    if (x == 0.0) return 0.0;

    lx = log10(fabs(x));
    p10 = floor(lx);
    fr = pow(10.0,lx - p10);
    if (fr <=1.0) fr = 1.0;
    else if (fr <= 2.0) fr = 2.0;
    else if (fr <= 5.0) fr = 5.0;
    else fr = 10.0;
    rv = fr * pow(10.0,p10);
    return sign * rv;
}
void VrScaleDraw::rebuild(double step)
{
    int nMaj, nMin, minSize, i,k, imax;
    double val, mval, firstTick, lastTick, minStep, zzzstep;
    QArray<double> buffer;

    step = qwtAbs(step);
    d_majMarks.duplicate(0,0);
    d_minMarks.duplicate(0,0);
    if (d_lBound == d_hBound) return;
    if (step == 0.0)
       d_majStep = qwtCeil125(qwtAbs(d_hBound - d_lBound) * 0.999999
			/ double(d_maxMajor));
    else
       d_majStep = step;
    if (d_majStep == 0.0) return;
    firstTick = ceil( (d_lBound - step_eps * d_majStep) / d_majStep) * d_majStep;
    lastTick = floor( (d_hBound + step_eps * d_majStep) / d_majStep) * d_majStep;
    nMaj = qwtMin(10000, int(rint((lastTick - firstTick) / d_majStep)) + 1);
    d_majMarks.resize(nMaj);
    imax = d_majMarks.size() -1;
    if (d_majMarks.size() > 0) {
		d_majMarks.data()[0] = firstTick;
		d_majMarks.data()[imax] = lastTick;
		zzzstep = (lastTick - firstTick) / double(imax);
		for (i=1;i<imax;i++)
			d_majMarks.data()[i] = firstTick + double(i) * zzzstep;
    }
    if (d_maxMinor < 1) return;
    minStep = qwtCeil125(d_majStep / double(d_maxMinor) );
    if (minStep == 0.0) return;
    nMin = qwtAbs(int(rint(d_majStep / minStep))) - 1; // # minor steps per interval
    // Do the minor steps fit into the interval?
    if ( qwtAbs(double(nMin +  1) * minStep - d_majStep) >  step_eps * d_majStep) {
		nMin = 1;
		minStep = d_majStep * 0.5;
    }
    // Are there minor ticks below the first major tick?
    if (d_majMarks[0] > d_lBound )
       i = -1;
    else
       i = 0;
    // resize buffer to the maximum possible number of minor ticks
    if (buffer.resize(nMin * (nMaj + 1))) {	// calculate minor ticks
		minSize = 0;
		val = d_majMarks[0] - d_majStep;
		for (; i < (int)d_majMarks.size(); i++) {
			if (i >= 0)
			val = d_majMarks[i];
			for (k=0; k< nMin; k++) {
				mval = (val += minStep);
				if (mval < d_lBound) {
					if (mval < d_lBound - qwtAbs(border_eps * d_lBound)) continue;
					mval = d_lBound;
				}
				else if (mval > d_hBound) {
					if (mval > d_hBound + qwtAbs(border_eps * d_hBound)) continue;
					mval = d_hBound;
				}
				buffer[minSize++] = mval;
			}
		}
		d_minMarks.duplicate(buffer.data(), minSize);
    }
}

VrSlider::VrSlider(QWidget *parent, Orientation orient, ScalePos scalePos,
	double vmin, double vmax, double arg_val, double arg_step) : QWidget(parent, "VrSlider")
{
    int d_sclDist = 4;
    int d_xMargin = 0;
    int d_yMargin = 0;

    d_prevValue = d_value = 0.0;
    d_step = arg_step; //jca 1.0;
	d_thumbLength = 16;
	d_thumbHalf = 8;
	d_thumbWidth = 30;
    d_borderWidth = 2;
    d_bwTrough = 0;
    d_orient = orient;
    d_sliderRect.setRect(0,0,8,8);
    if (d_orient == Horizontal)
       setMinimumSize(40,10);
    else
       setMinimumSize(10,40);
    d_tmrID = 0;
    d_updTime = 150;
    d_tracking = FALSE;
    d_mouseOffset = 0.0;
    yyd_scale.d_maxMajor = 5;
    yyd_scale.d_maxMinor = 3;
	yyd_scale.d_lBound = vmin;
	yyd_scale.d_hBound = vmax;
    yyd_scale.rebuild(0.0);
    if (yyd_scale.d_hBound != yyd_scale.d_lBound)
       yyd_scale.d_cnv = double(yyd_scale.d_y2 - yyd_scale.d_y1) / (yyd_scale.d_hBound - yyd_scale.d_lBound);
    else
       yyd_scale.d_cnv = 0.0;
    QSize s = QSize (200, yyd_scale.zzmaxHeight(this)
		+ 2*d_yMargin + d_thumbWidth + 2*d_bwTrough + d_sclDist);
	setFixedSize(s);

    // reposition slider
    int sliderWidth = d_thumbWidth + 2 * d_bwTrough;
    if(d_orient == Horizontal) {
		d_sliderRect.setRect(this->rect().x() + d_xMargin, this->rect().y() + d_yMargin,
				s.width() - 2*d_xMargin, sliderWidth);
		yyd_scale.setGeometry(d_sliderRect.x() + d_bwTrough + d_thumbHalf,
				d_sliderRect.y() + d_sliderRect.height() +  d_sclDist,
				d_sliderRect.width() - d_thumbLength - 2*d_bwTrough, VrScaleDraw::Bottom);
    }
    else {
		d_sliderRect.setRect(this->rect().x() + s.width() - sliderWidth - 1 - d_xMargin,
				this->rect().y() + d_yMargin, sliderWidth, s.height() - 2 * d_yMargin);
		yyd_scale.setGeometry(d_sliderRect.x() - d_sclDist, d_sliderRect.y() + d_thumbHalf + d_bwTrough,
				s.height() - d_thumbLength - 2*d_bwTrough, VrScaleDraw::Left);
    }
	setNewValue(arg_val,0);
    d_pageSize = int(qwtAbs((yyd_scale.d_hBound - yyd_scale.d_lBound) / d_step));
	if (d_pageSize > 1)
		d_pageSize = 1;
}

VrSlider::~VrSlider()
{
    if(d_tmrID) killTimer(d_tmrID);
}
void VrSlider::drawSlider (QPainter *p, const QRect &r)
{
    QColorGroup g = colorGroup();
    QBrush brBack(g.background());
    QBrush brMid;
    QBrush brDark(g.dark());
    QRect cr;
    int ipos,dist1;
    double rpos;
    int lineDist;
    int ws, ds, dLeft, lPos, rPos;
    QRect rSlot;

	cr = r;
	brMid = brBack;
    rpos = (d_value  - yyd_scale.d_lBound) / (yyd_scale.d_hBound - yyd_scale.d_lBound);
    lineDist = d_borderWidth - 1;
    if (lineDist < 1) lineDist = 1;
    if (d_orient == Horizontal) {
		dist1 = int(double(cr.width() - d_thumbLength) * rpos);
		ipos =  cr.x() + dist1;
		markerPos = ipos + d_thumbHalf;
		QRect rThumb = QRect(ipos, cr.y(), d_thumbLength, cr.height());
		const QColorGroup &g = colorGroup();
		ws = cr.height();
		ws = 4 + (ws & 1);
		ds = qwtMax(1, d_thumbLength/2 - 4);
		dLeft = rThumb.left() - cr.left();
		rSlot = QRect(cr.x() + ds, cr.y() + (cr.height() - ws) / 2,
			cr.width() - 2 * ds, ws);
		rPos = qwtMin(rSlot.x(), rThumb.left());
		if (rThumb.left() > cr.x()) {
			p->fillRect(cr.x(),cr.y(),dLeft, rSlot.top() - cr.top(), brMid);
			p->fillRect(cr.x(),rSlot.bottom() + 1,dLeft,
			cr.bottom() - rSlot.bottom(),brMid);
			if (rPos > cr.left())
				p->fillRect(cr.x(),rSlot.y(), rPos - cr.left(),ws,brMid);
			p->setPen(g.dark());
			if (rSlot.x() < rThumb.left())
				p->drawLine(rSlot.x(), rSlot.bottom(), rSlot.x(), rSlot.top());
			if (rSlot.x() < rThumb.left() - 1) {
			p->drawLine(rSlot.x(), rSlot.top(), rThumb.left() - 1, rSlot.top());
			p->setPen(g.light());
			p->drawLine(rSlot.x() + 1, rSlot.bottom(), rThumb.left() - 1, rSlot.bottom());
			p->fillRect(rSlot.x() + 1, rSlot.y() + 1, dLeft - ds -1,
					rSlot.height() -2, QBrush(black));
			}
		}
		lPos = qwtMax(rSlot.right(), rThumb.right()) + 1;
		if (rThumb.right() < cr.right()) {
			p->fillRect(rThumb.right() + 1,cr.y(),cr.right() - rThumb.right(),
			rSlot.top() - cr.top(), brMid);
			p->fillRect(rThumb.right() + 1,rSlot.bottom() + 1,
			cr.right() - rThumb.right(), cr.bottom() - rSlot.bottom(),brMid);
			if (lPos <= cr.right())
				p->fillRect(lPos, rSlot.y() , cr.right() - lPos + 1, ws ,brMid);

			p->setPen(g.dark());
			if (rSlot.right() > rThumb.right()) {
			p->drawLine(rThumb.right() + 1, rSlot.top(), rSlot.right(), rSlot.top());
			p->setPen(g.light());
			p->drawLine(rSlot.right(), rSlot.bottom(), rSlot.right(), rSlot.top() + 1);
			}

			if (rSlot.right() > rThumb.right() + 1) {
			p->setPen(g.light());
			p->drawLine(rThumb.right() + 1, rSlot.bottom(),
					rSlot.right() -1, rSlot.bottom());
			p->fillRect(rThumb.right() + 1, rSlot.y() + 1,
					rSlot.right() - rThumb.right() - 1, rSlot.height() -2, QBrush(black));
			}
		}
		// //	Draw thumb //
		qDrawShadePanel(p,ipos, cr.y(), d_thumbLength, cr.height(),
				colorGroup(), FALSE, d_borderWidth, &brBack);
#define DUAL(A,B,C,D, E, F) { \
		p->setPen(g.dark()); \
		p->drawLine((A) -(E) , (B) - (F), (C) -(E), (D) - (F) ); \
		p->setPen(g.light()); \
		p->drawLine((A), (B), (C), (D) ); }

		DUAL(markerPos, cr.y() + lineDist, markerPos, cr.y() + cr.height() - lineDist - 1, 1, 0);
    }
    else {
		dist1 = int(double(cr.height() - d_thumbLength) * (1.0 - rpos));
		ipos = cr.y() + dist1;
		markerPos = ipos + d_thumbHalf;
		p->fillRect(cr.x(),cr.y(),cr.width(),ipos,brMid);
		p->fillRect(cr.x(), ipos + d_thumbLength, cr.width(),
				cr.height() - d_thumbLength - dist1, brMid);
		qDrawShadePanel(p,cr.x(),ipos , cr.width(), d_thumbLength,
				colorGroup(),FALSE,d_borderWidth, &brBack);
		if (lineDist > 1)
		qDrawShadeLine(p, cr.x() + lineDist , markerPos,
				cr.x() + cr.width() - lineDist, markerPos,
				colorGroup(), TRUE, 1);
		else
			DUAL(cr.y() + lineDist, markerPos, cr.y() + cr.width() - lineDist - 1, markerPos, 0, 1);
    }
}

double VrSlider::getValue( const QPoint &p)
{
    double rv, mypos;
    int size;

	rv = 0.5 * (yyd_scale.d_lBound + yyd_scale.d_hBound);
    if (d_orient == Horizontal) {
		size = d_sliderRect.width() - 2 * d_bwTrough;
		mypos = p.x() - (d_sliderRect.x() + d_bwTrough) - d_thumbHalf;
    }
    else {
		size = d_sliderRect.height();
		mypos = 1.0 - double(p.y() - (d_sliderRect.y() - d_bwTrough) - d_thumbHalf);
    }
	if (size > d_thumbLength)
		rv =  yyd_scale.d_lBound +
			rint( (yyd_scale.d_hBound - yyd_scale.d_lBound) * mypos
			/ double(size - d_thumbLength)
			/ qwtAbs(d_step) ) * qwtAbs(d_step);
    return(rv);
}

void VrSlider::paintEvent(QPaintEvent *e)
{
    QPainter p;

    p.begin(this);
	p.fillRect(this->rect(), this->backgroundColor());
	yyd_scale.scaledraw(&p);
	drawSlider(&p, d_sliderRect);
    p.end();
}
void VrSlider::valueChange()
{
    QPainter p;
    p.begin(this);
    drawSlider(&p,d_sliderRect);
    p.end();
    if (d_tracking)
       emit valueChanged(d_value);
}
void VrSlider::stopMoving()
{
    if(d_tmrID) {
		killTimer(d_tmrID);
		d_tmrID = 0;
    }
}
void VrSlider::mousePressEvent(QMouseEvent *e)
{
    const QPoint &p = e->pos();
    int currentPos;
    d_timerTick = 0;
    if (d_orient == Horizontal)
       currentPos = p.x();
    else
       currentPos = p.y();
	d_direction = 0;
    if (d_sliderRect.contains(p)) {
		if ((currentPos > markerPos - d_thumbHalf)	&& (currentPos < markerPos + d_thumbHalf))
			d_scrollMode = ScrMouse;
		else {
			d_scrollMode = ScrPage;
			if ((currentPos > markerPos && d_orient == Horizontal)
				|| (currentPos <= markerPos && d_orient != Horizontal))
				d_direction = 1;
			else
				d_direction = -1;
		}
    }
    else
		d_scrollMode = ScrNone;
    stopMoving();
    switch(d_scrollMode) {
    case ScrPage:
		d_mouseOffset = 0;
		d_tmrID = startTimer(qwtMax(250, 2 * d_updTime));
		break;

    case ScrMouse:
		d_time.start();
		d_mouseOffset = getValue(p) - d_value;
		emit sliderPressed();
		break;
    }
}
void VrSlider::buttonReleased()
{
    if ((!d_tracking) || d_value != d_prevValue)
       emit valueChanged(d_value);
}
void VrSlider::mouseReleaseEvent(QMouseEvent *e)
{
    double inc = qwtAbs(d_step);

    switch(d_scrollMode) {
    case ScrMouse:
	setNewValue(getValue(e->pos()) - d_mouseOffset, 1);
		d_direction = 0;
		d_mouseOffset = 0;
		emit sliderReleased();
		break;
    case ScrPage:
		inc = double(d_pageSize) * d_step;
		stopMoving();
		if (!d_timerTick)
			setNewValue(d_value + double(d_direction) * inc, 1);
		d_timerTick = 0;
		break;
    }
	d_scrollMode = ScrNone;
	buttonReleased();
}
void VrSlider::mouseMoveEvent(QMouseEvent *e)
{
    if (d_scrollMode == ScrMouse ) {
    	setNewValue(getValue(e->pos()) - d_mouseOffset, 1);
		if (d_value != d_prevValue)
			emit sliderMoved(d_value);
    }
}
void VrSlider::timerEvent(QTimerEvent *e)
{
    if (d_scrollMode == ScrPage) {
    	setNewValue(d_value + double(d_direction) * double(d_pageSize) * d_step, 1);
		if (!d_timerTick) {
			killTimer(d_tmrID);
			d_tmrID = startTimer(d_updTime);
		}
    }
	else
		stopMoving();
    d_timerTick = 1;
}

void VrSlider::setValue(double val)
{
    if (d_scrollMode == ScrMouse) stopMoving();
    setNewValue(val,0);
}

void VrSlider::setNewValue(double x, int align)
{
    d_prevValue = d_value;
    if (x < yyd_scale.d_lBound) d_value = yyd_scale.d_lBound;
    else if (x > yyd_scale.d_hBound) d_value = yyd_scale.d_hBound;
    else d_value = x;

    if (align) {
		if (d_step != 0.0)
			d_value = yyd_scale.d_lBound + rint((d_value - yyd_scale.d_lBound) / d_step ) * d_step;
		else
			d_value = yyd_scale.d_lBound;

		// correct rounding error at the border
		if (fabs(d_value - yyd_scale.d_hBound) < MinEps * qwtAbs(d_step))
		d_value = yyd_scale.d_hBound;

		// correct rounding error if value = 0
		if (fabs(d_value) < MinEps * qwtAbs(d_step))
			d_value = 0.0;
    }
    if (d_prevValue != d_value)
	valueChange();
}

static const int MAXBTNS=3;
static const int MIN_LBL_WIDTH = 50;
static const int BUTTON_SIZE = 16;

VrCounter::VrCounter(QWidget *parent, double vmin, double vmax, double vstep, double arg_default)
: QWidget(parent, "VrCounter")
{
    QSize r;
    int i;
	VrArrowButton *temp;

	d_minValue = vmin;
	d_maxValue = vmax;
	d_step = vstep;
    d_prevValue = d_value = arg_default;

    d_Inc[0] = 10;
    d_Inc[1] = 100;
    d_Inc[2] = 1000;
	d_nButtons = 3;
    d_tmrIntv = 200;
    lblValue = new QLabel(this);
    lblValue->setNum(arg_default);
    lblValue->setAlignment(AlignCenter);
    lblValue->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    lblValue->setMargin(1);           // for sizeHint()
    int h =  qwtMax(lblValue->sizeHint().height(), BUTTON_SIZE);
    r.setHeight(h);
    r.setWidth( qwtMax(lblValue->sizeHint().width(), MIN_LBL_WIDTH) + d_nButtons * h * 2);
	setFixedSize(r);
    int btnWidth = qwtMax(5, qwtMin(r.height(), (r.width() - MIN_LBL_WIDTH) / ( 2 * d_nButtons)) );
    lblValue->resize(r.width() - 2*d_nButtons * btnWidth, r.height());
    lblValue->move(d_nButtons * btnWidth, 0);
    for(i=0;i<MAXBTNS;i++) {
		temp = new VrArrowButton(this, i, 1, r.height(), r.width());
		temp = new VrArrowButton(this, i, 0, r.height(), r.width());
    }
}
VrCounter::~VrCounter()
{
    delete lblValue;
}
void VrCounter::valueChange()
{
    lblValue->setNum(d_value);
    emit valueChanged(d_value);
}
void VrCounter::update_value()
{
    emit buttonReleased(d_value);
}
void VrCounter::resizeEvent(QResizeEvent *e) { }
void VrCounter::timerEvent(QTimerEvent *e)
{
    d_tick = 1;
    setNewValue(d_value + double(d_incValue) * d_step, 1);
}
void VrCounter::setNewValue(double x, int align)
{
    d_prevValue = d_value;
    d_value = x;
    if (d_value < d_minValue)
		d_value = d_minValue;
    else if (d_value > d_maxValue)
		d_value = d_maxValue;

    if (align) {
		if (d_step != 0.0)
			d_value = d_minValue + rint((d_value - d_minValue) / d_step ) * d_step;
		else
			d_value = d_minValue;

		if (fabs(d_value - d_maxValue) < MinEps * qwtAbs(d_step))
			d_value = d_maxValue;	// correct rounding error at the border

		if (fabs(d_value) < MinEps * qwtAbs(d_step))
			d_value = 0.0;			// correct rounding error if value = 0
    }
    if (d_prevValue != d_value)
	valueChange();
}
static const int MaxNum = 3;

VrArrowButton::VrArrowButton(VrCounter *parent, int num, int dir, int arg_height, int arg_width)
: QPushButton(parent, "VrArrowButton")
{
    d_num = num;
    d_dir = dir;
	d_parent = parent;
    int btnWidth = qwtMax(5, qwtMin(arg_height, (arg_width - MIN_LBL_WIDTH) / ( 2 * d_parent->d_nButtons)) );
    d_increment = d_parent->d_Inc[num];
	resize(btnWidth,arg_height);
	if (dir) {
		d_increment = -d_increment;
		move((d_parent->d_nButtons - d_num - 1) * btnWidth, 0);
	}
	else
		move(arg_width - (d_parent->d_nButtons - d_num) * btnWidth, 0);
	show();
    connect(this, SIGNAL(pressed()), SLOT(button_pressed()));
    connect(this, SIGNAL(released()), SLOT(button_released()));
}
void VrArrowButton::drawButtonLabel(QPainter *p)
{
    QPointArray symd_pa;
    int i,ws, hs, offs, wtop, wbottom, mid_y;
    QRect r = this->rect(), sym_rect;

    r.setHeight(r.height() - 4);
    r.setWidth(r.width() - 4);
    r.moveBy(2,2);
	hs = qwtMin(r.height() / 3 - 1, r.width() / 2 - 2);
	ws = hs * 2 - 1;
	offs = (r.height() - (d_num+1) * hs) / 2;
    p->save();
    for (i=0; i <= d_num; i++) {
		sym_rect = QRect(r.left() + (r.width() - ws) / 2,
			r.top() + offs + i * hs, ws, hs);
		p->setBrush(colorGroup().text());
		p->setPen(colorGroup().text());
		wtop = ws / 2;
		wbottom = 0;
		mid_y = sym_rect.bottom();
		if (d_dir) {
			wbottom = wtop;
			wtop = 0;
			mid_y = sym_rect.y();
		}
		symd_pa.resize(3);
		symd_pa.setPoint(0, sym_rect.x() + wtop, sym_rect.y());
		symd_pa.setPoint(1, sym_rect.right(), mid_y);
		symd_pa.setPoint(2, sym_rect.x() +  wbottom, sym_rect.bottom());
		p->drawPolygon(symd_pa);
	}
    p->restore();
}
void VrArrowButton::button_pressed()
{
    if (d_parent->tmrID)
		killTimer(d_parent->tmrID);
	d_parent->d_tick = 0;
    d_parent->d_incValue = d_increment;
    d_parent->tmrID = startTimer(d_parent->d_tmrIntv);
}
void VrArrowButton::button_released()
{
    if (!d_parent->d_tick) {
		d_parent->setNewValue(d_parent->d_value + double(d_parent->d_incValue) * d_parent->d_step, 1);
		d_parent->d_tick = 0;
    }
    if (d_parent->tmrID) killTimer(d_parent->tmrID);
	d_parent->update_value();
}
