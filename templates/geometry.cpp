/*
* @Author: wilson_t
* @Date:   2021-10-26 14:39:06
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-10-26 22:01:22
*/
struct Point2d {
    typedef Point2d Vec2d;
    double x, y;
    Point2d(double _x, double _y): x(_x), y(_y) {}
    Point2d(): x(0), y(0) {}
    Point2d& operator=(const Point2d& rhs) {
        x = rhs.x;
        y = rhs.y;
        return *this;
    }
    Point2d operator+(const Point2d& rhs) const {
        return Point2d(x + rhs.x, y + rhs.y);
    }
    Point2d operator-(const Point2d& rhs) const {
        return Point2d(x - rhs.x, y - rhs.y);
    }
    Point2d& operator+=(const Point2d& rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
    Point2d& operator-=(const Point2d& rhs) {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }
    double operator*(const Vec2d& rhs) const {
        return x * rhs.x + y * rhs.y;
    }
    Vec2d& operator*=(double k) {
        x *= k;
        y *= k;
        return *this;
    }
    Vec2d operator*(double k) {
        return Vec2d(x * k, y * k);
    }
    Vec2d& operator/=(double k) {
        x /= k;
        y /= k;
        return *this;
    }
    Vec2d operator/(double k) {
        return Vec2d(x / k, y / k);
    }
    double operator^(const Point2d& rhs) const {
        return x * rhs.y - y * rhs.x;
    }
};