#include "3DNR.h"
#include "stdint.h"

int main() {
	int image_height = 2448;
	int image_width  = 3264;
	int* min_noise_4channel;

	int GR_min = 200;
	int GB_min = 200;
	int R_min = 200;
	int B_min = 200;

	int noise_block[16][16] = {0};
	u16* bayer_dat;
	bayer_dat = (u16 *)malloc(sizeof(u16) * image_height *image_width);
	memset(bayer_dat,0,sizeof(u16) * image_height * image_width);
	FILE* f1 = fopen("test.txt","w");
	FILE* f = fopen("work/IMG_7_2_after_denoise.raw","rb");
	if(!f){
		printf("open unsuccessfully!\n");
	}else{
		printf("open successfully!\n");
	}
	fread(bayer_dat,sizeof(u16),image_height *image_width,f);

	for(int row = 0;row < image_height - 15;row += 16){
		for(int col = 0;row < image_width - 15;col += 16){
			for(int i = 0;i < 16;i++){
				for(int j = 0;j < 16;j++){
					noise_block[i][j] = bayer_dat[(row + i) * image_width +(j + col)];
				}
			}	
			min_noise_4channel = min_noise(noise_block);
			if(GR_min < min_noise_4channel[0]){
				GR_min = min_noise_4channel[0];
			}
			if(GB_min < min_noise_4channel[1]){
				GB_min = min_noise_4channel[1];
			}
			if(R_min < min_noise_4channel[2]){
				R_min = min_noise_4channel[2];
			}
			if(B_min < min_noise_4channel[3]){
				B_min = min_noise_4channel[3];
			}
		}
	}
	// for(int i = 0;i < 16;i++){
	// 	for(int j = 0;j < 16;j++){
	// 			noise_block[i][j] = bayer_dat[i * image_height + j];
	// 	}
	// }
	// for(int i = 0;i < 16;i++){
    //     			for(int j = 0;j < 16;j++){
    //         			fprintf(f1,"block[%d][%d]=%d\t",i,j,noise_block[i][j]);
    //         			if(j == 15){
    //         				fprintf(f1,"\n");
    //        				}
    //     			}   
    // 			}
	// min_noise_4channel = min_noise(noise_block);
	
	return 0;
}

