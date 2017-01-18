/*************************************************************************
	> File Name: string.h
	> Author: xu chaoxi
	> Mail: xuchaoxikb@gmail.com 
	> Created Time: Wed 18 Jan 2017 09:14:03 AM CST
 ************************************************************************/

#ifndef _STRING_H
#define _STRING_H
#endif

#include<cstdlib>
#define MAXSTRLEN 255
typedef unsigned char SString[MAXSTRLEN + 1];

int StrAssign(SString T, char *chars);

int StrCopy(SString T, SString S);

int StrEmpty(SString S);

int StrLength(SString S);

int StrCompare(SString S, SString T);

int ClearString(SString S);

int ConCat(SString T, SString S1, SString S2);

int SubString(SString Sub, SString S, int pos, int len);

int Index(SString S, SString T, int pos);

int StrInsert(SString S, int pos, SString T);

int StrDelete(SString S, int pos, int len);

int Replace(SString S, SString T, SString V);

void StrPrint(SString T);

void get_next(SString T, int next[]);

void get_nextval(SString T, int nextval[]);

int Index_KMP(SString S, SString T, int pos, int next[]);






