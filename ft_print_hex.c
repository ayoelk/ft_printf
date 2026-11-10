/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelkadi <ayelkadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 09:44:10 by ayelkadi          #+#    #+#             */
/*   Updated: 2026/11/10 10:18:54 by ayelkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int ft_print_hex(unsigned int n)
{
	char c;
	char *hex;
	int count;

	count = 0;
	hex = "0123456789abcdef";
	
	if (n <= 15)
	{
		c = hex[n];
		write(1,&c,1);
		count ++;
	}
	else
	{
		count = count + ft_print_hex(n / 16);
		count = count + ft_print_hex(n % 16);
	}
	return(count);
}
int ft_print_hex_maj(unsigned int n)
{
	char c;
	char *hex;
	int count;

	count = 0;
	hex = "0123456789ABCDEF";
	
	if (n <= 15)
	{
		c = hex[n];
		write(1,&c,1);
		count ++;
	}
	else
	{
		count = count + ft_print_hex_maj(n / 16);
		count = count + ft_print_hex_maj(n % 16);
	}
	return(count);
}

int ft_print_hex_void(unsigned long n)
{
	char c;
	char *hex;
	int count;

	count = 0;
	hex = "0123456789abcdef";
	

	if (n <= 15)
	{
		c = hex[n];
		write(1,&c,1);
		count ++;
	}
	else
	{
		count = count + ft_print_hex_void(n / 16);
		count = count + ft_print_hex_void(n % 16);
	}
	return(count);
}

int	ft_print_ptr(unsigned long n)
{
	int	count;

	if (n == 0)
		return (ft_print_str("(nil)"));
	write(1, "0x", 2);
	count = 2;
	count = count + ft_print_hex_void(n);
	return (count);
}
