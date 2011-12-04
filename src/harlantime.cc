/*
 * Author: David Mattli
 * Filename: harlantime.cc
 * License: ISC
 *
 */

#include <cstdio>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "harlantime.h"

HarlanTime::HarlanTime()
{
  SDL_Init(SDL_INIT_VIDEO);

  display = NULL;
  image = NULL;
  display_width = 640;
  display_height = 480;

  right_key = left_key = up_key = down_key = false;

  x = display_width/2;
  y = display_height/2;

  return;

}

HarlanTime::~HarlanTime()
{

}

bool HarlanTime::InitVideo(void)
{
  display = SDL_SetVideoMode(display_width, display_height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  image = SDL_CreateRGBSurface(SDL_SWSURFACE, display_width, display_height, 32, 0, 0, 0, 0);
  harlan = IMG_Load("src/harlan.png");

  return true;
}

void HarlanTime::UpdateInput(void)
{
  SDL_Event event;

  while (SDL_PollEvent( &event )) { // Loops until there are no more events
    switch (event.key.keysym.sym)
    {
      case SDLK_LEFT:
        left_key = !left_key;
        break;
      case SDLK_RIGHT:
        right_key = !right_key;
        break;
      case SDLK_UP:
        up_key = !up_key;
        break;
      case SDLK_DOWN:
        down_key = !down_key;
        break;
      case SDLK_ESCAPE:
        esc_pressed = true;
        break;
      default:
        break;
    }

  }

  return;
}

void HarlanTime::UpdateGameState(void)
{
  if (right_key) 
  {
    x += 1;
  } else if (left_key) {
    x -= 1;
  }

  if (up_key)
  {
    y -= 1;
  } else if (down_key) {
    y += 1; 
  }

  return;
}

void HarlanTime::UpdateVideo(void)
{

  SDL_Rect pos;

  pos.x = x;
  pos.y = y;
  int ret = SDL_BlitSurface(image, NULL, display, NULL);
      ret += SDL_BlitSurface(harlan, NULL, display, &pos);

  if (ret != 0) {
    printf("Problem blitting surface!\n");
    esc_pressed = true;
  }

  SDL_Flip(display);


  return;
}

void HarlanTime::GameLoop(void)
{
  while(!esc_pressed) {
    UpdateInput();
    UpdateGameState();
    UpdateVideo();
  }


}

bool HarlanTime::go(void)
{

  InitVideo();

  if (display == NULL || image == NULL || harlan == NULL) {
    fprintf(stderr, "Surface error!\n");
    return false;
  } else {
    GameLoop();
  }

    return true;
}

int main(void)
{
  HarlanTime game;

  game.go();

  return 0;
}

