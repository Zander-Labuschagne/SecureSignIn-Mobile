#ifndef MAINFORM_HPP
#define MAINFORM_HPP

#include <QObject>
#include <QClipboard>

class MainForm : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString cipher_password READ get_cipher_password WRITE set_cipher_password NOTIFY password_encrypted) //Die QProperty verklaar 'n eienskap(property) waartoe ek toegang kan kry vanaf QML
	Q_PROPERTY(QString password READ get_password WRITE set_password NOTIFY password_changed)
	Q_PROPERTY(QString key READ get_key WRITE set_key NOTIFY key_changed)
	Q_PROPERTY(bool compact READ get_compact WRITE set_compact NOTIFY compact_changed)

public:
//	MainForm(); //Default constructor
	~MainForm(); //Default destructor
	explicit MainForm(QObject *parent = nullptr); //watse constructor is die?

	void set_password(const QString password);
	QString get_password();
	void set_key(const QString key);
	QString get_key();
	void set_compact(const bool compact);
	bool get_compact();
//	char *cipher_password;
	QString get_cipher_password();
	QClipboard get_clipboard();
public slots:
	void encrypt_clicked();
	void clear();
signals:
	void password_encrypted();
	void password_changed();
	void key_changed();
	void compact_changed();
private:
	QString password;
	QString key;
	bool compact;
	QString cipher_password;
	void set_cipher_password(const QString &cipher_password);
	QClipboard *clipboard;
};

#endif // MAINFORM_HPP
