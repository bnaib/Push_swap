       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2019.09.09 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		sn;
	size_t		i;

	sn = ft_strlen(needle);
	if (!sn)
		return ((char *)haystack);
	if (!len)
		return (NULL);
	i = 0;
	while (haystack[i] && i <= len - sn)
	{
		if (ft_strnequ(haystack + i, needle, sn))
		{
			if (len < sn)
				return (NULL);
			else
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
