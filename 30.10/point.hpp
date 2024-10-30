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

        Point(Point & p) {
            x = p.x;
            y = p.y;
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
