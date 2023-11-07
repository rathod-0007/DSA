#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    int arr[10]={0};
    for (int i = 0; num!=0; i++)
    {
        int temp=num%10;
        arr[temp]++;
        num=num/10;
    }
    for (int i = 0; i < 10; i++)
    {
        // printf("arr[%d] = %d\n",i,arr[i]);
        int digit=arr[i];
        if (digit>1)
        {

            printf("the digit %d appears %d\n",i,digit);
        }
        
    }
    
    
}