#pragma once
#include "Figure.h"

class Square : public Figure {
public:
    Square();
    Square(double x1, double y1, double x2, double y2, 
           double x3, double y3, double x4, double y4);
    Square(const Square& other);
    Square(Square&& other) noexcept;
    Square& operator=(const Square& other);
    Square& operator=(Square&& other) noexcept;
    ~Square() override = default;
    std::pair<double, double> getCenter() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    explicit operator double() const override;
    bool operator==(const Figure& other) const override;

private:
    double x1, y1, x2, y2, x3, y3, x4, y4;
};
