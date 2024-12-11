#include<conio.h>
#include<string.h>
#include<iostream>
using namespace std;
enum symbol{sharpt,includet,lt,le,gt,ge,ne,eq,id,no,maint,opar,cpar,oak,
	    cak,fort,semi,ift,elset,intt,floatt,chart,ass,dot,coma,add,sub,
	    mul,divt};

char symbolname[50][10]={"sharpt","includet","lt","le","gt","ge","ne","eq","id","no","maint","opar","cpar","oak",
	    "cak","fort","semi","ift","elset","intt","floatt","chart","ass","dot","coma","add","sub",
	    "mul","divt"};
struct token{
 symbol type;
 int col,row;
 char lexeme[30];
};
token tokens[500];
char input[10000];
int pos=0,row=1,col=1;
int noftokens=0;
void mystrcat(char s[],char ch)
{
int l;
l= strlen(s);
s[l]=ch;
s[l+1]='\0';
}
void lexerror(char message[])
{
 cout << "line:"<<tokens[noftokens].row<<" col:"<<tokens[noftokens].col<<" "<<message;
 getch();
 exit(0);
}
int lex()
{
 int state=0;
 char ch;
 char str[30];
 while(1){
  switch(state)
   {
    case 0:str[0]='\0';
	   tokens[noftokens].col=col;
	   tokens[noftokens].row=row;
	   ch=input[pos++];
	   mystrcat(str,ch);
	   col++;
	   if (isdigit(ch)) state=1;
	   else if (isalpha(ch)) state=2;
	   else if (ch=='#') state=3;
	   else if (ch=='<') state=4;
	   else if (ch=='>') state=5;
	   else if (ch=='!') state=6;
	   else if (ch=='=') state=7;
	   else if (ch==';') state=8;
	   else if (ch=='(') state=9;
	   else if (ch==')') state=10;
	   else if (ch=='{') state=11;
	   else if (ch=='}') state=12;
	   else if (ch=='\n') state=13;
	   else if (ch==',') state=14;
	   else if (ch==' ') state=15;
	   else if (ch=='.') state=16;
	   else if (ch=='+') state=17;
	   else if (ch=='-') state=18;
	   else if (ch=='*') state=19;
	   else if (ch=='/') state=20;
	   else if (ch=='\0') return -1;
	   else lexerror("unknown character!");
	   break;
    case 1: ch=input[pos++];
	    while(isdigit(ch))
	       {
		mystrcat(str,ch);
		if (strlen(str)>5) lexerror("too big identifier");
		col++;
		ch=input[pos++];
	       }
	    pos--;
	    tokens[noftokens].type=no;
	    strcpy(tokens[noftokens].lexeme,str);
	    noftokens++;
	    return 1;
    case 2: ch=input[pos++];
	    while(isalnum(ch))
	       {
		mystrcat(str,ch);
		col++;
		ch=input[pos++];
	       }
	    pos--;
	    strcpy(tokens[noftokens].lexeme,str);
	    if (strcmp(str,"for")==0) tokens[noftokens].type=fort;
	    else if (strcmp(str,"if")==0) tokens[noftokens].type=ift;
	    else if (strcmp(str,"int")==0) tokens[noftokens].type=intt;
	    else if (strcmp(str,"float")==0) tokens[noftokens].type=floatt;
	    else if (strcmp(str,"char")==0) tokens[noftokens].type=chart;
	    else if (strcmp(str,"else")==0) tokens[noftokens].type=elset;
	    else if (strcmp(str,"main")==0) tokens[noftokens].type=maint;
	    else if (strcmp(str,"include")==0) tokens[noftokens].type=includet;
	    else { tokens[noftokens].type=id;
		   if(strlen(str)>10) lexerror("too big identifier");
		 }
	    noftokens++;
	    return 1;
    case 3:strcpy(tokens[noftokens].lexeme,str);
	   tokens[noftokens].type=sharpt;
	    noftokens++;
	   return 1;
    case 4:ch=input[pos++];
	   if (ch!='='){
			pos--;
			strcpy(tokens[noftokens].lexeme,str);
			tokens[noftokens].type=lt;
			noftokens++;
			return 1;
		       }
	   else        {
			col++;
			mystrcat(str,ch);
			strcpy(tokens[noftokens].lexeme,str);
			tokens[noftokens].type=le;
			noftokens++;
			return 1;
		       }
    case 5:ch=input[pos++];
	   if (ch!='='){
			pos--;
			strcpy(tokens[noftokens].lexeme,str);
			tokens[noftokens].type=gt;
			noftokens++;
			return 1;
		       }
	   else        {
			col++;
			mystrcat(str,ch);
			strcpy(tokens[noftokens].lexeme,str);
			tokens[noftokens].type=ge;
			noftokens++;
			return 1;
		       }
    case 6:ch=input[pos++];
	   if (ch!='=') lexerror("unknown character");
	   else        {
			col++;
			mystrcat(str,ch);
			strcpy(tokens[noftokens].lexeme,str);
			tokens[noftokens].type=ne;
			noftokens++;
			return 1;
		       }
    case 7:ch=input[pos++];
	   if (ch!='='){
			pos--;
			strcpy(tokens[noftokens].lexeme,str);
			tokens[noftokens].type=ass;
			noftokens++;
			return 1;
		       }
	   else        {
			col++;
			mystrcat(str,ch);
			strcpy(tokens[noftokens].lexeme,str);
			tokens[noftokens].type=eq;
			noftokens++;
			return 1;
		       }
    case 8:strcpy(tokens[noftokens].lexeme,str);
	   tokens[noftokens].type=semi;
	   noftokens++;
	   return 1;
    case 9:strcpy(tokens[noftokens].lexeme,str);
	   tokens[noftokens].type=opar;
	   noftokens++;
	   return 1;
    case 10:strcpy(tokens[noftokens].lexeme,str);
	   tokens[noftokens].type=cpar;
	   noftokens++;
	   return 1;
    case 11:strcpy(tokens[noftokens].lexeme,str);
	   tokens[noftokens].type=oak;
	   noftokens++;
	   return 1;
    case 12:strcpy(tokens[noftokens].lexeme,str);
	   tokens[noftokens].type=cak;
	   noftokens++;
	   return 1;
    case 13:row++;
	    col=1;
	    state=0;
	    break;
    case 14:strcpy(tokens[noftokens].lexeme,str);
	   tokens[noftokens].type=coma;
	   noftokens++;
	   return 1;
    case 15:state=0;
	    break;
    case 16:strcpy(tokens[noftokens].lexeme,str);
	   tokens[noftokens].type=dot;
	   noftokens++;
	   return 1;
    case 17:strcpy(tokens[noftokens].lexeme,str);
	   tokens[noftokens].type=add;
	   noftokens++;
	   return 1;
    case 18:strcpy(tokens[noftokens].lexeme,str);
	   tokens[noftokens].type=sub;
	   noftokens++;
	   return 1;
    case 19:strcpy(tokens[noftokens].lexeme,str);
	   tokens[noftokens].type=mul;
	   noftokens++;
	   return 1;
    case 20:strcpy(tokens[noftokens].lexeme,str);
	   tokens[noftokens].type=divt;
	   noftokens++;
	   return 1;
   }
  }
}
int main()
{
 FILE *fp;
 int i;
 fp=fopen("p.dat","rt");
 if(!fp){
         cout << "file p.dat not found!!!";
         getch();
         return 1;
         }
 i=0;
 while (!feof(fp)) input[i++]=getc(fp);
 input[i-1]='\0';
 pos=0;
 while(pos<strlen(input))
 		lex();
 cout<<"lexeme   "<<"row      "<<"col   "<<"token\n";
 for(i=0;i<noftokens;i++)
     {
      if (i%10==0 && i!=0) getch();
      cout<<tokens[i].lexeme<<"    "<<tokens[i].row<<"           "<<tokens[i].col<<"        "<<symbolname[tokens[i].type]<<"\n";
     }
 getch();
 return 0;
}
