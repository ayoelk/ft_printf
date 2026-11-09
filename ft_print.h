/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelkadi <ayelkadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 13:29:55 by ayelkadi          #+#    #+#             */
/*   Updated: 2026/11/09 13:29:56 by ayelkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *pr, ...);
int	ft_format(const char c, va_list args);
int	ft_print_char(int c);
int	ft_print_str(char *s);
int	ft_print_nbr(int n);
int	ft_print_unbr(unsigned int n);
int	ft_print_hex(unsigned int n);
int	ft_print_hex_maj(unsigned int n);
int	ft_print_hex_void(unsigned long n);
int	ft_print_ptr(unsigned long n);

#endif