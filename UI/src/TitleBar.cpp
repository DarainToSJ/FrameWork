#include "TitleBar.h"
#include <QQmlContext>
#include <QQmlEngine>
#include "TitleBarData.h"
TitleBar::TitleBar(const QUrl &url, QWidget *parent)
    : BaseQmlWidget(url, parent)
{
    initBaseQmlWidget();
    initConnect();
}

TitleBar::~TitleBar()
{

}


void TitleBar::initUI() {
    m_data = new TitleBarData("data");

   m_item->rootContext()->setContextProperty("data",m_data);
}
void TitleBar::initConnect()
{
    auto item = m_item->rootObject();
    connect(m_item->rootObject(), SIGNAL(minBtnClick()),this,SLOT(on_Min_Btn_Clicked()));
    
    connect(m_item->rootObject(), SIGNAL(maxBtnClick()),this,SLOT(on_Max_Btn_Clicked()));
    
    connect(m_item->rootObject(), SIGNAL(buyBtnClick()),this,SLOT(on_Buy_Btn_Clicked()));

    connect(m_item->rootObject(), SIGNAL(closeBtnClick()),this,SLOT(on_Close_Btn_Clicked()));

    connect(m_item->rootObject(), SIGNAL(restoreBtnClick()),this,SLOT(on_Restore_Btn_Clicked()));

    connect(m_item->rootObject(), SIGNAL(registerBtnClick()),this,SLOT(on_Register_Btn_Clicked()));

    connect(m_item->rootObject(), SIGNAL(menuBtnClick()),this,SLOT(on_Menu_Btn_Clicked()));
}

void TitleBar::on_Min_Btn_Clicked()
{

}

void TitleBar::on_Max_Btn_Clicked()
{
    m_data->setMaxWindowFlag(!m_data->maxWindowFlag());
}
void TitleBar::on_Buy_Btn_Clicked()
{
}
void TitleBar::on_Restore_Btn_Clicked()
{
}
void TitleBar::on_Close_Btn_Clicked()
{
    qApp->exit();
}
void TitleBar::on_Register_Btn_Clicked()
{
}
void TitleBar::on_Menu_Btn_Clicked()
{

}
