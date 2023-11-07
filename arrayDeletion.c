#include<Stdio.h>

int main()
{
    int pav[]={5,6,4,7,3,2};
    int i, size=5;
printf("initial array is:");
    for(i=0;i<=size;i++)
    {
        
        printf("%d,", pav[i]);
       
    }
    size=size-1;//we want to dlete last element so did it 
    printf("\n");
    printf("\n");
    printf("after Deletion array is:");
    for(i=0;i<=size;i++)
    {
        printf(" %d,", pav[i]);
    }

}