/* Zajcev Yurij, 11-1, group A, 25.11.2020 */

#ifndef __WIN_H_
#define __WIN_H_

#include <GLUT/glut.h>
#include <cstdlib>
#include "frame.h"
#include "rt.h"

namespace zyrt {
    class win {
    private:
        static void Display() {
            //frame frm(100, 100);
            glClearColor(0.30, 0.50, 0.70, 1.00);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            MainScene.Render();
            glFinish();
            glutSwapBuffers();
            glutPostRedisplay();
        }

        static void Keyboard(unsigned char Key, int X, int Y) {
            if (Key == 27)
                exit(0);
            else if (Key == 'f')
                glutFullScreen();
        }

    public:
        win() {
            const char *argv[] = {"ops"};
            int argc = 1;
            glutInit(&argc, const_cast<char **>(argv));
            glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
            glutInitWindowPosition(0, 0);
            glutInitWindowSize(5000, 5000);
            glutCreateWindow("RT");
            glutDisplayFunc(Display);
            glutKeyboardFunc(Keyboard);
        }

        void Run() {
            glutMainLoop();
        }

    };
}

#endif // __WIN_H_