#pragma once

#include <QWidget>
#include "ui_Setting.h"
#include <string>
#include "RWIniFile.h"
#include <qmessagebox.h>

using namespace std;

class Setting : public QWidget
{
	Q_OBJECT

public:
	Setting(QWidget *parent = Q_NULLPTR);
	~Setting();

private:
	Ui::Setting ui;
	QString str2qstr(const string str);
	string qstr2str(const QString qstr);

private slots:
	void button_modify_clicked();
	void button_cancel_clicked();
};
