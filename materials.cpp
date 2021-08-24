#include "materials.h"

namespace zyrt{
    material MtlLib[20] =
            {
                    /* 00 */ material("Black Plastic", vec(0.0, 0.0, 0.0),             vec(0.01, 0.01, 0.01),           vec(0.5, 0.5, 0.5),               32),
                    /* 01 */ material("Brass",         vec(0.329412,0.223529,0.027451), vec(0.780392,0.568627,0.113725), vec(0.992157,0.941176,0.807843), 27.8974),
                    /* 02 */ material("Bronze",        vec(0.2125,0.1275,0.054),       vec(0.714,0.4284,0.18144),       vec(0.393548,0.271906,0.166721),  25.6),
                    /* 03 */ material("Chrome",        vec(0.25, 0.25, 0.25),          vec(0.4, 0.4, 0.4),              vec(0.774597, 0.774597, 0.774597), 76.8),
                    /* 04 */ material("Copper",        vec(0.19125,0.0735,0.0225),     vec(0.7038,0.27048,0.0828),      vec(0.256777,0.137622,0.086014),  12.8),
                    /* 05 */ material("Gold",          vec(0.24725,0.1995,0.0745),     vec(0.75164,0.60648,0.22648),    vec(0.628281,0.555802,0.366065),  51.2),
                    /* 06 */ material("Peweter",       vec(0.10588,0.058824,0.113725), vec(0.427451,0.470588,0.541176), vec(0.3333,0.3333,0.521569),      9.84615),
                    /* 07 */ material("Silver",        vec(0.19225,0.19225,0.19225),   vec(0.50754,0.50754,0.50754),    vec(0.508273,0.508273,0.508273),  51.2),
                    /* 08 */ material("Polished Silver", vec(0.23125,0.23125,0.23125), vec(0.2775,0.2775,0.2775),       vec(0.773911,0.773911,0.773911),  89.6),
                    /* 09 */ material("Turquoise",     vec(0.1, 0.18725, 0.1745),      vec(0.396, 0.74151, 0.69102),    vec(0.297254, 0.30829, 0.306678), 12.8),
                    /* 10 */ material("Ruby",          vec(0.1745, 0.01175, 0.01175),  vec(0.61424, 0.04136, 0.04136),  vec(0.727811, 0.626959, 0.626959), 76.8),
                    /* 11 */ material("Polished Gold", vec(0.24725, 0.2245, 0.0645),   vec(0.34615, 0.3143, 0.0903),    vec(0.797357, 0.723991, 0.208006), 83.2),
                    /* 12 */ material("Polished Bronze", vec(0.25, 0.148, 0.06475),    vec(0.4, 0.2368, 0.1036),        vec(0.774597, 0.458561, 0.200621), 76.8),
                    /* 13 */ material("Polished Copper", vec(0.2295, 0.08825, 0.0275), vec(0.5508, 0.2118, 0.066),      vec(0.580594, 0.223257, 0.0695701), 51.2),
                    /* 14 */ material("Jade",          vec(0.135, 0.2225, 0.1575),     vec(0.135, 0.2225, 0.1575),      vec(0.316228, 0.316228, 0.316228), 12.8),
                    /* 15 */ material("Obsidian",      vec(0.05375, 0.05, 0.06625),    vec(0.18275, 0.17, 0.22525),     vec(0.332741, 0.328634, 0.346435), 38.4),
                    /* 16 */ material("Pearl",         vec(0.25, 0.20725, 0.20725),    vec(1.0, 0.829, 0.829),          vec(0.296648, 0.296648, 0.296648), 11.264),
                    /* 17 */ material("Emerald",       vec(0.0215, 0.1745, 0.0215),    vec(0.07568, 0.61424, 0.07568),  vec(0.633, 0.727811, 0.633),       76.8),
                    /* 18 */ material("Black Plastic", vec(0.0, 0.0, 0.0),             vec(0.01, 0.01, 0.01),           vec(0.5, 0.5, 0.5),                32.0),
                    /* 19 */ material("Black Rubber",  vec(0.02, 0.02, 0.02),          vec(0.01, 0.01, 0.01),           vec(0.4, 0.4, 0.4),                10.0),
            };
}