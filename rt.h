/* Zajcev Yurij, 11-1, group A, 25.11.2020 */

#ifndef __RT_H_
#define __RT_H_

#include <GLUT/glut.h>
#include <vector>
#include <cstdlib>
#include <thread>
#include "frame.h"
#include "materials.h"
#include "ray.h"


const double EPS = 0.000001;

namespace zyrt {
    class shape {
    public:
        material mat;

        shape(material mt) : mat(mt) {}

        virtual dbl Intersect(const ray &R) {
            return 0;
        }

        virtual vec get_normal(const vec &P) {
            return vec(0, 0, 0);
        }

    };

    class light_source {
    public:
        virtual vec destination(const vec &point) {
            return vec(0, 0, 0);
        }

        vec mat;
    };

    class rt {
    public:
        std::vector<shape *> Scene;
        std::vector<light_source *> lights;
        frame Shot;

        rt() : Shot(1200, 600) {}

        ~rt() {
            for (auto x : Scene)
                delete x;
            Scene.clear();
        }

        rt &operator<<(shape *NewShape) {
            Scene.push_back(NewShape);
            return *this;
        }

        rt &operator<<(light_source *source) {
            lights.push_back(source);
            return *this;
        }

        static vec fontface(const vec &dir, shape *object, const vec &point) {
            vec normal = object->get_normal(point);
            if ((dir & normal) > 0)
                normal = -normal;
            return normal;
        }

        std::pair<shape *, vec> intersect(const ray &r) {
            double intersection = 0;
            shape *closest = nullptr;
            vec point = vec(0, 0, 0);
            for (auto object : Scene) {
                double t = object->Intersect(r);
                if (t > 0 && (closest == nullptr || t < intersection))
                    intersection = t, closest = object;
            }

            if (closest != nullptr)
                point = r(intersection);

            return std::make_pair(closest, point);
        }

        vec trace(const ray &r, const int depth) {
            if (depth >= 5)
                return vec(0, 0, 0);
            std::pair<shape *, vec> intersection = intersect(r);
            if (intersection.first != nullptr)
                return shade(r, intersection.first, intersection.second, depth);
            return vec(0, 0, 0);
        }

        vec shade(const ray &r, shape *object, const vec &point, int depth) {
            const vec dir = r.Dir;
            const vec normal = fontface(dir, object, point);
            const vec reflected = (dir - normal * 2 * (normal & dir)).normalize();
            vec ambient = object->mat.amb;
            vec reflection = (vec(0.2, 0.2, 0.2) | trace(ray(point + normal * EPS, reflected), depth + 1));
            vec diffuse = vec(0, 0, 0), specular = vec(0, 0, 0);
            for (auto light : lights) {
                const vec destination = light->destination(point);

                if (intersect(ray(point + destination * EPS, destination)).first == nullptr) {
                    if ((normal & destination) > 0)
                        diffuse += (object->mat.dif | light->mat) * (normal & destination);
                    if ((reflected & destination) > 0)
                        specular += (object->mat.spec | light->mat) *
                                    pow(reflected & destination, object->mat.phi);
                }
            }
            return ambient + diffuse + specular + reflection;
        }

        void Render() {
            const int n = std::thread::hardware_concurrency();
            std::vector<std::thread> tasks;
            const vec from(1, 0, 4);
            const vec to(0, 0, 0);
            const double size = 0.1;
            const double wp = Shot.W > Shot.H ? size * Shot.W / Shot.H : size;
            const double hp = Shot.W > Shot.H ? size : size * Shot.H / Shot.W;
            const double pd = 2 * size, ws = Shot.W, hs = Shot.H;
            vec up = vec(0, 1, 0).normalize();
            const vec dir = (to - from).normalize();
            const vec r = (dir % up).normalize();
            up = (r % dir).normalize();

            for (int y = 0; y < Shot.H; y++) {
                tasks.push_back(std::thread([=]() {
                    for (int x = 0; x < Shot.W; x++) {
                        const vec p = dir * pd +
                                      r * ((x - ws / 2 + 0.5) * wp / ws) +
                                      up * ((hs / 2 - y - 0.5) * hp / hs);
                        const ray r(p + from, p);
                        Shot.PutPixel(x, y, trace(r, 0).clamp());
                    }
                }));
            }
            for (auto &tsk : tasks)
                tsk.join();
            Shot.Draw();
        }
    };

    extern rt MainScene;
}
#endif //__RT_H_