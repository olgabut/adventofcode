
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

// void init_pointers(int *curpoint, int *countpoint)
// {
// 	int i;
// 	i = 0;
// 	while (i < 100)
// 	{
// 		curpoint[i] = i;
// 		countpoint[i] = 0;
// 		i++;
// 	}
// }

// void print_count(int *curpoint)
// {
// 	int i;
// 	i = 0;
// 	while (i < 100)
// 	{
// 		printf("%d - %d\n", i, curpoint[i]);
// 		i++;
// 	}
// }

int main()
{
	char	*str;
	int		fd;
	int		count_point_to_zero;
	int		pass_zero;
	int		cur_point;
	int		prev_point;
	int		num;

	fd = open("rotations.txt", O_RDWR);
	if (fd == -1)
		return (1);
	cur_point = 50;
	count_point_to_zero = 0;
	while (str != NULL)
	{
		str = get_next_line(fd);
		if (!str)
			break;
		no_next_line_char(&str);
		printf("----------\n%s\n", str);
		num = atoi(str + 1);
		pass_zero = 0;
		if (str[0] == 'R')
		{
			printf("cur_point = %d\nnum = %d\n", cur_point, num);
			pass_zero = (int)(cur_point + num) / 100;
			printf("pass_zero = %d\n", pass_zero);
			count_point_to_zero += pass_zero;
			cur_point = cur_point + num - (pass_zero * 100);
			printf("%d\n", cur_point);
		}
		else
		{
			prev_point = cur_point;
			printf("cur_point = %d\nnum = -%d\n", cur_point, num);
			if (cur_point - num < 0)
			{
				pass_zero = 1 - ((int)(cur_point - num) / 100);
				cur_point = cur_point - num + (pass_zero * 100);
			}
			else
				cur_point = cur_point - num;
			if (prev_point == 0)
				pass_zero--;
			if (cur_point == 0)
				pass_zero++;
			count_point_to_zero += pass_zero;
			printf("pass_zero = %d\n", pass_zero);
			printf("%d\n", cur_point);
		}
		// if (cur_point % 100 == 0)
		// 	count_point_to_zero++;

	}
	printf("%d\n", count_point_to_zero);
	close(fd);

	// rest = 0;
	// cur_point = 50;
	// num = 150;
	// printf("%d\n", (cur_point+num) / 100);
	return (0);
}

/* part 01
/ make && ./solution | sort -n | uniq
/ The best result = 1040
/ That's the right answer! You are one gold star closer to decorating the North Pole.
*/
/* part 02
*/