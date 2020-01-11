#pragma once

#include <iostream>
#include "figure.hpp"

namespace bad {

struct Triangle : Figure {
public:
    Triangle() = default;
    Triangle(std::istream& is) {
        for (int i = 0; i < NUM; i++) {
            pts[i].Read(is);
        }
    }

    void print(std::ostream& os) const override {
        os << "Triangle\n";
        for (int i = 0; i < NUM; i++) {
            pts[i].Print(os);
        }
        os << std::endl;
    }
private:
    static const int NUM = 3;
    Point pts[NUM];
};

}; // namespace bad
