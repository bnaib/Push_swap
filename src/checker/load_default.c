       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.15 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "checker.h"

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

void		load_default(t_global_variables *p_gv, int argc, char **argv)
{
	p_gv->main.argc = argc;
	p_gv->main.argv = argv;
	p_gv->p_istream = NULL;
	p_gv->p_commands = NULL;
	p_gv->p_stacks[0] = NULL;
	p_gv->p_stacks[1] = NULL;
	p_gv->split_param = NULL;
	p_gv->flags = GV_FLAGS_DO_COMMAND;
	p_gv->max_index = 0;
	if (create_stacks(p_gv))
		exit_program(p_gv, EC_ERROR);
	if ((p_gv->p_istream = istream_construct_default(1024)) == NULL)
		exit_program(p_gv, EC_ERROR);
	if ((p_gv->p_commands = class_list_construct(
		copy_command_list_content, free_command_list_content, NULL)) == NULL)
		exit_program(p_gv, EC_ERROR);
}
