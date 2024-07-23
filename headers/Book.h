#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "Author.h"

class Book {
public:
    Book(const std::string& title, const Author& author);

    std::string getTitle() const;

    Author getAuthor() const;

private:
    std::string title;
    Author author;
};

#endif // BOOK_H