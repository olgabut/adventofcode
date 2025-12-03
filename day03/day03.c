#include "day03.h"


int main()
{
	char	*str;
	int		fd;
	int i;
	int first;
	int second;
	int cur;
	long long int sum;

	fd = open("input.txt", O_RDWR);
	if (fd == -1)
		return (1);
	sum = 0;
	while (str != NULL)
	{
		str = get_next_line(fd);
		if (!str)
			break;
		printf("----------\n%s\n", str);
		i = 2;
		first = str[0] - 48;
		second = str[1] - 48;
		while (i < strlen(str))
		{
			cur = str[i] - 48;
			// printf("cur num = %d\n", first * 10 + second);
			// printf("pot num = %d\n", second * 10 + cur);
			if ((first * 10 + cur) > second * 10 + cur)
			{
				if ((first * 10 + second) < (first * 10 + cur))
				{
					second = (str[i] - 48);
				}
			}
			else
			{
				if ((first * 10 + second) < (second * 10 + cur))
				{
					first = second;
					second = (str[i] - 48);
				}
			}
			i++;
		}
		sum += first * 10 + second;
		printf("first = %d\n", first);
		printf("second = %d\n", second);
	}
	printf("sum = %lld\n", sum);
	close(fd);
	return (0);
}