/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:16:37 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/05 20:01:51 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

#ifdef DEBUG

static t_mem_info	*memoryInformation = NULL;
static int			atexitCalled = 0;

static t_mem_info	*dbg_add_mem_info(t_mem_info *memoryInfo, void *ptrToReturn,
		size_t bytes, int line, const char *filename, const char *functionname)
{
	t_mem_info	*new_mem_info;

	new_mem_info = (t_mem_info *)malloc(sizeof(t_mem_info));
	if (new_mem_info == NULL)
		unix_error("Malloc error");
	new_mem_info->ptr = ptrToReturn;
	new_mem_info->bytes = bytes;
	new_mem_info->line = line;
	new_mem_info->filename = filename;
	new_mem_info->functionname = functionname;
	new_mem_info->next = memoryInfo;
	new_mem_info->prev = NULL;
	if (memoryInformation)
		memoryInformation->prev = new_mem_info;
	return (new_mem_info);
}

static int	search_mem_list(const char *filename, int line)
{
	t_mem_info	*tmp;
	int			counter;
	size_t		len;

	tmp = memoryInformation;
	counter = 0;
	len = strlen(filename);
	while (tmp)
	{
		if (len == strlen(tmp->filename))
		{
			if (!memcmp(filename, tmp->filename, len) && tmp->line == line)
				return (counter);
		}
		tmp = tmp->next;
		counter++;
	}
	return (-1);
}

static void	edit_info(int elemPos, size_t bytes)
{
	int			counter;
	t_mem_info	*tmp;

	counter = 0;
	tmp = memoryInformation;
	while (counter != elemPos)
	{
		tmp = tmp->next;
		counter++;
	}
	tmp->bytes += bytes;
}

void	*ft_malloc(t_reserve reserve)
{
	void	*ptrToReturn;
	int		pos;

	pos = 0;
	ptrToReturn = malloc(reserve.bytes);
	if (!ptrToReturn)
		return (NULL);
	if (!atexitCalled)
	{
		atexit(ft_leaks);
		atexitCalled = 1;
	}
	pos = search_mem_list(reserve.file, reserve.line);
	if (pos == -1)
	{
		memoryInformation = dbg_add_mem_info(memoryInformation,
												ptrToReturn,
												reserve.bytes,
												reserve.line,
												reserve.file,
												reserve.func);
		if (!memoryInformation)
		{
			free(ptrToReturn);
			return (NULL);
		}
	}
	else
		edit_info(pos, reserve.bytes);
	return (ptrToReturn);
}

void	ft_free(void *ptrToFree)
{
	t_mem_info	*tmp;
	t_mem_info	*toFree;
	t_mem_info	*prev;

	tmp = memoryInformation;
	toFree = NULL;
	prev = NULL;
	if (tmp->ptr == ptrToFree)
	{
		toFree = tmp;
		memoryInformation = tmp->next;
		free(toFree->ptr);
		free(toFree);
		if (memoryInformation)
			memoryInformation->prev = NULL;
		return ;
	}
	while (tmp)
	{
		if (tmp->ptr == ptrToFree)
		{
			toFree = tmp;
			tmp = tmp->next;
			prev = toFree->prev;
			if (prev)
				prev->next = tmp;
			if (tmp)
				tmp->prev = prev;
			free(toFree->ptr);
			if (toFree == memoryInformation)
				memoryInformation = NULL;
			free(toFree);
			return ;
		}
		tmp = tmp->next;
	}
}

void	ft_leaks(void)
{
	t_mem_info	*tmp;
	t_mem_info	*prev;
	size_t		sum;
	int			nbBlocks;

	tmp = memoryInformation;
	prev = NULL;
	sum = 0;
	nbBlocks = 0;
	if (tmp)
		printf("Memory Leaks detected.\n");
	while (tmp)
	{
		prev = tmp;
		printf("\n%ld bytes lost\n", tmp->bytes);
		printf("address : 0x%p in %s\t%s:%d\n",
				tmp->ptr,
				tmp->functionname,
				tmp->filename,
				tmp->line);
		printf("\n====================================\n");
		sum += tmp->bytes;
		tmp = tmp->next;
		free(prev);
		nbBlocks++;
	}
	printf("SUMMARY :\n%ld bytes lost in %d blocks\n", sum, nbBlocks);
}

#else

void	*ft_malloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (p == NULL)
		unix_error("Malloc error");
	return (p);
}

void	ft_free(void *ptr)
{
	free(ptr);
}

#endif
