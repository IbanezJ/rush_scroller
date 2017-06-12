/*
** main.c for raytracer1 in /home/ibanez_j/raytracer1
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Mon Mar 13 11:23:55 2017 Jean-Alexandre IBANEZ
** Last update Fri Apr 21 17:35:33 2017 Jean-Alexandre IBANEZ
*/

#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "parallax.h"

int			main()
{
  sfTexture		**textures;
  sfSprite		**sprites;
  sfVideoMode		mode;
  sfRenderWindow*	window;

  textures = NULL;
  sprites = NULL;
  if ((textures = init_textures(textures)) == NULL ||
      (sprites = init_sprites(sprites, textures)) == NULL)
    return (84);
  mode.width = SCREEN_WIDTH;
  mode.height = SCREEN_HEIGHT;
  mode.bitsPerPixel = 32;
  if ((window = sfRenderWindow_create(mode, "webcam video from",
				 sfResize | sfClose, NULL)) == NULL)
    return (84);
  window_loop(window, textures, sprites);
  sfRenderWindow_destroy(window);
  return (0);
}
