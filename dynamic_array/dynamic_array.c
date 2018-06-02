#include "dynamic_array.h"
#include <stdio.h>

static t_arr *change_size(t_arr *data)
{
	printf("%lu %lu\n", data->overall, data->prev);
	printf("size: %lu\n", sizeof(data->data));
	data->data = ft_realloc(data->data, (data->overall + data->prev * 2) * sizeof(char), data->overall * sizeof(char));
	printf("size: %lu\n", sizeof(data->data));
	if (!data->data)
		return NULL;
	data->prev = data->prev * 2;
	data->overall += data->prev;
	return data;
}

char get_at(unsigned long i, t_arr *data)
{
	if (i < data->length)
		return data->data[i];
	else
		return 0;
}

t_arr *create_arr()
{
	t_arr *new;

	new = ft_memalloc(sizeof(t_arr));
	new->data = ft_memalloc(1);
	new->length = 0;
	new->overall = 1;
	new->prev = 1;
	return new;
}

t_arr *free_arr(t_arr *arr)
{
	free(arr->data);
	free(arr);
	arr = NULL;
	return NULL;
}

char append_one(char new, t_arr *data)
{
	if (data->length + 1 > data->overall - 1)
	{
		ft_putendl("Changing size");
		printf("%d\n", data == NULL);
		data = change_size(data);
		printf("%d\n", data == NULL);
	}
	printf("adding: %c at: %lu with a overall length of: %lu\n", new, data->length, data->overall);
	data->data[data->length] = new;
	data->length += 1;
	return new;
}

char *append_mul(char *new, t_arr *data)
{
	int len;

	len = ft_strlen(new);
	if (data->length + len > data->overall - 1)
	{
		ft_putendl("Changing size");
		printf("%d\n", data == NULL);
		data = change_size(data);
		printf("%d\n", data == NULL);
	}
	printf("adding: %s at: %lu with a overall length of: %lu\n", new, data->length, data->overall);
	data->data = ft_strcat(data->data, new);
	data->length += len;
	return new;
}