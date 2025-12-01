
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
	int		num;
	int i;

	fd = open("rotations.txt", O_RDWR);
	// fd = open("test.txt", O_RDWR);
	if (fd == -1)
		return (1);
	cur_point = 50;
	count_point_to_zero = 0;
	i = 0;
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
			printf("cur_point = %d\nnum = -%d\n", cur_point, num);
			if (cur_point == 0)
				pass_zero = num / 100;
			else
			{
				if (num < cur_point)
					pass_zero = 0;
				else
					pass_zero = (int)((num - cur_point) / 100) + 1;
			}
			cur_point = cur_point - (int)(num % 100);
			if (cur_point < 0)
				cur_point += 100;
			count_point_to_zero += pass_zero;
			printf("pass_zero = %d\n", pass_zero);
			printf("%d\n", cur_point);
		}
		// if (cur_point % 100 == 0)
		// 	count_point_to_zero++;
		printf("count_point_to_zero = %d\n", count_point_to_zero);
		i++;
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
/ The result = 6027
/ That's the right answer! You are one gold star closer to decorating the North Pole.
*/