#ifndef FILEIO_H
#define FILEIO_H

#include <stdio.h>
#include "book.h"

// Function prototypes.
FILE *openFile (const char *filename, const char *mode);
Book importFromFile (const char *filename, int *record_count);
void exportToFile (Book books, int record_count);

#endif

// Add export to binary?