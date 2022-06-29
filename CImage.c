#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>


//ENCODER STRUCTURE:

//In the encoding process the input component’s samples are grouped into 8 × 8 blocks, and each block is transformed by
//the forward DCT (FDCT) into a set of 64 values referred to as DCT coefficients. One of these values is referred to as the
//DC coefficient and the other 63 as the AC coefficients.
//Each of the 64 coefficients is then quantized using one of 64 corresponding values from a quantization table (determined
//by one of the table specifications shown in Figure 4). No default values for quantization tables are specified in this
//Specification; applications may specify values which customize picture quality for their particular image characteristics,
//display devices, and viewing conditions.

//DECODER STRUCTURE:


//MODES OF OPERATION:

//1)sequential DCT-based 
//2)progressive DCT-based 
//3)lossless
//4)hierarchical

//Markers
const uint16_t JFIF_BYTE_0 = 0x00; // Null
const uint16_t JFIF_SOI    = 0xD8; // Start of image 
const uint16_t JFIF_EOI	   = 0xD9; // End of image
const uint16_t JFIF_SOS    = 0xDA; // Start of scan
const uint16_t JFIF_DQT    = 0xD8; // Define Quantization Table
const uint16_t JFIF_APP0   = 0xE0; // Application segment 0
const uint16_t JFIF_COM    = 0xFE; // Comment

//Represent image
//Pixel information keeps in 2d arrays in RGB color space
//r - buffer of red value 
//g - buffer of green value
//b - buffer of blue value
//h,w - height and width of image
struct Image{
	uint16_t** r;
	uint16_t** g;
	uint16_t** b;
	uint16_t h,w;
};

//Represent image format
enum Format{
	JPEG,PNG,BMP
};


//Open image by passed filename
struct Image* openImage(const char* filename){
	
	struct Image* img = malloc(sizeof(struct Image));
	
	int b_size = 0;
	char* buffer = 0;

	readBytes(filename,buffer,&b_size);
	decodeImage();

	return img;
}

//Save image
void saveImage(const char* filename,struct Image* img,enum Format f){

}

void compressImage(struct Image* img,float lvl){

}

//Make clone of image
struct Image* cloneImage(struct Image* src){
	
	struct Image* trg = malloc(sizeof(struct Image));

	uint16_t** r = malloc(src->h * sizeof(uint16_t*));
	uint16_t** g = malloc(src->h * sizeof(uint16_t*));
	uint16_t** b = malloc(src->h * sizeof(uint16_t*));

	for(int i = 0;i < src->h;i++)
	{
		r[i] = malloc(src->w * sizeof(uint16_t));
		g[i] = malloc(src->w * sizeof(uint16_t));
		b[i] = malloc(src->w * sizeof(uint16_t));
		
		for(int j = 0;j < src->w;j++)
		{
			r[i][j] = src->r[i][j];
			g[i][j] = src->g[i][j];
			b[i][j] = src->b[i][j];
		}
	}

	trg->r = r;
	trg->g = g;
	trg->b = b;
	trg->h = src->h;
	trg->w = src->w;

	return trg;
}

//Clear memory taked image
void clearImage(struct Image* img){

	for(int i = 0;i < img->h;i++)
	{
		free(img->r[i]);
		free(img->g[i]);
		free(img->b[i]);
	}

	free(img->r);
	free(img->g);
	free(img->b);
	free(img);

}

void decodeImage(){

}

//Forward discrete cosine transformation
void FDCT(){

}

//Inverse discrete cosine transformation
void IDCT(){

}

void quantization(){

}

void dequantization(){

}

//Returns huffman table 
void getHufTable(){

}

void encodeImage(){

}

void decodeJPEG(){

}

void decodePNG(){

}

void decodeBMP(){

}

//Mapped from RGB color space into YCbCr color space
void toYCbCr(){

}

//Mapped from YCbCr color space into RGB color space
void toRGB(){

}

//Read bytes from file 
//filename - name of the file
//buffer - указатель на массив в который будут записаны данные 
//(ВАЖНО.Указатель должен быть пустым, так как память в куче выделяется самой функцией)
//b_size - указатель на переменную в которую будет записан размер буфера
void readBytes(const char* filename,char* buffer,int* b_size){
	
	FILE* file = fopen(filename,"r");
	b_size = fsize(filename);
	buffer = malloc(b_size);

	if(file)
	{
		fscanf(file,"%s",buffer);
		fclose(file);
	}
	else
	{
		printf("Failed to open file : %s\n",filename);
		exit(EXIT_FAILURE);
	}

}

//Write bytes to file
//filename - name of the file
//buffer - pointer to array with data which must be write in file
void writeBytes(const char* filename,char* buffer){
	FILE* file = fopen(filename,"w");
	fprintf(file, buffer);
	fclose(file);
}


//Returns size of file in bytes
long fsize(const char* filename){
	
	struct stat st;

	if(stat(filename,&st) == 0) 
		return st.st_size;

	return -1;
}

int main()
{
	struct Image* img = openImage("test_img.jpg");

	return 0;
} 
