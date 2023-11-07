#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a term in the polynomial
typedef struct Term {
    float coefficient;
    int exponent;
    struct Term* next;
} Term;

// Structure to represent a polynomial (circular linked list with a header node)
typedef struct Polynomial {
    Term* header;
} Polynomial;

// Function to create a new term
Term* createTerm(float coefficient, int exponent) {
    Term* term = (Term*)malloc(sizeof(Term));
    term->coefficient = coefficient;
    term->exponent = exponent;
    term->next = NULL;
    return term;
}

// Function to initialize a polynomial
void initPolynomial(Polynomial* polynomial) {
    polynomial->header = createTerm(0.0, -1); // Header node with sentinel values
    polynomial->header->next = polynomial->header; // Circular self-reference
}

// Function to add a term to a polynomial
void addTerm(Polynomial* polynomial, float coefficient, int exponent) {
    Term* newTerm = createTerm(coefficient, exponent);
    Term* current = polynomial->header;

    while (current->next != polynomial->header && current->next->exponent > exponent) {
        current = current->next;
    }

    newTerm->next = current->next;
    current->next = newTerm;
}

// Function to read a polynomial and convert it to its circular representation
Polynomial* Pread() {
    Polynomial* polynomial = (Polynomial*)malloc(sizeof(Polynomial));
    initPolynomial(polynomial);

    int numTerms;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &numTerms);

    for (int i = 0; i < numTerms; i++) {
        float coefficient;
        int exponent;
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%f %d", &coefficient, &exponent);
        addTerm(polynomial, coefficient, exponent);
    }

    return polynomial;
}

// Function to output the polynomial in mathematical form
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

// Function to compute c = a + b
Polynomial* Padd(Polynomial* a, Polynomial* b) {
    Polynomial* c = (Polynomial*)malloc(sizeof(Polynomial));
    initPolynomial(c);

    Term* termA = a->header->next;
    Term* termB = b->header->next;

    while (termA != a->header && termB != b->header) {
        if (termA->exponent > termB->exponent) {
            addTerm(c, termA->coefficient, termA->exponent);
            termA = termA->next;
        } else if (termA->exponent < termB->exponent) {
            addTerm(c, termB->coefficient, termB->exponent);
            termB = termB->next;
        } else {
            addTerm(c, termA->coefficient + termB->coefficient, termA->exponent);
            termA = termA->next;
            termB = termB->next;
        }
    }

    // Add remaining terms from a and b
    while (termA != a->header) {
        addTerm(c, termA->coefficient, termA->exponent);
        termA = termA->next;
    }
    while (termB != b->header) {
        addTerm(c, termB->coefficient, termB->exponent);
        termB = termB->next;
    }

    return c;
}

// Function to compute c = a - b
Polynomial* Psub(Polynomial* a, Polynomial* b) {
    Polynomial* c = (Polynomial*)malloc(sizeof(Polynomial));
    initPolynomial(c);

    Term* termA = a->header->next;
    Term* termB = b->header->next;

    while (termA != a->header && termB != b->header) {
        if (termA->exponent > termB->exponent) {
            addTerm(c, termA->coefficient, termA->exponent);
            termA = termA->next;
        } else if (termA->exponent < termB->exponent) {
            addTerm(c, -termB->coefficient, termB->exponent);
            termB = termB->next;
        } else {
            addTerm(c, termA->coefficient - termB->coefficient, termA->exponent);
            termA = termA->next;
            termB = termB->next;
        }
    }

    // Add remaining terms from a and subtract terms from b
    while (termA != a->header) {
        addTerm(c, termA->coefficient, termA->exponent);
        termA = termA->next;
    }
    while (termB != b->header) {
        addTerm(c, -termB->coefficient, termB->exponent);
        termB = termB->next;
    }

    return c;
}


// Function to compute c = a * b with term reduction
Polynomial* Pmult(Polynomial* a, Polynomial* b) {
    Polynomial* c = (Polynomial*)malloc(sizeof(Polynomial));
    initPolynomial(c);

    Term* termA = a->header->next;

    while (termA != a->header) {
        Term* termB = b->header->next;
        while (termB != b->header) {
            addTerm(c, termA->coefficient * termB->coefficient, termA->exponent + termB->exponent);
            termB = termB->next;
        }
        termA = termA->next;
    }

    // Combine terms with the same exponent
    Term* current = c->header->next;
    while (current != c->header && current->next != c->header) {
        if (current->exponent == current->next->exponent) {
            current->coefficient += current->next->coefficient;
            Term* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    return c;
}


// Function to evaluate the polynomial at a given point
float Peval(Polynomial* polynomial, float x) {
    float result = 0.0;
    Term* current = polynomial->header->next;

    while (current != polynomial->header) {
        result += current->coefficient * pow(x, current->exponent);
        current = current->next;
    }

    return result;
}

// Function to erase a certain term of the polynomial
void Pearse(Polynomial* polynomial, int exponent) {
    Term* current = polynomial->header;
    while (current->next != polynomial->header) {
        if (current->next->exponent == exponent) {
            Term* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
}

int main() {
    printf("Enter polynomial A:\n");
    Polynomial* a = Pread();

    printf("\nEnter polynomial B:\n");
    Polynomial* b = Pread();

    printf("\nPolynomial A: ");
    Pwrite(a);

    printf("Polynomial B: ");
    Pwrite(b);

    Polynomial* c = Padd(a, b);
    printf("\nA + B = ");
    Pwrite(c);

    Polynomial* d = Psub(a, b);
    printf("A - B = ");
    Pwrite(d);

    Polynomial* e = Pmult(a, b);
    printf("A * B = ");
    Pwrite(e);

    float x;
    printf("\nEnter the value of x for polynomial evaluation: ");
    scanf("%f", &x);
    printf("A(when x is: %f) = %.2f\n", x, Peval(a, x));
    printf("B(when x is: %f) = %.2f\n", x, Peval(b, x));

    int eraseExponent;
    printf("\nEnter the exponent of the term to erase from polynomial A: ");
    scanf("%d", &eraseExponent);
    Pearse(a, eraseExponent);
    printf("Polynomial A after erasing term with exponent %d: ", eraseExponent);
    Pwrite(a);

    // Free memory
    // ...

    return 0;
}
