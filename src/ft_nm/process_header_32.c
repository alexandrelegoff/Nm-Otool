/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_header_32.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 13:34:07 by ale-goff          #+#    #+#             */
/*   Updated: 2019/06/25 21:48:15 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

extern int g_idx;
extern int g_fat;
extern int g_archive;

void		process_header_32(t_map *file, t_arch *arch,
			struct mach_header *header)
{
	uint32_t				i;
	struct load_command		*lc;
	uint32_t				val;

	i = -1;
	val = should_swap_32(arch, header->ncmds);
	lc = (void *)file->ptr + sizeof(struct mach_header);
	if (file->mul_files && !g_fat && !g_archive)
		print_file(file->file[g_idx++]);
	while (++i < val)
	{
		if (should_swap_32(arch, lc->cmd) == LC_SEGMENT)
			parse_segment_32((struct segment_command *)lc, arch, file);
		else if (should_swap_32(arch, lc->cmd) == LC_SYMTAB)
			parse_symbol_32((struct symtab_command *)lc, file, arch);
		lc = (void *)lc + should_swap_32(arch, lc->cmdsize);
		error_out_of_memory(file, lc);
	}
}
