       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.09 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_printf.h"

static int		convert_utf32_to_utf8_1(wchar_t wc_utf32, char **utf8)
{
	if ((*utf8 = malloc(sizeof(**utf8))) == NULL)
		return (0);
	(*utf8)[0] = (char)(wc_utf32);
	return (1);
}

static int		convert_utf32_to_utf8_2(
					unsigned char *uc,
					char **utf8,
					int i)
{
	int		i1;
	char	c;

	if ((*utf8 = malloc(sizeof(**utf8) * i)) == NULL)
		return (0);
	c = 0;
	i1 = -1;
	while (++i1 < i)
	{
		(*utf8)[i1] = uc[i - 1 - i1] | 0x80;
		c = (c >> 1) | 0x80;
	}
	(*utf8)[0] |= c;
	return (i);
}

static void		convert_utf32_to_utf8_set_ui(
					wchar_t wc_utf32,
					unsigned char *uc)
{
	t_utf32	t32;

	t32.wc = wc_utf32;
	uc[0] = t32.utf32.a;
	uc[1] = t32.utf32.b;
	uc[2] = t32.utf32.c;
	uc[3] = t32.utf32.d;
	uc[4] = t32.utf32.e;
	uc[5] = t32.utf32.f;
	uc[6] = t32.utf32.g;
}

int				convert_utf32_to_utf8(wchar_t wc_utf32, char **utf8)
{
	unsigned char	uc[7];

	if (wc_utf32 >= 0 && wc_utf32 < 0x80)
		return (convert_utf32_to_utf8_1(wc_utf32, utf8));
	convert_utf32_to_utf8_set_ui(wc_utf32, uc);
	if (wc_utf32 >= 0x80 && wc_utf32 < 0x800)
		return (convert_utf32_to_utf8_2(uc, utf8, 2));
	if (wc_utf32 >= 0x800 && wc_utf32 < 0x10000)
		return (convert_utf32_to_utf8_2(uc, utf8, 3));
	if (wc_utf32 >= 0x10000 && wc_utf32 < 0x200000)
		return (convert_utf32_to_utf8_2(uc, utf8, 4));
	if (wc_utf32 >= 0x200000 && wc_utf32 < 0x4000000)
		return (convert_utf32_to_utf8_2(uc, utf8, 5));
	if (wc_utf32 >= 0x4000000 && wc_utf32 < (wchar_t)0x80000000)
		return (convert_utf32_to_utf8_2(uc, utf8, 6));
	return (0);
}
