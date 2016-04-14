#ifndef __VIGENERE_H__
#define __VIGENERE_H__

#include <malloc.h>
#include <string.h>

const char *vgn_crypt(const char *msg, const char *key);
const char *vgn_decrypt(const char *msg, const char *key);

#endif
