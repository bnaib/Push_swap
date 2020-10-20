       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.19 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "io.h"

t_istream			*istream_construct_default(size_t buffer_len)
{
	t_istream		*p_istream;

	if (buffer_len == 0 || buffer_len == (size_t)-1)
		return (NULL);
	if ((p_istream = malloc(sizeof(*p_istream))) == NULL)
		return (NULL);
	p_istream->buffer_len = buffer_len;
	p_istream->buffer_size = buffer_len + 1;
	p_istream->last_read_list = NULL;
	p_istream->fd = 0;
	if ((p_istream->buffer = malloc(p_istream->buffer_size)) != NULL)
		return (p_istream);
	free(p_istream);
	return (NULL);
}

void				istream_destruct(t_istream **pp_istream)
{
	t_istream_list	*ptr;

	if (*pp_istream == NULL)
		return ;
	if ((*pp_istream)->last_read_list != NULL)
	{
		ptr = (*pp_istream)->last_read_list;
		while (ptr->p_next != (*pp_istream)->last_read_list)
		{
			ptr = ptr->p_next;
			free(ptr->p_last->str);
			free(ptr->p_last);
		}
		free(ptr->str);
		free(ptr);
	}
	if ((*pp_istream)->buffer != NULL)
		free((*pp_istream)->buffer);
	free(*pp_istream);
	*pp_istream = NULL;
}
