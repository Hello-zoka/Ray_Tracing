/* Zajcev Yurij, 11-1, group A, 25.11.2020 */

#ifndef __RAY_H_
#define __RAY_H_

#include "vec.h"

class ray {
public:
    vec Org, Dir;

    ray() {}

    ray(vec O, vec D) {
        D = D.normalize();
        Org = O;
        Dir = D;
    }

    vec operator()(dbl t) const {
        return Org + Dir * t;
    }
};

#endif // __RAY_H_