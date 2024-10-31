
#include <stdio.h>
#include <stdlib.h>

#define FILENAME "data.txt"
#define MAX_LENGTH 1

void writeSentence() {
    FILE *file = fopen(FILENAME, "a"); 
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    char sentence[MAX_LENGTH + 1]; 
    printf("Enter a sentence (up to 100 characters): ");
    fgets(sentence, sizeof(sentence), stdin);

    
    if (fprintf(file, "%s\n", sentence) < 0) {
        perror("Error writing to file");
    }

    fclose(file);
}


void readContent() {
    FILE *file = fopen(FILENAME, "r"); 
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }

    char line[MAX_LENGTH + 1];
    printf("\nContent of %s:\n", FILENAME);
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}

int main() {
    int choice;
    
    do {
        printf("\nMenu:\n");
        printf("1. Write a sentence\n");
        printf("2. Read content\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                writeSentence();
                break;
            case 2:
                readContent();
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
