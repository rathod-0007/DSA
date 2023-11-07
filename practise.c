#include<stdio.h>
#include<stdlib.h>

int main(){
FILE *fp = NULL;
char str[20];
char ch;

fp=fopen("text.txt","r");

if(fp == NULL){
       printf("error...");
       exit(1);
}
while(!feof(fp)){
       fgets(str,5,fp);//gettiing input
       printf("%s",str);
}

fclose(fp);}

