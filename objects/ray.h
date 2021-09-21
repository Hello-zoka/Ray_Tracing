/* Zajcev Yurij, 27.08.2021 */

#ifndef __RAY_H_
#define __RAY_H_

#include "../math_classes/vec.h"

class ray { // class for ray
public:
    vec Org, Dir; // radius-vector of end-point of ray, vector of direction

    ray() {}

    ray(vec O, vec D) {
        D = D.normalize();
        Org = O;
        Dir = D;
    }

    vec operator()(dbl t) const { // getting point in distance t from begin of ray
        return Org + Dir * t;
    }
};

#endif // __RAY_H_