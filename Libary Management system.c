#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 100 


struct Book {
    int book_id;
    char title[50];
    char author[50];
    int is_available;
};


struct Book library[MAX_BOOKS];

int num_books = 0;


void add_book(int book_id, char title[], char author[]) {
    if (num_books >= MAX_BOOKS) {
        printf("Error: Library is full.\n");
        return;
    }

    struct Book new_book;
    new_book.book_id = book_id;
    strcpy(new_book.title, title);
    strcpy(new_book.author, author);
    new_book.is_available = 1; 

    library[num_books++] = new_book;

    printf("Book added successfully.\n");
}

void display_books() {
    printf("ID\tTitle\tAuthor\tAvailable?\n");

    for (int i = 0; i < num_books; i++) {
        printf("%d\t%s\t%s\t%s\n", library[i].book_id, library[i].title, library[i].author, library[i].is_available ? "Yes" : "No");
    }
}


void search_book(char title[]) {
    int found = 0;

    for (int i = 0; i < num_books; i++) {
        if (strcmp(library[i].title, title) == 0) {
            found = 1;
            printf("ID: %d\nTitle: %s\nAuthor: %s\nAvailable: %s\n", library[i].book_id, library[i].title, library[i].author, library[i].is_available ? "Yes" : "No");
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}


void borrow_book(int book_id) {
    int found = 0;

    for (int i = 0; i < num_books; i++) {
        if (library[i].book_id == book_id) {
            found = 1;

            if (library[i].is_available) {
                library[i].is_available = 0;
                printf("Book borrowed successfully.\n");
            } else {
                printf("Book not available for borrowing.\n");
            }
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}


void return_book(int book_id) {
    int found = 0;

    for (int i = 0; i < num_books; i++) {
        if (library[i].book_id == book_id) {
            found = 1;

            if (!library[i].is_available) {
                library[i].is_available = 1;
                printf("Book returned successfully.\n");
            } else {
                printf("Book not borrowed.\n");
            }
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}


int main() {
    int choice, book_id;
    char title[50], author[50];

    while (1) {
        printf("\nLibrary Management System\n");
        printf("-------------------------\n");
            printf("Enter your choice:\n");
    printf("1. Add a book\n");
    printf("2. Display all books\n");
    printf("3. Search for a book\n");
    printf("4. Borrow a book\n");
    printf("5. Return a book\n");
    printf("6. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter book ID: ");
            scanf("%d", &book_id);
            printf("Enter book title: ");
            scanf("%s", title);
            printf("Enter book author: ");
            scanf("%s", author);
            add_book(book_id, title, author);
            break;

        case 2:
            display_books();
            break;

        case 3:
            printf("Enter book title: ");
            scanf("%s", title);
            search_book(title);
            break;

        case 4:
            printf("Enter book ID: ");
            scanf("%d", &book_id);
            borrow_book(book_id);
            break;

        case 5:
            printf("Enter book ID: ");
            scanf("%d", &book_id);
            return_book(book_id);
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice.\n");
    }
}

return 0;
}
