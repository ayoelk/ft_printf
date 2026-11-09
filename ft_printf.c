/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelkadi <ayelkadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 13:28:24 by ayelkadi          #+#    #+#             */
/*   Updated: 2026/11/09 17:30:45 by ayelkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

  # include <stdarg.h>    
  # include <unistd.h>  
  
  int ft_print_str(char *s)
{
    int j;
	
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
  
int ft_printf(const char *pr, ...)
{
	int i;
	int compt;
	va_list args;
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
			else if(pr[i + 1] == 'X'|| pr[i + 1] == 'x' )  
			{
			
			}
			else if(pr[i + 1] == 'p')
			{
				
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