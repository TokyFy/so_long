/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:52:00 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/23 13:38:43 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"
#include "engime.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


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

int valid_map_line(char *str)
{
  while (*str) {
    if(!(*str == '0' || *str == '1' || *str == 'C' || *str == 'P' || *str == 'E' || *str == '\n'))
      return 0;
    str++;
  }

  return 1;
}

int valid_wall(int **table , int width , int heigh)
{
  int i = 0;
  int j = 0;
  while(i < heigh)
  {
    j = 0;
    while (j < width) {
      if((i == 0 || i == heigh - 1) && table[i][j] != 1)
      {
        return 0;
      }
      else 
      {
        if((j == 0 || j == width - 1) && table[i][j] != 1)
          return 0;
      }
      j++;
    }
    i++;
  }

  return 1;
}

void print2darray(int rows, int cols, int **array) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void reachable_by_player(int x , int y , int **arr)
{
    if(arr[y][x] == 1 || arr[y][x] < 0)
        return;

    arr[y][x] -= 9;

    reachable_by_player(x , y - 1 , arr);
    reachable_by_player(x , y + 1 , arr);
    reachable_by_player(x - 1 , y , arr);
    reachable_by_player(x +  1 , y , arr);
}

int is_all_reachable( int rows , int cols , int **array )
{
    int i = 0;
    int j = 0;

    while(i < rows)
    {
        j = 0;
        while(j < cols)
        {
            if(array[i][j] > 1)
                return 0;

            if(array[i][j] < 0)
            {
                array[i][j] += 9;
            }
            j++;
        }
        i++;
    }
    return 1;
}


int have_only_one_player_exit(int row , int cols , int **array)
{
   int i = 0;
   int j = 0;
  
   int p = 0;
   int e = 0;

   while(i < row)
    {
        j = 0;
        while(j < cols)
        {
          if(array[i][j] == 3)
            e++;

          if(array[i][j] == 4)
            p++;

          j++;
        }
        i++;
  }

  return (p == 1 && e > 0);
}

int have_at_least_one_collectible(int row , int col , int **array)
{
   int i = 0;
   int j = 0;
  
   while(i < row)
    {
        j = 0;
        while(j < col)
        {
          if(array[i][j] == 2)
            return 1;
          j++;
        }
        i++;
  }
  
  return 0;
}

int valid_route(int **table , int width , int heigh)
{
  int p_x = 0;
  int p_y = 0;
  int i = 0;
  int j = 0;

  if(!have_only_one_player_exit(heigh, width, table)
    || !have_at_least_one_collectible(heigh , width , table))
    return 0;


  while(i < heigh)
  {
        j = 0;
        while(j < width)
        {
          if(table[i][j] == 4)
          {
            p_x = j;
            p_y = i;
            break;
          }
          j++;
        }
      i++;
  }
  reachable_by_player(p_x, p_y, table);
  return is_all_reachable(heigh, width , table);
}

int validate_table(int ***table , int width , int heigh)
{
  int error = 0;

  if(width == heigh)
    error = 1;

  if(!valid_wall(*table, width,heigh))
    error = 1;

  if(!valid_route(*table, width, heigh))
    error = 1;
  
  if(error)
  {
    write(1, "Map error !\n", 11);
    free_2d_int(*table, heigh);
    *table = NULL;
  }
  return error;
}

int ** fill_map_from_ber(t_list* line , int width , int heigh)
{
    int w = 0;
    int h = 0;
    t_list *lst = line;
    int **table = ft_calloc(sizeof(int*) , heigh);
    while(h < heigh)
    {
        table[h] = ft_calloc(sizeof(int) , width);
        w = 0;
        while(w < width)
        {
            fill_ceil(&table[h][w] , ((char*)(line->content))[w]);
            w++;
        }
        line = line->next;
        h++;
    }
    ft_lstclear(&lst, free);
    validate_table(&table , width , heigh);
    return table;
}

int ** ber_file_parser(char *path , int *w , int *h)
{
    int fd = open(path , O_RDONLY);
    t_list *line = NULL;
    char *str = NULL;
    int error = 0;

    if(fd == -1)
    {
      error = 1;
      write(2, "Map not fount\n", 14);
      return NULL;
    }

    *w = 0;
    *h = 0;

    while(line == NULL || str != NULL)
    {
        str = get_next_line(fd);
        if(*w == 0)
            *w = ft_strlen(str);

        if(str && *w != ft_strlen(str))
          error = 1;

        if(str && !valid_map_line(str))
          error = 1;

        (*h)++;
        ft_lstadd_back(&line , ft_lstnew(str));
    }
    (*w)--;
    (*h)--;
    
    if(error)
    {
      write(2, "Map error", 9);
      ft_lstclear(&line, free);
      return NULL;
    }

    close(fd);
    return fill_map_from_ber(line , *w ,*h);
}


