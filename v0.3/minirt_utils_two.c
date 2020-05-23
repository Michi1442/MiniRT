/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt_utils_two.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: migalvar <migalvar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/19 20:28:10 by migalvar      #+#    #+#                 */
/*   Updated: 2020/05/22 20:46:31 by migalvar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		ft_simple_ftoi(char *s, int *j, double n)
{
	int		count;

	count = 0;
	n = ft_simple_atoi(s, j, n);
	*j = *j + 1;
	if (n < 0)
	{
		while (s[*j] >= 48 && s[*j] <= 57)
		{
			count++;
			n = n - ((s[*j] - '0')/(pow(10, count)));
			*j = *j + 1;
		}
	}
	else
	{
		while (s[*j] >= 48 && s[*j] <= 57)
		{
			count++;
			n = n + ((s[*j] - '0')/(pow(10, count)));
			*j = *j + 1;
		}
	}
	return (n);
}

int			ft_simple_atoi(char *s, int *j, int n)
{
	int		sign;

	sign = 1;
	*j = ft_skip_c(s, *j, ' ');
	if (s[*j] == '-')
	{
		sign = -1;
		*j = *j + 1;
	}
	while (s[*j] >= 48 && s[*j] <= 57)
	{
		n = (n * 10) + s[*j] - '0';
		*j = *j + 1;
	}
	*j = ft_skip_c(s, *j, ',');
	return (n * sign);
}

void		ft_parse_env(char **lines, t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (lines[i] != NULL)
	{
		j = ft_skip_c(lines[i], 0, ' ');
		if (lines[i][j] == 'R' && env->res[0] == 0)
		{
			j++;
			env->res[0] = ft_simple_atoi(lines[i], &j, env->res[0]);
			env->res[1] = ft_simple_atoi(lines[i], &j, env->res[1]);
		}
		else if (lines[i][j] == 'A' && env->amb == 0)
		{
			j++;
			env->amb = ft_simple_ftoi(lines[i], &j, env->amb);
			env->amb_rgb[0] = ft_simple_atoi(lines[i], &j, env->amb_rgb[0]);
			env->amb_rgb[1] = ft_simple_atoi(lines[i], &j, env->amb_rgb[1]);
			env->amb_rgb[2] = ft_simple_atoi(lines[i], &j, env->amb_rgb[2]);
		}
		j = 0;
		i++;
	}
}

t_shape		*ft_pop_newsh(t_shape *obj, int c, int i)
{
	t_shape	*new;

	new = (t_shape *)malloc(sizeof(t_shape));
	obj->diam = 0;
	obj->side = 0;
	while (i < 3)
	{
		if (i < 2)
			obj->type[i] = 'f';
		obj->loc_cero[i] = 0;
		obj->loc_one[i] = 0;
		obj->loc_two[i] = 0;
		obj->vector[i] = 0;
		obj->color[i] = 0;
		i++;
	}
	obj->type[2] = '\0';
	if (c > 0)
	{
		c--;
		obj->next = ft_pop_newsh(new, c, 0);
	}
	else
		obj->next = NULL;
	return (obj);
}

t_shape		*ft_pop(t_env *env, t_shape *obj, int c)
{
	t_shape	*start;
	int		i;

	i = 0;
	start = obj;
	env->amb = 0;
	while (i < 3)
	{
		if (i < 2)
			env->res[i] = 0;
		env->amb_rgb[i] = 0;
		i++;
	}
	obj = ft_pop_newsh(obj, c, 0);
	return (start);
}
