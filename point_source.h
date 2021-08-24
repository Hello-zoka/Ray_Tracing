/* Zajcev Yurij, 11-1, 23.12.2020 */
#ifndef __POINT_SOURCE_H_
#define __POINT_SOURCE_H_

#include <cmath>
#include <iostream>
#include "rt.h"
#include "vec.h"

namespace zyrt {
    class point_source : public light_source {
    private:
        vec position;
    public:
        point_source(vec p, vec h) : position(p) {
            mat = h;
        }

        virtual vec destination(const vec &point) override {
            return (position - point).normalize();
        }
    };
}

#endif



