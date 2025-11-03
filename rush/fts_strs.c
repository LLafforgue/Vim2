#include <stdlib.h>

char *ft_atoi(char *number)
{
    char *nbr;
    int len;
    char *temp;

    while (*number < '!')
        number++;
    if (*number != '+' && !(*number >= '0' && *number <= '9'))
        return (NULL);
    else if (*number == '+')
        number++;
    temp = number;
    while (*number >= '0' && *number <= '9')
        number++;
    nbr = malloc((number - temp + 1) * sizeof(char));
    if (!nbr)
        return (NULL);
    len = 0;
    while (*temp >= '0' && *temp <= '9')
        nbr[len++] = *temp++;
    nbr[len] = '\0';
    return (nbr);
}

int ft_strlen(char *str)
{
    int len;

    len = 0;
    while(str[len++]);

    return (len - 1);
}