#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertEsc(char darr[]) {
    char arr[200];  // Buffer for the string after adding "flag" at the beginning and end
    char result[300] = "";  // Buffer for the final result
    
    // Step 1: Add "flag" at the beginning and end
    strcpy(arr, "flag");
    strcat(arr, darr);
    strcat(arr, "flag");

    // Step 2: Insert "esc" before each occurrence of "flag" or "esc"
    int i = 0;
    while (i < strlen(arr)) {
         // Insert "esc"
            if (strncmp(&arr[i], "flag", 4) == 0) {
                strcat(result, "flag");
                i += 4;  // Skip past "flag"
            } else {
                strcat(result, "esc");
                i += 3;  // Skip past "esc"
            }
        } else {
            strncat(result, &arr[i], 1);  // Copy the current character
            i++;
        }
    }

    // Copy the final result back to the original array
    strcpy(darr, result);
}

int main() {
    char darr[89];
    printf("Enter values: ");
    gets(darr);  // Remove the newline character

    insertEsc(darr);

    printf("Modified string: %s\n", darr);

    return 0;
}
