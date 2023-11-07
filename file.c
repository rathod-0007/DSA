# include <stdio.h>
int main()
{ 
    
    FILE *ptr = NULL;
    char string[50];
      ptr = fopen("file.txt", "w + r");
    fprintf(ptr ,"%s",string);
    scanf("%s",string);
   
    fscanf(ptr,"%s",string);
    printf("%s",string);
    fclose("file.txt");
   printf("hello");
    return 0;
}
