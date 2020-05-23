/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt_utils_three.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: migalvar <migalvar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/22 20:03:27 by migalvar      #+#    #+#                 */
/*   Updated: 2020/05/23 12:43:17 by migalvar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*int			ft_parse_rgb(t_shape *obj, char *lines, int i)
{
	if (obj->type[0] == 'l' || obj->type[0] == 't')

	return (i);
}*/

int			ft_parse_sd(t_shape *obj, char *lines, int i)
{
	i = ft_skip_c(lines, i, ' ');
	if (obj->type[0] == 't' || obj->type[0] == 'p' || obj->type[0] == 'l')
		return (i);
	if (obj->type[0] == 'c' && obj->type[1] != 'y')
		obj->color[0] = ft_simple_atoi(lines, &i, obj->color[0]);
	if (obj->type[0] == 'c' || obj->type[0] == 's')
	{
		if (obj->type[0] == 'c' || obj->type[1] == 'p')
			obj->diam = ft_simple_ftoi(lines, &i, obj->diam);
		i = ft_skip_c(lines, i, ' ');
		if (obj->type[0] == 'c' || obj->type[1] == 'q')
			obj->side = ft_simple_ftoi(lines, &i, obj->side);
	}
	return (i);	
}

int			ft_parse_vector(t_shape *obj, char *lines, int i)
{
	if (obj->type[0] == 'l' || (obj->type[0] == 's' && obj->type[1] == 'p')
							|| obj->type[0] == 't')
		return (i);
	obj->vector[0] = ft_simple_ftoi(lines, &i, obj->vector[0]);
	obj->vector[1] = ft_simple_ftoi(lines, &i, obj->vector[1]);
	obj->vector[2] = ft_simple_ftoi(lines, &i, obj->vector[2]);
	i = ft_skip_c(lines, i, ' ');
	return (i);
}

int			ft_parse_loc(t_shape *obj, char *lines, int i)
{
	obj->loc_cero[0] = ft_simple_ftoi(lines, &i, obj->loc_cero[0]);
	obj->loc_cero[1] = ft_simple_ftoi(lines, &i, obj->loc_cero[1]);
	obj->loc_cero[2] = ft_simple_ftoi(lines, &i, obj->loc_cero[2]);
	i = ft_skip_c(lines, i, ' ');
	if (obj->type[0] == 't')
	{
		obj->loc_one[0] = ft_simple_ftoi(lines, &i, obj->loc_one[0]);
		obj->loc_one[1] = ft_simple_ftoi(lines, &i, obj->loc_one[1]);
		obj->loc_one[2] = ft_simple_ftoi(lines, &i, obj->loc_one[2]);
		i = ft_skip_c(lines, i, ' ');
		obj->loc_two[0] = ft_simple_ftoi(lines, &i, obj->loc_two[0]);
		obj->loc_two[1] = ft_simple_ftoi(lines, &i, obj->loc_two[1]);
		obj->loc_two[2] = ft_simple_ftoi(lines, &i, obj->loc_two[2]);
	}
	return (i);
}

void		ft_parse_obj(char *lines, t_shape *obj)
{
	int		i;

	i = 0;
	i = ft_skip_c(lines, i, ' ');
	obj->type[0] = lines[i];
	i++;
	obj->type[1] = lines[i];
	i++;
	while (lines[i] != '\0')
	{
		i = ft_skip_c(lines, i, ' ');
		i = ft_parse_loc(obj, lines, i);
		i = ft_parse_vector(obj, lines, i);
		i = ft_parse_sd(obj, lines, i);
//		i = ft_parse_rgb(obj, lines, i);
		break ;
	}
}