//
//  Ceasar-cipher.h
//  Chyper-code
//
//  Created by noah helweg on 06/10/2025.
//
// contains the function encrypting the plaintext
#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#include <ctype.h>
#include <string.h>

// Normalize key into [0, 25]
static inline int caesar_normalize_key(int key) {
    int k = key % 26;
    if (k < 0) k += 26;
    return k;
}

// Encrypt using Caesar cipher :can only handel uppercase
void caesar_encrypt(char text[], int key) {
    int k = caesar_normalize_key(key);

    for (int i = 0; text[i] != '\0'; ++i) {
        unsigned char c = (unsigned char)text[i];

        if (isupper(c)) {
            text[i] = (char)(((c - 'A' + k) % 26) + 'A');
        }
    }
}

// Decrypt using Caesar cipher : can only handel uppercase
void caesar_decrypt(char text[], int key) {
    int k = caesar_normalize_key(key);

    for (int i = 0; text[i] != '\0'; ++i) {
        unsigned char c = (unsigned char)text[i];

        if (isupper(c)) {
            text[i] = (char)(((c - 'A' - k + 26) % 26) + 'A');
        }
    }
}

#endif

