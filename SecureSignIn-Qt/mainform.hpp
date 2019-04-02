#ifndef MAINFORM_HPP
#define MAINFORM_HPP

#include <QObject>
#include <QClipboard>

class MainForm : public QObject
{
	Q_OBJECT
public:
	MainForm();
	~MainForm();
	QClipboard *clipboard;
	char *cipher_password;
public slots:
	void encrypt_clicked(QString, QString, bool);
	void clear();
signals:
	void encrypted(QString);
};

#endif // MAINFORM_HPP
