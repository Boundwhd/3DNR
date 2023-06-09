#include"3DNR.h"

unsigned short sqrt(unsigned long a)
{
    unsigned long rem = 0;
    unsigned long root = 0;
    unsigned long divisor = 0;
    
    for (int i = 0; i < 16; i++)

    {
        root <<= 1;
        rem = ((rem << 2) + (a >> 30));
        a <<= 2;
        divisor = (root << 1) + 1;
        if (divisor <= rem) {
            rem -= divisor;
            root++;
        }
    }
    return (unsigned short)(root);
}

int* min_noise(int block[16][16]){
    int min_n[4] = {0};
    int GR_total = 0;
    int GB_total = 0;
    int R_total  = 0;
    int B_total  = 0;

    int GR_sigma = 0;
    int GB_sigma = 0;
    int R_sigma  = 0;
    int B_sigma  = 0;

    for (int i = 0;i < 16;i += 2){
        for (int j = 0;j < 16;j += 2){
            GR_total += block[i][j];
            GB_total += block[i][j+1];
            R_total  += block[i+1][j];
            B_total  += block[i+1][j+1];
        }
    }
    GR_total >>= 6;
    GB_total >>= 6;
    R_total  >>= 6;
    B_total  >>= 6;

    for (int i = 0;i < 16;i += 2) {
        for (int j = 0;j < 16;j += 2) {
            GR_sigma += GR_total - block[i][j];
            GB_sigma += GB_total - block[i][j + 1];
            R_sigma  += R_total  - block[i + 1][j];
            B_sigma  += B_total  - block[i + 1][j + 1];
        }
    }
    min_n[0] = sqrt(GR_sigma >> 6);
    min_n[1] = sqrt(GB_sigma >> 6);
    min_n[2] = sqrt(R_sigma  >> 6);
    min_n[3] = sqrt(B_sigma  >> 6);

    return min_n;
}