#include "../include/fileio.h"



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
    // Return NULL if file cannot successfully be opened.
    FILE *fh = fopen(filename, mode);
    if (!fh) return NULL;

    return fh;
}



/**
 * [fileio.c]
 * Function: getRecordCount
 * Purpose: Counts and returns the number of records in a file.
 * Parameters:
 *   - fh (FILE): The file pointer of the file holding records.
 * Example: int num = getRecordCount(fh);
 * Effects: Moves file pointer to EOF.
 * Return: (int) The number of records in the file.
*/
int getRecordCount (FILE *fh)
{
    int record_count = 0;
    char buffer[MAX_BUFFER_SIZE];

    // TO DO: Add ability to read and skip header (if applicable).

    while (fgets(buffer, MAX_BUFFER_SIZE, fh)) record_count++;

    return record_count;
}



/**
 * [fileio.c]
 * Function: importFromFile
 * Purpose: Imports records from a file into a dynamically allocated array of structs.
 * Parameters:
 *   - filename (char): The name of the file.
 *   - record_count (int): The number of recorsds in a file.
 * Example: Book books = importFromFile("file.csv", &record_count);
 * Effects: ???
 * Return: (Book) The dynamically allocated struct of records.
*/
Book *importFromFile (const char *filename, int *record_count)
{
    // Open file.
    FILE *fh = openFile(filename, "r");
    if (!fh) return NULL;

    // TO DO: Add ability to read and skip header (if applicable).

    // Get record count.
    *record_count = getRecordCount(fh);
    // Ensure records exist.
    if (*record_count <= 0) return NULL;

    rewind(fh);

    // Allocate memory.
    Book *records = malloc(sizeof(Book) * (*record_count));
    if (!records) return NULL;

    // Read data directly into array.
    int i = 0;
    while (i < (*record_count) && fscanf(fh, " %99[^,],%29[^,],%19[^,],%d,%lf,%d", records[i].title, records[i].author, records[i].genre, &records[i].page_count, &records[i].price, &records[i].rating) == 6) i++;

    fclose(fh);

    return records;
}



/**
 * [fileio.c]
 * Function: exportToFile
 * Purpose: Writes the current user data to a formatted CSV file.
 * Parameters:
 *   - books (Book): An array of user entries.
 *   - record_count (int): The number of user entries.
 * Example: exportToFile(books, 20);
 * Effects: ???
 * Return: 0 if data was exported succesfully. 1 if the data was not exported.
 */
int exportToFile (Book *records, int record_count)
{
    // Verify a valid record count.
    if (record_count <= 0) return FAIL;

    // Return 0 if the file could not be opened.
    FILE *export_fh = openFile("data.csv", "w");
    if (!export_fh) return FAIL;

    // Print header row to file.
    fprintf(export_fh, "Title,Author,Genre,PageCount,Price,Rating\n");

    // Write user data to file.
    for (int i = 0; i < record_count; i++)
    {
        fprintf(export_fh, "%s,%s,%s,%d,%.2lf,%d", records[i].title, records[i].author, records[i].genre, records[i].page_count, records[i].price, records[i].rating);
    }

    return SUCCESS;
}



/**
 * [fileio.c]
 * Function: importFromBinary
 * Purpose: Imports records from a binary file into a dynamically allocated array.
 * Parameters:
 *   - filename (char): The name of the file.
 *   - record_count (int): The number of user entries.
 * Example: Book *records = importFromBinary("bin_records.bin", &record_count);
 * Effects: ???
 * Return: Dynamically allocated array of records or NULL if unsuccessful.
 */
Book *importFromBinary (const char *filename, int *record_count)
{
    // Open binary file.
    FILE *bin_fh = openFile(filename, "r");
    if (!bin_fh) return NULL;

    // Get record count.
    fseek(bin_fh, 0, SEEK_END);
    long position = ftell(bin_fh);
    *record_count = position / sizeof(Book);

    // Allocate an array of structs.
    Book *records = malloc(sizeof(Book) * (*record_count));
    if (!records) return NULL;

    // Read records into the array.
    fread(records, sizeof(Book), (*record_count), bin_fh);

    fclose(bin_fh);
    
    return records;
}



/**
 * [fileio.c]
 * Function: exportToBinary
 * Purpose: Exports records in one write to a binary file.
 * Parameters:
 *   - records (Book): The array of records.
 *   - record_count (int): The number of user entries.
 * Example: int status = exportToBinary(records, record_count);
 * Effects: ???
 * Return: 0 for success or 1 for failed export.
 */
int exportToBinary (Book *records, int record_count)
{
    // TO DO: Handle filenames.
    // Open binary file.
    FILE *bin_fh = openFile("test.bin", "r");
    if (!bin_fh) return FAIL;

    // Attempt to write all records to binary file.
    if (fwrite(records, sizeof(Book), record_count, bin_fh) == (size_t)record_count) 
    {
        fclose(bin_fh);
        return SUCCESS;
    }
    else
    {
        fclose(bin_fh);
        return FAIL;
    }
    // TO DO: Delete file if export failed?
}

