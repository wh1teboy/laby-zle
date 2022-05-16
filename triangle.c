#include <stdio.h>
#include <stdlib.h>


//  linked list definition for the set of divisors
struct divisorSet {
    int divisor;
    struct divisorSet *next;
};

//  swaps two integers
void swap(int *a, int *b) {
    int t;

    t = *a;
    *a = *b;
    *b = t;

    return;
}

//  computes the greatest common divisor
int gcd(int a, int b) {
    int t;

    if (a < b) {
        swap(&a, &b);
    }

    while (b) {
        t = a % b;
        a = b;
        b = t;
    }

    return (a);
}

//  sorts a, b & c as follows:
//  a < c
//  b is the even integer regardless of its magnitude
int sort(int *a, int *b, int *c) {
    int oneEven;

    oneEven = 0;

    if (*b % 2) {
        if (*a % 2) {
            if (*c % 2) {
                oneEven = 1;
            }
            else {
                swap(b, c);
            }
        }
        else {
            swap(a, b);
        }
    }

    if (*a > *c) {
        swap(a, c);
    }

    return (oneEven);
}

//  creates the divisor set as linked list
struct divisorSet *createDivisorSet(int b) {
    struct divisorSet *dSet, *dTmp, *dBase;
    int l, i, k;

    k = sizeof(struct divisorSet);
    l = b / 2;
    dBase = malloc(k);
    dSet = dBase;
    i = 1;
    dSet->divisor = i;

    while (i++ < l) {
        if (!(b % i)) {
            dTmp = dSet;
            dSet = malloc(k);
            dSet->divisor = i;
            dTmp->next = dSet;
        }
    }

    dSet->next = 0;

    return (dBase);
}

//  frees allocated memory
void releaseMem(struct divisorSet *dSet) {
    struct divisorSet *dTmp;

    while (dSet->next) {
        dTmp = dSet->next;
        free(dSet);
        dSet = dTmp;
    }

    free(dSet);
    return;
}

//  test if pythagorean triangle or not
int isRightTriangle(int a, int b, int c) {
    struct divisorSet *dSet, *dTmp, *dBase;
    int g, baseA, baseB, baseC, m, n;

    g = gcd(a, gcd(b, c));
    baseA = a / g;
    baseB = b / g;
    baseC = c / g;

    if (sort(&baseA, &baseB, &baseC)) return (0);

    dSet = createDivisorSet(baseB / 2);
    dBase = dSet;

    while (dSet->next) {
        n = dSet->divisor * dSet->divisor;
        dTmp = dSet;

        while (dTmp->next) {
            dTmp = dTmp->next;
            m = dTmp->divisor * dTmp->divisor;

            if (m - n == baseA && m + n == baseC) {
                releaseMem(dBase);
                return (1);
            }
        }

        dSet = dSet->next;
    }

    releaseMem(dBase);
    return (0);
}

void scaleSides(int *a, int *b, int *c, int s) {
    *a *= s;
    *b *= s;
    *c *= s;
    return;
}
