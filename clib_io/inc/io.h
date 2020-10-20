       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.19 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#ifndef __IO_H
# define __IO_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct				s_istream_list
{
	char					*str;
	size_t					str_len;
	struct s_istream_list	*p_last;
	struct s_istream_list	*p_next;
}							t_istream_list;

typedef struct				s_istream
{
	int						fd;
	size_t					buffer_size;
	size_t					buffer_len;
	char					*buffer;
	t_istream_list			*last_read_list;
}							t_istream;

t_istream					*istream_construct_default(size_t buffer_len);
void						istream_destruct(t_istream **pp_istream);
char						get_line_from_last_read_list(
	t_istream *p_istream,
	char **pp_line,
	size_t *p_line_len);
char						get_line(
	t_istream *p_istream,
	char **pp_line,
	size_t *p_line_len);

#endif
