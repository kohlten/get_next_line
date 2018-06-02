#include "dynamic_array.h"
#include "libft.h"
#include <stdio.h>

int main()
{
	t_arr *arr = create_arr();


	for (int i = 0; i < 10000; i++)
	{
		append_mul("tttttt", arr);
		printf("overall: %lu, length: %lu\n", arr->overall, arr->length);
	}
	printf("%s\n", arr->data);
	free_arr(arr);
	return 0;
}