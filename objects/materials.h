/* Zajcev Yurij, 27.08.2021 */

#ifndef _MATERIALS_H_
#define _MATERIALS_H_

#include "../math_classes/vec.h"

namespace zyrt {
    class material { // class which contains information about material of object
    public:
        const char *name = "";
        vec amb, dif, spec;
        double phi;

        material(const char *new_name, vec amb, vec dif, vec spec, double phi) : name(new_name), amb(amb), dif(dif),
                                                                                 spec(spec), phi(phi) {}
    };

    extern material MtlLib[20];
}


#endif