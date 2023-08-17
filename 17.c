#include <stdio.h>
#include <stdlib.h>

int main() {
    // Opening a file for writing
    FILE *file = fopen("sample.txt", "w");
    
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1; // Exit with an error code
    }

    // Writing data to the file
    fprintf(file, "Hello, this is a sample file.\n");
    fprintf(file, "File operations in C.\n");

    // Closing the file after writing
    fclose(file);

    // Reopening the file for reading
    file = fopen("sample.txt", "r");

    if (file == NULL) {
        printf("Error opening the file for reading.\n");
        return 1; // Exit with an error code
    }

    // Reading and printing the contents of the file
    printf("Contents of the file:\n");
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    // Closing the file after reading
    fclose(file);

    return 0; // Exit successfully
}
