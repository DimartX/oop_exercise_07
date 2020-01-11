#pragma once

#include <iostream>

namespace bad {

struct Figure {
public:
    virtual void print(std::ostream& os) const = 0;
    virtual ~Figure() = default;
};

}; // namespace bad
