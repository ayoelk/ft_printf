/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelkadi <ayelkadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 13:28:24 by ayelkadi          #+#    #+#             */
/*   Updated: 2026/11/10 09:52:13 by ayelkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

  # include <stdarg.h>    
  # include <unistd.h> 
  #include "ft_printf.h" 
  
  

int ft_printf(const char *pr, ...)
{
	int i;
	int compt;
	va_list args;
	unsigned long onearg;
	char c;
	
	i = 0;
	compt = 0;
	va_start(args, pr);
	while(pr[i])
	{
		
		if(pr[i] == '%')
		{
			if(pr[i + 1] == 's')
			{

				compt = compt + ft_print_str(va_arg(args, char *));
    			i++; 
			}
			else if(pr[i + 1] == 'd' || pr[i + 1] == 'i')
			{
				compt = compt + ft_print_nbr(va_arg(args,int));
    			i++; 
			}
			else if(pr[i + 1] == 'x')  
			{
				compt = compt + ft_print_hex(va_arg(args,unsigned int));
    			i++; 
			}
			else if(pr[i + 1] == 'X')
			{
				compt = compt + ft_print_hex_maj(va_arg(args,unsigned int));
    			i++; 	
			}
			else if(pr[i + 1] == 'p')
			{
				onearg = va_arg(args,unsigned  long);
				if( onearg== 0)
				{
					compt = compt + ft_print_str("(nil)");
				}
				else
				{
					write(1, "0", 1);
					write(1, "x", 1);
					compt = compt + 2;
					compt = compt + ft_print_hex_void(onearg);
				}
				i++;
			}
			
			else if(pr[i + 1] == 'u')
			{
				compt = compt + ft_print_unbr(va_arg(args, unsigned int));
    			i++;	
			}
			else if(pr[i + 1] == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);         
				compt++;
				i++;
			}
			else if(pr[i + 1] == '%')
			{
				write(1, "%", 1);
				i++;
				compt++;				
			}
		}
		else
		{
			write(1, &pr[i], 1);
			compt++;
		}
		i++;
	}
	va_end(args);
	return (compt);
}