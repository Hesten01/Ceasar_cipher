//
//  main.c
//  Ceasar_cipher
//
//  Created by noah helweg on 06/10/2025.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Ceasar.h"

void strip_newline(char *s) {
    if (!s) return;
    size_t n = strlen(s);
    if (n && s[n-1] == '\n') s[n-1] = '\0';
}

int main(void) {
    char text[500];
    char line[50];

    printf("Enter a text you whish encrypted or decrypted: ");
    if (!fgets(text, sizeof(text), stdin)) {
        fprintf(stderr, "Failed to read text.\n");
        return 1;
    }
    strip_newline(text);

    printf("\nChoose cipher:\n");
    printf("  1) Caesar\n");
    printf("Choice: ");
    if (!fgets(line, sizeof(line), stdin)) {
        fprintf(stderr, "Failed to read choice.\n");
        return 1;
    }
    int cipher = (int)strtol(line, NULL, 10);

    printf("\nAction:\n");
    printf("  1) Encrypt\n");
    printf("  2) Decrypt\n");
    printf("Choice: ");
    if (!fgets(line, sizeof(line), stdin)) {
        fprintf(stderr, "Failed to read action.\n");
        return 1;
    }
    int action = (int)strtol(line, NULL, 10);

    if (cipher == 1) {
        // Caesar
        printf("\nEnter key: ");
        if (!fgets(line, sizeof(line), stdin)) {
            fprintf(stderr, "Failed to read key.\n");
            return 1;
        }
        int key = (int)strtol(line, NULL, 10);

        if (action == 1) {
            caesar_encrypt(text, key);
            printf("\nEncrypted: %s\n", text);
        } else if (action == 2) {
            caesar_decrypt(text, key);
            printf("\nDecrypted: %s\n", text);
        }
    }
    return 0;
}
