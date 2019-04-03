#include "mainform.hpp"

#include <QDebug>

#include <secure_sign_in.hpp>
#include <workerthread.hpp>

MainForm::MainForm(QObject *parent) : QObject(parent)
{
}

void MainForm::encrypt_clicked()
{
	SecureSignIn ssi;
	char *cp;
	this->set_cipher_password("");
	if (get_compact())
		cp = ssi.encrypt(&(password.toStdString().c_str()[0]), &(key.toStdString().c_str()[0]), 12);
	else
		cp = ssi.encrypt(&(password.toStdString().c_str()[0]), &(key.toStdString().c_str()[0]), 32);

	this->set_cipher_password(cp);
//	free(cp);

	qDebug() << get_cipher_password();
//	emit password_encrypted();
	//wait 8sec on new thread
//	WorkerThread *workerThread = new WorkerThread(this);
//	connect(workerThread, &WorkerThread::resultReady, this, &MainForm::clear);
//	connect(workerThread, &WorkerThread::finished, workerThread, &QObject::deleteLater);
//	workerThread->start();
}

void MainForm::clear()
{
	clipboard->clear();
//	free(this->get_cipher_password());
	this->set_cipher_password("");
	free(clipboard);
}

void MainForm::set_password(const QString password)
{
	if (this->get_password() == password)
		return;

	this->password = password;
}

QString MainForm::get_password()
{
	return this->password;
}

void MainForm::set_key(const QString key)
{
	if (this->get_key() == key)
		return;

	this->key = key;
}

QString MainForm::get_key()
{
	return this->key;
}

void MainForm::set_compact(const bool compact)
{
	if (this->get_compact() == compact)
		return;

	this->compact = compact;
}

bool MainForm::get_compact()
{
	return this->compact;
}

void MainForm::set_cipher_password(const QString &cipher_password)
{
	if (this->get_cipher_password() == cipher_password)
		return;

	this->cipher_password = cipher_password;
	emit password_encrypted();
}

QString MainForm::get_cipher_password()
{
	return this->cipher_password;
}


MainForm::~MainForm()
{
	this->clear();
}
