#include "MainWindow.h"
#include <QPoint>
class MainWindowPrivate
{

public:
    explicit MainWindowPrivate(MainWindow *parent);
    ~MainWindowPrivate();

private:
    QPoint m_pt;
    MainWindow *q_ptr;
    Q_DECLARE_PUBLIC(MainWindow)
}