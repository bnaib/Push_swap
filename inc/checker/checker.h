       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.15 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#ifndef __CHECKER_H
# define __CHECKER_H
# include "class_list.h"
# include "io.h"
# include "ft_printf.h"
# include "libft.h"
# include <unistd.h>
# define GV_FLAGS_DO_COMMAND 1
# define GV_FLAGS_PRINT_COMMAND 2
# define GV_FLAGS_PRINT_STATE 4
# define GV_FLAGS_PRINT_LINES 8
# define GV_FLAGS_PRINT_COLOR 16
# define GV_FLAGS_PRINT_PAUSE 32
# define GV_FLAGS_PRINT_CLS 64
# define GV_FLAGS_PRINT_TOP 128
# define GV_FLAGS_PRINT_HELP 256

typedef enum		e_error_code
{
	EC_OK,
	EC_KO,
	EC_ERROR,
	EC_NOTHING
}					t_error_code;

typedef struct		s_stack_list_content
{
	int				value;
	size_t			index;
}					t_stack_list_content;

typedef struct		s_gv_main
{
	int					argc;
	char				**argv;
}					t_gv_main;

typedef struct		s_global_variables
{
	t_gv_main		main;
	t_istream		*p_istream;
	t_class_list	*p_commands;
	t_class_list	*p_stacks[2];
	int				flags;
	int				print_top_size;
	size_t			max_index;
	char			**split_param;
}					t_global_variables;

typedef struct		s_command_list_content
{
	void			(*command)(t_global_variables *);
}					t_command_list_content;

char				check_space_str(char *str);
void				*copy_stack_list_content(const void *p_content);
void				free_stack_list_content(void *p_content);
void				*copy_command_list_content(const void *p_content);
void				free_command_list_content(void *p_content);
void				load_default(
	t_global_variables *p_gv,
	int argc, char **argv);
void				load_params(t_global_variables *p_gv);
void				load_commands(t_global_variables *p_gv);
void				do_commands(t_global_variables *p_gv);
t_error_code		check_sort(t_global_variables *p_gv);
void				exit_program(t_global_variables *p_gv, t_error_code c);
char				check_atoi(char *str, int *i);
void				print_usage(t_global_variables *p_gv);
void				print_state(t_global_variables *p_gv);
void				cls(t_global_variables *p_gv);
void				print_state_numbers(t_global_variables *p_gv);
void				print_state_lines(t_global_variables *p_gv);
size_t				set_index(t_class_list *p_list);
void				free_split_param(t_global_variables *p_gv);
char				find_in_list(t_class_list *p_list, int value);

void				sa(t_global_variables *p_gv);
void				sb(t_global_variables *p_gv);
void				ss(t_global_variables *p_gv);

void				pa(t_global_variables *p_gv);
void				pb(t_global_variables *p_gv);

void				ra(t_global_variables *p_gv);
void				rb(t_global_variables *p_gv);
void				rr(t_global_variables *p_gv);

void				rra(t_global_variables *p_gv);
void				rrb(t_global_variables *p_gv);
void				rrr(t_global_variables *p_gv);

#endif
