/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_oom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 16:29:51 by srichard          #+#    #+#             */
/*   Updated: 2026/10/12 08:53:17 by amguinam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

t_err	*err_oom(t_loc loc)
{
	static t_err	err = {
		.message = (t_string){
		(char*)"could not allocate while constructing error", 43, 0},
		.next = NULL
	};

	err.loc = loc;
	return (&err);
}
