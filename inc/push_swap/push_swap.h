       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.15 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#ifndef __PUSH_SWAP_H
# define __PUSH_SWAP_H
# include "class_list.h"
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
	EC_ERROR
}					t_error_code;

typedef enum		e_bool
{
	false = 0,
	true = 1
}					t_bool;

typedef struct		s_stack_list_content
{
	int				value;
	size_t			index;
	t_bool			norm_position;
}					t_stack_list_content;

typedef struct		s_gv_main
{
	int					argc;
	char				**argv;
}					t_gv_main;

typedef enum
{
	R,
	RR
}	t_direction;

typedef struct		s_shift_info
{
	t_list_element	*a_elem;
	t_list_element	*b_elem;
	t_direction		a_direction;
	t_direction		b_direction;
	size_t			size;
	t_bool			is_set;
}					t_shift_info;

typedef struct		s_global_variables
{
	t_gv_main		main;
	t_class_list	*p_commands[2];
	t_class_list	*p_stacks[3];
	size_t			norm_size;
	t_list_element	*p_start_norm;
	int				flags;
	int				print_top_size;
	t_shift_info	shift_info;
	size_t			max_index;
	char			**split_param;
}					t_global_variables;

typedef struct		s_command_list_content
{
	void			(*command)(t_global_variables *);
}					t_command_list_content;

void				*copy_stack_list_content(const void *p_content);
void				free_stack_list_content(void *p_content);
void				*copy_command_list_content(const void *p_content);
void				free_command_list_content(void *p_content);
void				exit_program(t_global_variables *p_gv, t_error_code c);
void				load_default_shift_info(t_global_variables *p_gv);
void				load_default(
	t_global_variables *p_gv,
	int argc, char **argv);
char				check_space_str(char *str);
char				check_atoi(char *str, int *i);
void				load_params(t_global_variables *p_gv);
size_t				set_index(t_class_list *p_list);
size_t				norm_equally(
	t_class_list *p_list,
	t_list_element *p_element);
size_t				norm_more(t_class_list *p_list, t_list_element *p_element);
void				set_norm(
	t_global_variables *p_gv,
	t_class_list *p_list,
	size_t	(*norm)(t_class_list *, t_list_element *));
void				add_command(
	t_global_variables *p_gv,
	t_class_list *p_command_list,
	void (*command)(t_global_variables *));
void				solve(
	t_global_variables *p_gv,
	size_t (*norm)(t_class_list *, t_list_element *),
	t_class_list *p_command_list);
void				solve_a(
	t_global_variables *p_gv,
	size_t (*norm)(t_class_list *, t_list_element *),
	t_class_list *p_command_list);
void				solve_b(
	t_global_variables *p_gv,
	t_class_list *p_command_list);
void				print_commands(
	t_global_variables *p_gv,
	t_class_list *p_commands);
void				opt_direction(t_global_variables *p_gv);
t_list_element		*find_a_elem(
	t_global_variables *p_gv,
	t_list_element *p_index_el);
void				print_usage(t_global_variables *p_gv);
void				print_state(t_global_variables *p_gv);
void				cls(t_global_variables *p_gv);
void				print_state_numbers(t_global_variables *p_gv);
void				print_state_lines(t_global_variables *p_gv);
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
