#include <stdio.h>
#include <string.h>

typedef struct Book{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
} book_t;

void printBook(book_t *book){
    printf("Book title: %s\n", book->title);
    printf("Book author: %s\n", book->author);
    printf("Book subject: %s\n", book->subject);
    printf("Book id: %d\n\n", book->book_id);
}

int main(){

    book_t * book1ptr = malloc( sizeof( book_t));
    if (book1ptr == NULL) {
        printf("malloc() failed to allocate memory for book1\n");
        exit(1);
    }


    book_t * book2ptr = malloc( sizeof( book_t));
    if (book2ptr == NULL) {
        printf("malloc() failed to allocate memory for book2\n");
        exit(1);
    }

    
    strcpy( book1ptr->title, "C Programming");
    strcpy( book1ptr->author, "Huna Ali");
    strcpy( book1ptr->subject, "C Programming Tutorial");
    book1ptr->book_id = 6457894;

    strcpy( book2ptr->title, "Telecom Billing");
    strcpy( book2ptr->author, "Zara Ali");
    strcpy( book2ptr->subject, "Telecom Billing Tutorial");
    book2ptr->book_id = 7894564;

    printf("Book 1:\n");
    printBook(book1ptr);

    printf("Book 2:\n");
    printBook(book2ptr);



}