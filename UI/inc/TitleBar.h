#ifndef _TITLE_BAR_H_
#define _TITLE_BAR_H_
#include "Export_Dll.h"
#include "BaseWidget.h"

class QLabel;
class QPushButton;

class DLLEXPORT TitleBar : public BaseWidget
{
	Q_OBJECT
public:
	explicit TitleBar(QWidget *parent = nullptr);

	/**
	 * @brief 更新TitleBar 最大化按钮
	 *
	 * @param isMaxFlag
	 */
	void updateToMaxWindow(bool isMaxFlag = false);

public:
	/**
	 * @brief hideBtn 点击响应事件
	 *
	 */
	void on_hideBtn_Clicked();

	/**
	 * @brief MaxBtn 点击响应事件
	 *
	 */
	void on_MaxOrRestoreBtn_Clicked();

signals:
	/**
	 * @brief
	 *
	 */
	void signalExitBtnClicked();

protected:
	void initUI();

	void initConnect();

	virtual void mousePressEvent(QMouseEvent *event) override;

	virtual void mouseReleaseEvent(QMouseEvent *event) override;

	virtual void mouseDoubleClickEvent(QMouseEvent *event) override;

	virtual void mouseMoveEvent(QMouseEvent *event) override;

private:
	QLabel *m_AppName;
	QPushButton *m_ExitBtn;
	QPushButton *m_MaxWBtn;
	QPushButton *m_HideBtn;
	QPushButton *m_reStoreBtn;

	QPoint m_mousePt;
	bool m_bPressed = false;
};

#endif // !_TITLE_BAR_H_
