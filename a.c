#include "a.h"
#include "m.h"
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// PS(g, mnar) {
//  printf("%d %p %p %p\n", m, s, e, b);
//  printf("%ld\n", e - s);
//}
//
// PE(g, mnar)
// PS(f, mnar) {
//  printf("%d %p %p %p\n", m, s, e, b);
//  printf("%ld\n", e - s);
//}
// PE(f, mnar)
//
void pith(int m, void *s, void *e, void *b) { *((int *)b) += 1; }
int run(void (*nar)(pith_t, void *, void *, void *)) {
  int err = 0;
  nar(pith, 0, 0, &err);
  if (err)
    printf("error\n");
  return err;
}
PS(a, mnar) {
  printf("%d %p %p %p %ld\n", m, s, e, b, e - s);
  SE(frame1,
      P4(float, 1, 1, 1, 1)
      P4(float, 2, 2, 2, 2)
      P4(float, 3, 3, 3, 3)
      P4(float, 4, 4, 4, 4));
  printf("%d %p %p %p %ld\n", m, s, e, b, e - s);
  o(0, frame1[0], frame1[1], b);

  SE(frame2, P(float, 1); P(float, 2); P(float, 3); P(float, 4););
  printf("%d %p %p %p %ld\n", m, s, e, b, e - s);
  o(0, frame2[0], frame2[1], b);
}
PE(a, mnar)
PS(a, aomnar) { printf("%d %p %p %p %ld\n", m, s, e, b, e - s); }
PE(a, aomnar)

// void MultiplyMatrixVector(vec3d &i, vec3d &o, mat4x4 &m)
//	{
//		o.x = i.x * m.m[0][0] + i.y * m.m[1][0] + i.z * m.m[2][0] +
// m.m[3][0]; 		o.y = i.x * m.m[0][1] + i.y * m.m[1][1] + i.z *
// m.m[2][1] +
// m.m[3][1]; 		o.z = i.x * m.m[0][2] + i.y * m.m[1][2] + i.z *
// m.m[2][2] +
// m.m[3][2]; 		float w = i.x * m.m[0][3] + i.y * m.m[1][3] + i.z *
// m.m[2][3] + m.m[3][3]; 		if (w != 0)
//		{
//			o.x /= w; o.y /= w; o.z /= w;
//		}
//	}
N(MultiplyMatrixVector) {
  A4(float, m00, m01, m02, m03)
  A4(float, m10, m11, m12, m13)
  A4(float, m20, m21, m22, m23)
  A4(float, m30, m31, m32, m33)
  A4(float, x, y, z, w)

  printf("%f %f %f %f\n", m00, m01, m02, m03);
  printf("%f %f %f %f\n", m10, m11, m12, m13);
  printf("%f %f %f %f\n", m20, m21, m22, m23);
  printf("%f %f %f %f\n", m30, m31, m32, m33);
  printf("%f %f %f %f\n", x, y, z, w);
  w = x * m03 + y * m13 + z * m23 + m33;
  if (w == 0)
    w = 1;
  SE(frame, P(float, (x * m00 + y * m10 + z * m20 + m30) / w);
     P(float, (x * m01 + y * m11 + z * m21 + m31) / w);
     P(float, (x * m02 + y * m12 + z * m22 + m32) / w); P(float, w););
  {
    void *s = frame[0];
    void *e = frame[1];
    A4(float, x, y, z, w);
    printf("%f %f %f %f\n", x, y, z, w);
  }
  o(0, frame[0], frame[1], b);
}

N(cubemesh) {
  void *r = s;
  P16(float, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1);
  P16(float, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1);
  P16(float, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1);
  P16(float, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1);
  P16(float, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1);
  P16(float, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1);
  P16(float, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1);
  P16(float, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1);
  P16(float, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
  P16(float, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1);
  P16(float, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1);
  P16(float, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1);
  o(0, r, s, b);
}
N(projmat) {
  A(float, fN);  // = 0.1f;
  A(float, fF);  // = 1000;
  A(float, fA);  // = 800 / 600;
  A(float, fVR); // = 1 / tanf(fV * 0.5f / 180 * 3.14159f);
  void *r = s;
  P4(float, fA *fVR, 0, 0, 0);
  P4(float, 0, fVR, 0, 0);
  P4(float, 0, 0, fF / (fF - fN), 1);
  P4(float, 0, 0, (-fF * fN) / (fF - fN), 0);
  o(0, r, s, b);
}
void rpith(int m, void *s, void *e, void *b) {
  void **r = b;
  r[0] = s;
  r[1] = e;
  r[2] = (void *)((int64_t)m);
}
PS(sample1, mnar) {
  P(float, 0.1f);
  P(float, 1000);
  P(float, 800.0f / 600.0f);
  P(float, 1 / tanf(90.0f * 0.5f / 180 * 3.14159f));
  void *r[3] = {0, 0, 0};
  projmat(rpith, s, e, r);
  printf("%p %p %p %ld\n", r[0], r[1], r[2], r[1] - r[0]);
}
PE(sample1, mnar);
int main() {
  run(sample1omnar);
  printf("%d okok\n", 9);
  return 0; // run(gomnar);
}
