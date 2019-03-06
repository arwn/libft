#include <libft.h>
#include <stdarg.h>

char	*ft_strvcat(char *s, ...)
{
	va_list	vargs;
	char	*a;

	va_start(vargs, s);
	while((a = va_arg(vargs, char*)))
		s = ft_strcat(s, a);
	return (s);
}
