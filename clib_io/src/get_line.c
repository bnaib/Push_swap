       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.19 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "io.h"

static char			static_add_buffer_to_list(
	t_istream *p_istream,
	size_t str_len)
{
	t_istream_list	*el;
	char			*buffer;

	if ((el = malloc(sizeof(*el))) == NULL)
		return (-1);
	if ((buffer = malloc(p_istream->buffer_size)) == NULL)
	{
		free(el);
		return (-1);
	}
	el->str = p_istream->buffer;
	el->str_len = str_len;
	p_istream->buffer = buffer;
	if (p_istream->last_read_list == NULL)
	{
		p_istream->last_read_list = el;
		el->p_next = el;
		el->p_last = el;
		return (0);
	}
	el->p_last = p_istream->last_read_list->p_last;
	p_istream->last_read_list->p_last->p_next = el;
	el->p_next = p_istream->last_read_list;
	p_istream->last_read_list->p_last = el;
	return (0);
}

static size_t		static_read_next_buffer(
	t_istream *p_istream)
{
	size_t			str_len;

	str_len = read(p_istream->fd, p_istream->buffer, p_istream->buffer_len);
	if (str_len == 0 || str_len == (size_t)-1)
		return (str_len);
	p_istream->buffer[str_len] = '\0';
	if (static_add_buffer_to_list(p_istream, str_len))
		return (-1);
	return (str_len);
}

static char			static_check_slash_n(
	const char *str)
{
	while (*str != '\0' && *str != '\n')
		str++;
	return (*str == '\n');
}

char				get_line(
	t_istream *p_istream,
	char **pp_line,
	size_t *p_line_len)
{
	*pp_line = NULL;
	if (p_istream->last_read_list == NULL)
	{
		*p_line_len = static_read_next_buffer(p_istream);
		if (*p_line_len == 0 || *p_line_len == (size_t)-1)
			return (*p_line_len);
	}
	while (!static_check_slash_n(p_istream->last_read_list->p_last->str))
	{
		*p_line_len = static_read_next_buffer(p_istream);
		if (*p_line_len == 0)
			break ;
		if (*p_line_len == (size_t)-1)
			return (-1);
	}
	return (get_line_from_last_read_list(p_istream, pp_line, p_line_len));
}
