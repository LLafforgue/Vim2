#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "rush_02.h"

int main(int argc, char *argv[])
{
    char *number;
    const char *dict;
    char *line;
    if (argc != 2 && argc != 3)
        {
            write(1, "Error\n", 6);
            return (1);
        }
    else
    {
        number = ft_atoi(argv[argc - 1]);
        if (number == NULL)
        {
            write(1, "Error\n", 6);
            return (1);
        }
        if (argc == 2)
            dict = "./numbers.dict";
        if (argc == 3)
            dict = argv[1];
    }
    write(1, number, ft_strlen(number));
    write(1, "\n", 1);
    if(*dict)
    {
        line = ft_parse_lib(dict);
        printf("\n%s", line);
        free(line);
    }
    return (0);
}