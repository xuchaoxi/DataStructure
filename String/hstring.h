/*************************************************************************
	> File Name: hstring.h
	> Author: xu chaoxi
	> Mail: xuchaoxikb@gmail.com 
	> Created Time: Wed 18 Jan 2017 10:54:26 AM CST
 ************************************************************************/

#ifndef _HSTRING_H
#define _HSTRING_H
#endif
#include<cstdlib>
#include<cstring>

typedef struct {
    char *str;
    int len;
}HString;

int StrAssign(HString &T, char *ch);

int StrCopy(HString &T, char *ch);

int StrEmpty(HString S);

int StrLength(HString S);

int StrCompare(HString S, HString T);

int ClearString(HString &S);

int ConCat(HString &T, HString S1, HString S2);

int SubString(HString &Sub, HString S, int pos, int len);

int Index(HString S, HString T, int pos);

int StrInsert(HString &S, int pos, HString T);

int StrDelete(HString &S, int pos, int len);

int Replace(HString &S, HString T, HString V);

void StrPrint(HString T);

void get_next(HString T, int next[]);

void get_nextval(HString T, int nextval[]);

int Index_KMP(HString S, HString T, int pos, int next[]);
