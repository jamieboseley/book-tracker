#ifndef BOOK_H
#define BOOK_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAIL 1
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 30
#define MAX_GENRE_LEN 20

// Book structure.
typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    char genre[MAX_GENRE_LEN];
    int page_count;
    double price;
    int rating;
} Book;

// Function prototypes.
void displayRecords (Book *records, int record_count);


#endif