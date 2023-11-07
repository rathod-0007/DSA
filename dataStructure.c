#include <stdio.h>

int main()
{
    int pav[][4] = {{1, 5,2, 3},{ 4, 8, 9}, {3}};
    int length = sizeof(pav) / sizeof(pav[0]);
    printf("size of array is: %d\n", length);
    int col=(sizeof(pav) / sizeof(pav[0][0]))/length;
    printf("noof cols= %d", col);
}