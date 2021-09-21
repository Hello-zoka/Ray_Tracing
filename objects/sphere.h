/* Zajcev Yurij, 27.08.2021 */

#ifndef __SPHERE_H_
#define __SPHERE_H_

#include <GLUT/glut.h>
#include <vector>
#include <cmath>
#include <cstdlib>
#include "../tracing/tracing.h"
#include "ray.h"

namespace zyrt {
    class sphere : public shape {
    private:
        dbl r; // radius of sphere
        vec pos; // center of sphere
    public:

        const dbl EPS = 0.0001;

        sphere(const vec pos, const dbl r, const int mat_ind) : r(r), pos(pos), shape(MtlLib[mat_ind]) {}

        dbl Intersect(const ray &R) override { // finding distance between ray's end and intersection's point with sphere
            // F(x, y, z) = (x - C_x) ^ 2 + (y - C_y) ^ 2 + (z - C_z) ^ 2 - r * r = 0
            // (Org + Dir * t - C) ^ 2 - r * r = 0
            // Dir^2 * t^2 + 2 * (Dir & (Org - pos)) * t + (Org - pos) ^ 2 - r * r = 0
            // Then solving simple quadratic equation for t
            double discrim =
                    (R.Dir & (R.Org - pos)) * (R.Dir & (R.Org - pos)) - ((R.Org - pos) & (R.Org - pos)) + r * r;
            if (discrim < EPS) return 0;
            dbl t1 = std::max((dbl) 0, (-R.Dir & (R.Org - pos)) + sqrt(discrim));
            dbl t2 = std::max((dbl) 0, (-R.Dir & (R.Org - pos)) - sqrt(discrim));
            if (t1 < EPS)
                return t2;
            if (t2 < EPS)
                return t1;
            return std::min(t1, t2);
        }

        vec get_normal(const vec &P) override { // getting normal using point on sphere
            return (P - pos) / r;
        }
    };
}
#endif // __SPHERE_H_