/* Zajcev Yurij, 27.08.2021 */

#ifndef __POINT_SOURCE_H_
#define __POINT_SOURCE_H_

#include <cmath>
#include <iostream>
#include "rt.h"
#include "vec.h"

namespace zyrt {
    class point_source : public light_source { // point light sources
    private:
        vec position;
    public:
        point_source(vec p) : position(p) {
            mat = vec(1, 1, 1);
        }

        virtual vec destination(const vec &point) override {
            return (position - point).normalize();
        }
    };
}

#endif



