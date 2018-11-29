#ifndef RWINIFILE_H  
#define RWINIFILE_H  

#include <QtGui>  
class RWIniFile
{
public:
	RWIniFile();
	static QString iniPath;
	bool static writeIni(QString path, QString section, QString keyword, QString keyvalue, bool clear_flag);
	bool static writeIni(QString path, QString section, QString keyword, QString keyvalue);
	QString static readIni(QString path, QString section, QString keyword, QString &keyvalue);
};
#endif // RWINIFILE_H
