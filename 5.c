#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char op[10],arg1[10],arg2[10],result[10];

int main()
{
FILE *f1,*f2;
f1=fopen("input.txt","r");
f2=fopen("output.txt","w");
while(!feof(f1))
{
fscanf(f1,"%s%s%s%s",result,op,arg1,arg2);
if(strcmp(op,"+")==0)
{
fprintf(f2,"MOVE R0,%s",arg1);
fprintf(f2,"ADD R0,%s",arg2);
fprintf(f2,"MOVE %s,R0\n",result);
}
if(strcmp(op,"-")==0)
{
fprintf(f2,"MOVE R0,%s",arg1);
fprintf(f2,"SUB R0,%s",arg2);
fprintf(f2,"MOVE %s,R0\n",result);
}
if(strcmp(op,"/")==0)
{
fprintf(f2,"MOVE R0,%s",arg1);
fprintf(f2,"DIV R0,%s",arg2);
fprintf(f2,"MOVE %s,R0\n",result);
}
if(strcmp(op,"*")==0)
{
fprintf(f2,"MOVE R0,%s",arg1);
fprintf(f2,"MUL R0,%s",arg2);
fprintf(f2,"MOVE %s,R0\n",result);
}
if(strcmp(op,"=")==0)
{
fprintf(f2,"MOVE R0,%s",arg1);
fprintf(f2,"MOVE %s,R0\n",result);
}
}
}

