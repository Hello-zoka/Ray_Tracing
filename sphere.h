/* Zajcev Yurij, 11-1, group A, 25.11.2020 */

#ifndef __SPHERE_H_
#define __SPHERE_H_

#include <GLUT/glut.h>
#include <vector>
#include <cmath>
#include <cstdlib>
#include "rt.h"
#include "ray.h"

namespace zyrt {
    class sphere : public shape {
    private:
        dbl r;
        vec pos;
    public:

        const dbl EPS = 0.001;

        sphere(vec pos, dbl r, material mat) : r(r), pos(pos), shape(mat) {}

        dbl Intersect(const ray &R) override {
            double d = (R.Dir & (R.Org - pos)) * (R.Dir & (R.Org - pos)) - ((R.Org - pos) & (R.Org - pos)) + r * r;
            if (d < EPS) return 0;
            dbl t1 = std::max((dbl) 0, (-R.Dir & (R.Org - pos)) + sqrt(d));
            dbl t2 = std::max((dbl) 0, (-R.Dir & (R.Org - pos)) - sqrt(d));
            if (t1 < EPS)
                return t2;
            if (t2 < EPS)
                return t1;
            return std::min(t1, t2);
        }

        vec get_normal(const vec &P) override {
            return (P - pos) / r;
        }
    };
}
#endif // __SPHERE_H_