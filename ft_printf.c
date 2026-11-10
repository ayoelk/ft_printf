/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelkadi <ayelkadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 13:28:24 by ayelkadi          #+#    #+#             */
/*   Updated: 2026/11/10 09:46:11 by ayelkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

  # include <stdarg.h>    
  # include <unistd.h> 
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

int	ft_print_char(int c)
{
	char	ch;

	ch = c;
	write(1, &ch, 1);
	return (1);
}

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