/* Zajcev Yurij, 27.08.2021 */

#ifndef __VEC_H_
#define __VEC_H_

#include <cmath>
#include <random>
#include <chrono>

typedef double dbl;

class vec { // implementation of vector
public:
    dbl x, y, z;

    vec() {}

    vec(dbl A, dbl B, dbl C) : x(A), y(B), z(C) {
    }

    vec operator+(const vec &V) const { // sum of vectors
        return vec(x + V.x, y + V.y, z + V.z);
    }

    vec operator-(const vec &V) const { // difference of vectors
        return vec(x - V.x, y - V.y, z - V.z);
    }

    vec operator%(const vec &V) const { // cross product
        return vec(y * V.z - z * V.y, z * V.x - x * V.z, x * V.y - y * V.x);
    }

    dbl operator&(const vec &V) const { // dot product
        return x * V.x + y * V.y + z * V.z;
    }

    vec operator*(dbl N) const { // multiply vector by number
        return vec(x * N, y * N, z * N);
    }

    vec operator-() const { // inverting vector
        return vec(-x, -y, -z);
    }

    vec operator/(dbl N) const { // dividing vector by number
        return vec(x / N, y / N, z / N);
    }

    vec normalize() { // normalizing vector
        return *this / sqrt(*this & *this);
    }

    vec &operator+=(const vec &V) { // sum of vectors
        x += V.x;
        y += V.y;
        z += V.z;
        return *this;
    }

    vec operator|(const vec &r) const {
        return vec(x * r.x, y * r.y, z * r.z);
    }

    dbl &operator[](int i) { // access to vector parameters by index
        return *(&x + i);
    }

    vec clamp() const { // clamping vector's parameters in array [0,1]
        vec result = *this;
        for (int i = 0; i < 3; i++)
            if (result[i] < 0)
                result[i] = 0;
            else if (result[i] > 1)
                result[i] = 1;
        return result;
    }

    static dbl r1(void) { // random number in range [-1,5]
        return (rand() % 7) - 1;
    }


    static vec Rnd1(void) { // vector with random parameters
        return vec(r1(), r1(), r1());
    }

    static vec Rnd2(void) { // vector with random parameters * 0,3
        return vec(r1() * 0.3, r1() * 0.3, r1() * 0.3);
    }
};

#endif // __VEC_H_