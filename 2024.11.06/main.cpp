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
// 1 constructors: -default -main -copying
// 2 getters setters
// 3 poly field calc func
// 4 operator overloading ([], =, <<)

#include <cmath>
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

        std::ostream& operator<< (std::ostream& os) const {
            os << x << " " << y << std::endl;
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

class Polygon {
    int count;
    point* verticies;
};
