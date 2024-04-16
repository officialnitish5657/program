#include <stdio.h>
#include <string.h>

// Function to perform pattern matching
void patternMatching(char text[], char pattern[]) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    int i, j;

    for (i = 0; i <= textLength - patternLength; i++) {
        for (j = 0; j < patternLength; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == patternLength) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    char text[100], pattern[100];

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    patternMatching(text, pattern);

    return 0;
}
