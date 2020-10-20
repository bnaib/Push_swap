       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.19 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "io.h"

static void			static_cut_list_to_line(
	t_istream *p_istream,
	char **pp_line,
	size_t str_len)
{
	size_t			i[2];
	t_istream_list	*ptr;

	i[0] = 0;
	ptr = p_istream->last_read_list;
	while (ptr->p_next != p_istream->last_read_list)
	{
		i[1] = -1;
		while (++i[1] < ptr->str_len)
			(*pp_line)[i[0]++] = ptr->str[i[1]];
		ptr = ptr->p_next;
		free(ptr->p_last->str);
		free(ptr->p_last);
	}
	i[1] = -1;
	while (i[0] < str_len)
		(*pp_line)[i[0]++] = ptr->str[++i[1]];
	(*pp_line)[i[0]] = '\0';
	p_istream->last_read_list = ptr;
	p_istream->last_read_list->p_next = p_istream->last_read_list;
	p_istream->last_read_list->p_last = p_istream->last_read_list;
}

static char			static_fix_last(t_istream *p_istream, size_t i)
{
	char			*str;
	size_t			str_size;

	if (i == (size_t)-1 || i == p_istream->last_read_list->str_len - 1)
	{
		free(p_istream->last_read_list->str);
		free(p_istream->last_read_list);
		p_istream->last_read_list = NULL;
		return (0);
	}
	str_size = p_istream->last_read_list->str_len - i;
	if ((str = malloc(sizeof(*str) * str_size)) == NULL)
		return (-1);
	i = str_size;
	while (i-- > 0)
	{
		str[i] = p_istream->last_read_list->
			str[(p_istream->last_read_list->str_len)--];
	}
	free(p_istream->last_read_list->str);
	p_istream->last_read_list->str_len = str_size - 1;
	p_istream->last_read_list->str = str;
	return (0);
}

static size_t		static_get_slash_n_index(const char *str)
{
	size_t			i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (-1);
	return (i);
}

char				get_line_from_last_read_list(
	t_istream *p_istream,
	char **pp_line,
	size_t *p_line_len)
{
	size_t			i;
	t_istream_list	*ptr;

	*p_line_len = 0;
	ptr = p_istream->last_read_list;
	while (ptr->p_next != p_istream->last_read_list)
	{
		*p_line_len += ptr->str_len;
		ptr = ptr->p_next;
	}
	i = static_get_slash_n_index(ptr->str);
	*p_line_len += (i == (size_t)-1) ? ptr->str_len : i;
	if ((*pp_line = malloc(sizeof(**pp_line) * (*p_line_len + 1))) == NULL)
		return (-1);
	static_cut_list_to_line(p_istream, pp_line, *p_line_len);
	if (static_fix_last(p_istream, i))
	{
		free(*pp_line);
		*pp_line = NULL;
		return (-1);
	}
	return (i != (size_t)-1);
}
