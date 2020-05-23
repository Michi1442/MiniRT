/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: migalvar <migalvar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/19 15:05:10 by migalvar      #+#    #+#                 */
/*   Updated: 2020/05/21 21:45:59 by migalvar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			ft_skip_c(char *s, int i, char c)
{
	if (i == -1)
		return (-1);
	while (s[i] == c)
		i++;
	return (i);
}

void		*ft_free(char **lines)
{
	int		i;

	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
	lines = NULL;
	return (NULL);
}

size_t		ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strdup(char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s2)
	{
		while (s1[i])
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
	}
	return (s2);
}

char		*ft_strjoin(char *s, char *s1)
{
	char	*d;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	d = (char *)malloc(sizeof(char) * (ft_strlen(s) + ft_strlen(s1) + 1));
	if (!s1 || !s || !d)
		return (NULL);
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	free(s);
	while (s1[j] != '\0')
	{
		d[i] = s1[j];
		j++;
		i++;
	}
	d[i] = '\0';
	return (d);
}