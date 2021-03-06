#pragma once

#include <iostream>

namespace bad {

struct Point {
public:
    void Read(std::istream& is) {
        is >> x >> y;
    }
    
    void Print(std::ostream& os) const {
        os << x << ' ' << y << ' ';
    }

    int x, y;
};

inline int dist(const Point& a, const Point& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

}; // namespace bad
