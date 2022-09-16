#include "../inc/MainWindow.h"
#include "TitleBar.h"
#include <QVBoxLayout>
MainWindow::MainWindow(QWidget *parent) : FramelessWindow<QMainWindow>(true, parent)
{
    initUI();
}
void MainWindow::initUI()
{
    m_titileBar = new TitleBar(QUrl("qrc:/qml/TitleBar.qml"),this);

    setTitlebar(m_titileBar->quickWidget());
    QWidget* widgetCentral = new QWidget();
    QVBoxLayout* vLayout = new QVBoxLayout;
    vLayout->setSpacing(0);
    vLayout->setContentsMargins(2, 2, 2, 2);
    vLayout->addWidget(m_titileBar);
    m_titileBar->setFixedHeight(32);

    m_mainWidget = new QLabel();
    m_mainWidget->setText(tr("MainWindow"));
    m_mainWidget->setStyleSheet(QString("background-color:#2E2F30;"));
    vLayout->addWidget(m_mainWidget);
    widgetCentral->setLayout(vLayout);
    setCentralWidget(widgetCentral);
    this->setMinimumSize(800, 600);
    setResizeable(true);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{

    QMainWindow::resizeEvent(event);
    
}
