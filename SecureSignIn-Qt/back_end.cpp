/**
 * Copyright (C) 2019 Zander Labuschagne. All rights reserved.
 * @version 3.0.0 05/04/19
 * @since 3.0.0
 *
 * Authors:
 *         @author Zander Labuschagne <zander.labuschagne@protonmail.ch>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU GPL 2.0 License, as published by the
 * Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GPL 2.0 License for more details.
 *
 * You should have received a copy of the GNU GPL 2.0 License
 * along with this program; if not, write to the author,
 * contact details above in line 7.
 */

#include "back_end.hpp"

#include <secure_sign_in.hpp>
#include <worker_thread.hpp>

/**
 * @brief Constructor
 * back_end.cpp
 * Purpose: Initialize object members
 * @since 3.0.0
 */
BackEnd::BackEnd(QObject *parent) : QObject(parent)
{
}

/**
 * @brief slot connected to encrypt button click signal.
 * back_end.cpp
 * calls encrypt function.
 * @since 3.0.0
 */
void BackEnd::encrypt_clicked()
{
	SecureSignIn ssi;
	char *cp;
	this->set_cipher_password("");
	if (get_compact())
		cp = ssi.encrypt(&(password.toStdString().c_str()[0]), &(key.toStdString().c_str()[0]), 12);
	else
		cp = ssi.encrypt(&(password.toStdString().c_str()[0]), &(key.toStdString().c_str()[0]), 32);

	this->set_cipher_password(cp);
	free(cp);
}

/**
 * @brief slot connected to copy password button click signal.
 * back_end.cpp
 * calls functions necessary to copy the password to memory.
 * @since 3.0.0
 */
void BackEnd::copy_clicked()
{
	//wait 8sec on new thread
	WorkerThread *waiter_thread = new WorkerThread(this);
	connect(waiter_thread, &WorkerThread::done_waiting, this, &BackEnd::clear);
	connect(waiter_thread, &WorkerThread::finished, waiter_thread, &QObject::deleteLater);
	waiter_thread->start();
}

/**
 * @brief slot connected to the timeout signal to clear the password from memory.
 * back_end.cpp
 * calls functions necessary to erase the password.
 * @since 3.0.0
 */
void BackEnd::clear()
{
	this->get_clipboard()->clear();
	this->set_cipher_password("");
	this->get_clipboard()->setText("");
}

/**
 * @brief password mutator.
 * back_end.cpp
 * assigns the input password.
 * @since 3.0.0
 */
void BackEnd::set_password(const QString password)
{
	if (this->get_password() == password)
		return;

	this->password = password;
}

/**
 * @brief password accessor.
 * back_end.cpp
 * @return the original input password.
 * @since 3.0.0
 */
QString BackEnd::get_password()
{
	return this->password;
}

/**
 * @brief key mutator.
 * back_end.cpp
 * assigns the key.
 * @since 3.0.0
 */
void BackEnd::set_key(const QString key)
{
	if (this->get_key() == key)
		return;

	this->key = key;
}

/**
 * @brief key accessor.
 * back_end.cpp
 * @return the key as entered by the user.
 * @since 3.0.0
 */
QString BackEnd::get_key()
{
	return this->key;
}

/**
 * @brief compact mutator.
 * back_end.cpp
 * assigns the compact variable status.
 * @since 3.0.0
 */
void BackEnd::set_compact(const bool compact)
{
	if (this->get_compact() == compact)
		return;

	this->compact = compact;
}

/**
 * @brief compact accessor.
 * back_end.cpp
 * @return the status of the compact switch.
 * @since 3.0.0
 */
bool BackEnd::get_compact()
{
	return this->compact;
}

/**
 * @brief cipher_password mutator.
 * back_end.cpp
 * assigns the encrypted password.
 * @since 3.0.0
 */
void BackEnd::set_cipher_password(const QString &cipher_password)
{
	if (this->get_cipher_password() == cipher_password)
		return;

	this->cipher_password = cipher_password;
	emit password_encrypted();
}

/**
 * @brief cipher_password accessor.
 * back_end.cpp
 * @return the encrypted password.
 * @since 3.0.0
 */
QString BackEnd::get_cipher_password()
{
	return this->cipher_password;
}

/**
 * @brief clipboard accessor.
 * back_end.cpp
 * @return the clipboard object used in this application.
 * @since 3.0.0
 */
QClipboard* BackEnd::get_clipboard()
{
	return this->clipboard;
}

/**
 * @brief default destructor.
 * back_end.cpp
 * ensures that no memory is left assigned and that all relevant variables are cleared.
 * @since 3.0.0
 */
BackEnd::~BackEnd()
{
	this->clear();
}
