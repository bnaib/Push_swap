       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.18 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "push_swap.h"

static t_bool	move_b_check_double(
	t_global_variables *p_gv,
	t_class_list *p_command_list)
{
	if (p_gv->shift_info.a_direction == p_gv->shift_info.b_direction
		&& p_gv->shift_info.a_elem != p_gv->p_stacks[0]->p_element
		&& p_gv->shift_info.b_elem != p_gv->p_stacks[1]->p_element)
	{
		if (p_gv->shift_info.a_direction == R)
			add_command(p_gv, p_command_list, rr);
		else
			add_command(p_gv, p_command_list, rrr);
		return (true);
	}
	return (false);
}

static void		move_b(
	t_global_variables *p_gv,
	t_class_list *p_command_list)
{
	while (p_gv->shift_info.a_elem != p_gv->p_stacks[0]->p_element
		|| p_gv->shift_info.b_elem != p_gv->p_stacks[1]->p_element)
	{
		if (move_b_check_double(p_gv, p_command_list))
			continue ;
		if (p_gv->shift_info.a_elem != p_gv->p_stacks[0]->p_element)
		{
			if (p_gv->shift_info.a_direction == R)
				add_command(p_gv, p_command_list, ra);
			else
				add_command(p_gv, p_command_list, rra);
		}
		else if (p_gv->shift_info.b_elem != p_gv->p_stacks[1]->p_element)
		{
			if (p_gv->shift_info.b_direction == R)
				add_command(p_gv, p_command_list, rb);
			else
				add_command(p_gv, p_command_list, rrb);
		}
	}
}

void			solve_b(
	t_global_variables *p_gv,
	t_class_list *p_command_list)
{
	load_default_shift_info(p_gv);
	while (p_gv->p_stacks[1]->length > 0)
	{
		p_gv->shift_info.is_set = false;
		opt_direction(p_gv);
		move_b(p_gv, p_command_list);
		add_command(p_gv, p_command_list, pa);
	}
}
