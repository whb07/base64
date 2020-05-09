//
// Created by william bright on 5/9/20.
//

#ifndef BASE64_URLSAFE_H
#define BASE64_URLSAFE_H
int encodeURLSafeWithPadding(char * coded_dst, int len_coded_dst, const char *plain_src, int len_plain_src);
int encodeURLSafeNoPadding(char * coded_dst, int len_coded_dst, const char *plain_src, int len_plain_src);
void SwapNotSafeChars(char * coded_dst, int len_coded_dst);
void ReplaceSafeChars(char *url_safe_coded_src, int len_url_safe_coded_src);
int decodeURLSafe(char * plain_dst, const char *coded_src, int len_coded_src);
void RemovePadding(char * coded_dst, int len_coded_dst);
#endif //BASE64_URLSAFE_H
