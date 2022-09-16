#ifndef _TITLE_BAR_H_
#define _TITLE_BAR_H_
#include "BaseQmlWidget.h"

class TitleBarData;
class UIDLLEXPORT TitleBar : public BaseQmlWidget
{
    Q_OBJECT


public:
    explicit TitleBar(const QUrl &url, QWidget *parent = nullptr);
    ~TitleBar();




 public slots:
    void on_Max_Btn_Clicked();
    void on_Min_Btn_Clicked();
    void on_Buy_Btn_Clicked();
    void on_Menu_Btn_Clicked();
    void on_Close_Btn_Clicked();
    void on_Restore_Btn_Clicked();
    void on_Register_Btn_Clicked();
protected:
     virtual void initUI()override;
    void initConnect();
    TitleBarData* m_data=nullptr;
};

#endif
