/* Zajcev Yurij, 27.08.2021 */


#include "vec.h"
#include "win.h"
#include "sphere.h"
#include "point_source.h"
#include "plane.h"
#include "rt.h"

/* !!!!!!!!!!!!!!!
 * MATERIALS LIST:
 * 0) Black Plastic
 * 1) Brass
 * 2) Bronze
 * 3) Chrome
 * 4) Copper
 * 5) Gold
 * 6) Peweter
 * 7) Silver
 * 8) Polished Silver
 * 9) Turquoise
 * 10) Ruby
 * 11) Polished Gold
 * 12) Polished Bronze
 * 13) Polished Copper
 * 14) Jade
 * 15) Obsidian
 * 16) Pearl
 * 17) Emerald
 * 18) Black Plastic
 * 19) Black Rubber
*/

zyrt::rt zyrt::MainScene; // Making scene for our objects

int main() {
    zyrt::win A; // Making window for scene

    // Making objects:
    //    Spheres:
    // coordinates of center radius, number of material
    zyrt::shape *s = new zyrt::sphere(vec(0.0, 0.0, 0.0), 0.2, 16); // Pearl
    zyrt::shape *s2 = new zyrt::sphere(vec(-0.5, -0.5, 0.0), 0.3, 2); // Bronze
    zyrt::shape *s3 = new zyrt::sphere(vec(-0.1, 0.25, 0.0), 0.2, 17); // Emerald
    //    Planes:
    // coordinates of point in plane, normal-vector, number of material
    zyrt::shape *p = new zyrt::plane(vec(0.5, 0.5, -0.15), vec(-1, -1, 0), 10); // Ruby
    //    Point light sources
    // coordinates of source
    zyrt::point_source *x = new zyrt::point_source(vec(0, 7, 0));
    zyrt::point_source *x2 = new zyrt::point_source(vec(1, 1, 1));

    zyrt::MainScene << s << s2 << p << x << x2 << s3; // inserting objects into scene
    A.Run(); // running ray tracing
    return 0;
}
