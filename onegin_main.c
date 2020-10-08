#include "headers.h"

int main(int argc, char **argv)
{
    int str = koll_str(argv[1]);
    char **mas = (char **)calloc(str, sizeof(char *));
    int fd = file_open_desc(argv[1], O_RDWR, 0004);
    char *str_point = mem(fd, PROT_READ | PROT_WRITE, MAP_PRIVATE);
    mas_of_pointers(mas, str_point, str);
    q_sort(cmp_begin, mas, 0, str - 1);

    print_res(mas, str);
    main_test();
    free(mas);
}