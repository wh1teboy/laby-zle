#include <stdio.h>
#include <stdlib.h>


int main(void) {
    int a, b, c, s;

    s=20;

    a = 9;
    b = 40;
    c = 41; // (right triangle)
    printf("a = %10d   b = %10d   c = %10d   rightTriangle = %d\n", a, b, c, isRightTriangle(a, b, c));

    scaleSides(&a, &b, &c, s); // testing for overflow (right triangle)
    printf("a = %10d   b = %10d   c = %10d   rightTriangle = %d\n", a, b, c, isRightTriangle(a, b, c));

    b += 2; // testing for overflow (not right triangle)
    printf("a = %10d   b = %10d   c = %10d   rightTriangle = %d\n", a, b, c, isRightTriangle(a, b, c));

    a = 207;
    b = 224;
    c = 305; // (right triangle)
    printf("a = %10d   b = %10d   c = %10d   rightTriangle = %d\n", a, b, c, isRightTriangle(a, b, c));

    scaleSides(&a, &b, &c, s); // testing for overflow (right triangle)
    printf("a = %10d   b = %10d   c = %10d   rightTriangle = %d\n", a, b, c, isRightTriangle(a, b, c));

    b += 2; // testing for overflow (not right triangle)
    printf("a = %10d   b = %10d   c = %10d   rightTriangle = %d\n", a, b, c, isRightTriangle(a, b, c));

    printf("press <enter> to exit...\n");
    getchar();
    return (0);
}
