/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmagroun <mmagroun@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 12:14:11 by mmagroun          #+#    #+#             */
/*   Updated: 2026/07/19 22:20:44 by mmagroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	error1(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		write(1, "Error", 5);
		write(1, "\n", 1);
		return (1);
	}
	return (0);
}

int	error2(int argc, char **argv)
{
	(void)argc;
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] != ' ' && (argv[1][i] < '1' || argv[1][i] > '4'))
		{
			write(1, "Error", 5);
			write(1, "\n", 1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	error3(int argc, char **argv)
{
	(void)argc;
	int	i;
	int	j;
	int	sum;

	i = 0;
	while (i <= 6)
	{
		j = i + 8;
		sum = ((argv[1][i] - '0') + (argv[1][j] - '0'));
		if (sum < 3 || sum > 5)
		{
			write(1, "Error", 5);
			write(1, "\n", 1);
			return (1);
		}
		i = i + 2;
	}
	return (0);
}

int	error4(int argc, char **argv)
{
	(void)argc;
	int	i;
	int	j;
	int	sum;

	i = 16;
	while (i <= 22)
	{
		j = i + 8;
		sum = ((argv[1][i] - '0') + (argv[1][j] - '0'));
		if (sum < 3 || sum > 5)
		{
			write(1, "Error", 5);
			write(1, "\n", 1);
			return (1);
		}
		i = i + 2;
	}
	return (0);
}

int	final_error(int argc, char **argv)
{
	if (error1(argc, argv) == 1)
		return (1);
	if (error2(argc, argv) == 1)
		return (1);
	if (error3(argc, argv) == 1)
		return (1);
	if (error4(argc, argv) == 1)
		return (1);
	return (0);
}
