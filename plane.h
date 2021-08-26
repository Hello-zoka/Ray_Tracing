/* Zajcev Yurij, 11-1, group A, 14.12.2020 */
/* Zajcev Yurij, 27.08.2021 */

#ifndef __PLANE_H_
#define __PLANE_H_

#include <GLUT/glut.h>
#include <vector>
#include <cmath>
#include <cstdlib>
#include "rt.h"
#include "ray.h"

namespace zyrt {
    class plane : public shape {
    private:
        vec p, norm; // point in plane, normal to this plane
    public:
        plane(vec norm, const vec p, const int mat_ind) : p(p), norm(norm.normalize()), shape(MtlLib[mat_ind]) {}

        dbl Intersect(const ray &R) override { // finding distance between ray's end and intersection's point with plane
            if ((norm & R.Dir) == 0) // no intersection
                return 0;
            return (-(norm & R.Org) + (norm & p)) / (norm & R.Dir);
            // substitute in the equation of the plane the point of the ray at the distance that we are looking for
            // F(x, y, z) = Ax + By + Cz + D = 0
            // A(O_x + D_x * t) + B(O_y + D_y * t) + C(O_z + D_z * t) + D = 0
            // t = -(A*O_x + B*O_y + C*O_z + D) / (A*D_x + B*D_y + C*D_z)
        }

        vec get_normal(const vec &P) override { // getting normal
            return norm;
        }
    };
}

#endif // __PLANE_H_