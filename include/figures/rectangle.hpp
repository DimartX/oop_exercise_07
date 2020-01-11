#pragma once

#include <iostream>
#include "figure.hpp"

namespace bad {

struct Rectangle : Figure{
public:
    Rectangle() = default;
    Rectangle(std::istream& is) {
        for (int i = 0; i < NUM; i++) {
            pts[i].Read(is);
        }
        if (dist(pts[0], pts[2]) == dist(pts[1], pts[3]) &&
            dist(pts[0], pts[1]) == dist(pts[2], pts[3]) &&
            dist(pts[1], pts[2]) == dist(pts[0], pts[3])) ;
        else
            throw std::logic_error("It is NOT rectangle\n");
    }

    void print(std::ostream& os) const override {
        os << "Rectangle\n";
        for (int i = 0; i < NUM; i++) {
            pts[i].Print(os);
        }
        os << std::endl;
    }
private:
    static const int NUM = 4;
    Point pts[NUM];
};

}; // namespace bad
