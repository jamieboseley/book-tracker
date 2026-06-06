#include "book.h"



/**
 * [book.c]
 * Function: displayRecords
 * Purpose: Displays the records to the terminal.
 * Parameters:
 *   - records (Book): The dynamically allocated array of structs.
 *   - record_count (int): The number of records in the array.
 * Example: displayRecords(records, record_count);
 * Effects: ???
 * Return: None.
*/
void displayRecords (Book *records, int record_count)
{
    // Check if any records exist.
    if (record_count <= 0)
    {
        printf("No records were found.");
        return;
    }

    // TO DO: Add clean dynamic spacing.
}
