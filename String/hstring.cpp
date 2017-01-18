/*************************************************************************
	> File Name: hstring.cpp
	> Author: xu chaoxi
	> Mail: xuchaoxikb@gmail.com 
	> Created Time: Wed 18 Jan 2017 11:04:40 AM CST
 ************************************************************************/

#include<iostream>
#include "hstring.h"
using namespace std;

int StrAssign(HString &T, char *ch)
{
    if(strlen(ch)==0)
    {
        T.str = NULL;
        T.len = 0;
    }
    else
    {
 
        T.len = strlen(ch);
        T.str = (char *)malloc(T.len * sizeof(char));
        for(int i = 0; i < T.len; i++)
            T.str[i] = ch[i];
    }
    return 1;
}

int StrCopy(HString &T, char *ch)
{
    StrAssign(T, ch);
}

int StrLength(HString S)
{
    return S.len;
}

int StrCompare(HString S, HString T)
{
    for(int i = 0; i < S.len&&i < T.len;i++)
        if(S.str[i]!=T.str[i])return S.str[i] - T.str[i];
    return S.len - T.len;
}

int ClearString(HString &S)
{
    if(S.str)
    {
        free(S.str);
        S.str = NULL;
    }
    S.len = 0;
    return 1;
}

int ConCat(HString &T, HString S1, HString S2)
{
    if(T.str)
    {
        free(T.str);
    }
    T.str = (char*)malloc((S1.len + S2.len)*sizeof(char));
    for(int i = 0; i < S1.len;i++)
        T.str[i] = S1.str[i];
    for(int i = 0; i < S2.len;i++)
        T.str[i+S1.len] = S2.str[i];
    T.len = S1.len + S2.len;
    return 1;
}

int SubString(HString &Sub, HString S, int pos, int len)
{
    if(Sub.str)free(Sub.str);
    if(!len) {
        Sub.str = NULL;
        Sub.len = 0;
    }
    else {
        Sub.str = (char*)malloc(len*sizeof(char));
        if(!Sub.str)exit(EXIT_FAILURE);
        for(int i = 0; i < len; i++)
            Sub.str[i] = S.str[i+pos-1];
        Sub.len = len;
    }
    return 1;
}

int StrInsert(HString &S, int pos, HString T)
{
    if(pos < 1||pos > S.len+1)return 0;
    if(T.len) {
        S.str = (char*)realloc(S.str, (S.len+T.len)*sizeof(char));
        if(!S.str)exit(EXIT_FAILURE);
        for(int i = S.len-1; i >= pos-1;i--)
            S.str[i+T.len] = S.str[i];
        for(int i = 0;i < T.len;i++)
            S.str[i+pos-1] = T.str[i];
        S.len += T.len;
    }
    return 1;
}

void StrPrint(HString T)
{
    for(int i = 0; i < T.len;i++)
        cout<<T.str[i]<<" ";
    cout<<endl;
}

void get_next(HString T, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while(i < T.len)
    {
        if(j==0||T.str[i]==T.str[j] )
        {
            i++;
            j++;
            next[i] = j;
        }
        else j = next[j];
    }
}

void get_nextval(HString T, int nextval[])
{
    int i = 1, j = 0;
    nextval[1] = 0;
    while(i < T.len) 
    {
        if(j==0||T.str[i]==T.str[j])
        {
            i++;
            j++;
            if(T.str[i]==T.str[j])nextval[i] = nextval[j];
            else nextval[i] = j;
        }
        else j = nextval[j];
    }
}

int Index_KMP(HString S, HString T, int pos, int next[])
{
    int i = pos, j =1;
    while(i <= S.len&&j <= T.len)
    {
        if(S.str[i]==T.str[j])
        {
            i++;
            j++;
        }
        else {
            j = next[j];
        }
    }
    if(j > T.len)
        return i-T.len;
    return 0;
}



