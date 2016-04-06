#include <bmp.h>

struct bmp_header *bmp_get_header(FILE *bmp);
struct bmp_header_map *bmp_get_header_map(FILE *bmp);
struct RGB *bmp_get_colors(FILE *bmp, int width, int height);

/* This method read the bitmap files */
extern Bitmap *bmp_read(const char *fname){
	struct bmp_header *header;
	struct bmp_header_map *map;
	struct RGB *rgb;

	Bitmap *bmp = (Bitmap *) malloc(sizeof(Bitmap));
	FILE *file = fopen(fname, "r");

	header = bmp_get_header(file);
	if(header->id[0] != 'B' && header->id[1] != 'M') // verifi if the file is a bitmap file
		return NULL;

	map = bmp_get_header_map(file);
	rgb = bmp_get_colors(file, map->width, map->height);

	fclose(file);
	bmp->header = header;
	bmp->map = map;
	bmp->rgb = rgb;

	return bmp;
}

/* This method read the header of bitmap */
struct bmp_header *bmp_get_header(FILE *bmp){
	struct bmp_header *header;
	header = (struct bmp_header *) malloc(sizeof(struct bmp_header));
	bzero(header, sizeof(struct bmp_header));

	fread(header, sizeof(struct bmp_header), 1, bmp);

	return header;
}

/* This method read the second part of header, with informations of
 * properties of bitmap */
struct bmp_header_map *bmp_get_header_map(FILE *bmp){
	struct bmp_header_map *map;
	map = (struct bmp_header_map *) malloc(sizeof(struct bmp_header_map));
	bzero(map, sizeof(struct bmp_header_map));

	fread(map, sizeof(struct bmp_header_map), 1, bmp);

	return map;
}

/* This method get the vector of colors*/
struct RGB *bmp_get_colors(FILE *bmp, int width, int height){
	struct RGB *rgb = (struct RGB*) malloc(sizeof(struct RGB)*width*height);
	bzero(rgb, sizeof(struct RGB));
	fread(rgb, width*height*3, 1, bmp);

	return rgb;
}
