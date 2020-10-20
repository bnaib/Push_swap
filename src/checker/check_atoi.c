       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.15 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "checker.h"

char		check_atoi(char *str, int *i)
{
	int	sign;

	while (*str != '\0' && ((*str >= '\t' && *str <= '\r') || *str == ' '))
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	*i = 0;
	if (*str < '0' || *str > '9')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		if (*i > 214748364)
			return (0);
		if (sign == 1 && *i == 214748364 && (*str == '9' || *str == '8'))
			return (0);
		if (sign == -1 && *i == 214748364 && *str == '9')
			return (0);
		*i = *i * 10 + (*(str++) - '0');
	}
	*i *= sign;
	return (check_space_str(str));
}
