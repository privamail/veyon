/*
 * vncntlm.cpp - minimalistic implementation of vncntlm module
 *
 * Copyright (c) 2016 Tobias Doerffel <tobydox/at/users/dot/sf/dot/net>
 *
 * This file is part of Veyon - http://veyon.io
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */


#include "addon/ms-logon/authSSP/authSSP.h"

#define MAXSTRING 254

int CheckUserGroupPasswordUni(char * userin,char *password,const char *machine)
{
	TCHAR user2[MAXSTRING];
#if defined(UNICODE) || defined(_UNICODE)
	mbstowcs(user2, userin, MAXSTRING);
#else
	strcpy(user2, userin);
#endif

	return CUPSD2(user2, password);
}
