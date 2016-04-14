#include <vigenere.h>

const char *vgn_crypt(const char *msg, const char *key){
	if(!msg || !key)
		return 0;

	char *_new = (char *) malloc(strlen(msg));
	int x;
	for(x=0;x<strlen(msg);x++)
		_new[x] = ((msg[x]+key[x]) % 255)+1;

	return (const char *) _new;
}

const char *vgn_decrypt(const char *msg, const char *key){
	if(!msg || !key)
		return 0;

	char *_new = (char *) malloc(strlen(msg));
	int x;
	for(x=0; x<strlen(msg); x++){
		_new[x] = (msg[x] - key[x])-1;
		_new[x] = (_new[x] < 0) ? 256-_new[x] : _new[x];
	}

	return (const char *) _new;
}
