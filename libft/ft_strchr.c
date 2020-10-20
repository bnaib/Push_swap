       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2019.09.09 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	cc;
	int		i;

	cc = (char)c;
	i = 0;
	while (s[i]
		&& s[i] != cc)
		i++;
	if (s[i] == cc)
		return ((char *)s + i);
	return (NULL);
}
