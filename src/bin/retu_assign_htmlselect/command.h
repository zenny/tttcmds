/*
 * Copyright (c) 2016 Daichi GOTO
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are 
 * met: 
 * 
 * 1. Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above copyright 
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the distribution. 
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#define VERSION "20161230"
#define CMDNAME "retu_assign_htmlselect"
#define ALIAS "assign_htmlselect col_assign_htmlselect"

#include "ttt.h"
#include "./../retu_assign/retu_assign.h"

/*
 * setup linked-list data for HTML SELECT
 */
#define TGT_GYO_PROCESS(GYO_BUFFER,NF) \
	if (flag_1 && flag_1_firstline) { \
		flag_1_firstline = 0; \
		goto next_gyo_process; \
	} \
	sel2 = calloc(1, sizeof(*sel2)); \
	sel2->name = calloc(1, \
		(strlen(GYO_BUFFER[R_ARGV[1]]) + 1) * sizeof(char)); \
	strcpy(sel2->name, GYO_BUFFER[R_ARGV[1]]); \
	value_len = len = 0; \
	for (int j = 2; j <= R_ARGC; j++) \
		value_len += strlen(GYO_BUFFER[R_ARGV[j]]) + delim_len; \
	sel2->value = calloc(1, value_len * sizeof(char)); \
	for (int j = 2; j <= R_ARGC; j++) { \
		strcpy(sel2->value + len, GYO_BUFFER[R_ARGV[j]]) ; \
		len += strlen(GYO_BUFFER[R_ARGV[j]]); \
		strcpy(sel2->value + len, delim); \
		len += delim_len; \
	} \
	*(sel2->value + len - delim_len) = '\0'; \
	if (firstline) { \
		SLIST_INSERT_HEAD(&list[i], sel2, entries); \
		firstline = 0; \
	} \
	else \
		SLIST_INSERT_AFTER(sel1, sel2, entries); \
	sel1 = sel2; \
next_gyo_process: 

/*
 * value to HTML SELECT conversion
 */
#define TGT_RETU_PROCESS(RETU_BUFFER,RETU_BUFFER_MAXLEN,INDEX) \
	printf("<select"); \
	if (0 == hashtables[INDEX]->seq( \
		hashtables[INDEX], &hash_key, &hash_val, R_FIRST)) { \
		printf("_%s=\"%s\"", hash_key.data, hash_val.data); \
	} \
	while (0 == hashtables[INDEX]->seq( \
		hashtables[INDEX], &hash_key, &hash_val, R_NEXT)) { \
		printf("_%s=\"%s\"", hash_key.data, hash_val.data); \
	} \
	printf(">"); \
	SLIST_FOREACH(sel1, &list[INDEX], entries) { \
		if (0 == strcmp(RETU_BUFFER, sel1->name)) \
			printf("<option_value=\"%s\"_selected>", \
				sel1->name); \
		else \
			printf("<option_value=\"%s\">", sel1->name); \
		if (0 == strcmp("@", sel1->value)) \
			printf("</option>"); \
		else \
			printf("%s</option>", sel1->value); \
	} \
	printf("</select>");

#define NOTGT_RETU_PROCESS(RETU_BUFFER,RETU_BUFFER_MAXLEN,INDEX) \
	printf("%s",RETU_BUFFER);

#define END_OF_LINE_RETU_PROCESS
