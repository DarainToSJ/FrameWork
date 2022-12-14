#ifndef  _BASE_WIDGET_H_
#define _BASE_WIDGET_H_
#include "Export_Dll.h"
#include <QWidget>
class DLLEXPORT BaseWidget :public QWidget {

	Q_OBJECT
public:
	explicit  BaseWidget(QWidget* parent = nullptr);
protected:
	void initWidget();
	
	void drawShadow(int radius);

	virtual void paintEvent(QPaintEvent *event)override;
};

#endif // ! _BASE_WIDGET_H_


