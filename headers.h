#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>

int file_open_desc(char *filename, int flags, mode_t mode);
void *mem(int fd, int prot, int flags);
FILE *file_open(char *filename, char *flags);
int koll_str(char *filename);
void mas_of_pointers(char **mas, char *str_point, int str);
char *is_alpha(char *str);
int cmp_begin(char *str1, char *str2);
void q_sort(int (*cmp)(char *, char *), char **mas, int left, int right);
void print_res(char **mas, int k);
void main_test();