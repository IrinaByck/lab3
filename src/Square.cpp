#include "Square.h"
#include <cmath>
#include <iostream>

Square::Square() : x1(0), y1(0), x2(0), y2(0), 
                   x3(0), y3(0), x4(0), y4(0) {}

Square::Square(double x1, double y1, double x2, double y2, 
               double x3, double y3, double x4, double y4) 
    : x1(x1), y1(y1), x2(x2), y2(y2), 
      x3(x3), y3(y3), x4(x4), y4(y4) {}

Square::Square(const Square& other) 
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2),
      x3(other.x3), y3(other.y3), x4(other.x4), y4(other.y4) {}

Square::Square(Square&& other) noexcept 
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2),
      x3(other.x3), y3(other.y3), x4(other.x4), y4(other.y4) {
    other.x1 = 0; other.y1 = 0; 
    other.x2 = 0; other.y2 = 0;
    other.x3 = 0; other.y3 = 0; 
    other.x4 = 0; other.y4 = 0;
}

Square& Square::operator=(const Square& other) {
    if (this == &other) {
        return *this;
    }
    x1 = other.x1; y1 = other.y1;
    x2 = other.x2; y2 = other.y2;
    x3 = other.x3; y3 = other.y3;
    x4 = other.x4; y4 = other.y4;
    return *this;
}

Square& Square::operator=(Square&& other) noexcept {
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

std::pair<double, double> Square::getCenter() const {
    double center_x = (x1 + x2 + x3 + x4) / 4.0;
    double center_y = (y1 + y2 + y3 + y4) / 4.0;
    return {center_x, center_y};
}

void Square::print(std::ostream& os) const {
    os << "(" << x1 << "," << y1 << ") "
       << "(" << x2 << "," << y2 << ") "
       << "(" << x3 << "," << y3 << ") "
       << "(" << x4 << "," << y4 << ")";
}

void Square::read(std::istream& is) {
    is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
}

Square::operator double() const {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double side = std::sqrt(dx * dx + dy * dy);
    return side * side;
}

bool Square::operator==(const Figure& other) const {
    const Square* other_square = dynamic_cast<const Square*>(&other);
    if (other_square == nullptr) {
        return false;
    }
    return (x1 == other_square->x1 && y1 == other_square->y1 &&
            x2 == other_square->x2 && y2 == other_square->y2 &&
            x3 == other_square->x3 && y3 == other_square->y3 &&
            x4 == other_square->x4 && y4 == other_square->y4);
}
