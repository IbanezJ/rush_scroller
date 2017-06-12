/*
** init_functions.c for rush in /home/ibanez_j/parallax
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Sun Apr  2 00:45:21 2017 Jean-Alexandre IBANEZ
** Last update Mon Apr 24 22:07:36 2017 Jean-Alexandre IBANEZ
*/

#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "parallax.h"

sfTexture	**init_textures(sfTexture **textures)
{
  if ((textures = malloc(sizeof(sfTexture*) * 8)) == NULL)
    return (NULL);
  if ((textures[GROUND] = sfTexture_createFromFile("images/lunarground.png",
						   NULL)) == NULL ||
      (textures[BACK] = sfTexture_createFromFile("images/pattern.png",
						 NULL)) == NULL ||
      (textures[EARTH] = sfTexture_createFromFile("images/deathsat.png",
						  NULL)) == NULL ||
      (textures[SHIP] = sfTexture_createFromFile("images/xwing.png",
						 NULL)) == NULL ||
      (textures[LFIRE] = sfTexture_createFromFile("images/little_fire.png",
						  NULL)) == NULL ||
      (textures[LASER] = sfTexture_createFromFile("images/greenlaser.png",
						  NULL)) == NULL ||
      (textures[PAUSE] = sfTexture_createFromFile("images/pause-button.png",
						  NULL)) == NULL ||
      (textures[TAKE] = sfTexture_createFromFile("images/take.png",
						 NULL)) == NULL)
    return (NULL);
  textures[8] = NULL;
  return (textures);
}

sfSprite	**init_sprites(sfSprite **sprites, sfTexture **textures)
{
  int	i;

  i = GROUND;
  if ((sprites = malloc(sizeof(sfSprite*) * (12 + 1))) == NULL)
    return (NULL);
  while (i <= TAKE)
    {
      sprites[i] = sfSprite_create();
      i++;
    }
  sprites[12] = NULL;
  i = 0;
  while (i <= TAKE)
    {
      sfSprite_setTexture(sprites[i], textures[i], sfTrue);
      i++;
    }
  if ((sprites[LFIRE2] = sfSprite_copy(sprites[LFIRE])) == NULL ||
      (sprites[LASER2] = sfSprite_copy(sprites[LASER])) == NULL ||
      (sprites[GROUND2] = sfSprite_copy(sprites[GROUND])) == NULL ||
      (sprites[BACK2] = sfSprite_copy(sprites[BACK])) == NULL)
    return (NULL);
  return (sprites);
}

sfVector2f	*init_puts(sfVector2f *puts)
{
  if ((puts = malloc(sizeof(sfVector2f) * 11)) == NULL)
    return (NULL);
  puts[0].x = SCREEN_WIDTH + 200;
  puts[0].y = SCREEN_HEIGHT;
  puts[1].x = 0;
  puts[1].y = SCREEN_HEIGHT - 377;
  puts[2].x = 60;
  puts[2].y = SCREEN_HEIGHT / 2 - 100;
  puts[3].x = -1;
  puts[3].y = -1;
  puts[4].x = -10;
  puts[4].y = SCREEN_HEIGHT / 2 - 20;
  puts[5].x = SCREEN_WIDTH;
  puts[5].y = 0;
  puts[6].x = -10;
  puts[6].y = SCREEN_HEIGHT / 2 - 83;
  puts[7] = puts[5];
  puts[8].x = 100;
  puts[8].y = SCREEN_HEIGHT - 100;
  puts[9].x = SCREEN_WIDTH;
  puts[9].y = SCREEN_HEIGHT;
  puts[10].x = -84;
  puts[10].y = -84;
  return (puts);
}

void	initial_pos(sfSprite **sprites, sfVector2f *puts, sfVector2f *set)
{
  sfSprite_setPosition(sprites[EARTH], puts[0]);
  sfSprite_setPosition(sprites[GROUND], puts[1]);
  sfSprite_setPosition(sprites[SHIP], puts[2]);
  sfSprite_setPosition(sprites[BACK2], set[0]);
  sfSprite_setPosition(sprites[GROUND2], set[1]);
  sfSprite_setPosition(sprites[LFIRE], puts[4]);
  sfSprite_setPosition(sprites[LFIRE2], puts[6]);
  sfSprite_setPosition(sprites[LASER], puts[5]);
  sfSprite_setPosition(sprites[LASER2], puts[7]);
  sfSprite_setPosition(sprites[PAUSE], puts[8]);
  sfSprite_setPosition(sprites[TAKE], puts[9]);
}
