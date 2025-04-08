#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "nwtfr.h"

int main (int argc, char *argv[]) {
   double xmn, xmx, ymn, ymx, tolcnv;
   int nx, ny, maxit, narr;
/* Línia de comandes
   int narr double xmn double xmx int nx double ymn double ymx int ny double tolcnv int maxit
 */
   if (argc<10
         || sscanf(argv[1], "%d", &narr)!=1
         || sscanf(argv[2], "%lf", &xmn)!=1
         || sscanf(argv[3], "%lf", &xmx)!=1
         || sscanf(argv[4], "%d", &nx)!=1
         || sscanf(argv[5], "%lf", &ymn)!=1
         || sscanf(argv[6], "%lf", &ymx)!=1
         || sscanf(argv[7], "%d", &ny)!=1
         || sscanf(argv[8], "%lf", &tolcnv)!=1
         || sscanf(argv[9], "%d", &maxit)!=1
      ) {
      fprintf(stderr,"%s narr xmn xmx nx ymn ymx ny tolcnv maxit\n", argv[0]);
      return -1;
   }
double xIncrement, yIncrement;
int j, k, i;
double xj, yk;
double u[narr], v[narr];
double r[narr], g[narr], b[narr];

for(i=0; i<narr; i++){
   scanf("%lf", &u[i]);
   scanf("%lf", &v[i]);
   scanf("%lf", &r[i]);
   scanf("%lf", &g[i]);
   scanf("%lf", &b[i]);
}

xIncrement = (xmx - xmn)/nx;
yIncrement = (ymx - ymn)/ny;

for(j=0; j<nx; j++){
   xj = xmn + j * xIncrement;
   for(k=0; k<ny; k++){
      yk = ymn + k * yIncrement;
      i = cnvnwt (xj, yk, tolcnv, maxit, narr, u, v);
      if(i == -1){
         printf("%f %f 255 255 255\n",xj, yk);
         }
      else{
         int redInt = (int)(r[i]*255);
         int blueInt = (int)(b[i]*255);
         int greenInt = (int)(g[i]*255);
         printf("%f %f %d %d %d\n",xj, yk, redInt, blueInt, greenInt);
      }
      }
   }

   return 0;
}