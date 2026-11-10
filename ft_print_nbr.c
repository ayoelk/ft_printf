/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelkadi <ayelkadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 09:44:13 by ayelkadi          #+#    #+#             */
/*   Updated: 2026/11/10 09:45:58 by ayelkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_str(char *s)
{
    int j;
	if (s == NULL)
    	s = "(null)";
	j = 0;
	
	while(s[j])
	{
		write(1,&s[j],1);
		j++;
	}
	return(j);
}

int ft_print_nbr(int n)
{
	long int	res;
	char c;
	int count;

	count = 0;
	res = n;
	if (res < 0)
	{
		write(1,"-",1);
		res = -res;
		count ++;
	}
	if (res <= 9)
	{
		c = (res + '0');
		write(1,&c,1);
		count ++;
	}
	else
	{
		count = count + ft_print_nbr(res / 10);
		count = count + ft_print_nbr(res % 10);
	}
	return(count);
}

int ft_print_unbr(unsigned int n)
{
	char c;
	int count;

	count = 0;
	
	if (n <= 9)
	{
		c = (n + '0');
		write(1,&c,1);
		count ++;
	}
	else
	{
		count = count + ft_print_unbr(n / 10);
		count = count + ft_print_unbr(n% 10);
	}
	return(count);
}