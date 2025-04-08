#include <stdio.h>
#include <math.h>
#include "nwtfr.h"

void avalp (double x, double y, double *px, double *py,
      int n, double u[], double v[]) {
      double inicior = 1.;
      double inicioi = 0.;
      for(int i = 0; i < n; i++){
            double termereal = x - u[i];
            double termeimag = y - v[i];
            double partereal = (inicior*termereal - inicioi*termeimag);
            double parteimag = (inicior*termeimag + inicioi*termereal);
            inicior = partereal;
            inicioi = parteimag;
    }
    *px = inicior;
    *py = inicioi;      
}


void avaldp (double x, double y, double *dpx, double *dpy,
      int n, double u[], double v[]) {
      double sumx = 0;
      double sumy = 0;
      
      for (int j = 0; j < n; j++){
            double prodx_tmp = 1;
            double prody_tmp = 0;
            for (int k = 0; k < n; k++){
                  if (k != j){
                        double prodx = (prodx_tmp * (x - u[k])) - (prody_tmp*(y-v[k]));
                        double prody = (prodx_tmp * (y - v[k])) + (prody_tmp*(x-u[k]));
                        prodx_tmp = prodx;
                        prody_tmp = prody;

                  }
            }
            sumx = sumx + prodx_tmp;
            sumy = sumy + prody_tmp;
      }
      *dpx = sumx;
      *dpy = sumy;      
}

int cnvnwt (double x, double y, double tolcnv, int maxit, int n, double u[], double v[]) {
      double px, py, dpx, dpy;
      for (int i = 0; i < maxit; i++){
            avalp(x, y, &px, &py, n, u, v);                         
            avaldp(x, y, &dpx, &dpy, n, u, v);
            for (int j = 0; j < n; j++) {
                  if (sqrt((x - u[j])*(x - u[j]) + (y - v[j])*(y - v[j]) ) < tolcnv){return j;}
            }
            double norma = (dpx * dpx + dpy * dpy);
            double next_x = x - (px * dpx + py * dpy) / norma;
            double next_y = y - (py * dpx - px * dpy) / norma;
            x = next_x;
            y = next_y;
      }
      return -1;
}

