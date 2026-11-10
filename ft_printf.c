/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelkadi <ayelkadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 13:28:24 by ayelkadi          #+#    #+#             */
/*   Updated: 2026/11/10 10:50:23 by ayelkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_format(const char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 's')
		count = ft_print_str(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count = ft_print_nbr(va_arg(args, int));
	else if (c == 'u')
		count = ft_print_unbr(va_arg(args, unsigned int));
	else if (c == 'x')
		count = ft_print_hex(va_arg(args, unsigned int));
	else if (c == 'X')
		count = ft_print_hex_maj(va_arg(args, unsigned int));
	else if (c == 'p')
		count = ft_print_ptr(va_arg(args, unsigned long));
	else if (c == 'c')
		count = ft_print_char(va_arg(args, int));
	else if (c == '%')
		count = ft_print_char('%');
	return (count);
}

int	ft_printf(const char *pr, ...)
{
	int		i;
	int		count;
	va_list	args;
	
	i = 0;
	count = 0;
	va_start(args, pr);
	while (pr[i])
	{
		if (pr[i] == '%')
		{
			count = count + ft_format(pr[i + 1], args);
			i++;
		}
		else
		{
			write(1, &pr[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
