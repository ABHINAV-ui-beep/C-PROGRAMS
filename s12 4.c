
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_NAME_LENGTH 100

// Structure for Book
struct Book {
    char author_name[MAX_NAME_LENGTH];
    char book_name[MAX_NAME_LENGTH];
};

// Function to read n books
void readBooks(struct Book *books, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details for Book %d:\n", i + 1);
       
        printf("Author Name: ");
        getchar(); // To consume any leftover newline character
        fgets(books[i].author_name, MAX_NAME_LENGTH, stdin);
        // Manually remove newline character if present
        if (books[i].author_name[strlen(books[i].author_name) - 1] == '\n') {
            books[i].author_name[strlen(books[i].author_name) - 1] = '\0';
        }

        printf("Book Name: ");
        fgets(books[i].book_name, MAX_NAME_LENGTH, stdin);
        // Manually remove newline character if present
        if (books[i].book_name[strlen(books[i].book_name) - 1] == '\n') {
            books[i].book_name[strlen(books[i].book_name) - 1] = '\0';
        }
    }
}

// Function to display books
void displayBooks(struct Book *books, int n) {
    printf("\nBook Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Book %d:\n", i + 1);
        printf("Author Name: %s\n", books[i].author_name);
        printf("Book Name: %s\n\n", books[i].book_name);
    }
}

int main() {
    int n;

    printf("Enter the number of books: ");
    scanf("%d", &n);

    // Allocate memory for n books
    struct Book *books = (struct Book *)malloc(n * sizeof(struct Book));
    if (books == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read and display books
    readBooks(books, n);
    displayBooks(books, n);

    // Free allocated memory
    free(books);

    return 0;
}



