#include "headers.h"

int test(double a, double b)
{

    if (a == b)
        return 1;
    return 0;
}

void print_result(int res)
{
    static int i = 0;
    printf("%d: ", i++);
    if (res)
        printf("ok\n");
    else
        printf("error\n");
}

void main_test()
{
    printf("Tests for cmp_begin:\n");
    print_result(test(cmp_begin("aaa", "aaa"), 0));
    print_result(test(cmp_begin("b", "c"), 1));
    print_result(test(cmp_begin("#aaa*aa", "$$bbb@"), 1));
    print_result(test(cmp_begin("&&", "aaaa"), 1));
    print_result(test(cmp_begin("abc", "$$bbss"), 1));
    print_result(test(cmp_begin("33w", "aaaa"), 0));
}