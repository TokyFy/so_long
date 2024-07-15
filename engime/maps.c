#include "../libft/libft.h"
#include "../so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int ** fill_map_from_ber(t_list* line , int width , int heigh)
{
    int w = 0;
    int h = 0;
    int **table = malloc(sizeof(int*) * heigh);
    while(h < heigh)
    {
        table[h] = malloc(sizeof(int) * width);
        w = 0;
        while(w < width)
        {
            table[h][w] = ((char*)(line->content))[w] == '1';
            w++;
        }
        line = line->next;
        h++;
    }

    return table;
}

int ** ber_file_parser(char *path , int *w , int *h)
{
    int fd = open(path , O_RDONLY);
    t_list *line = NULL;
    char *str = NULL;

    *w = 0;
    *h = 0;

    while(line == NULL || str != NULL)
    {
        str = get_next_line(fd);
        if(*w == 0)
            *w = ft_strlen(str);
        (*h)++;
        ft_lstadd_back(&line , ft_lstnew(str));
    }
    (*w)--;
    (*h)--;

    return fill_map_from_ber(line , *w ,*h);
}

void print_arr(int **arr , int w , int h)
{
    int i = 0;
    int j = 0;

    while(i < h)
    {
        j = 0;
        while(j < w)
        {
            printf("%d " , arr[i][j]);
            j++;
        }
        i++;
        printf("\n");
    }
}
