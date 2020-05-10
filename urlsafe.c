#include "urlsafe.h"
#include "base64.h"

void RemovePadding(char * coded_dst, int len_coded_dst) {
    for(int i = 0; i < len_coded_dst; i++){
        if(coded_dst[i] == '='){
            coded_dst[i] = '\0';
            return;
        }
    }
}

void SwapNotSafeChars(char * coded_dst, int len_coded_dst) {
    for(int i = 0; i < len_coded_dst; i++){
        if(coded_dst[i] == '+'){
            coded_dst[i] = '-';
        } else if(coded_dst[i] == '/'){
            coded_dst[i] = '_';
        }
    }
}

void ReplaceSafeChars(char *url_safe_coded_src, int len_url_safe_coded_src){
    for(int i = 0; i < len_url_safe_coded_src; i++){
        if(url_safe_coded_src[i] == '-'){
            url_safe_coded_src[i] = '+';
        } else if(url_safe_coded_src[i] == '_'){
            url_safe_coded_src[i] = '/';
        }
    }
}

int decodeURLSafe(char * plain_dst, char *coded_src, int len_coded_src) {
    ReplaceSafeChars(coded_src, len_coded_src);
    return Base64decode(plain_dst, coded_src);
}



int encodeURLSafeNoPadding(char * coded_dst, int len_coded_dst, const char *plain_src, int len_plain_src) {
    int result = Base64encode(coded_dst, plain_src, len_plain_src);
    SwapNotSafeChars(coded_dst, len_coded_dst);
    RemovePadding(coded_dst, len_coded_dst);
    return result;
}

int encodeURLSafeWithPadding(char * coded_dst, int len_coded_dst, const char *plain_src, int len_plain_src) {
    int result = Base64encode(coded_dst, plain_src, len_plain_src);
    SwapNotSafeChars(coded_dst, len_coded_dst);
    return result;
}

int length(const char *str){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    // add one for the null fairy
    return i + 1;
}
