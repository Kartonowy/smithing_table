#include <iostream>
#include <stdio.h>

// 1. konstrkutor glowny
// 2. kontruktor domyslny
// 3. gettery i settery

class Point {
    private:
        float x;
        float y;
    public:

        void setX(float _x) {
            x = _x;
        }
        float getX() {
            return x;
        }

        void setY(float _y) {
            y = _y;
        }
        float getY() {
            return y;
        }

        Point(float _x, float _y) {
            x = _x;
            y = _y;
        }
        
        Point() {
            x = 0.0f;
            y = 0.0f;
        }

};

int main() {

    Point point1(34.5f, 34.5f);
    Point point2;

    std::cout << point1.getX() << std::endl << point1.getY() << std::endl;
    std::cout << point2.getX() << std::endl << point2.getY() << std::endl;

}
