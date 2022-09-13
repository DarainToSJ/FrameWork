#include "../inc/BaseWidget.h"
#include <QStyleOption>
#include <QStyle>
#include <QPainter>
#include <QGraphicsDropShadowEffect>
BaseWidget::BaseWidget(QWidget *parent) : QWidget(parent)
{

	initWidget();
}

void BaseWidget::initWidget()
{

	if (!parent())
	{
		setAttribute(Qt::WA_TranslucentBackground);
	}
	else
	{
		setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	}
}

void BaseWidget::drawShadow(int radius)
{
	QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
	shadow->setOffset(0, 0);
	shadow->setColor(QColor("#444444"));
	shadow->setBlurRadius(radius);
	this->setGraphicsEffect(shadow);
}

void BaseWidget::paintEvent(QPaintEvent *event)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

	QWidget::paintEvent(event);
}