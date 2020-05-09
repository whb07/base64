//
// Created by william bright on 5/9/20.
//
#include "base64.h"
#include "urlsafe.h"
#include <stdlib.h>
#include <stdio.h>

int main(void){
    char word[] = "Hello world!";
    int wordlen = sizeof(word);
    char *encoded;
    encoded = (char *) malloc((size_t ) (Base64encode_len(wordlen)));
    encodeURLSafeWithPadding(encoded, Base64encode_len(wordlen), word, wordlen);
    printf("Here is safe with padding:  %s \n ", encoded);
    encodeURLSafeNoPadding(encoded, Base64encode_len(wordlen), word, wordlen);
    printf("Here is safe with NO padding:  %s \n ", encoded);
    char wordPlain[50];
    decodeURLSafe(wordPlain, encoded, Base64encode_len(wordlen));
    free(encoded);
    printf("Here is back to normal:  %s \n ", wordPlain);

    return 0;
}
