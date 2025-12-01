
#include "day01.h"

void no_next_line_char(char **origin)
{
	int len = 0;
	char *str;

	str = *origin;
	if (!str)
		return ;
	len = strlen(str);
	if (str[len-1] == '\n')
		str[len-1] = '\0';
	origin = &str;
}

void init_pointers(int *curpoint, int *countpoint)
{
	int i;
	i = 0;
	while (i < 100)
	{
		curpoint[i] = i;
		countpoint[i] = 0;
		i++;
	}
}

void print_count(int *curpoint)
{
	int i;
	i = 0;
	while (i < 100)
	{
		printf("%d - %d\n", i, curpoint[i]);
		i++;
	}
}

int main()
{
	char	*str;
	int		fd;
	int		count_point_to_zero[100];
	int		cur_point[100];
	int		num;
	int		i;

	fd = open("rotations.txt", O_RDWR);
	if (fd == -1)
		return (1);
	init_pointers(cur_point, count_point_to_zero);
	print_count(cur_point);
	while (str != NULL)
	{
		str = get_next_line(fd);
		if (!str)
			break;
		no_next_line_char(&str);
		num = atoi(str + 1);
		i = 0;
		while (i < 100)
		{
			if (str[0] == 'R')
				cur_point[i] += num;
			else
				cur_point[i] -= num;
			if (cur_point[i] % 100 == 0)
				count_point_to_zero[i]++;
			i++;
		}
		
	}
	print_count(count_point_to_zero);
	close(fd);
	return (0);
}

/* part 01
/ make && ./day01 | sort -n | uniq
/ The best result = 1040
/ That's the right answer! You are one gold star closer to decorating the North Pole.
*/
/* part 02
*/