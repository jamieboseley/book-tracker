#ifndef FILEIO_H
#define FILEIO_H

#include "book.h"

#define MAX_BUFFER_SIZE 250

// Function prototypes.
FILE *openFile (const char *filename, const char *mode);
int getRecordCount (FILE *fh);
Book *importFromFile (const char *filename, int *record_count);
void exportToFile (Book books, int record_count);

#endif

// Add export to binary?