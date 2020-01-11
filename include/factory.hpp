#pragma once

#include <iostream>

namespace bad {

class Factory {
public:
    std::shared_ptr<Figure> FigureCreate(std::istream& is);
};

}; // namespace bad
