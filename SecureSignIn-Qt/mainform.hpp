#ifndef MAINFORM_HPP
#define MAINFORM_HPP

#include <QObject> //slots
//#include <QQmlApplicationEngine>

class MainForm : public QObject
{
	Q_OBJECT
public:
	MainForm();
	~MainForm();
public slots:
	void encrypt_clicked();
};

#endif // MAINFORM_HPP
