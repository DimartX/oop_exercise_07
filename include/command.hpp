#pragma once

namespace bad {

struct Command {
public:
    virtual void Undo() = 0;
    virtual ~Command() = default;
protected:
    std::shared_ptr<Document> document_;
};

struct InsertCommand : public Command{
public:
    InsertCommand(std::shared_ptr<Document> document) :
        document_(document)
    {};
    
    void Undo() override;
};

struct DeleteCommand : public Command {
public:
    DeleteCommand(std::shared_ptr<Figure>& figure, int index, std::shared_ptr<Document> document) :
        document_(document),
        figure_(figure),
        index_(index)
    {};
    
    
    void Undo() override;
private:
    std::shared_ptr<Figure> figure_;
    int index_;
}

}; // namespace bad
