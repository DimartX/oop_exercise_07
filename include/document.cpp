#include "document.hpp"

namespace bad {

void Document::Insert(std::shared_ptr<figure>& ptr) {
    std::unique_ptr<Command> command = std::unique_ptr<Command>
        (new InsertCommand(this));
    history_.push(std::move(command));
    
    buffer_.push_back(ptr);
}

void Document::Insert(std::shared_ptr<figure>& ptr, int index) {
    buffer_.insert(buffer_.begin() + index, newFigure);
}

void Document::Erase(int index) {
    std::shared_ptr<Figure> tmp = buffer_[index];
    std::unique_ptr<Command> command = std::unique_ptr<Command>
        (new DeleteCommand(std::move(tmp), index, this));
    history_.push(std::move(command));
    
    buffer_.erase(index);
}

void Document::Erase() {
    buffer_.pop_back();
}

void Document::Save(const string& name) const {
    std::ifstream fis(name);
    if (!fis.is_open()) {
        throw std::runtime_error("File is not opened\n");
    }
    while (fis) {
        buffer_.push_back(factory_.FigureCreate(fis));
        documentName_ = name;
    }
}

void Document::Load(const string& name) {
    std::ofstream fos(name);
    if (!fos.is_open()) {
        throw std::runtime_error("File is not opened\n");
    }
    for (auto elem : buffer_) {
        elem->print(fos);
    }
}

void Document::Print(std::ostream& os) const {
    if (buffer_.empty()) {
        os << "Buffer is empty" << std::endl;
        return;
    }
    for (const auto& figure : buffer_) {
        figure->print(os);
    }
}

void Document::Undo() {
    if (history_.empty()) {
        throw std::logic_error("No further undo information\n");
    }
    std::unique_ptr<Command> last = std::move(history_.top());
    last->Undo();
    history_.pop();
}

}; // namespace bad
