       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.17 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "push_swap.h"

static void		align_a_get_rotation(
	t_global_variables *p_gv,
	t_list_element *p_element[2],
	t_stack_list_content *p_content[2],
	size_t i[3])
{
	p_element[0] = class_list_get_root(p_gv->p_stacks[0]);
	p_element[1] = p_element[0];
	i[0] = 0;
	i[1] = 0;
	i[2] = (size_t)-1;
	while (++(i[2]) < p_gv->p_stacks[0]->length)
	{
		p_content[0] = p_element[0]->p_content;
		p_content[1] = p_element[1]->p_content;
		if (p_content[0]->index == 1 && p_content[1]->index == 1)
			break ;
		if (p_content[0]->index != 1)
		{
			(i[0])++;
			p_element[0] = p_element[0]->p_next;
		}
		if (p_content[1]->index != 1)
		{
			(i[1])++;
			p_element[1] = p_element[1]->p_last;
		}
	}
}

static void		align_a(
	t_global_variables *p_gv,
	t_class_list *p_command_list)
{
	t_list_element			*p_element[2];
	t_stack_list_content	*p_content[2];
	size_t					i[3];

	align_a_get_rotation(p_gv, p_element, p_content, i);
	if (i[0] < i[1])
	{
		while ((i[0])-- > 0)
			add_command(p_gv, p_command_list, ra);
	}
	else
	{
		while ((i[1])-- > 0)
			add_command(p_gv, p_command_list, rra);
	}
}

void			solve(
	t_global_variables *p_gv,
	size_t (*norm)(t_class_list *, t_list_element *),
	t_class_list *p_command_list)
{
	set_norm(p_gv, p_gv->p_stacks[0], norm);
	solve_a(p_gv, norm, p_command_list);
	solve_b(p_gv, p_command_list);
	align_a(p_gv, p_command_list);
}
