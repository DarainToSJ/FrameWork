#include "../inc/ContentW.h"
#include "FileHelper.h"
#include <QVBoxLayout>
#include <QLabel>
ContentW::ContentW(QWidget* parent) :BaseWidget(parent)
{
	initUI();
    initConnect();
}


void ContentW::initUI() {
    m_label = new QLabel("MainWidget",this);
	m_label->setAlignment(Qt::AlignCenter);
    m_label->setObjectName("m_label");
    QVBoxLayout* layout = new QVBoxLayout(this);
	layout->setSpacing(0);
	layout->setMargin(0);
	layout->addWidget(m_label);
	this->setLayout(layout);
	this->setStyleSheet(FileHelper::ReadAllText(":/qss/ContentW.qss"));
}


void ContentW::initConnect() {



}


