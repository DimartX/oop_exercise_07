#pragma once

#include <iostream>
#include "figure.hpp"

namespace bad {

struct Square : Figure{
public:
    Square() = default;
    Square(std::istream& is) {
        for (int i = 0; i < NUM; i++) {
            pts[i].Read(is);
        }
        if (dist(pts[0], pts[2]) == dist(pts[1], pts[3]) &&
            dist(pts[0], pts[1]) == dist(pts[2], pts[3]) &&
            dist(pts[1], pts[2]) == dist(pts[0], pts[3]) &&
            dist(pts[0], pts[1]) == dist(pts[1], pts[2])) ;
        else
            throw std::logic_error("It is NOT square\n");
    }
    
    void print(std::ostream& os) const override {
        os << "Square\n";
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
