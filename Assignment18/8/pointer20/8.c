#include<stdio.h>

int main() {
 int a=56;
 int *b = &a;//b is pointer pointing to a
 printf("the address of a is %x\n", b);  //%x is format specifier that gives hexa decimal 
 printf("the value of a is %d\n", *b);  

}   