#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
# define SIZE_OF_BUF 20000

int		ft_strlen(char *stroka)
{
	int		i;

	i = 0;
	while(stroka[i] != '\0')
		i++;
	return (i);
}

void	ft_cat2(char **argv, int i)
{
	i = 0;
	write(2, "cat :", 5);
	write(2, argv[1], ft_strlen(argv[1]));
	if (errno == 2)
		write(2, ": No such directory or file\n", 29);
	if (errno == 21)
		write(2, ": Is a directory\n", 18);
	if (errno == 13)
		write(2, ": Permission denied\n", 20);
}

void	ft_cat(int argc, char **argv)
{
	int		fd;
	int		i;
	int		ret;
	char		buf[SIZE_OF_BUF];

	i = 0;
	while (++i < argc)
	{
		fd = open(argv[i], O_RDWR);
		if(fd == 1)
		{
			ft_cat2(argv, i);
			close(fd);
			continue ;
		} 
		while ((ret = read (fd, buf, SIZE_OF_BUF)))
			write(1, buf, ret);
		close(fd);
	}
}

int		main(int argc, char **argv)
{
	char	symbol;

	if (argc == 1)
	{
		while (read(0, &symbol, 1))
			write(1, &symbol, 1);
	}
	else
		ft_cat(argc, argv);
	return (0);
}


























