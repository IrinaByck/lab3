#include "Rectangle.h"
#include <cmath>
#include <iostream>

Rectangle::Rectangle() : x1(0), y1(0), x2(0), y2(0), 
                         x3(0), y3(0), x4(0), y4(0) {}

Rectangle::Rectangle(double x1, double y1, double x2, double y2, 
                     double x3, double y3, double x4, double y4)
    : x1(x1), y1(y1), x2(x2), y2(y2), 
      x3(x3), y3(y3), x4(x4), y4(y4) {}

Rectangle::Rectangle(const Rectangle& other)
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2),
      x3(other.x3), y3(other.y3), x4(other.x4), y4(other.y4) {}

Rectangle::Rectangle(Rectangle&& other) noexcept
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2),
      x3(other.x3), y3(other.y3), x4(other.x4), y4(other.y4) {
    other.x1 = 0; other.y1 = 0; 
    other.x2 = 0; other.y2 = 0;
    other.x3 = 0; other.y3 = 0; 
    other.x4 = 0; other.y4 = 0;
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this == &other) {
        return *this;
    }
    x1 = other.x1; y1 = other.y1;
    x2 = other.x2; y2 = other.y2;
    x3 = other.x3; y3 = other.y3;
    x4 = other.x4; y4 = other.y4;
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
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

std::pair<double, double> Rectangle::getCenter() const {
    double center_x = (x1 + x2 + x3 + x4) / 4.0;
    double center_y = (y1 + y2 + y3 + y4) / 4.0;
    return {center_x, center_y};
}

void Rectangle::print(std::ostream& os) const {
    os << "(" << x1 << "," << y1 << ") "
       << "(" << x2 << "," << y2 << ") "
       << "(" << x3 << "," << y3 << ") "
       << "(" << x4 << "," << y4 << ")";
}

void Rectangle::read(std::istream& is) {
    is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
}

Rectangle::operator double() const {
    double dx_width = x2 - x1;
    double dy_width = y2 - y1;
    double width = std::sqrt(dx_width * dx_width + dy_width * dy_width);
    double dx_height = x3 - x2;
    double dy_height = y3 - y2;
    double height = std::sqrt(dx_height * dx_height + dy_height * dy_height);
    return width * height;
}

bool Rectangle::operator==(const Figure& other) const {
    const Rectangle* other_rectangle = dynamic_cast<const Rectangle*>(&other);
    if (other_rectangle == nullptr) {
        return false;
    }
    return (x1 == other_rectangle->x1 && y1 == other_rectangle->y1 &&
            x2 == other_rectangle->x2 && y2 == other_rectangle->y2 &&
            x3 == other_rectangle->x3 && y3 == other_rectangle->y3 &&
            x4 == other_rectangle->x4 && y4 == other_rectangle->y4);
}
