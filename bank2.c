#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure for storing the bank card information
struct BankCard {
    char cardNumber[20];
    char cardType[10];
};

int main() {
    // Initializing variables
    struct BankCard card;
    int option;

    // User interface for adding a card
    printf("Please select the type of card you want to add:\n");
    printf("1. SBI\n");// see how many cards you can add in your account!
    printf("2. Axis\n");
    scanf("%d", &option);

    // Validating the user's choice
    if (option == 1) {
        strcpy(card.cardType, "SBI");
    } else if (option == 2) {
        strcpy(card.cardType, "Axis");
    } else {
        printf("Invalid option\n");
        exit(0);
    }

    // Getting the card number from the user
    printf("Enter the card number: ");
    scanf("%s", card.cardNumber);

    // Adding the card to the database (here, we just print the details to the console)
    printf("\nCard Added Successfully!\n");
    printf("Card Type: %s\n", card.cardType);
    printf("Card Number: %s\n", card.cardNumber);

    return 0;
}
