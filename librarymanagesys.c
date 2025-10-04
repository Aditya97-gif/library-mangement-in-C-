#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[50];
    char author[50];
    int available;
};
struct Book library[MAX_BOOKS];
int book_count = 0;
void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }
    struct Book b;
    printf("Enter book ID: ");
    scanf("%d", &b.id);
    getchar(); // clear newline after ID input
    printf("Enter book title: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = 0;
    printf("Enter author name: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = 0;
    b.available = 1;
    library[book_count++] = b;
    printf("Book added successfully!\n");
}
void display_books() {
    printf("\n%-5s %-30s %-30s %-10s\n", "ID", "Title", "Author", "Status");
    for (int i = 0; i < book_count; i++) {
        printf("%-5d %-30s %-30s %-10s\n", library[i].id, library[i].title, library[i].author, 
            library[i].available ? "Available" : "Issued");
    }
}
void issue_book() {
    int id;
    printf("Enter book ID to issue: ");
    scanf("%d", &id);
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            if (library[i].available) {
                library[i].available = 0;
                printf("Book issued successfully!\n");
            } else {
                printf("Book already issued!\n");
            }
            return;
        }
    }
    printf("Book not found!\n");
}
void return_book() {
    int id;
    printf("Enter book ID to return: ");
    scanf("%d", &id);
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            if (!library[i].available) {
                library[i].available = 1;
                printf("Book returned successfully!\n");
            } else {
                printf("Book was not issued!\n");
            }
            return;
        }
    }
    printf("Book not found!\n");
}
int main() {
    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n2. Display Books\n3. Issue Book\n4. Return Book\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_book(); break;
            case 2: display_books(); break;
            case 3: issue_book(); break;
            case 4: return_book(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}