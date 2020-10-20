       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.16 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "push_swap.h"

static char	create_stacks(t_global_variables *p_gv)
{
	if ((p_gv->p_stacks[0] = class_list_construct(
		copy_stack_list_content, free_stack_list_content, NULL)) == NULL)
		return (-1);
	if ((p_gv->p_stacks[1] = class_list_construct(
		copy_stack_list_content, free_stack_list_content, NULL)) == NULL)
		return (-1);
	return (0);
}

static char	create_command_lists(t_global_variables *p_gv)
{
	if ((p_gv->p_commands[0] = class_list_construct(
		copy_command_list_content, free_command_list_content, NULL)) == NULL)
		return (-1);
	if ((p_gv->p_commands[1] = class_list_construct(
		copy_command_list_content, free_command_list_content, NULL)) == NULL)
		return (-1);
	return (0);
}

void		load_default_shift_info(t_global_variables *p_gv)
{
	p_gv->shift_info.a_elem = NULL;
	p_gv->shift_info.b_elem = NULL;
	p_gv->shift_info.a_direction = R;
	p_gv->shift_info.b_direction = R;
	p_gv->shift_info.size = 0;
	p_gv->shift_info.is_set = false;
}

void		load_default(t_global_variables *p_gv, int argc, char **argv)
{
	p_gv->main.argc = argc;
	p_gv->main.argv = argv;
	p_gv->p_commands[0] = NULL;
	p_gv->p_commands[1] = NULL;
	p_gv->p_stacks[0] = NULL;
	p_gv->p_stacks[1] = NULL;
	p_gv->p_stacks[2] = NULL;
	p_gv->norm_size = 0;
	p_gv->p_start_norm = NULL;
	p_gv->flags = GV_FLAGS_DO_COMMAND;
	p_gv->max_index = 0;
	load_default_shift_info(p_gv);
	if (create_stacks(p_gv))
		exit_program(p_gv, EC_ERROR);
	if (create_command_lists(p_gv))
		exit_program(p_gv, EC_ERROR);
}
