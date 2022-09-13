#include "..\inc\FileHelper.h"
#include <QFile>


QString FileHelper::ReadAllText(const QString& path)
{
	QFile file(path);
	file.open(QFile::ReadOnly);
	QString ret = file.readAll();
	file.close();
	return ret;
}
