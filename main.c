//
// Created by william bright on 5/9/20.
//
#include "base64.h"
#include "urlsafe.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(void){
    char word[] = "Hello world!";
    int wordlen = sizeof(word);
    char *decoded;
    char *encoded;
    // encode our word
    encoded = (char *) malloc((size_t ) (Base64encode_len(wordlen)));
    encodeURLSafeWithPadding(encoded, Base64encode_len(wordlen), word, wordlen);
    // decode it
    int encoded_length = length(encoded);
    decoded = (char *) malloc((size_t ) (encoded_length));

    decodeURLSafe(decoded, encoded, encoded_length);
    // check they are the same string, 0 means its equal
    assert(strcmp(word, decoded) == 0);
    // free the memory otherwise it will delete your favorite cat pictures
    free(encoded);
    free(decoded);
    return 0;
}
