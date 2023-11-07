#include <stdio.h>
#include <stdlib.h>
#include<math.h>

typedef struct Term {
    float coefficient;
    int exponent;
    struct Term* next;
} Term;

typedef struct Polynomial {
    Term* header;
} Polynomial;

Term* createTerm(float coefficient, int exponent) {
    Term* term = (Term*)malloc(sizeof(Term));
    term->coefficient = coefficient;
    term->exponent = exponent;
    term->next = NULL;
    return term;
}

void initPolynomial(Polynomial* polynomial) {
    polynomial->header = createTerm(0.0, -1);
    polynomial->header->next = polynomial->header;
}

void addTerm(Polynomial* polynomial, float coefficient, int exponent) {
    Term* newTerm = createTerm(coefficient, exponent);
    Term* current = polynomial->header;

    while (current->next != polynomial->header && current->next->exponent > exponent) {
        current = current->next;
    }

    newTerm->next = current->next;
    current->next = newTerm;
}

void Pwrite(Polynomial* polynomial) {
    Term* current = polynomial->header->next;
    int firstTerm = 1;

    while (current != polynomial->header) {
        if (current->coefficient != 0) {
            if (!firstTerm) {
                if (current->coefficient > 0) {
                    printf(" + ");
                } else {
                    printf(" - ");
                }
            }
            if (fabs(current->coefficient) != 1 || current->exponent == 0) {
                printf("%.2f", fabs(current->coefficient));
            }
            if (current->exponent > 0) {
                printf("x");
                if (current->exponent > 1) {
                    printf("^%d", current->exponent);
                }
            }
            firstTerm = 0;
        }
        current = current->next;
    }

    if (firstTerm) {
        printf("0");
    }
    printf("\n");
}

void Padd(Polynomial* polynomial, float coefficient, int exponent) {
    Term* current = polynomial->header->next;
    Term* prev = polynomial->header;

    while (current != polynomial->header && current->exponent > exponent) {
        prev = current;
        current = current->next;
    }

    if (current != polynomial->header && current->exponent == exponent) {
        current->coefficient += coefficient;
        if (current->coefficient == 0) {
            prev->next = current->next;
            free(current);
        }
    } else {
        Term* newTerm = createTerm(coefficient, exponent);
        newTerm->next = current;
        prev->next = newTerm;
    }
}

int main() {
    Polynomial result;
    initPolynomial(&result);

    printf("Enter polynomial A:\n");
    Polynomial a;
    initPolynomial(&a);
    int numTermsA;
    printf("Enter the number of terms in polynomial A: ");
    scanf("%d", &numTermsA);
    for (int i = 0; i < numTermsA; i++) {
        float coefficient;
        int exponent;
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%f %d", &coefficient, &exponent);
        addTerm(&a, coefficient, exponent);
    }

    printf("Enter polynomial B:\n");
    int numTermsB;
    printf("Enter the number of terms in polynomial B: ");
    scanf("%d", &numTermsB);
    for (int i = 0; i < numTermsB; i++) {
        float coefficient;
        int exponent;
        printf("Enter coefficient for term %d: ", i + 1);
        scanf("%f", &coefficient);
        exponent = i;  // Assigning increasing exponents for the second polynomial
        Padd(&result, coefficient, exponent);
    }

    printf("\nPolynomial A: ");
    Pwrite(&a);

    printf("Polynomial B: ");
    Pwrite(&result);

    return 0;
}
