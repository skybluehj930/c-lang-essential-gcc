#include <stdio.h>
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main() {
    int a = 10;
    int b = 20;
    printf("before a: %d, b: %d \n", a, b);
    /* ... */
    swap(&a, &b);
    printf("after a: %d, b: %d", a, b);
    return 0;
}