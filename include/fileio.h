#ifndef FILEIO_H
#define FILEIO_H

#include "../include/book.h"
#include <string.h>

#define MAX_BUFFER_SIZE 250

// Function prototypes.
FILE *openFile (const char *filename, const char *mode);
int getRecordCount (FILE *fh);
Book *importFromFile (const char *filename, int *record_count);
int exportToFile (Book *records, int record_count);
Book *importFromBinary (const char *filename, int *record_count);
int exportToBinary (Book *records, int record_count);


#endif