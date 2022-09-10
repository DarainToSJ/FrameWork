#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_
#include <QMainWindow>
#include "Export_Dll.h"
class MainWindowPrivate;

class DLLEXPORT MainWindow : public QMainWindow
{

	Q_OBJECT
public:
private:
	MainWindowPrivate *d_ptr = nullptr;
	Q_DECLARE_PRIVATE(MainWindow)
	Q_DISABLE_COPY(MainWindow)
};

#endif // !_MAIN_WINDOW_H_
