#include "fileio.h"



/**
 * [fileio.c]
 * Function: openFile
 * Purpose: Attempts to open a file under the specified mode.
 * Parameters:
 *   - filename (char): The name of the file.
 *   - mode (char): The mode the file should be opened under.
 * Example: FILE *fh = fopen("data.csv", "r");
 * Effects: None.
 * Return: (FILE) The file pointer of the file from the specified name or NULL if unsuccessful.
 */
 FILE *openFile (const char *filename, const char *mode)
 {
    // Verify a valid mode is present.
    if (mode != "r" && mode != "w" && mode != "a") return NULL;

    // Return NULL if file cannot successfully be opened.
    FILE *fh = fopen(filename, mode);
    if (!fh) return NULL;

    return fh;
 }



// Book importFromFile (const char *filename, int *record_count);



/**
 * [fileio.c]
 * Function: exportToFile
 * Purpose: Writes the current user data to a formatted CSV file.
 * Parameters:
 *   - books (Book): An array of user entries.
 *   - record_count (int): The number of user entries.
 * Example: exportToFile(books, 20);
 * Effects: ???
 * Return: 1 if data was exported succesfully. 0 if the data was not exported.
 */
int exportToFile (Book books, int record_count)
{
    // Verify a valid record count.
    if (record_count <= 0) return 0;

    // Return 0 if the file could not be opened.
    FILE *export_fh = openFile("data.csv", "w");
    if (!export_fh) return 0;

    // Print header row to file.
    fprintf(export_fh, "Title,Author,Genre,PageCount,Price,Rating\n");

    // Write user data to file.
    for (int i = 0; i < record_count; i++)
    {
        fprintf(export_fh, "%s,%s,%s,%d,%.2lf,%d", books[i].title, books[i].author, books[i].genre, books[i].page_count, books[i].price, books[i].rating);
    }

    return 1;
}