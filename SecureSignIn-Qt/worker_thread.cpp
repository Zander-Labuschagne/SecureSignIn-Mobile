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

#include "worker_thread.hpp"

/**
 * @brief Overloaded constructor
 * worker_thread.cpp
 * @since 3.0.0
*/
WorkerThread::WorkerThread(QObject *parent) : QThread()
{

}

/**
 * @brief Waits until 8 seconds has elapsed followed by emitting done_waiting() signal
 * Used to halt operations while waiting for user to complete actions such as pasting the password into website password box
 * worker_thread.cpp
 * @since 3.0.0
*/
void WorkerThread::run()
{
       /* ... here is the expensive or blocking operation ... */
       sleep(8);
       emit done_waiting();
}
