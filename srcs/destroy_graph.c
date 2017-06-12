/*
** destroy_graph.c for scroller in /home/ibanez_j/parallax
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Sun Apr  2 03:53:09 2017 Jean-Alexandre IBANEZ
** Last update Sun Apr  2 18:28:27 2017 Jean-Alexandre IBANEZ
*/

#include "parallax.h"

void	my_framebuffer_destroy(t_my_framebuffer *framebuffer)
{
  free(framebuffer->pixels);
  free(framebuffer);
}

void	destroying_graph(sfSprite **sprites, sfTexture **textures)
{
  int	i;

  i = 0;
  while (sprites[i] != NULL)
    {
      sfSprite_destroy(sprites[i]);
      i++;
    }
  free(sprites);
  i = 0;
  while (textures[i] != NULL)
    {
      free(textures[i]);
      i++;
    }
  free(textures);
}
