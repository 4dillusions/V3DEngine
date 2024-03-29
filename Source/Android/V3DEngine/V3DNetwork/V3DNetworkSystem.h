/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

// ReSharper disable CppUnusedIncludeDirective
#pragma once

#include <cerrno>
#include <fcntl.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <linux/in.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

typedef int SOCKET;
constexpr int NO_ERROR = 0;
constexpr int INVALID_SOCKET = -1;
constexpr int WSAECONNRESET = ECONNRESET;
constexpr int WSAEWOULDBLOCK = EAGAIN;
constexpr int SOCKET_ERROR = -1;
