       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.16 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "push_swap.h"

static void	check_param(t_global_variables *p_gv, char *str)
{
	if (str[0] == '-')
	{
		if (str[1] == 'v' && str[2] == '\0'
			&& !(p_gv->flags & GV_FLAGS_PRINT_STATE))
			p_gv->flags |= GV_FLAGS_PRINT_STATE;
		else if (str[1] == 'l' && str[2] == '\0'
			&& !(p_gv->flags & GV_FLAGS_PRINT_LINES))
			p_gv->flags |= GV_FLAGS_PRINT_LINES;
		else if (str[1] == 'c' && str[2] == '\0'
			&& !(p_gv->flags & GV_FLAGS_PRINT_COLOR))
			p_gv->flags |= GV_FLAGS_PRINT_COLOR;
		else if (str[1] == 'p' && str[2] == '\0'
			&& !(p_gv->flags & GV_FLAGS_PRINT_PAUSE))
			p_gv->flags |= GV_FLAGS_PRINT_PAUSE;
		else if (str[1] == 'c' && str[2] == 'l' && str[3] == 's' &&
			str[4] == '\0' && !(p_gv->flags & GV_FLAGS_PRINT_CLS))
			p_gv->flags |= GV_FLAGS_PRINT_CLS;
		else if (str[1] == 'h' && str[2] == '\0'
			&& !(p_gv->flags & GV_FLAGS_PRINT_HELP))
			p_gv->flags |= GV_FLAGS_PRINT_HELP;
		else
			exit_program(p_gv, EC_ERROR);
		return ;
	}
	exit_program(p_gv, EC_ERROR);
}

static char	check_param_top(t_global_variables *p_gv, char *str)
{
	if (str[0] == '-' && str[1] == 't' && str[2] == 'o' && str[3] == 'p'
		&& !(p_gv->flags & GV_FLAGS_PRINT_TOP))
	{
		if (!check_atoi(&(str[4]), &(p_gv->print_top_size)))
			exit_program(p_gv, EC_ERROR);
		if (p_gv->print_top_size < 1)
			exit_program(p_gv, EC_ERROR);
		p_gv->flags |= GV_FLAGS_PRINT_TOP;
		return (1);
	}
	return (0);
}

static void	fix_param(t_global_variables *p_gv)
{
	if ((p_gv->flags & GV_FLAGS_PRINT_STATE)
		&& (p_gv->flags & GV_FLAGS_PRINT_LINES))
		exit_program(p_gv, EC_ERROR);
	if (((p_gv->flags & GV_FLAGS_PRINT_COLOR)
			|| (p_gv->flags & GV_FLAGS_PRINT_PAUSE)
			|| (p_gv->flags & GV_FLAGS_PRINT_CLS)
			|| (p_gv->flags & GV_FLAGS_PRINT_TOP))
		&& !((p_gv->flags & GV_FLAGS_PRINT_STATE)
			|| (p_gv->flags & GV_FLAGS_PRINT_LINES)))
		exit_program(p_gv, EC_ERROR);
}

static void	load_splited_params(t_global_variables *p_gv, char *str)
{
	size_t					st;
	t_stack_list_content	content;

	content.index = 0;
	content.norm_position = false;
	if ((p_gv->split_param = ft_strsplit(str, ' ')) == NULL)
		exit_program(p_gv, EC_ERROR);
	st = (size_t)-1;
	while (p_gv->split_param[++st] != NULL)
	{
		if (check_atoi(p_gv->split_param[st], &(content.value)))
		{
			if (find_in_list(p_gv->p_stacks[0], content.value))
				exit_program(p_gv, EC_ERROR);
			if (class_list_create_element_to_end(
				p_gv->p_stacks[0], &content) == NULL)
				exit_program(p_gv, EC_ERROR);
			continue ;
		}
		if (!check_param_top(p_gv, p_gv->split_param[st]))
			check_param(p_gv, p_gv->split_param[st]);
	}
	free_split_param(p_gv);
}

void		load_params(t_global_variables *p_gv)
{
	int						i;

	i = 0;
	while (++i < p_gv->main.argc)
		load_splited_params(p_gv, p_gv->main.argv[i]);
	fix_param(p_gv);
}
