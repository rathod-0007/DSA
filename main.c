#include <stdio.h>
int main(){
    FILE *file;
    file=fopen("io.txt","a");           
    int data =8;
    fprintf(file,"the given data is %d\n",data);
    fputs("hello world\n",file);
    fclose(file);
}