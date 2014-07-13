/*
 * gtmdata.c
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

#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <gtmxc_types.h>


#define BUFLEN (2048 + 1)
#define RETLEN ((1024 * 1024) + 1)

struct termios stderr_sav, stdin_sav, stdout_sav;
gtm_char_t ret[RETLEN];
gtm_char_t msgbug[BUFLEN];
gtm_status_t status;
int db_opened = 0;

int open(void) 
{

  if(db_opened) {
    return(0);
  }

  char *gtmgbldir = getenv("gtmgbldir");
  char *gtm_dist = getenv("gtm_dist");
  char *gtmroutines = getenv("gtmroutines");

  /* we want to fail out if the GT.M environment is not configured */
  if((gtmgbldir == NULL) | (gtm_dist == NULL) | (gtmroutines == NULL)) {
    return(0);
  }

  /* save the state of the standard I/O devices */
  tcgetattr(0, &stdin_sav);
  tcgetattr(1, &stdout_sav);
  tcgetattr(2, &stderr_sav);

  status = gtm_init();

  if(status) {
    db_opened = 0;
    return(0);
  }
  else {
    return(1);
  }
}

int close(void)
{
  if(db_opened) {
    status = gtm_exit();
  
    if(status) {
      return(0);
    }

    tcsetattr(0, 0, &stdin_sav);
    tcsetattr(1, 0, &stdout_sav);
    tcsetattr(2, 0, &stderr_sav);

    db_opened = 0;

    return(1);
  }
  else {
    return(0);
  }
}


int set(char *glref, char *value)
{
  if(!db_opened) {
    return(0);
  }

  char m_command[] = "set";
  ci_name_descriptor gtm_set;

  gtm_set.rtn_name.address = m_command;
  gtm_set.rtn_name.length = strlen(gtm_set.rtn_name.address);
  gtm_set.handle = NULL;

  status = gtm_cip(&gtm_set, ret, glref, value);

  if(status) {
    return(0);
  }
  else {
    return(1);
  }
}

int get(char *glref, char *result)
{
  if(!db_opened) {
    return(0);
  }

  char m_command[] = "get";
  ci_name_descriptor gtm_get;

  gtm_get.rtn_name.address = m_command;
  gtm_get.rtn_name.length = strlen(gtm_get.rtn_name.address);
  gtm_get.handle = NULL;

  status = gtm_cip(&gtm_get, ret, glref);

  if(status) {
    result = NULL;
    return(0);
  }
  else {
    result = (char *) ret;
    return(1);
  }
}

int kill(char *glref)
{
  if(!db_opened) {
    return(0);
  }

  char m_command[] = "kill";
  ci_name_descriptor gtm_kill;

  gtm_kill.rtn_name.address = m_command;
  gtm_kill.rtn_name.length = strlen(gtm_kill.rtn_name.address);
  gtm_kill.handle = NULL;

  status = gtm_cip(&gtm_kill, ret, glref);

  if(status) {
    return(0);
  }
  else {
    return(1);
  }
}

int data(char *glref)
{
  if(!db_opened) {
    return(0);
  }

  char m_command[] = "data";
  ci_name_descriptor gtm_data;
  gtm_int_t ret_val;

  gtm_data.rtn_name.address = m_command;
  gtm_data.rtn_name.length = strlen(gtm_data.rtn_name.address);
  gtm_data.handle = NULL;

  status = gtm_cip(&gtm_data, ret_val, glref);

  if(status) {
    return(0);
  }
  else {
    return((int) ret_val);
  }
}

int order(char *glref, char *result)
{
  if(!db_opened) {
    return(0);
  }

  char m_command[] = "order";
  ci_name_descriptor gtm_order;

  gtm_order.rtn_name.address = m_command;
  gtm_order.rtn_name.length = strlen(gtm_order.rtn_name.address);
  gtm_order.handle = NULL;

  status = gtm_cip(&gtm_order, ret, glref);

  if(status) {
    result = NULL;
    return(0);
  }
  else {
    result = (char *) ret;
    return(1);
  }
}

int query(char *glref, char *result)
{
  if(!db_opened) {
    return(0);
  }

  char m_command[] = "query";
  ci_name_descriptor gtm_query;

  gtm_query.rtn_name.address = m_command;
  gtm_query.rtn_name.length = strlen(gtm_query.rtn_name.address);
  gtm_query.handle = NULL;

  status = gtm_cip(&gtm_query, ret, glref);

  if(status) {
    result = NULL;
    return(0);
  }
  else {
    result = (char *) ret;
    return(1);
  }
}

int lock(char *glref)
{
  if(!db_opened) {
    return(0);
  }

  char m_command[] = "lock";
  ci_name_descriptor gtm_lock;
  gtm_int_t ret_val;

  gtm_lock.rtn_name.address = m_command;
  gtm_lock.rtn_name.length = strlen(gtm_lock.rtn_name.address);
  gtm_lock.handle = NULL;

  status = gtm_cip(&gtm_lock, ret_val, glref);

  if(status) {
    return(0);
  }
  else {
    return((int) ret_val);
  }
}

int unlock(char *glref)
{
  if(!db_opened) {
    return(0);
  }

  char m_command[] = "unlock";
  ci_name_descriptor gtm_unlock;
  gtm_int_t ret_val;

  gtm_unlock.rtn_name.address = m_command;
  gtm_unlock.rtn_name.length = strlen(gtm_unlock.rtn_name.address);
  gtm_unlock.handle = NULL;

  status = gtm_cip(&gtm_unlock, ret_val, glref);

  if(status) {
    return(0);
  }
  else {
    return((int) ret_val);
  }

}

int version(char *result)
{
  if(!db_opened) {
    return(0);
  }

  char m_command[] = "version";
  ci_name_descriptor gtm_version;

  gtm_version.rtn_name.address = m_command;
  gtm_version.rtn_name.length = strlen(gtm_version.rtn_name.address);
  gtm_version.handle = NULL;

  status = gtm_cip(&gtm_version, ret);

  if(status) {
    result = NULL;
    return(0);
  }
  else {
    result = (char *) ret;
    return(1);
  }

}

int function(char *fn, char *result)
{
  if(!db_opened) {
    return(0);
  }

  char m_command[] = "function";
  ci_name_descriptor gtm_function;

  gtm_function.rtn_name.address = m_command;
  gtm_function.rtn_name.length = strlen(gtm_function.rtn_name.address);
  gtm_function.handle = NULL;

  status = gtm_cip(&gtm_function, ret, fn);

  if(status) {
    result = NULL;
    return(0);
  }
  else {
    result = (char *) ret;
    return(1);
  }
}


