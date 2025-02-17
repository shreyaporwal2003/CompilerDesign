#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

const char *keywords[] = {"int", "float", "if", "else", "while", "return", "char", "void", "for"};
const int keyword_count = 9;

// Function to check if a word is a keyword
int isKeyword(char *word) {
    for (int i = 0; i < keyword_count; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1; // It's a keyword
        }
    }
    return 0; // Not a keyword
}

// Function to recognize identifiers (variable names)
int isIdentifier(char *word) {
    if (!isalpha(word[0]) && word[0] != '_') return 0;
    for (int i = 1; word[i] != '\0'; i++) {
        if (!isalnum(word[i]) && word[i] != '_') return 0;
    }
    return 1;
}

// Function to recognize numbers
int isNumber(char *word) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (!isdigit(word[i])) return 0;
    }
    return 1;
}

// Function to check if a character is a special symbol
int isSpecialSymbol(char ch) {
    char symbols[] = {'+', '-', '*', '/', '=', '<', '>', '!', ';', '(', ')', '{', '}', ','};
    int len = sizeof(symbols) / sizeof(symbols[0]);
    for (int i = 0; i < len; i++) {
        if (ch == symbols[i]) return 1;
    }
    return 0;
}

// Lexical Analyzer function
void lexicalAnalyzer(char *code) {
    char token[50]; 
    int i = 0, j = 0;

    while (code[i] != '\0') {
        // Skip whitespace
        if (isspace(code[i])) {
            i++;
            continue;
        }

        // Handling special symbols
        if (isSpecialSymbol(code[i])) {
            printf("Special Symbol: %c\n", code[i]);
            i++;
            continue;
        }

        // Handling numbers
        if (isdigit(code[i])) {
            j = 0;
            while (isdigit(code[i])) {
                token[j++] = code[i++];
            }
            token[j] = '\0';
            printf("Number: %s\n", token);
            continue;
        }

        // Handling identifiers and keywords
        if (isalpha(code[i]) || code[i] == '_') {
            j = 0;
            while (isalnum(code[i]) || code[i] == '_') {
                token[j++] = code[i++];
            }
            token[j] = '\0';

            if (isKeyword(token))
                printf("Keyword: %s\n", token);
            else
                printf("Identifier: %s\n", token);

            continue;
        }

        i++; // Move to the next character
    }
}

// Driver function
int main() {
    char code[] = "int main() { int num = 10; if (num > 5) return num; }";
    
    printf("Input Code: %s\n\n", code);
    printf("Lexical Analysis:\n");
    lexicalAnalyzer(code);
    
    return 0;
}
