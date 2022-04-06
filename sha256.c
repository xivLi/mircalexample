#include <stdio.h>
#include <time.h>
#include "miracl.h"
int main(){
    clock_t tstart, tend;
    double duration=0.0;
    char test[] = "iftevbseabcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";

    for (int i = 0; i < 1000; i++)
    {
	char hash[32];
        int i;
        sha256 sh;
        shs256_init(&sh);
	tstart = clock();
        for (i=0;test[i]!=0;i++) shs256_process(&sh,test[i]);
        shs256_hash(&sh,hash);
        tend = clock();	
        for (i=0;i<32;i++) printf("%02x",(unsigned char)hash[i]);
        printf("\n");
	duration += (double)(tend-tstart)/CLOCKS_PER_SEC;
    }
    printf("1000 times sha256 duration: %lf\n", duration);
    return 0;
}
