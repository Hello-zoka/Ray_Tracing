/* Zajcev Yurij, 11-1, group A, 25.11.2020 */

#include "ray.h"
#include "vec.h"
#include "win.h"
#include "frame.h"
#include "sphere.h"
#include "point_source.h"
#include "plane.h"
#include "materials.h"
#include "rt.h"

zyrt::rt zyrt::MainScene;

int main( void ) {
  vec v;
  zyrt::win A;

  zyrt::shape *s = new zyrt::sphere(vec(0.0, 0.0, 0.0), 0.2, zyrt::MtlLib[16]);
  zyrt::shape *s2 = new zyrt::sphere(vec(-0.5, -0.5, 0.0), 0.3, zyrt::MtlLib[2]);
  zyrt::shape *p = new zyrt::plane(vec(0.5, 0.5, -0.15), vec(-1, -1, 0), zyrt::MtlLib[10]);
  zyrt::shape *s3 = new zyrt::sphere(vec(-0.1, 0.25, 0.0), 0.2, zyrt::MtlLib[17]);
  zyrt::point_source *x = new zyrt::point_source(vec(0, 7, 0), vec(1, 1, 1));
  zyrt::point_source *x2 = new zyrt::point_source(vec(1, 1, 1), vec(1, 1, 1));
  zyrt::MainScene << s << s2 << p << x << x2 << s3;
  A.Run();
  return 0;
}
