#pragma once
#include "Figure.h"
class Rectangle : public Figure {
public:
    Rectangle();
    Rectangle(double x1, double y1, double x2, double y2, 
              double x3, double y3, double x4, double y4);
    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;
    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other) noexcept;
    ~Rectangle() override = default;
    std::pair<double, double> getCenter() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    explicit operator double() const override;
    bool operator==(const Figure& other) const override;

private:
    double x1, y1, x2, y2, x3, y3, x4, y4;
};
