#ifndef DAY03_H
# define DAY03_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"

char	*get_next_line(int fd);

#endif