/*
 * Copyright (c) 2016,2017 Daichi GOTO
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

#define VERSION "20170201"
#define CMDNAME "retu_select"
#define ALIAS "retusel col_select"

#include "ttt.h"

#define TGT_GYO_PROCESS(GYO_BUFFER,NF) \
	if (0 != NF) { \
		if (FLAG_1 && first_line) \
			first_line = 0; \
		else { \
			for (int i = 1; i < R_ARGC; i++) \
				if (R_ARGV[i] > NF || \
					NULL == GYO_BUFFER[R_ARGV[i]]) \
					PRINT("@", i, " ") \
				else \
					PRINT(GYO_BUFFER[R_ARGV[i]], \
						i, " ") \
			if (R_ARGV[R_ARGC] > NF || \
				NULL == GYO_BUFFER[R_ARGV[R_ARGC]]) \
				PRINT("@", R_ARGC, "\n") \
			else \
				PRINT(GYO_BUFFER[R_ARGV[R_ARGC]], \
					R_ARGC, "\n") \
			outputed = 1; \
		} \
	}

#define PRINT(TARGET,INDEX,DELIMITER) { \
	if (NULL != R_ARGV_ARG1[INDEX] && \
	    NULL != R_ARGV_ARG2[INDEX]) { \
		if (0 == strcmp(TARGET, R_ARGV_ARG1[INDEX])) \
			printf("%s%s", R_ARGV_ARG2[INDEX], DELIMITER); \
		else \
			printf("%s%s", TARGET, DELIMITER); \
	} \
	else { \
		printf("%s%s", TARGET, DELIMITER); \
	} \
}
