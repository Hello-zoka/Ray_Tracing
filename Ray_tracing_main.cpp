#include <vector>
#include "glut_drawing/win.h"
#include "objects/point_source.h"
#include "tracing/tracing.h"
#include "interface.cpp"


int main() {
    zyrt::win A;
    std::cout << "Hello! Do you want to see standard picture(1 or 2) or make your own(3)?\nPlease type 1, 2 or 3: ";
    std::string s;
    std::cin >> s;
    while (true) {
        if (s == "1") {
            std_pic();
            break;
        } else if (s == "2") {
            std_pic2();
            break;
        } else if (s == "3") {
            interface();
            break;
        } else {
            std::cout << "\nWrong command\nPlease type 1, 2 or 3: ";
            std::cin >> s;
        }
    }
    A.Run();
    return 0;
}
