#include <stdio.h>
#include <stdlib.h>

/*pw6 ex 1*/
void destroyPolynomial(Polynomial* poly);
void addMonomial(Polynomial* poly, double coefficient, int degree);
void printPolynomial(Polynomial* poly);
int isZeroPolynomial(Polynomial* poly);

typedef struct Monomial {
    double coefficient;
    int degree;
    struct Monomial* next;
} Monomial;

typedef struct Polynomial {
    Monomial* head;
} Polynomial;

Polynomial* addPolynomials(Polynomial* p1, Polynomial* p2) {
    Polynomial* result = createPolynomial();
    Monomial* p1_current = p1->head;
    Monomial* p2_current = p2->head;

    while (p1_current != NULL || p2_current != NULL) {
        if (p1_current == NULL) {
            addMonomial(result, p2_current->coefficient, p2_current->degree);
            p2_current = p2_current->next;
        } else if (p2_current == NULL) {
            addMonomial(result, p1_current->coefficient, p1_current->degree);
            p1_current = p1_current->next;
        } else if (p1_current->degree > p2_current->degree) {
            addMonomial(result, p1_current->coefficient, p1_current->degree);
            p1_current = p1_current->next;
        } else if (p1_current->degree < p2_current->degree) {
            addMonomial(result, p2_current->coefficient, p2_current->degree);
            p2_current = p2_current->next;
        } else {
            double sum = p1_current->coefficient + p2_current->coefficient;
            if (sum != 0.0) {
                addMonomial(result, sum, p1_current->degree);
            }
            p1_current = p1_current->next;
            p2_current = p2_current->next;
        }
    }

    return result;
}



Monomial* createMonomial(double coefficient, int degree) {
    Monomial* newMonomial = (Monomial*)malloc(sizeof(Monomial));
    newMonomial->coefficient = coefficient; //access through pointer
    newMonomial->degree = degree;
    newMonomial->next = NULL;
    return newMonomial;
}

Polynomial* createPolynomial() {
    Polynomial* newPolynomial = (Polynomial*)malloc(sizeof(Polynomial));
    newPolynomial->head = NULL;
    return newPolynomial;
}


void addMonomial(Polynomial* poly, double coefficient, int degree) {
    
    Monomial* newMonomial = createMonomial(coefficient, degree);
    if (poly->head == NULL) {
        poly->head = newMonomial;
        return;
    }
    Monomial* current = poly->head;
    Monomial* prev = NULL;
    while (current != NULL && current->degree > degree) {
        prev = current;
        current = current->next;
    }

   
    if (current != NULL && current->degree == degree) {
        current->coefficient += coefficient;
        if (current->coefficient == 0.0) {
            if (prev == NULL) {
                poly->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
        }
        return;
    }

    if (prev == NULL) {
        newMonomial->next = poly->head;
        poly->head = newMonomial;
    } else {
        newMonomial->next = current;
        prev->next = newMonomial;
    }
}

void printPolynomial(Polynomial* poly) {
    Monomial* current = poly->head;
    while (current != NULL) {
        printf("%.2fx^%d", current->coefficient, current->degree);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}

int isZeroPolynomial(Polynomial* poly) {
    Monomial* current = poly->head;
    while (current != NULL) {
        if (current->coefficient != 0.0) {
            return 0; // Non-zero polynomial
        }
        current = current->next;
    }
    return 1; // Zero polynomial
}

int main() {
    Polynomial* p = createPolynomial();

    addMonomial(p, 3.5, 4);
    addMonomial(p, 2.0, 2);
    addMonomial(p, -1.0, 1);
    addMonomial(p, 1.5, 0);

    printPolynomial(p);

    if (isZeroPolynomial(p)) {
        printf("Polynomial p is the zero polynomial.\n");
    } else {
        printf("Polynomial p is not the zero polynomial.\n");
    }

    Polynomial* q = createPolynomial();
    addMonomial(q, 0.0, 0);
    addMonomial(q, 0.0, 1);
    addMonomial(q, 0.0, 2);

    if (isZeroPolynomial(q)) {
        printf("\nPolynomial q is zero polynomial.\n");
    } else {
        printf("\nPolynomial q is not the zero polynomial.\n");
    }

    destroyPolynomial(p);
    destroyPolynomial(q);
    return 0;
}

/////////////////////////////////////////////
                                /*pw6 ex 2*/
int main() {
  
    Polynomial* p = initializePolynomial();

  
    printPolynomial(p); 
    //display exercise
    Polynomial* r = createPolynomial();

    addMonomial(r, 1.0, 0);
    addMonomial(r, 1.0, 3);
    addMonomial(r, -3.0, 2);
    addMonomial(r, 2.0, 7);

    display_debug(r);
    printPolynomial(r);

    destroyPolynomial(r);

    return 0;
}

/*pw6 ex 3*/
void destroyPolynomial(Polynomial* poly) {
    Monomial* current = poly->head;
    while (current != NULL) {
        Monomial* next = current->next;
        free(current);
        current = next;
    }
    free(poly);
}

void display_debug(Polynomial* poly) {
    Monomial* current = poly->head;
    while (current != NULL) {
        printf("->(%.1f X %d)", current->coefficient, current->degree);
        current = current->next;
    }
    printf(" ->E\n");
}
