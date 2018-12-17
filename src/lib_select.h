/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_select.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:56:51 by ttresori          #+#    #+#             */
/*   Updated: 2018/12/17 01:23:27 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_SELECT_H
# define LIB_SELECT_H
# include "../libft/libft.h"
# include <sys/time.h>
# include <termcap.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <termios.h>
# include <dirent.h>
# include <sys/stat.h>

# define ESCAPE	buf[0] == 27 && buf[1] == 0 && buf[2] == 0
# define CTRL_Z buf[0] == 3
# define CTRL_D buf[0] == 4
# define ENTER buf[0] == 10
# define DEL buf[0] == 127
# define SPACE	buf[0] == 32
# define UP	buf[0] == 27 && buf[1] == 91 && buf[2] == 65
# define LEFT	buf[0] == 27 && buf[1] == 91 && buf[2] == 68
# define RIGHT	buf[0] == 27 && buf[1] == 91 && buf[2] == 67
# define DOWN	buf[0] == 27 && buf[1] == 91 && buf[2] == 66

typedef	struct	s_reset
{
	struct termios term;
}				t_reset;

t_reset			g_reset;

typedef struct	s_term
{
	char			*name_term;
	struct termios	term;
}				t_term;

t_term			g_term;

typedef struct	s_file
{
	char		**arg;
	int			nb_arg;
	int			*select;
	int			start_y;
	int			y;
	int			return_keys;
}				t_file;

t_file			g_file;

t_file			*init_file(int argc, char **argv, t_file *s_file);
void			init_term(t_term *s_term, t_reset *s_reset);
void			restore_term(t_reset *s_reset, t_term *s_term);
void			free_struct(t_file *s_file);
void			place_curs(int c, int y);
void			clean_window();
void			moove_up();
void			moove_down(t_file *s_file);
void			save_curs_pos();
void			restore_curs_pos();
void			go_last(t_file *s_file);
void			go_first(t_file *s_file);
void			print_tab_size(t_file *g_file);
int				del_one();
void			clean_line();
void			under_current();
void			clean_current_line();
void			de_under(t_file *s_file);
void			select_arg(t_file *s_file);
void			print_select(t_file *s_file);
void			refresh_select_arg(t_file *s_file);
void			init_signal();
int				key_to_moove(t_file *s_file, char *buf);
int				check_key(t_file *s_file);
int				my_outp(int c);

#endif
