#include "headers.h"

/**  Opens the file. Returns descriptor
 *
 * @param filename - name of the file
 * @param flags - flags for open()
 * @param filename - mode for open()
 * 
 */
int file_open_desc(char *filename, int flags, mode_t mode)
{
    int fd = open(filename, flags, mode);
    assert(fd != -1);
    return fd;
}

/**  Count the amount of all strings in file
 *
 * @param fd - descriptor of the file, which was opened
 * @param prot - prot for mmap()
 * @param flags - flags for mmap()
 * 
 */
void *mem(int fd, int prot, int flags)
{
    struct stat stb;
    assert(fstat(fd, &stb) != -1);
    off_t size = stb.st_size;

    void *vptr = mmap(NULL, size, prot, flags, fd, 0);
    assert(vptr != MAP_FAILED);

    return vptr;
}

/**  Count the amount of all strings in file
 *
 * @param filename - name of the file
 *
 */
int koll_str(char *filename)
{
    FILE *fp = fopen(filename, "r");
    assert(fp != NULL);
    char l;
    int kol_str = 0;
    while (l != EOF)
    {
        while ((l != '\n') && (l != EOF))
        {
            l = fgetc(fp);
        }
        kol_str++;
        l = fgetc(fp);
    }
    assert(fclose(fp) != EOF);
    return kol_str;
}

/**  Fills the array with strings
 *
 * @param mas - array of strings
 * @param str_point - the pointer to the beginning of the file which is written to memory
 * @param str - amount of strings
 * 
 */
void mas_of_pointers(char **mas, char *str_point, int str)
{
    for (int i = 0; i < str; i++)
    {
        mas[i] = str_point;
        while (*str_point != '\0' && *str_point != '\n')
        {
            str_point++;
        }
        *str_point = '\0';
        str_point++;
    }
}

/**  
 *Skip symbol in str if it is not a letter. Returns a pointer to the first letter in str.
 * 
 * @param str - pointer to string 
 *
 */
char *is_alpha(char *str)
{
    while ((!isalpha(*str)) && (*str != '\0'))
        str++;
    return str;
}

/**  Compares two strings, ignoring all charachters, except for letters
 * Returns 0 if strings are equal, negative value if str1>str2, positive value if str1<str2
 *
 * @param str1 - pointer to string 1
 * @param str2 - pointer to string 2
 * 
 */
int cmp_begin(char *str1, char *str2)
{
    do
    {
        str1 = is_alpha(str1);
        str2 = is_alpha(str2);
        if (*str1 != *str2)
            break;
        str1++;
        str2++;
    } while (*str1 == *str2 && (*str2 != '\0') && (*str1 != '\0'));
    return (*str1 - *str2) < 0 ? 1 : 0;
}


/**  Sort the whole strings 
 *
 * @param cmp - type of comparator function(sort from the begining/sort in reverse)
 * @param mas - array of strings
 * @param left - index of the left unsorted element
 * @param right - index of the right unsorted element
 * 
 */
void q_sort(int (*cmp)(char *, char *), char **mas, int left, int right)
{
    char *middle = mas[(left + right) / 2];
    char *tmp;
    int l = left;
    int r = right;
    while (l <= r)
    {

        while ((cmp(mas[l], middle) == 1) && (l < right))
        {
            l++;
        }
        while ((cmp(middle, mas[r]) == 1) && (r > left))
        {
            r--;
        }
        if (r >= l)
        {

            tmp = mas[l];
            mas[l] = mas[r];
            mas[r] = tmp;
            l++;
            r--;
        }
    }

    if (left < r)
        q_sort(cmp, mas, left, r);
    if (l < right)
        q_sort(cmp, mas, l, right);
}

/**  Print the result to new file. 
 *
 * @param mas - array of strings
 * @param k - amount of strings
 * 
 */
void print_res(char **mas, int k)
{
    FILE *fp = fopen("result.txt", "w");
    assert(fp != NULL);
    for (int i = 0; i <= k - 1; i++)
    {
        fprintf(fp, "%s\n", mas[i]);
    }
}