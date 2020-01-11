#pragma once

#include <iostream>
#include "point.hpp"

namespace bad {

struct Figure {
public:
    virtual void print(std::ostream& os) const = 0;
    virtual ~Figure() = default;
};

}; // namespace bad
