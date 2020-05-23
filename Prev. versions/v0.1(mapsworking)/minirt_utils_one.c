/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt_utils_one.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: migalvar <migalvar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/19 16:37:18 by migalvar      #+#    #+#                 */
/*   Updated: 2020/05/20 19:47:23 by migalvar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			ft_cpy_line(char *s, int i, char **lines, int *l)
{
	int		j;
	int		k;

	j = 0;
	k = i;
	while (s[k] != '\0' && s[k] != '\n')
		k++;
	lines[*l] = (char *)malloc(sizeof(char) * (k - i + 1));
	if (!*lines)
		return (-1);
	while (s[i] != '\0' && s[i] != '\n')
	{
		lines[*l][j] = s[i];
		i++;
		j++;
	}
	lines[*l][j] = '\0';
	*l = *l + 1;
	return (i);
}

void		ft_cut(char **lines, char *content)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (content[i] != '\0' && i != -1)
	{
		while (content[i] == ' ' || content[i] == '\n')
		{
			i = ft_skip_c(content, i, ' ');
			i = ft_skip_c(content, i, '\n');
		}
		if (content[i] != '\0')
		{
			i = ft_cpy_line(content, i, lines, &j);
		}
	}
	lines[j] = NULL;
	free(content);
	if (i == -1)
		ft_free(lines);
}

int			ft_skip_c(char *s, int i, char c)
{
	if (i == -1)
		return (-1);
	while (s[i] == c)
		i++;
	return (i);
}

int			ft_check_and_count(char *s, int i)
{
	int		j;

	j = 0;
	while (s[i] != '\0' && i != -1)
	{
		i = ft_skip_c(s, i, '\n');
		if (s[i] == 's')
			i = ft_check_s(s, i, &j);
		else if (s[i] == 'c' && s[i + 1] == 'y')
			i = ft_check_c(s, i, &j, 'c');
		else if (s[i] == 't')
			i = ft_check_c(s, i, &j, 't');
		else if (s[i] == 'p')
			i = ft_check_c(s, i, &j, 'p');
		else if (s[i] == 'R')
			i = ft_check_res(s, i);
		else if ((s[i] == 'c' && s[i + 1] != 'y')
					|| s[i] == 'A' || s[i] == 'l')
			i = ft_check_n(s, i);
		else if (s[i] != '\n' && s[i] != '\0')
			i = -1;
	}
	if (i == -1)
		return (-1);
	return (j);
}

char		*ft_content(int fd, int ret)
{
	char	buf[1025];
	char	*s;

	s = ft_strdup("");
	while (ret > 0)
	{
		ret = read(fd, buf, 1024);
		if (ret == -1)
		{
			free(s);
			return (NULL);
		}
		buf[ret] = '\0';
		s = ft_strjoin(s, buf);
		if (!s)
			return (NULL);
	}
	return (s);
}