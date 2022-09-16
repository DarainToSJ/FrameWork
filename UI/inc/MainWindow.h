#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_
#include "FramelessWindow.hpp"
#include <QMainWindow>
#include <QWidget>
#include "Ui_Export_Dll.h"
#include <QObject>
class TitleBar;
#include <QLabel>
class UIDLLEXPORT MainWindow : public FramelessWindow<QMainWindow>
{
	Q_OBJECT
public:
	MainWindow(QWidget *parent = nullptr);

protected:
	void resizeEvent(QResizeEvent *event);

private:
	void initUI();

	TitleBar *m_titileBar = nullptr;
	QLabel	*m_mainWidget = nullptr;
};
#endif // !_MAIN_WINDOW_H_
