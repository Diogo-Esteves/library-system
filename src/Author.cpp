#include "Author.h"

Author::Author(const std::string& name) : name(name) {}

std::string Author::getName() const {
    return name;
}