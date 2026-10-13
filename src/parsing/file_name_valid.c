/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amguinam <amguinam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 11:28:20 by amguinam          #+#    #+#             */
/*   Updated: 2026/10/03 11:39:04 by ambre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "str.h"

t_err	*file_name_valid(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 5 || str[len - 1] != 'b' || str[len - 2] != 'u'
		|| str[len - 3] != 'c' || str[len - 4] != '.')
		return (err_new_fmt(err_loc(__FILE__, __LINE__),
				"invalid filename: `%s`", str));
	return (NULL);
}
