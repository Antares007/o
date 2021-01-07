#include "a.h"
//#include <GL/gl.h>
//#include <SDL2/SDL.h>
//#include <stdio.h>

// N(window) {
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
//  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
//  SDL_GL_CONTEXT_PROFILE_CORE); SDL_GLContext *context =
//  SDL_GL_CreateContext(window); if (context == 0) {
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
#include <stdio.h>
#include <stdlib.h>
static void *cf() { return malloc(4); };
static void *cg() { return malloc(4); };
static void *ch() { return malloc(4); };
static void df(void *p) { free(p); };
static void dg(void *p) { free(p); };
static void dh(void *p) { free(p); };
static N(f) {
  void *p = cf();
  if (p == 0)
    o(-1, s, e, b);
  void *start = s;
  P(void *, p);
  o(0, start, e, b);
  df(p);
}
NPS(g, f, {
  void *start = s;
  A(void *, pp);
  void *p = cg();
  if (p == 0)
    o(-1, s, e, b);
  P(void *, p);
  o(0, start, e, b);
  dg(p);
})
PS(h, gof) {
  void *start = s;
  A(void *, p1);
  A(void *, p2);
  void *p = ch();
  if (p == 0)
    o(-1, s, e, b);
  P(void *, p);
  o(0, start, e, b);
  dh(p);
}
PE(h, gof)
PS(m, hogof) {
  A(void *, p1);
  A(void *, p2);
  A(void *, p3);

  printf("%p %p %p\n", p1, p2, p3);
  P4(void *, p1, p2, p3, 0);
  o(4, s, e, b);
}
PE(m, hogof)
static void pith(int m, void *s, void *e, void *b) { *((int *)b) += 1; }
int main() {
  void *m = malloc(1024);
  void *s = m;
  void *e = s + 1024;
  int err = 0;
  mohogof(pith, s, e, &err);
  return err;
}
