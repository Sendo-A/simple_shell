#include "shell.h"

/**
 * _memcpy - Copies n bytes from memory area src to memory area dest
 * @dest: Pointer to the destination array where the content is to be copied
 * @src: Pointer to the source of data to be copied
 * @n: Number of bytes to be copied
 * Return: Pointer to the destination array
*/

void *_memcpy(void *dest, const void *src, int n)
{
	int i;
	char *dest_copy;
	char *src_copy;

	dest_copy = (char *)dest;
	src_copy = (char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		dest_copy[i] = src_copy[i];
		i++;
	}
	return (dest);
}

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to the memory previously allocated
 * @old_size: Size of the allocated space for `ptr`
 * @new_size: New size of the memory block to allocate
 *
 * Return: Pointer to the newly allocated memory block, or NULL if failed
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new;

	if ((new_size == 0) && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
	{
		new = malloc(new_size);
		if (!new)
			return (NULL);
		return (new);
	}
	if (new_size == old_size)
		return (ptr);
	new = malloc(new_size);
	if (!new)
		return (NULL);
	if (new_size > old_size)
		_memcpy(new, ptr, old_size);
	else
		_memcpy(new, ptr, new_size);
	free(ptr);
	return (new);
}
