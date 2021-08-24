#ifndef _MATERIALS_H_
#define _MATERIALS_H_

#include "vec.h"


namespace zyrt
{
    class material
    {
    public:
        const char *name = "";
        vec amb, dif, spec;
        double phi;
        material(const char *new_name, vec a, vec b, vec c, double d) : name(new_name), amb(a), dif(b), spec(c), phi(d)
        {}
    };

    extern material MtlLib[20];

}


#endif