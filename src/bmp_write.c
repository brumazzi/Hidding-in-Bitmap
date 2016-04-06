#include <bmp.h>

char bmp_set_header(FILE *bmp, struct bmp_header *header);
char bmp_set_header_map(FILE *bmp, struct bmp_header_map *map);
char bmp_set_colors(FILE *bmp, struct RGB *rgb, int width, int height);

/* This method write bitmap data to file*/
extern char bmp_write(const char *fname, Bitmat *bmp){
	FILE *file = fopen(fname,"w");
	if(!file)
		return NULL;

	if(!bmp->header || !bmp->map || !bmp->rgb)
		return NULL;

	bmp_set_header(file, bmp->header);
	bmp_set_header_map(file, bmp->map);
	bmp_set_colors(file, bmp->rgb);

	return 1;
}

char bmp_set_header(FILE *bmp, struct bmp_header *header){
	fwrite(header, sizeof(struct bmp_header), 1, bmp);
}

char bmp_set_header_map(FILE *bmp, struct bmp_header_map *map){
	fwrite(map, sizeof(struct bmp_header_map), 1, bmp);
}

char bmp_set_colors(FILE *bmp, struct RGB *rgb, int width, int height){
	fwrite(rgb, sizeof(struct RGB)*width*height, 1, bmp);
}
