#include "a.h"
#define AA(t, a, b)                                                            \
  A(t, a);                                                                     \
  A(t, b);
#define AAAA(t, a, b, c, d)                                                    \
  AA(t, a, b);                                                                 \
  AA(t, c, d);
#define AAAAAAAA(t, a, b, c, d, e, f, g, h)                                    \
  AAAA(t, a, b, c, d);                                                         \
  AAAA(t, e, f, g, h);
#define PP(t, a, b)                                                            \
  P(t, a);                                                                     \
  P(t, b);
#define PPPP(t, a, b, c, d)                                                    \
  PP(t, a, b);                                                                 \
  PP(t, c, d);
#define PPPPPPPP(t, a, b, c, d, e, f, g, h)                                    \
  PPPP(t, a, b, c, d);                                                         \
  PPPP(t, e, f, g, h);
//#define S(name, str)                                                           \
//  void name(void (*o)(int, void *, void *, void *), void *s, void *e,          \
//            void *b) {                                                         \
//    const char *i = str;                                                       \
//    size_t *length = s;                                                        \
//    *length = 0;                                                               \
//    while (i[*length] && (char *)s + sizeof *length < (char *)e) {             \
//      *((char *)s + sizeof *length + *length) = i[*length];                    \
//      (*length)++;                                                             \
//    };                                                                         \
//    if (i[*length] == 0)                                                       \
//      o(0, s, (char *)s + sizeof *length + *length, b);                        \
//    else                                                                       \
//      o('S', s, e, b);                                                         \
//  }
#include <SDL.h>
#include <SDL_ttf.h>
#include <stddef.h>
#include <stdio.h>

N(sample1) {
  float fN = 0.1f;
  float fF = 1000.0f;
  float fV = 90.0f;
  float fA = 800.0f / 600.0f;
  float fVR = 1.0f / tanf(fV * 0.5f / 180.0f * 3.14159f);
  PPPP(float, fA * fVR, 0,   0,                      0);
  PPPP(float, 0,        fVR, 0,                      0);
  PPPP(float, 0,        0,   fF / (fF - fN),         1);
  PPPP(float, 0,        0,   (-fF * fN) / (fF - fN), 0);
  PPPP(float, 0,0,0,0);
}
N(go) { C(o, 0, P(const char *, "drawline"); P(int, 320);); }
N(tri) {
  AAAAAAAA(float, xx, xy, yx, yy, zx, zy, wx, wy);
  A(SDL_Renderer *, renderer);
  SDL_RenderDrawLine(renderer, xx + wx, xy + wy, yx + wx, yy + wy);
  SDL_RenderDrawLine(renderer, yx + wx, yy + wy, zx + wx, zy + wy);
  SDL_RenderDrawLine(renderer, zx + wx, zy + wy, xx + wx, xy + wy);
}
N(win) {
  A(int, w);
  A(int, h);
  int err = 0;
  if (TTF_Init() == -1) {
    printf("TTF_Init: %s\n", TTF_GetError());
    exit(2);
  }
  TTF_Font *Sans = TTF_OpenFont("PragmataPro.ttf", 32); // this opens a font style and sets a size
  printf("%p\n", Sans);
  SDL_Color White = {255, 255, 255};
  SDL_Surface *surfaceMessage =
      TTF_RenderUTF8_Solid(Sans, "put ξ your text here", White);

  if (!(err = SDL_Init(SDL_INIT_VIDEO))) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    if (!(err = SDL_CreateWindowAndRenderer(w, h, 0, &window, &renderer))) {
      SDL_bool done = SDL_FALSE;
      printf("b, %p\n", renderer);
      while (!done) {
        SDL_SetRenderDrawColor(renderer, 0, 128, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        SDL_Texture *Message =
            SDL_CreateTextureFromSurface(renderer, surfaceMessage);
        SDL_RenderCopy(renderer, Message, NULL,
                       &((SDL_Rect){.x = 100,
                                    .y = 200,
                                    .w = surfaceMessage->w,
                                    .h = surfaceMessage->h}));
        // Don't forget to free your surface and texture
        for (int i = 0; i < 100; i += 9) {
          for (int j = 0; j < 700; j += 63) {
            SDL_SetRenderDrawColor(renderer, 255 - i % 50, 255 - i,
                                   100 + (j % 155), SDL_ALPHA_OPAQUE);
            C(tri, o, PPPPPPPP(float, 90, 90, 60, 30, 30, 60, i + j, i);
              P(void *, renderer););
          }
        }
        SDL_DestroyTexture(Message);
        SDL_RenderPresent(renderer);
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
          if (event.type == SDL_QUIT) {
            done = SDL_TRUE;
          }
        }
      }
      if (renderer)
        SDL_DestroyRenderer(renderer);
      if (window)
        SDL_DestroyWindow(window);
    } else
      o(err, s, e, b);
    SDL_Quit();
  } else
    o(err, s, e, b);

  SDL_FreeSurface(surfaceMessage);
}
#include "m.h"
PS(g, mnar) {
  printf("1\n");
  C(win, o, P(int, 800); P(int, 600););
  printf("2\n");
}
PE(g, mnar)
int main(int argc, char *argv[]) {
  int err = 0;
  void *b = &err;
  gomnar(pith, 0, 0, b);
  if (err != 0)
    printf("error\n");
  return err;
  if (TTF_Init() == -1) {
    printf("TTF_Init: %s\n", TTF_GetError());
    exit(2);
  }
  TTF_Font *Sans = TTF_OpenFont("PragmataPro.ttf",
                                28); // this opens a font style and sets a size
  printf("%p\n", Sans);

  if (SDL_Init(SDL_INIT_VIDEO) == 0) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) == 0) {
      SDL_bool done = SDL_FALSE;

      while (!done) {
        SDL_Event event;

        SDL_SetRenderDrawColor(renderer, 0, 128, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(renderer, 320, 200, 300, 240);
        SDL_RenderDrawLine(renderer, 300, 240, 340, 240);
        SDL_RenderDrawLine(renderer, 340, 240, 320, 200);

        SDL_Color White = {
            255, 255,
            255}; // this is the color in rgb format, maxing out all would give
                  // you the color white, and it will be your text's color
        SDL_Surface *surfaceMessage = TTF_RenderUTF8_Solid(
            Sans, "აput your text here",
            White); // as TTF_RenderText_Solid could only be used on SDL_Surface
                    // then you have to create the surface first
        SDL_Texture *Message = SDL_CreateTextureFromSurface(
            renderer, surfaceMessage); // now you can convert it into a texture
        SDL_Rect Message_rect;         // create a rect
        Message_rect.x = 0;            // controls the rect's x coordinate
        Message_rect.y = 0;            // controls the rect's y coordinte
        Message_rect.w = surfaceMessage->w; // controls the width of the rect
        Message_rect.h = surfaceMessage->h; // controls the height of the rect
        // Mind you that (0,0) is on the top left of the window/screen, think a
        // rect as the text's box, that way it would be very simple to
        // understand Now since it's a texture, you have to put RenderCopy in
        // your game loop area, the area where the whole code executes
        SDL_RenderCopy(
            renderer, Message, NULL,
            &Message_rect); // you put the renderer's name first, the Message,
                            // the crop size(you can ignore this if you don't
                            // want to dabble with cropping), and the rect which
                            // is the size and coordinate of your texture
        SDL_RenderCopy(renderer, Message, NULL,
                       &((SDL_Rect){.x = 100,
                                    .y = 100,
                                    .w = surfaceMessage->w,
                                    .h = surfaceMessage->h}));
        SDL_DestroyTexture(Message);
        // END
        SDL_RenderPresent(renderer);
        while (SDL_PollEvent(&event)) {
          if (event.type == SDL_QUIT) {
            done = SDL_TRUE;
          }
        }
      }
    }

    if (renderer) {
      SDL_DestroyRenderer(renderer);
    }
    if (window) {
      SDL_DestroyWindow(window);
    }
  }
  SDL_Quit();
  return 0;
}
