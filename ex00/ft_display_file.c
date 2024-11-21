/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:55:25 by ibrunial          #+#    #+#             */
/*   Updated: 2024/11/21 08:55:28 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	char	buffer[1000];
	int		read_byte;
	int		file;

	read_byte = 1;
	if (argc <= 1 || argc > 2)
	{
		if (argc > 2)
			write(2, "Too many arguments.\n", 21);
		else
			write(2, "File name missing.\n", 20);
		return (1);
	}
	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		write(2, "Cannot read file.\n", 19);
		return (1);
	}
	while (read_byte > 0)
	{
		read_byte = read(file, buffer, 1000);
		write(1, buffer, read_byte);
	}
	close(file);
}
