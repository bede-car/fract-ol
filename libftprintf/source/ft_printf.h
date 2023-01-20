/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:07:23 by bede-car          #+#    #+#             */
/*   Updated: 2022/09/27 19:07:54 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_check_specifier(char format, va_list arguments);
int		print_character(va_list arguments);
int		print_string(va_list arguments);
int		print_pointer_adress(va_list arguments);
int		print_signed_decimal_integer(va_list arguments);
int		print_unsigned_decimal_integer(va_list arguments);
int		print_unsigned_hexadecimal_integer(va_list arguments, char format);
char	*ft_uitoa(unsigned int n);
char	*ft_hitoa(unsigned int n);
char	*ft_pitoa(unsigned long int n);

#endif