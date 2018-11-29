#include "Setting.h"

Setting::Setting(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

Setting::~Setting()
{
}

QString Setting::str2qstr(const string str)
{
	return QString::fromLocal8Bit(str.data());
}

string Setting::qstr2str(const QString qstr)
{
	QByteArray cdata = qstr.toLocal8Bit();
	return string(cdata);
}

void Setting::button_cancel_clicked()
{
	this->close();
}

void Setting::button_modify_clicked()
{
	string str_key = qstr2str(ui.lineEdit_key->text());
	string str_salt = qstr2str(ui.lineEdit_salt->text());
	if (str_key.length() == 0 || str_salt.length() == 0)
	{
		QMessageBox::about(NULL, "Tips", "Input can not be empty!");
		return;
	}
	bool b = RWIniFile::writeIni(RWIniFile::iniPath, "config1", "key", str2qstr(str_key));
	b &= RWIniFile::writeIni(RWIniFile::iniPath, "config1", "salt", str2qstr(str_salt));
	if (b)
	{
		QMessageBox::about(NULL, "Tips", "Modify settings successfully!");
		this->close();
	}
	else
	{
		QMessageBox::about(NULL, "Tips", "Modify settings failed!");
	}
}