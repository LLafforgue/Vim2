#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	char	*temp;

	if (s)
	{
		temp = s;
		while(*s)
			s++;
		write(fd, temp, s - temp);
	}
}
/*
int main(void)
{
    char *s = "Avadaaaa!";

    ft_putstr_fd(s, 0);
    write(1, "\n", 1);
    ft_putstr_fd((void *)0, 0);
    write(1, "\n", 1);
}
*/
