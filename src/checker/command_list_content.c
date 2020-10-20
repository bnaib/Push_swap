       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.15 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "checker.h"

void	*copy_command_list_content(const void *p_content)
{
	t_command_list_content			*p_content_to;
	const t_command_list_content	*p_content_from = p_content;

	if ((p_content_to = malloc(sizeof(*p_content_to))) == NULL)
		return (NULL);
	p_content_to->command = p_content_from->command;
	return (p_content_to);
}

void	free_command_list_content(void *p_content)
{
	free(p_content);
}
