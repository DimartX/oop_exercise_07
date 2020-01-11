#include "document.hpp"
#include <fstream>

namespace bad {

void Document::Insert(std::shared_ptr<Figure>& ptr) {
    std::unique_ptr<Command> command = std::unique_ptr<Command>
        (new InsertCommand(this));
    history_.push(std::move(command));
    
    buffer_.push_back(ptr);
}

void Document::Insert(std::shared_ptr<Figure>& ptr, int index) {
    buffer_.insert(buffer_.begin() + index, ptr);
}

void Document::Erase(int index) {
    std::shared_ptr<Figure> tmp = buffer_[index];
    std::unique_ptr<Command> command = std::unique_ptr<Command>
        (new DeleteCommand(tmp, index, this));
    //std::cout << "PUSHED ";
    //tmp->print(std::cout);
    history_.push(std::move(command));
    
    buffer_.erase(buffer_.begin() + index);
}

void Document::Erase() {
    buffer_.pop_back();
}

void Document::Load(const std::string& name) {
    std::ifstream fis(name);
    if (!fis.is_open()) {
        throw std::runtime_error("File is not opened\n");
    }
    documentName_ = name;
    int size_buf;
    fis >> size_buf;
    buffer_.resize(size_buf);
    for (int i = 0; i < buffer_.size(); i++) {
        buffer_[i] = factory_.FigureCreate(fis);
    }
}

void Document::Save(const std::string& name) {
    std::ofstream fos(name);
    if (!fos.is_open()) {
        throw std::runtime_error("File is not opened\n");
    }
    fos << buffer_.size() << std::endl;
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
