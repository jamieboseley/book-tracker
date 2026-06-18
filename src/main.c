#include "../include/fileio.h"

int main (void)
{
    int record_count = 0;
    Book *records = importFromFile("../data/test.csv", &record_count);
    if (!records) 
    {
        printf("Error\n");
        exit(1);
    }

    displayRecords(records, record_count);

    return 0;
}