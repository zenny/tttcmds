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

#include "command.h"

struct textset cmdtextsets[] = {
	{ "command_version", "en_", VERSION },

	{ "command_name", "en_", CMDNAME },

	{ "command_alias", "en_", ALIAS },

	{ "command_copyright", "en_", "2016,2017 ONGS Inc." },

	{ "command_comment", "ja_JP",
	  "条件に一致する行を出力する" },

	{ "command_comment", "en_", 
	  "print the rows if condition is true" }, 

	{ "command_synopsis", "en_", 
	  _CMD(CMDNAME) " "
	  "[" _OPT("a") "|" _OPT("o") "] "
	  "[" _OPT("n") "] "
	  "[" _OPT("hvD") "] [" _OPT("-") "] "
	  _ARG("N=key") "|" _ARG("N/M=key") "|" 
	  _ARG("N>key") "|" _ARG("N/M>key") "|\n" 
	  _ARG("N<key") "|" _ARG("N/M<key") "|"
	  _ARG("N.f.K") "|" _ARG("N/M.f.K") " "
	  "[" _ARG("N=key") "|" _ARG("N/M=key") "|"
	      _ARG("N>key") "|" _ARG("N/M>key") "|" 
	      _ARG("N<key") "|\n" _ARG("N/M<key") "|" 
	      _ARG("N.f.K") "|" _ARG("N/M.f.K") " " _ETC "] "
	  "[" _ARG("file") " " _ETC "]" },

	{ "command_description", "ja_JP", 
	  "条件に一致する行を出力する。\n"
	  "\n"
	  ES_BOLD("等価条件") "\n"
	  _ARG("N=key") "\t	" _ARG("N") "列の値が" _ARG("key") 
	  			"に一致\n"
	  _ARG("N>key") "\t	" _ARG("N") "列の値が" _ARG("key") 
	  			"よりも大きい\n"
	  _ARG("N<key") "\t	" _ARG("N") "列の値が" _ARG("key") 
	  			"よりも小さい\n"
	  _ARG("N/M=key") "\t	" _ARG("N=key") "と同じ処理を" _ARG("M") 
	  			"例まで適用\n"
	  _ARG("N/M>key") "\t	" _ARG("N>key") "と同じ処理を" _ARG("M") 
	  			"例まで適用\n"
	  _ARG("N/M<key") "\t	" _ARG("N<key") "と同じ処理を" _ARG("M") 
	  			"例まで適用\n"
	  "\n"
	  ES_BOLD("結合条件") "\n"
	  _ARG("N.f.K") "\t	" _ARG("N") "列の値と" _ARG("f") "ファイル"
	  			"の" _ARG("K") "列の値が一致\n"
	  _ARG("N/M.f.K") "\t	" _ARG("N.f.K") "と同じ処理を" _ARG("M") 
	  			"例まで適用\n"
	  "\n"
	  "ファイルの指定がないか、-が指定されている場合には標準入力を使用。" },

	{ "command_description", "en_", 
	  "Print the rows if condition is true.\n"
	  "\n"
	  ES_BOLD("EQUALITY/INEQUALITY CONDITION") "\n"
	  _ARG("N=key") "\t	The value of " _ARG("N") "th column and "
	  			"the " _ARG("key") " match.\n"
	  _ARG("N>key") "\t	The value of " _ARG("N") "th column is "
	  			"greater than the " _ARG("key") ".\n"
	  _ARG("N<key") "\t	The value of " _ARG("N") "th column is "
	  			"lesser than the " _ARG("key") ".\n"
	  _ARG("N/M=key") "\t	Process the " _ARG("N") "th to " 
	  			_ARG("M") "th columns in the same way\n"
				"\t\tas " _ARG("N=key") ".\n" 
	  _ARG("N/M>key") "\t	Process the " _ARG("N") "th to " 
	  			_ARG("M") "th columns in the same way\n"
				"\t\tas " _ARG("N>key") ".\n" 
	  _ARG("N/M<key") "\t	Process the " _ARG("N") "th to " 
	  			_ARG("M") "th columns in the same way\n"
				"\t\tas " _ARG("N<key") ".\n" 
	  "\n"
	  ES_BOLD("JOIN CONDITION") "\n"
	  _ARG("N.f.K") "\t	The value of " _ARG("N") "th column and "
	  			"the value of " _ARG("K") "th\n\t\tcolumn "
				"of the file " _ARG("f") " match.\n"
	  _ARG("N/M.f.K") "\t	Process the " _ARG("N") "th to " 
	  			_ARG("M") "th columns in the same way\n"
				"\t\tas " _ARG("N.f.K") ".\n" 
	  "\n"
	  "If " _ARG("file") " is a signle dash (`-') or absent, it reads "
	  "from the standard\ninput." },

	{ "command_options", "ja_JP", 
	  _OPT("a") "		指定をAND条件として処理 (デフォルト設定)\n"
	  _OPT("o") "		指定をOR条件として処理\n"
	  _OPT("n") "		出力を行わず、1行も一致しなかった場合には"
	  			"1で、\n\t\tそうでない場合には0で終了\n"
	  _OPT("h") "		使い方表示\n"
	  _OPT("v") "		バージョン表示\n"
	  _OPT("D") "		デバッグモード\n"
	  _OPT("-") "		オプションの終了を指定\n"
	  _ARG("file") "\t	ファイルを指定" },
	 
	{ "command_options", "en_", 
	  _OPT("a") "		Specify AND condition (by default).\n"
	  _OPT("o") "		Specify OR condition.\n"
	  _OPT("n") "		Do not print. If one or more lines match "
	  			"it\n\t\treturns 0, otherwise it "
				"returns 1.\n"
	  _OPT("h") "		Print the usage message.\n"
	  _OPT("v") "		Print the version.\n"
	  _OPT("D") "		Enable the debug mode.\n"
	  _OPT("-") "		Specify the end of options.\n"
	  _ARG("file") "\t	Specify the file." },

	{ "command_example", "en_", 
	  _P("cata data.ssv")
	  _S("1 2 3 4 5 6 7 8 9")
	  _S("1 @ 3 4 5 6 7 8 9")
	  _S("1 2 @ 4 5 6 7 8 9")
	  _P("gyo_select 2=2 data.ssv")
	  _S("1 2 3 4 5 6 7 8 9")
	  _S("1 2 @ 4 5 6 7 8 9")
	  _P("gyo_select 2= data.ssv")
	  _S("1 @ 3 4 5 6 7 8 9")
	  _P("gyo_select -a 2= 3= data.ssv")
	  _P("gyo_select -o 2= 3= data.ssv")
	  _S("1 @ 3 4 5 6 7 8 9")
	  _S("1 2 @ 4 5 6 7 8 9")
	  _P("gyo_select -o 2= 2=2 data.ssv")
	  _S("1 2 3 4 5 6 7 8 9")
	  _S("1 @ 3 4 5 6 7 8 9")
	  _S("1 2 @ 4 5 6 7 8 9")
	  _P("cat date.ssv")
	  _S("20150101 20150505 20151010")
	  _S("20160101 20160505 20161010")
	  _S("20170101 20170505 20171010")
	  _P("gyo_select 2'>'20160101 date.ssv")
	  _S("20160101 20160505 20161010")
	  _S("20170101 20170505 20171010")
	  _P("gyo_select 2'>'20160101 3'<'20170101 date.ssv")
	  _S("20160101 20160505 20161010")
	  _P("gyo_select 2'>'20150505 2'<'20170505 date.ssv")
	  _S("20160101 20160505 20161010")
	  _P("cat key.ssv")
	  _S("001 20160101 20151010")
	  _S("002 20170101 20171010")
	  _P("gyo_select 1:key.ssv:2 date.ssv")
	  _S("20160101 20160505 20161010")
	  _S("20170101 20170505 20171010")
	  _P("gyo_select 3:key.ssv:3 date.ssv")
	  _S("20160101 20160505 20161010")
	  _S("20170101 20170505 20171010")
	  _P("gyo_select -n -a 2= 3= data.ssv && echo match")
	  _P("gyo_select -n -o 2= 3= data.ssv && echo match")
	  _S("match")
	  _P("") },

	TEXTSET_END
};
