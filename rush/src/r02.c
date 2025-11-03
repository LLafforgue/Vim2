#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void	find_nb(char *file)
{
	int	fd;
	char	buffer[5];

	fd = open(file, O_RDONLY);
	read(fd, buffer, 5);
	close(fd);
	write(1, buffer, 5);
	printf("%d", fd);
}
/*
char	find_name(char file)
{
	// cherche le nombre ecrit en lettres
}
*/
int	main(int argc, char **argv)
{

	printf("%s",argv[1]);
       	find_nb(argv[1]);
	argc += 1;
}
