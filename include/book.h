#ifndef BOOK_H
#define BOOK_H

#include <stdio.h>
#include <stdlib.h>

// Book structure.
typedef struct {
    char *title;
    char *author;
    char *genre;
    int page_count;
    double price;
    int rating;
} Book;

// Function prototypes.
void displayRecords (Book *records, int record_count);



#endif