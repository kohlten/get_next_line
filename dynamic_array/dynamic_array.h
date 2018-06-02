#ifndef DYNAMIC_ARRAY_H
# define DYNAMIC_ARRAY_H
# include "libft.h"

typedef struct	s_arr
{
	char			*data;
	unsigned long	length;
	unsigned long 	overall;
	unsigned long	prev;
}				t_arr;

char append_one(char new, t_arr *data);
char *append_mul(char *new, t_arr *data);
char get_at(unsigned long i, t_arr *data);
t_arr *free_arr(t_arr *arr);
t_arr *create_arr();

#endif