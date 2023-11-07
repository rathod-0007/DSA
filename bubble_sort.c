#include <stdio.h>

void array(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubbleSort(int *a, int n)              /*since n is 6
 so bubble sort starts with comparison as follows(this is for 1st pass & follows till we get sorted array):
 :0,1; 1,2; 2,3; 3,4; 4,5*/
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {                                       /*for noof passes i.e., n-1*/
        for (int j = 0; j < n - 1 - i; j++) /*for no of comparisons for each pass i.e., n-1-i*/
        {
            if (a[j] > a[j + 1])            /*more noof swaps seen*/
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int a[] = {5, 15, 4, 36, 9, 24};
    int n = 6;
    array(a, n);      /*initial elements*/
    bubbleSort(a, n); /*function to sort*/
    array(a, n);      /*it printd after the bubblesort*/
}