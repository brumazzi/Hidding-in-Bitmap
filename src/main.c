#include <bmp.h>
#include <vigenere.h>
#include <stdio.h>
#include <string.h>

#define usage(ext) \
	puts("usage: bmp-hidden -[ioskcd] [<args>,[<args>]]");\
	puts("");\
	puts("\t-i in.bmp\tBitmap input.");\
	puts("\t-o out.bmp\tBitmap output.");\
	puts("\t-s <msg>\tString to put in bitmap.");\
	puts("\t-k <key>\tString key to crypt msg.");\
	puts("\t-c \tCript message before insert in bitmap.");\
	puts("\t-d \tDecript message after get to bitmap.");\
	puts("");\
	if(ext) printf("Error: %s\n", (const char *) ext);\
	return 1

#define putin(_) \
	x++;\
	_ = (char *) malloc(sizeof(strlen(argv[1])));\
	strcpy(_, argv[x]);\
	break;

int main(int argc, char **argv){
	if(argc < 2){
		usage(0);
	}
	int x,y;
	char *in = 0;
	char *out = 0;
	char *msg = 0;
	char *key = 0;
	char cd = 2;

	for(x=1; x<argc; x++){
		if(argv[1][0] == '-'){
			for(y=1; y<strlen(argv[1]); y++){
				switch(argv[1][y]){
					case 'i':
						putin(in);
					case 'o':
						putin(out);
					case 's':
						putin(msg);
					case 'k':
						putin(key);
					case 'c':
						cd = 1;
						break;
					case 'd':
						cd = 0;
						break;
				}
			}
			
		}else{
			usage(0);
		}
	}
	
	if(!in || !key || cd == 2){
		usage(0);
	}
	if(cd && (!out || !msg)){
		usage("Invalid parameters.");
	}

	Bitmap *bmp = bmp_read(in);
	if(!bmp){
		printf("%s not found or is not a bitmap!", in);
		return 1;
	}


	char *rgb = bmp_rgb_to_pchar(bmp->rgb);
	const char *res = 0;

	if(cd){
		res = vgn_crypt(msg, key);
		for(x=0; x<strlen(msg); x++){
			rgb[x] = res[x];
		}
		bmp->rgb = (struct RGB*) rgb;

		bmp_write(out, bmp);
	}else{
		res = vgn_decrypt(rgb, key);

		puts(res);
	}

	return 0;
}
