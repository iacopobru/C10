/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:46:40 by ibrunial          #+#    #+#             */
/*   Updated: 2024/11/21 11:51:37 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

void	putstr(const char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
}

int	check_err(int argc, char *str_file)
{
	if (errno)
	{
		write(1, "", 0);
		if (argc > 1)
		{
			putstr("cat: ");
			putstr(str_file);
			putstr(": ");
		}
		putstr(strerror(errno));
		putstr("\n");
		errno = 0;
		return (1);
	}
	return (0);
}

void	read_from_stdin(char *buffer, int read_byte)
{
	while (read_byte > 0)
	{
		read_byte = read(0, buffer, 1000);
		if (check_err(0, NULL))
			return ;
		if (write(1, buffer, read_byte) == -1)
			if (check_err(0, NULL))
				return ;
	}
}

void	read_from_file(char *buffer, int read_byte, int file, char *str_file)
{
	file = open(str_file, O_RDONLY);
	if (file == -1)
		if (check_err(2, str_file))
			return ;
	while (read_byte > 0)
	{
		read_byte = read(file, buffer, 1000);
		if (check_err(2, str_file))
		{
			close(file);
			return ;
		}
		if (write(1, buffer, read_byte) == -1)
		{
			if (check_err(2, str_file))
			{
				close(file);
				return ;
			}
		}
	}
	close(file);
}

int	main(int argc, char **argv)
{
	char	buffer[1000];
	int		file;
	int		i;

	i = 0;
	if (argc == 1)
		read_from_stdin(buffer, 1);
	while (++i < argc)
	{
		if (argv[i][0] == '-' && (argv[i][1] == '\0' || (argv[i][1] == '-'
					&& argv[i][2] == '\0')))
		{
			read_from_stdin(buffer, 1);
		}
		else
			read_from_file(buffer, 1, file, argv[i]);
	}
}
