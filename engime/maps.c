#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int **ber_file_parser(char *path)
{
    int fd = open(path , O_RDONLY);
    int width = 0;
    int height = 0;
    t_list *line = NULL;
    char *str = NULL;

    while(line == NULL || str != NULL)
    {
        printf("%s" , str);
        str = get_next_line(fd);
        ft_lstadd_back(&line , ft_lstnew(str));
    }

    return 0;
}

int main()
{
    ber_file_parser("./map.ber");
}