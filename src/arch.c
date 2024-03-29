/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arch.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 22:26:02 by ale-goff          #+#    #+#             */
/*   Updated: 2019/06/24 15:21:17 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

uint8_t		is_valid_magic(uint32_t x, char *ptr)
{
	return (IS_BIG_OBJ(x) || IS_FAT_BIG(x) || IS_FAT_LITTLE(x)
		|| IS_64_FAT(x) || IS_64_OBJ(x) || IS_ARCHIVE(ptr) || IS_32_OBJ(x));
}
