#pragma once
#include "Figure.h"

class Trapezoid : public Figure {
public:
    Trapezoid();
    Trapezoid(double x1, double y1, double x2, double y2,
              double x3, double y3, double x4, double y4);
    Trapezoid(const Trapezoid& other);
    Trapezoid(Trapezoid&& other) noexcept;
    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid& operator=(Trapezoid&& other) noexcept;
    ~Trapezoid() override = default;
    std::pair<double, double> getCenter() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    explicit operator double() const override;
    bool operator==(const Figure& other) const override;

private:
    double x1, y1, x2, y2, x3, y3, x4, y4;
};
