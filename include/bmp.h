#pragma pack(push,1)
#ifndef  BMP_H
#define  BMP_H

#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

__attribute__((packed)) struct RGB{ // Color of Bitmap file
	char blue;
	char red;
	char green;
	//char reserved;
};

__attribute__((packed)) struct bmp_header{
	char id[2]; // File identificator
	int size; // Size on bytes
	short int r_area_1; // Reserved area
	short int r_area_2; // Reserved area
	int offset; // Offset of Bitmap
};

__attribute__((packed)) struct bmp_header_map{
	int size; // Size of Header - 40 bytes
	int width; // Width of Bitmap
	int height; // Height of Bitmap
	short int p_quality; // Qualit of planes (default = 1)
	short int bpp; // Bits per Pixel
	int compression; // Compresion method
	int image_size; // Size of image
	int h_resolution; // Horizontal resolution
	int v_resolution; // Vertical resolution
	int p_color; // Number of color in palet
	int i_color; // Number of important colors
};

struct bitmap{
	struct bmp_header *header;
	struct bmp_header_map *map;
	struct RGB *rgb;
};

typedef struct bitmap Bitmap;

extern Bitmap *bmp_read(const char *fname); // read bitmap files
extern char bmp_write(const char *fname, Bitmap *bmp); // write bitmap files
extern char *bmp_rgb_to_pchar(struct RGB *rgb); // convert RGB to char vector

#endif  // BMP_H*/
#pragma pack(pop)
