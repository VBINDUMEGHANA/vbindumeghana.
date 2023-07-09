#include <iostream>
#include <string>
#include <vector>

// Book class represents a book with title, author, genre, and availability
class Book {
public:
    std::string title;
    std::string author;
    std::string genre;
    bool available;

    Book(const std::string& t, const std::string& a, const std::string& g)
        : title(t), author(a), genre(g), available(true) {}
};

// Library class manages books, members, and borrowing transactions
class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const std::string& title, const std::string& author, const std::string& genre) {
        Book book(title, author, genre);
        books.push_back(book);
    }

    void searchBooks(const std::string& keyword) {
        std::cout << "Search results for '" << keyword << "':\n";
        for (const auto& book : books) {
            if (book.title.find(keyword) != std::string::npos ||
                book.author.find(keyword) != std::string::npos ||
                book.genre.find(keyword) != std::string::npos) {
                std::cout << "Title: " << book.title << ", Author: " << book.author << ", Genre: " << book.genre;
                if (book.available) {
                    std::cout << " (Available)\n";
                } else {
                    std::cout << " (Not available)\n";
                }
            }
        }
    }

    void borrowBook(const std::string& title) {
        for (auto& book : books) {
            if (book.title == title && book.available) {
                book.available = false;
                std::cout << "Successfully borrowed the book: " << book.title << "\n";
                return;
            }
        }
        std::cout << "The book '" << title << "' is either unavailable or does not exist.\n";
    }

    void returnBook(const std::string& title) {
        for (auto& book : books) {
            if (book.title == title && !book.available) {
                book.available = true;
                std::cout << "Successfully returned the book: " << book.title << "\n";
                return;
            }
        }
        std::cout << "The book '" << title << "' is either already available or does not exist.\n";
    }
};

int main() {
    Library library;

    // Add some example books to the library
    library.addBook("The Great Gatsby", "F. Scott Fitzgerald", "Fiction");
    library.addBook("To Kill a Mockingbird", "Harper Lee", "Fiction");
    library.addBook("Pride and Prejudice", "Jane Austen", "Romance");

    // Search for books by title, author, or genre
    library.searchBooks("Fiction");
    library.searchBooks("Harper");

    // Borrow and return books
    library.borrowBook("The Great Gatsby");
    library.borrowBook("To Kill a Mockingbird");
    library.returnBook("To Kill a Mockingbird");
    library.returnBook("To Kill a Mockingbird");

    return 0;
}
