/* Zajcev Yurij, 27.08.2021 */

#ifndef __FRAME_H_
#define __FRAME_H_

#include <GLUT/glut.h>
#include <cstring>
#include "vec.h"

typedef unsigned char byte;

namespace zyrt {
    class frame {
    public:
        static dbl clamp(dbl t) { // clamping double in range [0,1]
            if (t < 0)
                return 0.0;
            if (t > 1)
                return 1.0;
            return t;
        };

        byte (*Image)[3];
        int W, H; // sizes

        frame(int NewW, int NewH) :
                W(NewW), H(NewH), Image(new byte[NewW * NewH][3]) {
        }

        ~frame() {
            delete[]Image;
        }

        void Draw() { // standard glut draw function which draw Image
            glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
            glRasterPos2d(-1, 1);
            glPixelZoom(1, -1);
            glDrawPixels(W, H, GL_BGR_EXT, GL_UNSIGNED_BYTE, Image);
        }

        void PutPixel(int x, int y, vec Color) { // putting pixel into x,y with Color
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