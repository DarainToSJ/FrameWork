#ifndef _CONTENT_W_H_
#define _CONTENT_W_H_
#include "BaseWidget.h"


class QLabel;
class DLLEXPORT ContentW:public BaseWidget {
	Q_OBJECT
public:
	explicit ContentW(QWidget* parent = nullptr);

protected:
	void initUI();
	void initConnect();

private:

    QLabel *m_label;

};

#endif // !_MAIN_WINDOW_H_
