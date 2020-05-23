/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: migalvar <migalvar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/19 15:05:10 by migalvar      #+#    #+#                 */
/*   Updated: 2020/05/20 18:39:04 by migalvar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		ft_pop_sh(t_shape *obj)
{
	int		i;

	i = 0;
	obj->diam = -1;
	obj->side = -1;
	while (i < 3)
	{
		if (i < 2)
			obj->type[i] = 'f';
		obj->loc_cero[i] = -1;
		obj->loc_one[i] = -1;
		obj->loc_two[i] = -1;
		obj->vector[i] = -1;
		obj->color[i] = -1;
	}
}

void		ft_pop(t_env *env, t_shape **obj)
{
	int		i;

	i = 0;
	env->amb = -1;
	env->cam_fov = -1;
	env->light_br = -1;
	while (i < 3)
	{
		if (i < 2)
			env->res[i] = -1;
		env->amb_rgb[i] = -1;
		env->cam[i] = -1;
		env->cam_v[i] = -1;
		env->light[i] = -1;
		env->light_rgb[i] = -1;
		i++;
	}
	i = 0;
	while (i < 256)
	{
		ft_pop_sh(obj[i]);
		i++;
	}
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