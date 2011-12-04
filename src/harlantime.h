/*
 * Author: David Mattli
 * Filename: harlantime.h
 * License: ISC
 *
 */



class HarlanTime
{
 public:
  HarlanTime();
  ~HarlanTime();
  bool InitVideo(void);
  void UpdateInput(void);
  void UpdateGameState(void);
  void UpdateVideo(void);
  void GameLoop(void);
  bool go(void);

  

  // Video State
  SDL_Surface *display;
  SDL_Surface *image;
  SDL_Surface *harlan;
  int display_width ;
  int display_height;

  // Input State
  bool right_key;
  bool left_key;
  bool up_key;
  bool down_key;
  bool esc_pressed;

  // Entity State
  int x;
  int y; 

};
