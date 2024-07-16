/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:52:00 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/16 12:10:01 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


void fill_ceil(int *ceil , char content) {
    if(content == '1')
        *ceil = 1;
    else if(content == 'C')
        *ceil = 2;
    else if(content == 'E')
        *ceil = 3;
    else if(content == 'P')
        *ceil = 4;
}

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
            fill_ceil(&table[h][w] , ((char*)(line->content))[w]);
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

