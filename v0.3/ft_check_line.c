/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: migalvar <migalvar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/19 20:28:33 by migalvar      #+#    #+#                 */
/*   Updated: 2020/05/22 20:22:58 by migalvar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_skip_n(char *s, int i)
{
	if (i == -1)
		return (-1);
	i = ft_skip_c(s, i, ' ');
	if (s[i] == '-')
		i++;
	while (s[i] >= 48 && s[i] <= 57)
		i++;
	if (s[i] == '.')
	{
		i++;
		while (s[i] >= 48 && s[i] <= 57)
			i++;
	}
	i = ft_skip_c(s, i, ' ');
	if ((s[i] < 48 || s[i] > 57) 
		&& s[i] != '\0' && s[i] != '\n' && s[i] != ',' && s[i] != '.')
		return (-1);
	return (i);
}

int		ft_check_c(char *s, int i, int *j, char c)
{
	int		k;

	i++;
	if (c == 'c' && s[i] != 'y' && s[i] != ' ')
		return (-1);
	if (c == 't' && s[i] != 'r')
		return (-1);
	if (c == 'p' && s[i] != 'l')
		return (-1);
	if (c == 'l' && s[i] != ' ')
		return (-1);
	k = ft_check_n(s, i);
	if (k == -1)
		return (-1);
	*j = *j + 1;
	return (k);
}

int		ft_check_n(char *s, int i)
{
	i++;
	i = ft_skip_c(s, i, ' ');
	while (s[i] != '\n' && s[i] != '\0' && i != -1)
	{
		i = ft_skip_n(s, i);
		if (s[i] == ',')
			i++;
	}
	if (s[i] != '\n' && s[i] != '\0')
		return (-1);
	return (i);
}

int		ft_check_res(char *s, int i)
{
	i++;
	i = ft_skip_c(s, i, ' ');
	while (s[i] >= 48 && s[i] <= 57)
		i++;
	i = ft_skip_c(s, i, ' ');
	while (s[i] >= 48 && s[i] <= 57)
		i++;
	i = ft_skip_c(s, i, ' ');
	if (s[i] != '\n' && s[i] != '\0')
		return (-1);
	return (i);
}

int		ft_check_s(char *s, int i, int *j)
{
	i++;
	if (s[i] == 'q' || s[i] == 'p')
	{
		i++;
		while (s[i] != '\n' && s[i] != '\0' && i != -1)
		{
			i = ft_skip_n(s, i);
			if (s[i] == ',')
				i++;
		}
	}
	if (s[i] != '\n' && s[i] != '\0')
		return (-1);
	*j = *j + 1;
	return (i);
	
}