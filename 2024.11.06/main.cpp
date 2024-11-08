// class point
//
// 1 constructors: -default ✓ -main ✓ -copying ✓
// 2 getters setters ✓
// 3 vector length calc func ✓
// 4 operator overloading (+✓, -✓, * (scalar product)✓, =✓, <<✓) ✓
// a-> . b-> = |a->| * |b->| * cos(a->, b->)
// [a1, a2] * [b1, b2] = [a1 * b1] + [a2 * b2]

// class Polygon
//
// 1 constructors: -default✓ -main✓ -copying✓
// 2 getters setters ✓
// 3 poly field calc func
// 4 operator overloading ([]✓, =✓, <<✓)

#include <cassert>
#include <cmath>
#include <iostream>
#include <ostream>
class point {
    float x;
    float y;
    public:
        
        
        point operator+ (const point& p) const {
            return point ( p.x + x, p.y + y);
        };

        point operator- (const point& p) const {
            return point ( p.x - x, p.y - y);
        };

        point operator= (const point& p) const {
            return point(p.x, p.y);
        };

        friend std::ostream & operator<< (std::ostream & os, const point & p) {
            os << p.x << " " << p.y;
            return os;
        };

        int operator* (const point& p) const {
            return x * p.x + y * p.y;
        };
        
        void setX(float _x) {
            x = _x;
        };
        float getX() {
            return x;
        };
        void setY(float _y) {
            y = _y;
        };
        float getY() {
            return y;
        };
        float calcLen() {
            return sqrt(x*x + y*y);
        }
        point(float _x, float _y) {
            x = _x;
            y = _y;
        }
        point() {
            x = 0.0f;
            y = 0.0f;
        }
        point(point& p) {
            x = p.x;
            y = p.y;
        }
};

class polygon {
    int count;
    point* verticies;

    public:
        float calculateArea() {
            // 2A = i = 1 => sum(p[i].x * (p[i-1].y - p[i+1]+1))
            float sum = 0.0f;
            for (int i = 1; i <= count; ++i) {
                sum += verticies[i].getX() * (verticies[i-1].getY() - verticies[i+1].getY());
            }
            return sum / 2;
        }
        void setVerticies(point* _verticies, int _count) {
            count = _count;
            verticies = _verticies;
        }
        point* getVerticies() {
            return verticies;
        }

        int getCount() {
            return count;
        }

        point operator[] (int pos) const {
            assert(pos < count);
            return verticies[pos];
        }

        polygon operator= (const polygon& p) {
            return polygon(p.verticies, p.count);
        };

        friend std::ostream & operator<< (std::ostream & os, const polygon & p) {
            for (int i = 0; i < p.count; ++i) {
                os << p.verticies[i]  << std::endl;

            }
            return os;
        };


        polygon() {
            count = 0.0;
            verticies = nullptr;
        }
        polygon(point* _verticies, int _count) {
            count = _count;
            verticies = _verticies;
        };
        polygon(polygon & p) {
            count = p.count;
            verticies = p.verticies;
        };
};

int main() {
    auto a = point();
    auto b = point(0.0f, 5.0f);
    auto c = point(5.0f, 7.5f);
    auto d = point(6.0f, 6.9f);
    auto e = point(3.42f, 3.69f);
    auto f = point(1.0f, 1.69f);
    point verticies[] = {a, b, c, d, e, f};

    polygon poly = polygon(verticies, 3);
    
    std::cout << poly.calculateArea();

    return 0;
}
