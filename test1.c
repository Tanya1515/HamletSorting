#include "headers.h"

char *is_alpha(char *str)
{
    while ((!isalpha(*str)) && (*str != '\0'))
        str++;
    return str;
}

int cmp_begin(char *str1, char *str2)
{
    do
    {
        str1 = is_alpha(str1);
        str2 = is_alpha(str2);
        printf("q!\n");
        if (*str1 != *str2)
            break;
        printf("%s\n", str1);
        str1++;
        str2++;
    } while (*str1 == *str2 && (*str2 != '\0') && (*str1 != '\0'));
    return *str1 - *str2;
}

int main()
{
    printf("%d", cmp_begin("aaaa", "aaaa"));
}