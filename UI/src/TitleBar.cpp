#include "../inc/TitleBar.h"
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

#include <QDebug>
#include <QMouseEvent>

#include "FileHelper.h"
TitleBar::TitleBar(QWidget *parent) : BaseWidget(parent)
{

	initUI();
	initConnect();
}

void TitleBar::initUI()
{

	this->setObjectName("TitleBar");

	m_AppName = new QLabel(this);
	m_AppName->setObjectName("m_AppName");
	m_AppName->setText("FrameWork");

	m_ExitBtn = new QPushButton(this);
	m_ExitBtn->setObjectName("m_ExitBtn");

	m_MaxWBtn = new QPushButton(this);
	m_MaxWBtn->setObjectName("m_MaxWBtn");
	m_MaxWBtn->setVisible(true);

	m_HideBtn = new QPushButton(this);
	m_HideBtn->setObjectName("m_HideBtn");

	m_reStoreBtn = new QPushButton(this);
	m_reStoreBtn->setObjectName("m_reStoreBtn");
	m_reStoreBtn->setVisible(m_MaxWBtn->isVisible());

	QHBoxLayout *layout = new QHBoxLayout(this);
	layout->setSpacing(0);
	layout->setMargin(0);
	layout->addSpacing(12);
	layout->addWidget(m_AppName);
	layout->addStretch();
	layout->addSpacing(3);
	layout->addWidget(m_HideBtn);
	layout->addSpacing(3);
	layout->addWidget(m_MaxWBtn);
	layout->addWidget(m_reStoreBtn);
	layout->addSpacing(3);
	layout->addWidget(m_ExitBtn);
	layout->addSpacing(3);
	this->setLayout(layout);

	QString styleSheet = FileHelper::ReadAllText(":/qss/TitileBar.qss");
	// qDebug() << "TitleBar::strStyle" << styleSheet;
	this->setStyleSheet(styleSheet);
	setMouseTracking(true);
}

void TitleBar::initConnect()
{

	connect(m_HideBtn, &QPushButton::clicked, this, &TitleBar::on_hideBtn_Clicked);

	connect(m_MaxWBtn, &QPushButton::clicked, this, &TitleBar::on_MaxOrRestoreBtn_Clicked);

	connect(m_reStoreBtn, &QPushButton::clicked, this, &TitleBar::on_MaxOrRestoreBtn_Clicked);

	connect(m_ExitBtn, &QPushButton::clicked, this, [=]()
			{ emit signalExitBtnClicked(); });
}

void TitleBar::on_hideBtn_Clicked()
{
	if (parentWidget() != nullptr)
	{
		parentWidget()->hide();
	}
}

void TitleBar::on_MaxOrRestoreBtn_Clicked()
{
	if (parentWidget() != nullptr)
	{
		if (parentWidget()->isMaximized())
		{
			parentWidget()->showNormal();
		}
		else
		{
			parentWidget()->showMaximized();
		}
		updateToMaxWindow(parentWidget()->isMaximized());
	}
}

void TitleBar::updateToMaxWindow(bool isMaxFlag)
{
	m_MaxWBtn->setVisible(!isMaxFlag);
	m_reStoreBtn->setVisible(isMaxFlag);
}

void TitleBar::mouseMoveEvent(QMouseEvent *event)
{
	if (parentWidget() != nullptr && m_bPressed)
	{
		parentWidget()->move(event->globalPos() - m_mousePt);
	}
	return QWidget::mouseMoveEvent(event);
}

void TitleBar::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_bPressed = true;
		m_mousePt = event->globalPos() - parentWidget()->pos();
	}

	return QWidget::mousePressEvent(event);
}

void TitleBar::mouseReleaseEvent(QMouseEvent *event)
{

	m_bPressed = false;
	return QWidget::mouseReleaseEvent(event);
}

void TitleBar::mouseDoubleClickEvent(QMouseEvent *event)
{

	on_MaxOrRestoreBtn_Clicked();

	return QWidget::mouseMoveEvent(event);
}