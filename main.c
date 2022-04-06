#include "miracl.h"
#include "time.h"
#include "stdlib.h"
#include "stdio.h"

void main()
{
	clock_t start, finish;
	double duration;
	epoint *G=NULL;
	FILE *fp;
	big a, b, p, Gx, Gy, n;
	miracl *mip = mirsys(5000,16);
	a=mirvar(0);
	b=mirvar(0);
	p=mirvar(0);
	Gx=mirvar(0);
	Gy=mirvar(0);
	n=mirvar(0);
	fp = fopen("data.txt", "r+");
	if(fp == 0)
	{
		printf("no file data.txt");
		exit(1);
	}
	mip->IOBASE=16;
	cinnum(a,fp);
	cinnum(b,fp);
	cinnum(p,fp);
	cinnum(Gx,fp);
	cinnum(Gy,fp);
	cinnum(n,fp);
	fclose(fp);
	start = clock();
	ecurve_init(a,b,p,MR_PROJECTIVE);
	finish = clock();
	G=epoint_init();
	if (epoint_set(Gx,Gy,0,G))
		printf("G success\n");
	if (epoint_x(Gx))
		printf("Gx success\n");

	mirkill(a);
	mirkill(b);
	mirkill(p);
	mirkill(Gx);
	mirkill(Gy);
	epoint_free(G);
	mirexit();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("duration: %lf\n", duration);
}
