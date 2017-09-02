/*
 * Copyright (c) 2017 Daichi GOTO
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

#include "command.h"

struct textset cmdtextsets[] = {
	{ "command_version", "en_", VERSION },

	{ "command_name", "en_", CMDNAME },

	{ "command_alias", "en_", ALIAS },

	{ "command_copyright", "en_", "2017 ONGS Inc." },

	{ "command_comment", "ja_JP", "SSVデータを転置する" },

	{ "command_comment", "en_", "Transpose the SSV data" },

	{ "command_synopsis", "en_", 
	  _CMD(CMDNAME) " "
	  "[" _OPT("hvD") "] [" _OPT("-") "] "
	  "[" _ARG("file") " " _ETC "]" },
	
	{ "command_description", "ja_JP", 
	  "SSVデータを転置する。ファイルの指定がないか、-が指定されている"
	  "場合\nには標準入力を使用。" },

	{ "command_description", "en_", 
	  "Transpose the SSV data. If " _ARG("file") " is a single "
	  "dash (`-') or absent,\nit reads from the standard input." },

	{ "command_options", "ja_JP", 
	  _OPT("h") "		使い方表示\n"
	  _OPT("v") "		バージョン表示\n"
	  _OPT("D") "		デバッグモード\n"
	  _OPT("-") "		オプションの終了を指定" },
	
	{ "command_options", "en_", 
	  _OPT("h") "		Print the usage message.\n"
	  _OPT("v") "		Print the version.\n"
	  _OPT("D") "		Enable the debug mode.\n"
	  _OPT("-") "		Specify the end of options." }, 

	{ "command_example", "en_", 
	  _P("cat data.ssv")
	  _S("1 2 3 4 5 6 7 8 9")
	  _S("a b c d @ @ @ @ @")
	  _S("@ a b c d @ @ @ @")
	  _P("conv_ssv2transposedssv data.ssv") 
	  _S("1 a @")
	  _S("2 b a")
	  _S("3 c b")
	  _S("4 d c")
	  _S("5 @ d")
	  _S("6 @ @")
	  _S("7 @ @")
	  _S("8 @ @")
	  _S("9 @ @")
	  _P("cat data2.ssv")
	  _S("A")
	  _S("B")
	  _P("conv_ssv2transposedssv data2.ssv") 
	  _S("A B")
	  _P("conv_ssv2transposedssv data2.ssv data.ssv") 
	  _S("A B 1 a @")
	  _S("@ @ 2 b a")
	  _S("@ @ 3 c b")
	  _S("@ @ 4 d c")
	  _S("@ @ 5 @ d")
	  _S("@ @ 6 @ @")
	  _S("@ @ 7 @ @")
	  _S("@ @ 8 @ @")
	  _S("@ @ 9 @ @")
	  _P("") },

	TEXTSET_END
};
