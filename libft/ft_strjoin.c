       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2019.09.09 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1s;
	size_t	s2s;

	if (!s1 || !s2)
		return (NULL);
	s1s = ft_strlen(s1);
	s2s = ft_strlen(s2);
	str = malloc(sizeof(*str) * (s1s + s2s + 1));
	if (!str)
		return (NULL);
	ft_strncpy(str, s1, s1s);
	ft_strncpy(str + s1s, s2, s2s);
	str[s1s + s2s] = 0;
	return (str);
}
