#include <stdio.h>
#include <string.h>

typedef struct Book{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
} book_t;

void printBook(book_t book){
    printf("Book title: %s\n", book.title);
    printf("Book author: %s\n", book.author);
    printf("Book subject: %s\n", book.subject);
    printf("Book id: %d\n\n", book.book_id);
}

int main(){

    struct Book book1;
    book_t book2;

    
    strcpy( book1.title, "C Programming");
    strcpy( book1.author, "Huna Ali");
    strcpy( book1.subject, "C Programming Tutorial");
    book1.book_id = 6457894;

    strcpy( book2.title, "Telecom Billing");
    strcpy( book2.author, "Zara Ali");
    strcpy( book2.subject, "Telecom Billing Tutorial");
    book2.book_id = 7894564;

    printBook(book1);
    printBook(book2);



}