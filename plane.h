/* Zajcev Yurij, 11-1, group A, 14.12.2020 */

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
        vec p, norm;
    public:
        plane(vec norm, const vec p, const material mat) : p(p), norm(norm.normalize()), shape(mat) {}

        dbl Intersect(const ray &R) override {
            if ((norm & R.Dir) == 0)
                return 0;
            return (-(norm & R.Org) + (norm & p)) / (norm & R.Dir);
        }

        vec get_normal(const vec &P) override {
            return norm;
        }
    };
}
#endif // __PLANE_H_