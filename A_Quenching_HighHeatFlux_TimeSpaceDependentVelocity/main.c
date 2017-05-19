/*==========================================================================================================
 
 Programmer:    Zeyong Wang
 
 Date:          Mar-29-2017
 
 Model:         Uniform velocity in the direction normal to the wall. Velocity is a function of time and distance to centerline of bubble
 
 Objective:     Given non-dimensionalized velocity U0 at r=R, solve for space and time averaged wall superheat.
 
 ==========================================================================================================*/

#include <stdio.h>
#include <math.h>
#include "share.h"


double U0,tau_star,tau_global,D,theta_exp;


int main(int argc, const char * argv[]) {
    
    // Properties
    double rhol,cpl,kl,al,t0,R,qw_pp,dtw,t_w,npp,xi;
    
    double temp,theta_ave;
    
    rhol=958.5;
    cpl=4217.;
    kl=0.665;
    al=kl/rhol/cpl;
    
    R=1.e-3;
    
    FILE *f_in, *f_out;
    
    f_in=fopen("input.dat", "r");
    f_out=fopen("output.csv", "w");
    
    fprintf(f_out, "%12s,%12s,%12s,%12s,%12s,%12s,%12s,%12s,%12s\n","D_b (m)","t_0(s)","qw_pp(w/m^2)","dtw(K)","t_w(s)","n(1/m^2)","theta","U0","xi");
    printf("%12s,%12s,%12s,%12s,%12s,%12s,%12s,%12s,%12s\n","D_b (m)","t_0(s)","qw_pp(w/m^2)","dtw(K)","t_w(s)","n(1/m^2)","theta","U0","xi");
    
    int i=1;
    while (fscanf(f_in, "%lf %lf %lf %lf %lf %lf",&R,&t0,&qw_pp,&dtw,&t_w,&npp)!=EOF) {
        
        R=R/1000./2.;
        t0/=1000.;
        qw_pp*=1000.;
        D=al*t0/pow(R, 2.);
        theta_exp=kl*dtw/qw_pp/R;
        t_w/=1000.;
        npp*=1.e4;

        U0=BRENT(0.1, 40., 1.e-6, U0Effect);
        
//        xi=U0/(npp*t0/t_w);
        xi=U0/(pow(npp, 3./2.)*t0);
        xi=U0/(pow(npp, 3./2.));
        xi=U0/(pow(npp, 3./2.)*t0/t_w);
        
        fprintf(f_out, "%12.4e,%12.4e,%12.4e,%12.4e,%12.4e,%12.4e,%12.4e,%12.4e,%12.4e\n",R*2.,t0,qw_pp,dtw,t_w,npp,theta_exp,U0,xi);
        printf("%12.4e,%12.4e,%12.4e,%12.4e,%12.4e,%12.4e,%12.4e,%12.4e,%12.4e\n",R*2.,t0,qw_pp,dtw,t_w,npp,theta_exp,U0,xi);
<<<<<<< HEAD
        if ((i==4) || (i==8)) {
            printf("====================================================================================================================\n");
        }
        i++;
=======

>>>>>>> 6aab48f655c217bb6598395044ae30b858d8acd9
    }
    
    
    
    fclose(f_in);
    fclose(f_out);
    printf("Hello, World!\n");
    return 0;
}
