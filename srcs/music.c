/*
** music.c for tekadventure in /home/ibanez_j/parallax
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Fri Apr 21 17:42:54 2017 Jean-Alexandre IBANEZ
** Last update Tue Apr 25 20:45:00 2017 Jean-Alexandre IBANEZ
*/

#include <SFML/Audio.h>
#include "parallax.h"

void	play_music(char *music_name)
{
  sfMusic	*music;

  music = sfMusic_createFromFile(music_name);
  sfMusic_play(music);
  sfMusic_setLoop(music, sfTrue);
}

void	before_loop(sfSprite **sprites, sfVector2f *puts,
		    sfRenderWindow *window, sfVector2f *set)
{
  initial_pos(sprites, puts, set);
  menu_loop(window);
  play_music("throne.ogg");
}
