/* Zajcev Yurij, 27.08.2021 */

#ifndef __WIN_H_
#define __WIN_H_

#include <GLUT/glut.h>
#include <cstdlib>
#include "frame.h"
#include "../tracing/tracing.h"

namespace zyrt {
    class win {
    private:
        static void Display() { // standard glut display function
            glClearColor(0.30, 0.50, 0.70, 1.00); // calm color of background
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            MainScene.Render(); // Rendering scene
            glFinish();
            glutSwapBuffers();
            glutPostRedisplay();
        }

        static void Keyboard(unsigned char Key, int X, int Y) {
            if (Key == 27) // if you push escape button program will close
                exit(0);
            else if (Key == 'f') // 'f' button open full screen mode
                glutFullScreen();
        }

    public:
        win() { // standard glut function which create glut window
            const char *argv[] = {"ops"};
            int argc = 1;
            glutInit(&argc, const_cast<char **>(argv));
            glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
            glutInitWindowPosition(0, 0);
            glutInitWindowSize(5000, 5000); // size of glut window
            glutCreateWindow("RT"); // name of glut window
            glutDisplayFunc(Display);
            glutKeyboardFunc(Keyboard);
        }

        void Run() {
            glutMainLoop();
        }

    };
}

#endif // __WIN_H_