#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>

class Author {
public:
    Author(const std::string& name);
    std::string getName() const;

private:
    std::string name;
};

#endif // AUTHOR_H