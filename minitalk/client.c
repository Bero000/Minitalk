/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:03:29 by beeren            #+#    #+#             */
/*   Updated: 2023/08/14 16:57:16 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

int	ft_atoi(char *str)
{
	int	index;

	index = 0;
	while (*str)
	{
		index = index * 10 + (*str - '0');
		str++;
	}
	return (index);
}

void	ft_bytesend(int pid, unsigned char c)
{
	int	bit;

	bit = 7;
	while (bit != -1)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit--;
	}
}

int	main(int ac, char *av[])
{
	int				pid;
	unsigned char	*str;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		str = (unsigned char *)av[2];
		while (*str)
		{
			ft_bytesend(pid,*str++);
		}
		ft_bytesend(pid, '\n');
	}
	else
		write (1, "Error code: Check ur ARGS.(client, pid, string)\n", 48);
	return (0);
}
