       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.19 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_printf.h"

int				calculate_wstrlen(wchar_t *lst, int max, int flag)
{
	size_t res[3];

	res[2] = -1;
	res[0] = 0;
	while (lst[++res[2]] != '\0')
	{
		res[1] = res[0];
		if (lst[res[2]] >= 0 && lst[res[2]] < 0x80)
			res[0] += 1;
		else if (lst[res[2]] >= 0x80 && lst[res[2]] < 0x800)
			res[0] += 2;
		else if (lst[res[2]] >= 0x800 && lst[res[2]] < 0x10000)
			res[0] += 3;
		else if (lst[res[2]] >= 0x10000 && lst[res[2]] < 0x200000)
			res[0] += 4;
		else if (lst[res[2]] >= 0x200000 && lst[res[2]] < 0x4000000)
			res[0] += 5;
		else if (lst[res[2]] >= 0x4000000 && lst[res[2]] < (wchar_t)0x80000000)
			res[0] += 6;
		else
			return (0);
		if (res[0] > (size_t)max && flag)
			return (res[1]);
	}
	return (res[0]);
}

static int		convert_utf32_to_utf8_1(wchar_t wc_utf32, char **utf8, int pos)
{
	(*utf8)[pos] = (char)(wc_utf32);
	return (1);
}

static int		convert_utf32_to_utf8_2(
					unsigned char *uc,
					char **utf8,
					int i,
					int pos)
{
	int		i1;
	char	c;

	c = 0;
	i1 = pos - 1;
	while (++i1 < i + pos)
	{
		(*utf8)[i1] = uc[(i + pos) - 1 - i1] | 0x80;
		c = (c >> 1) | 0x80;
	}
	(*utf8)[pos] |= c;
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

int				convert_utf32_to_utf8_str(t_format_list_el *lst)
{
	unsigned char	uc[7];
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	while (j < lst->str_size)
	{
		convert_utf32_to_utf8_set_ui(lst->param.ls[i], uc);
		if (lst->param.ls[i] >= 0 && lst->param.ls[i] < 0x80)
			j += convert_utf32_to_utf8_1(lst->param.ls[i], &lst->str, j);
		convert_utf32_to_utf8_set_ui(lst->param.ls[i], uc);
		if (lst->param.ls[i] >= 0x80 && lst->param.ls[i] < 0x800)
			j += convert_utf32_to_utf8_2(uc, &lst->str, 2, j);
		if (lst->param.ls[i] >= 0x800 && lst->param.ls[i] < 0x10000)
			j += convert_utf32_to_utf8_2(uc, &lst->str, 3, j);
		if (lst->param.ls[i] >= 0x10000 && lst->param.ls[i] < 0x200000)
			j += convert_utf32_to_utf8_2(uc, &lst->str, 4, j);
		if (lst->param.ls[i] >= 0x200000 && lst->param.ls[i] < 0x4000000)
			j += convert_utf32_to_utf8_2(uc, &lst->str, 5, j);
		if (lst->param.ls[i] >= 0x4000000 && lst->param.ls[i] < (wchar_t)U6)
			j += convert_utf32_to_utf8_2(uc, &lst->str, 6, j);
		i++;
	}
	return (0);
}
