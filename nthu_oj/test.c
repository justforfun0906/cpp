#include <stdio.h>

int main(void) {
    int a, b, ret;
    a = b = -1;
    ret = scanf("(%d,%d)", &a, &b);
    printf("%d %d %d", ret, a, b);
    return 0;
}