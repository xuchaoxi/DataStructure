/*************************************************************************
	> File Name: sstring.cpp
	> Author: xu chaoxi
	> Mail: xuchaoxikb@gmail.com 
	> Created Time: Wed 18 Jan 2017 09:22:48 AM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
#include "string.h"
using namespace std;

int StrAssign(SString S, char *chars)
{
    if(strlen(chars) > MAXSTRLEN)
        return 0;
    else {
        S[0] = strlen(chars);
        for(int i = 1; i <= S[0]; i++)
            S[i] = *(chars + i - 1);
        return 1;
    }
}

int StrCopy(SString T, SString S)
{
    for(int i = 0;i <= S[0];i++)
        T[i] = S[i];
    return 1;
}

int StrEmpty(SString S)
{
    if(S[0]==0)return 1;
    else return 0;
}

int StrLength(SString S)
{
    return S[0];
}

int ClearString(SString S)
{
    S[0] = 0;
    return 1;
}

int StrCompare(SString S, SString T)
{
    for(int i = 1; i <= S[0]&&i <= T[0];i++)
        if(S[i]!=T[i])
            return S[i]-T[i];
    return S[0]-T[0];
}

int ConCat(SString T, SString S1, SString S2)
{
    if(S1[0]+S2[0] > MAXSTRLEN)
    {
        for(int i = 1; i <= S1[0]; i++)
            T[i] = S1[i];
        for(int i = 1; i <= MAXSTRLEN-S1[0];i++)
            T[i+S1[0]] = S2[i];
        T[0] = MAXSTRLEN;
        return 0;
    }
    else {
        for(int i = 1; i <= S1[0]; i++)
            T[i] = S1[i];
        for(int i = 1; i <= S2[0]; i++)
            T[i+S1[0]] = S2[i];
        T[0] = S1[0]+S2[0];
        return 1;
    }
}

int SubString(SString Sub, SString S, int pos, int len)
{
    if(pos < 1|| pos > S[0]||len < 0||len + pos > S[0]+1) 
        return 0;
    for(int i = 1; i <= len; i++)
        Sub[i] = S[pos+i-1];
    Sub[0] = len;
    return 1; 

}

void StrPrint(SString S)
{
    for(int i = 1;i < S[0];i++)
        cout<<S[i]<<" ";
    cout<<endl;
}

void get_next(SString T, int next[])
{
    int i = 1 , j = 0;
    next[1] = 0;
    while(i < T[0])
    {
        if(j==0||T[i]==T[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
}

void get_nextval(SString T, int nextval[])
{
    int i = 1, j = 0;
    nextval[1] = 0;
    while(i < T[0])
    {
        if(j==0||T[i]==T[j])
        {
            i++;
            j++;
            if(T[i]==T[j])nextval[i] = nextval[j];
            else nextval[i] = j;
        }
        else j = nextval[j];
    }
}

int Index_KMP(SString S, SString T, int pos, int next[])
{
    int i = pos, j = 1;
    while(i <= S[0] && j <= T[0])
    {
        if(j==0||S[i]==T[j]) 
        {
            i++;
            j++;
        }
        else j = next[j];
    }
    if(j > T[0])
        return i-T[0];
    else return 0;
}



