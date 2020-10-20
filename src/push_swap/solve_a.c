       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.17 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "push_swap.h"

static t_bool	needs_pb(t_global_variables *p_gv)
{
	t_list_element			*p_element;
	t_stack_list_content	*p_content;
	size_t					i;

	p_element = class_list_get_root(p_gv->p_stacks[0]);
	i = (size_t)-1;
	while (++i < p_gv->p_stacks[0]->length)
	{
		p_content = p_element->p_content;
		if (!(p_content->norm_position))
			return (true);
		p_element = p_element->p_next;
	}
	return (false);
}

static t_bool	needs_sa(
	t_global_variables *p_gv,
	size_t (*norm)(t_class_list *, t_list_element *))
{
	size_t			current_norm_size;

	if (p_gv->p_stacks[0]->length > 1)
	{
		sa(p_gv);
		current_norm_size = norm(p_gv->p_stacks[0], p_gv->p_start_norm);
		sa(p_gv);
		norm(p_gv->p_stacks[0], p_gv->p_start_norm);
		if (current_norm_size > p_gv->norm_size)
			return (true);
	}
	return (false);
}

void			solve_a(
	t_global_variables *p_gv,
	size_t (*norm)(t_class_list *, t_list_element *),
	t_class_list *p_command_list)
{
	t_list_element			*p_element;
	t_stack_list_content	*p_content;

	while (needs_pb(p_gv))
	{
		p_element = class_list_get_root(p_gv->p_stacks[0]);
		p_content = p_element->p_content;
		if (needs_sa(p_gv, norm))
		{
			add_command(p_gv, p_command_list, sa);
			p_gv->norm_size = norm(p_gv->p_stacks[0], p_gv->p_start_norm);
		}
		else if (!p_content->norm_position)
			add_command(p_gv, p_command_list, pb);
		else
			add_command(p_gv, p_command_list, ra);
	}
}
