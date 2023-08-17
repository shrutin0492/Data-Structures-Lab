#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coefficient;
    int exponent;
    struct Term *next;
};

struct Polynomial {
    struct Term *head;
};

struct Term *createTerm(int coefficient, int exponent) {
    struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

void insertTerm(struct Polynomial *poly, int coefficient, int exponent) {
    struct Term *newTerm = createTerm(coefficient, exponent);
    if (poly->head == NULL) {
        poly->head = newTerm;
        return;
    }
    struct Term *current = poly->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newTerm;
}

void displayPolynomial(struct Polynomial poly) {
    struct Term *current = poly.head;
    while (current != NULL) {
        printf("%dx^%d", current->coefficient, current->exponent);
        current = current->next;
        if (current != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

struct Polynomial addPolynomials(struct Polynomial poly1, struct Polynomial poly2) {
    struct Polynomial result;
    result.head = NULL;

    struct Term *term1 = poly1.head;
    struct Term *term2 = poly2.head;

    while (term1 != NULL && term2 != NULL) {
        if (term1->exponent > term2->exponent) {
            insertTerm(&result, term1->coefficient, term1->exponent);
            term1 = term1->next;
        } else if (term2->exponent > term1->exponent) {
            insertTerm(&result, term2->coefficient, term2->exponent);
            term2 = term2->next;
        } else {
            int sumCoefficient = term1->coefficient + term2->coefficient;
            if (sumCoefficient != 0) {
                insertTerm(&result, sumCoefficient, term1->exponent);
            }
            term1 = term1->next;
            term2 = term2->next;
        }
    }

    while (term1 != NULL) {
        insertTerm(&result, term1->coefficient, term1->exponent);
        term1 = term1->next;
    }

    while (term2 != NULL) {
        insertTerm(&result, term2->coefficient, term2->exponent);
        term2 = term2->next;
    }

    return result;
}

int main() {
    struct Polynomial poly1;
    poly1.head = NULL;

    struct Polynomial poly2;
    poly2.head = NULL;

    int n1, n2;
    printf("Enter the number of terms in polynomial 1: ");
    scanf("%d", &n1);

    for (int i = 0; i < n1; i++) {
        int coefficient, exponent;
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly1, coefficient, exponent);
    }

    printf("Enter the number of terms in polynomial 2: ");
    scanf("%d", &n2);

    for (int i = 0; i < n2; i++) {
        int coefficient, exponent;
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly2, coefficient, exponent);
    }

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    struct Polynomial sum = addPolynomials(poly1, poly2);

    printf("Sum of the polynomials: ");
    displayPolynomial(sum);

    // Free memory by deallocating linked lists
    struct Term *current1 = poly1.head;
    while (current1 != NULL) {
        struct Term *temp = current1;
        current1 = current1->next;
        free(temp);
    }

    struct Term *current2 = poly2.head;
    while (current2 != NULL) {
        struct Term *temp = current2;
        current2 = current2->next;
        free(temp);
    }

    struct Term *currentSum = sum.head;
    while (currentSum != NULL) {
        struct Term *temp = currentSum;
        currentSum = currentSum->next;
        free(temp);
    }

    return 0;
}
