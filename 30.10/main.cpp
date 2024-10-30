#include <iostream>
#include "point.hpp"


int main() {
    Point point1(34.5f, 34.5f);
    Point point2;
    Point point3(point1);

    std::cout << point1.getX() << " " << point1.getY() << std::endl;
    std::cout << point2.getX() << " " << point2.getY() << std::endl;
    std::cout << point3.getX() << " " << point3.getY() << std::endl;

    return 0;
}
