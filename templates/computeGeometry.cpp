#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

double EPS = 1e-10;
double INF = 1e18;

double add(double a, double b) {
  if (abs(a + b) < EPS * (abs(a) + abs(b))) return 0;
  return a + b;
}
double max(double a, double b) { return a > b ? a : b; }
double min(double a, double b) { return a < b ? a : b; }

struct Point2d {
  double x, y;
  Point2d() {}
  Point2d(double _x, double _y) : x(_x), y(_y) {}
  Point2d(const Point2d& p) : x(p.x), y(p.y) {}
  Point2d& operator=(const Point2d& p) {
    x = p.x;
    y = p.y;
    return *this;
  }
  bool operator==(const Point2d& p) const { return x == p.x && y == p.y; }
  Point2d operator+(const Point2d& other) const {
    return Point2d(x + other.x, y + other.y);
  }
  Point2d operator-(const Point2d& other) const {
    return Point2d(x - other.x, y - other.y);
  }
  Point2d operator*(double f) const { return Point2d(x * f, y * f); }
  Point2d operator/(double f) const { return Point2d(x / f, y / f); }
  Point2d& operator+=(const Point2d& other) {
    x += other.x;
    y += other.y;
    return *this;
  }
  Point2d& operator-=(const Point2d& other) {
    x -= other.x;
    y -= other.y;
    return *this;
  }
  Point2d& operator*=(double f) {
    x *= f;
    y *= f;
    return *this;
  }
  Point2d& operator/=(double f) {
    x /= f;
    y /= f;
    return *this;
  }
  // 内积
  double dot(const Point2d& other) const {
    return add(x * other.x, y * other.y);
  }
  // 外积
  double det(const Point2d& other) const {
    return add(x * other.y, -y * other.x);
  }

  double norm() const { return sqrt(x * x + y * y); }
  double norm2() const { return x * x + y * y; }
  Point2d normalize() const { return *this / norm(); }
};

typedef Point2d Vec2d;

struct Line {
  Point2d p0, p1;
  Line() {}
  Line(const Point2d& _p0, const Point2d& _p1) : p0(_p0), p1(_p1) {}
  bool onLeft(const Point2d& p) const { return (p1 - p0).det(p - p0) > 0; }
  bool onRight(const Point2d& p) const { return (p1 - p0).det(p - p0) < 0; }
  bool onLeft(const Line& l) const { return onLeft(l.p0) && onLeft(l.p1); }
  bool onRight(const Line& l) const { return onRight(l.p0) && onRight(l.p1); }
  bool onLine(const Point2d& p) const {
    return (p0 - p).det(p1 - p) == 0 && (p0 - p).dot(p1 - p) <= 0;
  }
  double getMinX() const { return min(p0.x, p1.x); }
  double getMaxX() const { return max(p0.x, p1.x); }
  double getMinY() const { return min(p0.y, p1.y); }
  double getMaxY() const { return max(p0.y, p1.y); }
  bool isIntersect(const Line& l) const {
    if (getMaxX() < l.getMinX() || l.getMaxX() < getMinX() ||
        getMaxY() < l.getMinY() || l.getMaxY() < getMinY()) {
      return false;
    }
    return (l.p0 - p0).det(p1 - p0) * (l.p1 - p0).det(p1 - p0) <= 0 &&
           (p0 - l.p0).det(l.p1 - l.p0) * (p1 - l.p0).det(l.p1 - l.p0) <= 0;
  }
  Point2d intersect(const Line& l) const {
    return p0 + (p1 - p0) * (l.p0 - p0).det(l.p1 - l.p0) /
                    (p1 - p0).det(l.p1 - l.p0);
  }
  friend std::ostream& operator<<(std::ostream& os, const Line& l) {
    os << "(" << l.p0.x << ", " << l.p0.y << ") - (" << l.p1.x << ", " << l.p1.y
       << ")";
    return os;
  }
};

Vec2d normalVec(Vec2d v) { return Vec2d(v.y, -v.x) / v.norm(); }

Point2d project(Point2d a, Point2d b, Point2d pt) {
  Vec2d v = b - a;
  return a + v * v.dot(pt - a) / v.norm2();
}

Point2d reflection(Point2d a, Point2d b, Point2d p) {
  Point2d proj = project(a, b, p);
  return proj + proj - p;
}

double distance(Line l, Point2d p) {
  Point2d proj = project(l.p0, l.p1, p) - p;
  if (l.onLine(proj))
    return (proj - p).norm();
  else {
    return min((p - l.p0).norm(), (p - l.p1).norm());
  }
}

int main() {
  int q;
  std::cin >> q;
  Point2d p0, p1, p2, p3;
  while (q--) {
    std::cin >> p0.x >> p0.y >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    Line l1(p0, p1), l2(p2, p3);
    if (l1.isIntersect(l2)) {
      std::cout << std::fixed << std::setprecision(10) << 0 << "\n";
    } else {
      double dist1 = min(distance(l1, l2.p0), distance(l1, l2.p1));
      double dist2 = min(distance(l2, l1.p0), distance(l2, l1.p1));
      std::cout << std::fixed << std::setprecision(10) << min(dist1, dist2)
                << "\n";
    }
  }
  return 0;
}