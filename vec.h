/* Zajcev Yurij, 11-1, group A, 25.11.2020 */

#ifndef __VEC_H_
#define __VEC_H_

#include <cmath>
#include <random>
#include <chrono>

//std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
typedef double dbl;

class vec {
public:
    dbl x, y, z;

    vec(void) {}

    vec(dbl A, dbl B, dbl C) : x(A), y(B), z(C) {
    }

    vec operator+(const vec &V) const {
        return vec(x + V.x, y + V.y, z + V.z);
    }

    vec operator-(const vec &V) const {
        return vec(x - V.x, y - V.y, z - V.z);
    }

    vec operator%(const vec &V) const {
        return vec(y * V.z - z * V.y, z * V.x - x * V.z, x * V.y - y * V.x);
    }

    dbl operator&(const vec &V) const {
        return x * V.x + y * V.y + z * V.z;
    }

    vec operator*(dbl N) const {
        return vec(x * N, y * N, z * N);
    }

    vec operator-(void) const {
        return vec(-x, -y, -z);
    }

    vec operator/(dbl N) const {
        return vec(x / N, y / N, z / N);
    }

    vec normalize(void) {
        return *this / sqrt(*this & *this);
    }

    vec &operator+=(const vec &V) {
        x += V.x;
        y += V.y;
        z += V.z;
        return *this;
    }

    vec operator|(const vec &r) const {
        return vec(x * r.x, y * r.y, z * r.z);
    }

    dbl &operator[](int i) {
        return *(&x + i);
    }

    vec clamp() const {
        vec result = *this;
        for (int i = 0; i < 3; i++)
            if (result[i] < 0)
                result[i] = 0;
            else if (result[i] > 1)
                result[i] = 1;
        return result;
    }

    static dbl r1(void) {
        return 2.0 * (rand() % 4) - 1;
    }

    static vec Rnd1(void) {
        return vec(r1(), r1(), r1());
    }

    static vec Rnd2(void) {
        return vec(r1() * 0.3, r1() * 0.3, r1() * 0.3);
    }
};

#endif // __VEC_H_