/*
 * gtmdata.h
 *  Part of gtmci-data-api shared library
 *
 * Copyright (C) 2014 Coherent Logic Development LLC
 *  All Rights Reserved
 *
 * Author:  John P. Willis <jpw@coherent-logic.com>
 * Written: 7/12/2014
 *
 *  This file is part of gtmci-data-api.
 *
 *  gtmci-data-api is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  gtmci-data-api is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with gtmci-data-api.  If not, see <http://www.gnu.org/licenses/>. 
 *
 */

extern int gtmdata_version(char *);
extern int db_open(void);
extern int db_close(void);
extern int db_set(char *, char *);
extern int db_get(char *, char *);
extern int db_kill(char *);
extern int db_data(char *);
extern int db_order(char *, char *);
extern int db_query(char *, char *);
extern int db_lock(char *);
extern int db_unlock(char *);
extern int db_version(char *);
extern int db_function(char *, char *);
