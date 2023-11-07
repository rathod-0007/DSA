#include <stdio.h> 
#include <string.h> 

int main() 
{ 
	char card_name[50]; 
	char card_number[50]; 
	int expiry_month, expiry_year; 
	int cvv; 

	printf("Enter card name: "); 
	scanf("%s", card_name); 

	printf("Enter card number: "); 
	scanf("%s", card_number); 

	printf("Enter expiry month: "); 
	scanf("%d", &expiry_month); 

	printf("Enter expiry year: "); 
	scanf("%d", &expiry_year); 

	printf("Enter CVV: "); 
	scanf("%d", &cvv); 

	printf("Card details:\n"); 
	printf("Name: %s\n", card_name); 
	printf("Number: %s\n", card_number); 
	printf("Expiry: %d/%d\n", expiry_month, expiry_year); 
	printf("CVV: %d\n", cvv); 

	return 0; 
} 
