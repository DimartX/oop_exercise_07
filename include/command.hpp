#pragma once

namespace bad {
struct Command;
}

#include "document.hpp"
#include "figure.hpp"

namespace bad {

struct Command {
public:
    virtual void Undo() = 0;
    virtual ~Command() = default;
protected:
    Document* document_;
};

struct InsertCommand : public Command{
public:
    InsertCommand(Document* document) {
        document_ = document;
    };
    
    void Undo() override;
};

struct DeleteCommand : public Command {
public:
    DeleteCommand(std::shared_ptr<Figure>& figure, int index, Document* document) :
        figure_(figure),
        index_(index) {
        document_ = document;
    };
    
    
    void Undo() override;
private:
    std::shared_ptr<Figure> figure_;
    int index_;
};

}; // namespace bad
