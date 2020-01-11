#include "command.hpp"

namespace bad{

void InsertCommand::Undo() {
    document_->Erase();
}

void DeleteCommand::Undo() {
    document_->Insert(figure_, index_);
}

}; //namespace bad



