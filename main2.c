#include <stdio.h>
#include <time.h>
#include "miracl.h"
int main(){
    big a,b,p,Gx,Gy,n;
    epoint* G=NULL;
    clock_t tstart, tend;
    double duration=0.0;
    miracl* mip=mirsys(1000,16);
    a=mirvar(0);
    b=mirvar(0);
    p=mirvar(0); //p 256 bits
    Gx=mirvar(0);
    Gy=mirvar(0);
    n=mirvar(0);
    mip->IOBASE=16;
    cinstr(a,"787968B4FA32C3FD2417842E73BBFEFF2F3C848B6831D7E0EC65228B3937E498");
    cinstr(b,"63E4C6D3B23B0C849CF84241484BFE48F61D59A5B16BA06E6E12D1DA27C5249A");
    cinstr(p,"8542D69E4C044F18E8B92435BF6FF7DE457283915C45517D722EDB8B08F1DFC3");
    cinstr(Gx,"421DEBD61B62EAB6746434EBC3CC315E32220B3BADD50BDC4C4E6C147FEDD43D");
    cinstr(Gy,"0680512BCBB42C07D47349D2153B70C4E5D7FDFCBFA36EA1A85841B9E46E09A2");
    cinstr(n,"8542D69E4C044F18E8B92435BF6FF7DD297720630485628D5AE74EE7C32E79B7");
    //printf("a=");
    //cotnum(a,stdout);
    //printf("b=");
    //cotnum(b,stdout);
    //printf("p=");
    //cotnum(p,stdout);
    ecurve_init(a,b,p,MR_PROJECTIVE);
    G=epoint_init();
    if(epoint_set(Gx,Gy,0,G))
        printf("点G生成成功！\n");
    else
        printf("点G生成失败！\n");
    if(epoint_x(Gx))
        printf("Gx坐标有效！\n");
    else
        printf("Gx坐标无效！\n");

    big k = mirvar(0);
    epoint* kk = epoint_init();
    irand(time(NULL));
    for (int i = 0; i < 1000; i++)
    {
        bigrand(n, k);
        cotnum(k,stdout);
        tstart=clock();
        ecurve_mult(k, G, kk);
        tend=clock();
        duration += (double)(tend-tstart)/CLOCKS_PER_SEC;
    }
    printf("1000 times ecurve_mult duration: %lf\n", duration);
    mirkill(a);
    mirkill(b);
    mirkill(p);
    mirkill(Gx);
    mirkill(Gy);
    mirkill(k);
    epoint_free(G);
    epoint_free(kk);
    mirexit();
    return 0;
}
