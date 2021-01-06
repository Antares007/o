#include "SDL_error.h"
#include "SDL_video.h"
#include "a.h"
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <stdio.h>

//N(window) {
//  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
//    return o(-1, s, e, b);
//  SDL_Window *window =
//      SDL_CreateWindow("title", SDL_WINDOWPOS_UNDEFINED,
//                       SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_OPENGL);
//  if (window == 0) {
//    SDL_Quit();
//    return o(-1, s, e, b);
//  }
//  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
//  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
//  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
//  SDL_GLContext *context = SDL_GL_CreateContext(window);
//  if (context == 0) {
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//    return o(-1, s, e, b);
//  }
//  void *start = s;
//  P(int, 'ptr') P(int, 2) P(void *, window) P(void *, context) o(0, s, e, b);
//  o(0,start,e,b);
//  SDL_GL_DeleteContext(context);
//  SDL_DestroyWindow(window);
//  SDL_Quit();
//}
void* cf();
void* cg();
void* ch();
void df(void*);
void dg(void*);
void dh(void*);
N(f){
  void* p = cf();
  if(p==0) o(-1,s,e,b); 
  void *start = s;
  P(void*, p);
  o(0,start,e,b);
  df(p);
}

int main() { return 0; }
