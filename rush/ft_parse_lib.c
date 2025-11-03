#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void ft_line(char *buff, int *len)
{
    while(*buff != '\n')
    {
        (*len)++;
        if (*len > 500)
            return;
    }
    return;
}

char *ft_parse_lib(const char *dict)
{
    int fd;
    char buff[1024];
    char *line;
    int len;
    // int nb;

    fd = open(dict, O_RDONLY);
    if (fd == -1)
        return (NULL);
    read(fd, buff, 500);
    close(fd);
    
    buff[501] = '\0';
    ft_line(buff, &len);
    if (len > 500)
        return (NULL);
    line = malloc((len + 1)*sizeof(char));
    len = 0;
    while (*buff != '\n')
        *line++ = buff[len++];
    line[len] = '\0';
    return (line);
}