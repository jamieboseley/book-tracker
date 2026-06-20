#include "../include/book.h"



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

    printf("Title,Author,Genre,PageCount,Price,Rating\n");

    // Index through each record and print.
    for (int i = 0; i < record_count; i++)
    {
        // TO DO: Recognize and handle empty fields.
        printf("%s,%s,%s,%d,%.2lf,%d\n", records[i].title, records[i].author, records[i].genre, records[i].page_count, records[i].price, records[i].rating);
    }
}

