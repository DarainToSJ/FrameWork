#ifndef _FILE_HELPER_H_
#define _FILE_HELPER_H_
#include "Export_Dll.h"

#include <QString>

class DLLEXPORT FileHelper
{
public:
	/**
	 * @brief
	 *
	 * @param path
	 * @return QString
	 */
	static QString ReadAllText(const QString &path);
};

#endif // !  _FILE_HELPER_H_
