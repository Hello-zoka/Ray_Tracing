/* Zajcev Yurij, 11-1, group A, 25.11.2020 */

#ifndef __FRAME_H_
#define __FRAME_H_

#include <GLUT/glut.h>
#include <cstring>
#include "vec.h"

typedef unsigned char byte;

namespace zyrt {
    class frame {
    public:
        static dbl clamp(dbl t) {
            if (t < 0)
                return 0.0;
            if (t > 1)
                return 1.0;
            return t;
        };

        byte (*Image)[3];
        int W, H;

        frame(int NewW, int NewH) :
                W(NewW), H(NewH), Image(new byte[NewW * NewH][3]) {
        }

        ~frame() {
            delete[]Image;
        }

        void Draw() {
            glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
            glRasterPos2d(-1, 1);
            glPixelZoom(1, -1);
            glDrawPixels(W, H, GL_BGR_EXT, GL_UNSIGNED_BYTE, Image);
        }

        void PutPixel(int x, int y, vec Color) {
            if (x < 0 || y < 0 || x >= W || y >= H)
                return;

            int off = y * W + x;
            Image[off][0] = int(clamp(Color.z) * 255);
            Image[off][1] = int(clamp(Color.y) * 255);
            Image[off][2] = int(clamp(Color.x) * 255);
        }
    };
}
#endif // __FRAME_H_