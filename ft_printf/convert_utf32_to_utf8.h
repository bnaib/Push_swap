       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.09 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#ifndef __CONVERT_UTF32_TO_UTF8_H
# define __CONVERT_UTF32_TO_UTF8_H
# include <stdlib.h>
# include <wchar.h>

typedef union			u_utf32
{
	wchar_t				wc;
	struct
	{
		unsigned int	a : 6;
		unsigned int	b : 6;
		unsigned int	c : 6;
		unsigned int	d : 6;
		unsigned int	e : 6;
		unsigned int	f : 1;
		unsigned int	g : 1;
	}					utf32;
}						t_utf32;

int						convert_utf32_to_utf8(
							wchar_t wc_utf32,
							char **utf8);

#endif
