#include "Shelf.h"

Shelf::Shelf(const std::string& name) : name(name) {}

void Shelf::addBook(const Book& book) {
    books.push_back(book);
}

void Shelf::removeBook(const std::string& bookTitle) {
    books.erase(std::remove_if(books.begin(), books.end(),
        [&bookTitle](const Book& book) { return book.getTitle() == bookTitle; }), books.end());
}

std::string Shelf::getName() const {
    return name;
}

std::vector<Book> Shelf::getBooks() const {
    return books;
}