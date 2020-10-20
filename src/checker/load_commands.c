       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.15 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "checker.h"

static void		load_command_content_2(
	t_command_list_content *p_content,
	char *str)
{
	if (str[0] == 's' && str[1] == 'a')
		p_content->command = sa;
	else if (str[0] == 's' && str[1] == 'b')
		p_content->command = sb;
	else if (str[0] == 's' && str[1] == 's')
		p_content->command = ss;
	else if (str[0] == 'p' && str[1] == 'a')
		p_content->command = pa;
	else if (str[0] == 'p' && str[1] == 'b')
		p_content->command = pb;
	else if (str[0] == 'r' && str[1] == 'a')
		p_content->command = ra;
	else if (str[0] == 'r' && str[1] == 'b')
		p_content->command = rb;
	else if (str[0] == 'r' && str[1] == 'r')
		p_content->command = rr;
}

static void		load_command_content_3(
	t_command_list_content *p_content,
	char *str)
{
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		p_content->command = rra;
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		p_content->command = rrb;
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		p_content->command = rrr;
}

static size_t	load_command_content(
	t_command_list_content *p_content,
	char *str)
{
	p_content->command = NULL;
	if (str[0] != '\0' && str[1] != '\0' && str[2] == '\0')
	{
		load_command_content_2(p_content, str);
		if (p_content->command != NULL)
			return (2);
		return (0);
	}
	if (str[0] != '\0' && str[1] != '\0' && str[2] != '\0' && str[3] == '\0')
	{
		load_command_content_3(p_content, str);
		if (p_content->command != NULL)
			return (3);
		return (0);
	}
	return (0);
}

static char		load_command(t_global_variables *p_gv, char *str)
{
	t_command_list_content	content;

	str += load_command_content(&content, str);
	if (content.command == NULL)
		return (-1);
	if (class_list_create_element_to_end(
		p_gv->p_commands, &content) == NULL)
		return (-1);
	return (!check_space_str(str));
}

void			load_commands(t_global_variables *p_gv)
{
	size_t	st;
	char	*p_str;
	char	r;

	while ((r = get_line(p_gv->p_istream, &p_str, &st) > 0) && p_str != NULL)
	{
		if (load_command(p_gv, p_str))
		{
			free(p_str);
			exit_program(p_gv, EC_ERROR);
		}
		free(p_str);
	}
	if (r == -1)
		exit_program(p_gv, EC_ERROR);
	if (p_str != NULL)
	{
		free(p_str);
		exit_program(p_gv, EC_ERROR);
	}
}
