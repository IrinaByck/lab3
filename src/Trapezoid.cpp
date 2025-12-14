#include "Trapezoid.h"
#include <cmath>
#include <iostream>

Trapezoid::Trapezoid() : x1(0), y1(0), x2(0), y2(0), 
                         x3(0), y3(0), x4(0), y4(0) {}

Trapezoid::Trapezoid(double x1, double y1, double x2, double y2,
                     double x3, double y3, double x4, double y4)
    : x1(x1), y1(y1), x2(x2), y2(y2), 
      x3(x3), y3(y3), x4(x4), y4(y4) {}

Trapezoid::Trapezoid(const Trapezoid& other)
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2),
      x3(other.x3), y3(other.y3), x4(other.x4), y4(other.y4) {}

Trapezoid::Trapezoid(Trapezoid&& other) noexcept
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2),
      x3(other.x3), y3(other.y3), x4(other.x4), y4(other.y4) {
    other.x1 = 0; other.y1 = 0; 
    other.x2 = 0; other.y2 = 0;
    other.x3 = 0; other.y3 = 0; 
    other.x4 = 0; other.y4 = 0;
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this == &other) {
        return *this;
    }
    x1 = other.x1; y1 = other.y1;
    x2 = other.x2; y2 = other.y2;
    x3 = other.x3; y3 = other.y3;
    x4 = other.x4; y4 = other.y4;
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept {
    if (this == &other) {
        return *this;
    }
    x1 = other.x1; y1 = other.y1;
    x2 = other.x2; y2 = other.y2;
    x3 = other.x3; y3 = other.y3;
    x4 = other.x4; y4 = other.y4;
    other.x1 = 0; other.y1 = 0;
    other.x2 = 0; other.y2 = 0;
    other.x3 = 0; other.y3 = 0;
    other.x4 = 0; other.y4 = 0;
    return *this;
}

std::pair<double, double> Trapezoid::getCenter() const {
    double center_x = (x1 + x2 + x3 + x4) / 4.0;
    double center_y = (y1 + y2 + y3 + y4) / 4.0;
    return {center_x, center_y};
}

void Trapezoid::print(std::ostream& os) const {
    os << "(" << x1 << "," << y1 << ") "
       << "(" << x2 << "," << y2 << ") "
       << "(" << x3 << "," << y3 << ") "
       << "(" << x4 << "," << y4 << ")";
}

void Trapezoid::read(std::istream& is) {
    is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
}

Trapezoid::operator double() const {
    double dx1 = x2 - x1;
    double dy1 = y2 - y1;
    double base1 = std::sqrt(dx1 * dx1 + dy1 * dy1);
    double dx2 = x4 - x3;
    double dy2 = y4 - y3;
    double base2 = std::sqrt(dx2 * dx2 + dy2 * dy2);
    double A = y3 - y4;
    double B = x4 - x3;
    double C = x3 * y4 - x4 * y3;
    double height = std::abs(A * x1 + B * y1 + C) / std::sqrt(A * A + B * B);
    return 0.5 * (base1 + base2) * height;
}

bool Trapezoid::operator==(const Figure& other) const {
    const Trapezoid* other_trapezoid = dynamic_cast<const Trapezoid*>(&other);
    if (other_trapezoid == nullptr) {
        return false;
    }
    return (x1 == other_trapezoid->x1 && y1 == other_trapezoid->y1 &&
            x2 == other_trapezoid->x2 && y2 == other_trapezoid->y2 &&
            x3 == other_trapezoid->x3 && y3 == other_trapezoid->y3 &&
            x4 == other_trapezoid->x4 && y4 == other_trapezoid->y4);
}
