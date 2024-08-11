#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count;

// Function to perform string matching
void strMatch(const char* str, const char* pat) {
    int str_len = strlen(str);
    int pat_len = strlen(pat);

    for (int i = 0; i <= str_len - pat_len; i++) {
        int j = 0;
        while (++count && pat[j] == str[i + j] && j < pat_len) {
            j++;
        }
        if (j == pat_len) return; // Pattern found
    }
}

// Function to generate best-case, worst-case, and average-case scenarios
void plotter() {
    int n;
    char *str;
    FILE *b, *w, *a;

    // Open files to store data
    b = fopen("b.txt", "a");
    w = fopen("w.txt", "a");
    a = fopen("a.txt", "a");

    for (n = 10; n < 1000; n += 10) {
        str = (char*)calloc(n, sizeof(char));
        memset(str, '0', n); // Fill with '0'

        char pat[] = "0000";

        // Best Case
        count = 0;
        strMatch(str, pat);
        fprintf(b, "%d\t%d\n", n, count);

        // Worst Case
        count = 0;
        pat[3] = '1';
        str[n-1] = '1'; // Pattern can be found at the end
        strMatch(str, pat);
        fprintf(w, "%d\t%d\n", n, count);

        // Average Case
        count = 0;
        pat[1] = pat[2] = '1';
        pat[3] = '0';
        str[n/2] = str[n/2 + 1] = '1'; // Pattern appears in the middle
        strMatch(str, pat);
        fprintf(a, "%d\t%d\n", n, count);

        free(str);
    }

    fclose(b);
    fclose(a);
    fclose(w);
}

// Basic tester function to demonstrate string matching
void tester() {
    const char str[] = "harsha";
    const char pat[] = "har";
    int n = strlen(str);
    int patlen = strlen(pat);

    printf("String: %s\n", str);
    printf("Pattern: %s\n", pat);

    count = 0;
    strMatch(str, pat);

    printf("Number of comparisons: %d\n", count);
}

int main() {
    // Call the tester function to perform a basic string match
    tester();

    // Call the plotter function to measure string matching performance
    plotter();

    return 0;
}