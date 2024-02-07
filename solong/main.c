/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:54:01 by fekiz             #+#    #+#             */
/*   Updated: 2024/02/07 19:24:20 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strstr(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	close_game(t_game *list)
{
	mlx_destroy_window(list->mlx, list->win);
	get_free(list);
	system("leaks so_long");
	exit (0);
}

void	ft_putnbr(int n)
{
	long	num;
	char	c;

	num = n;
	if (num < 0)
	{
		write (1, "-", 1);
		num *= -1;
	}
	if (num < 10)
	{
		c = num + '0';
		write (1, &c, 1);
	}
	else
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
}

int	main(int ac, char **av)
{
	t_game	*list;

	list = (t_game *)malloc(sizeof(t_game));
	if (!list)
		return (0);
	if (ac == 2 && av[1] && av[1][0] != '.')
	{
		game_edit(list);
		arg_control(av[1], list);
		map_creator(av[1], list);
		game_start(list);
	}
	else
		ft_error(list);
	get_free(list);
	system("leaks so_long");
}
