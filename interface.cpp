#include <iostream>
#include "tracing/tracing.h"
#include "math_classes/vec.h"
#include "glut_drawing/frame.h"
#include "objects/sphere.h"
#include "objects/point_source.h"
#include "objects/plane.h"

zyrt::rt zyrt::MainScene;

void print_mat() { // printing all materials
    std::cout << "0. Black Plastic\n"
                 "1. Brass\n"
                 "2. Bronze\n"
                 "3. Chrome\n"
                 "4. Copper\n"
                 "5. Gold\n"
                 "6. Peweter\n"
                 "7. Silver\n"
                 "8. Polished Silver\n"
                 "9. Turquoise\n"
                 "10. Ruby\n"
                 "11. Polished Gold\n"
                 "12. Polished Bronze\n"
                 "13. Polished Copper\n"
                 "14. Jade\n"
                 "15. Obsidian\n"
                 "16. Peral\n"
                 "17. Emerald\n"
                 "18. Black Plastic\n"
                 "19. Black Rubber\n";
}

void add_object() { // getting info about adding object
    std::cout << "Which object do you want to add?\n"
                 "1 - sphere\n"
                 "2 - plane\n"
                 "3 - light source\n"
                 "Please input number from 1 to 3: ";
    std::string s;
    std::cin >> s;
    while (1) {
        if (s == "1") { // case sphere
            std::cout << "\nPlease input 3 double numbers - x, y, z coordinates: ";
            double x, y, z, r;
            std::cin >> x >> y >> z;
            std::cout << "\nPlease input 1 double number - radius: ";
            std::cin >> r;
            print_mat();
            std::cout << "\nPlease input 1 number - material from ^ list:\n";
            int mt;
            std::cin >> mt;
            zyrt::shape *obj = new zyrt::sphere(vec(x, y, z), r, mt);
            zyrt::MainScene << obj;
            break;
        } else if (s == "2") { // case plane
            std::cout << "\nPlease input 3 double numbers - x, y, z coordinates of any point in this plane: ";
            double x, y, z, x2, y2, z2;
            std::cin >> x >> y >> z;
            std::cout << "\nPlease input 3 double numbers - x, y, z coordinates of normal vector to this plane: ";
            std::cin >> x2 >> y2 >> z2;
            print_mat();
            std::cout << "\nPlease input 1 number - material from ^ list:\n";
            int mt;
            std::cin >> mt;
            zyrt::shape *obj = new zyrt::plane(vec(x2, y2, z2), vec(x, y, z), mt);
            zyrt::MainScene << obj;
            break;

        } else if (s == "3") { // case light source
            std::cout << "\nPlease input 3 double numbers - x, y, z coordinates: ";
            double x, y, z;
            std::cin >> x >> y >> z;
            zyrt::point_source *obj = new zyrt::point_source(vec(x, y, z));
            zyrt::MainScene << obj;
            break;

        } else { // case incorrect command
            std::cout << "\nWrong command\nPlease input number from 1 to 3: ";
            std::cin >> s;
        }
    }
}

void interface() { // adding objects while user want to
    std::cout << "You are looking from (0,0,8) coordinates to (0, 0, 0)\n";
    while (1) {
        std::cout << "Do you want add one new object?\n"
                     "Print 1(yes) or 0(no): ";
        std::string s;
        std::cin >> s;
        while (1) {
            if (s == "0") {
                return;
            } else if (s == "1") {
                add_object();
                break;
            } else {
                std::cout << "\nPrint 1(yes) or 0(no): ";
                std::cin >> s;
            }
        }
    }
}

void std_pic() { // first standard picture
    zyrt::shape *s = new zyrt::sphere(vec(0.0, 0.0, 5), 0.2, 6);
    zyrt::shape *s2 = new zyrt::sphere(vec(-0.5, -0.5, 5), 0.3, 2);
    zyrt::shape *p = new zyrt::plane(vec(1, 1, 0), vec(-1, -1, 0), 10);
    zyrt::shape *s3 = new zyrt::sphere(vec(-0.1, 0.25, 5), 0.2, 17);
    zyrt::point_source *x = new zyrt::point_source(vec(0, 7, 5));
    zyrt::point_source *x2 = new zyrt::point_source(vec(1, 1, 6));
    zyrt::MainScene << s << s2 << p << x << x2 << s3;
}

void std_pic2() { // second standard picture
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            zyrt::shape *s = new zyrt::sphere(vec(i, j, 0), 0.5, 16);
            zyrt::MainScene << s;
        }
    }
    zyrt::shape *p = new zyrt::plane(vec(0, 1, 0), vec(0, -1, 0), 5);

    zyrt::point_source *x = new zyrt::point_source(vec(-10, 10, 0));
    zyrt::point_source *x2 = new zyrt::point_source(vec(10, 10, 0));
    zyrt::MainScene << x << x2 << p;
}
