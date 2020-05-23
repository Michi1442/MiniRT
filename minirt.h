/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: migalvar <migalvar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/18 19:59:35 by migalvar      #+#    #+#                 */
/*   Updated: 2020/05/18 19:59:35 by migalvar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINIRT_H
# define _MINIRT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>

typedef	struct		s_env//Ambience settings
{
	int				res[2];

	double			amb;
	int				amb_rgb[3];

}					t_env;

typedef struct		s_shape
{
	char			type[3];

	double			loc_cero[3];
	double			loc_one[3];
	double			loc_two[3];

	double			diam;
	double			side;

	double			vector[3];

	int				color[3];

	struct s_shape	*next;
}					t_shape;

int					ft_parse_loc(t_shape *obj, char *lines, int i);
void				ft_parse_obj(char *lines, t_shape *obj);

double				ft_simple_ftoi(char *s, int *j, double n);
int					ft_simple_atoi(char *s, int *j, int n);
void				ft_parse_env(char **lines, t_env *env);
t_shape				*ft_pop_newsh(t_shape *obj, int c, int i);
t_shape				*ft_pop(t_env *env, t_shape *obj, int c);

int					ft_read_rt(t_env *env, t_shape *obj, int fd);

void				print_structs(t_env *env, t_shape *obj);//TO REMOVE!!

int					ft_skip_n(char *s, int i);
int					ft_check_c(char *s, int i, int *j, char c);
int					ft_check_n(char *s, int i);
int					ft_check_res(char *s, int i);
int					ft_check_s(char *s, int i, int *j);

t_shape				*ft_info(char **lines, t_shape *obj, t_env *env, int i);
int					ft_cpy_line(char *s, int i, char **lines, int *j);
void				ft_cut(char **lines, char *content);
int					ft_check_and_count(char *s, int i, int j);
char				*ft_content(int fd, int ret);

int					ft_skip_c(char *s, int i, char c);
void				*ft_free(char **lines);
size_t				ft_strlen(char *s);
char				*ft_strdup(char *s);
char				*ft_strjoin(char *s, char *s1);

#endif
