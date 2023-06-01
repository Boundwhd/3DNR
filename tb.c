#include "3DNR.h"

int main() {
	FILE* f = fopen("D:\\RAWtest\\AFTER_DENOISE\\IMG_7_2_after_denoise.raw","rb");
    char filename[] = "IMG_7_2_after_denoise.raw";
    if (!f) {
        printf("Err: load_image: file not found! (%s)\n", filename);
        (-1);
    }
    else {
        printf("(%s) successfully open!\n",filename);
    }
}