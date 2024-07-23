#ifndef SHELF_H
#define SHELF_H

#include <vector>
#include <string>
#include "Book.h"

class Shelf {
public:
    Shelf(const std::string& name);
    void addBook(const Book& book);
    void removeBook(const std::string& bookTitle);

    std::string getName() const;

    std::vector<Book> getBooks() const;

private:
    std::string name;
    std::vector<Book> books;
};

#endif // SHELF_H