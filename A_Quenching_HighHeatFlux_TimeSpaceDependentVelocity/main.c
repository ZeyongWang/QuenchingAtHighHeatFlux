/*==========================================================================================================
 
 Programmer:    Zeyong Wang
 
 Date:          Mar-29-2017
 
 Model:         Uniform velocity in the direction normal to the wall. Velocity is a function of time and distance to centerline of bubble
 
 Objective:     Given non-dimensionalized velocity U0 at r=R, solve for space and time averaged wall superheat.
 
 ==========================================================================================================*/

#include <stdio.h>
#include <math.h>
#include "share.h"


double U0,tau_star,tau_global,D;


int main(int argc, const char * argv[]) {
    
    // Properties
    double rhol,cpl,kl,al,t0,R,qw_pp,dtw;
    
    double temp,theta_ave;
    
    double theta_exp;
    
    rhol=958.5;
    cpl=4217.;
    kl=0.665;
    al=kl/rhol/cpl;
    
    R=1.e-3;
    
    FILE *f_in, *f_out;
    
    f_in=fopen("input.dat", "r");
    f_out=fopen("output.csv", "w");
    
    while (fscanf(f_in, "%lf %lf %lf %lf",&R,&t0,&qw_pp,&dtw)!=EOF) {
        
        R=R/1000./2.;
        t0/=1000.;
        qw_pp*=1000.;
        D=al*t0/pow(R, 2.);
        theta_exp=kl*dtw/qw_pp/R;
        
        fprintf(f_out, "%s,%s,%s,%s\n","D_b/2 (m)","t_0(s)","qw_pp(w/m^2)","dtw(K)");
        fprintf(f_out, "%f,%f,%f,%f\n",R,t0,qw_pp,dtw);
        fprintf(f_out, "Experimental Wall Superheat: %f\n",theta_exp);
        fprintf(f_out, "%s,%s,%s\n","U0","Theta","U0*R/t0");
        for (int i=1; i<=91; i++) {
            temp=1.e-5+(i-1)*5./10;
            theta_ave=U0Effect(temp);
            fprintf(f_out, "%f,%f,%f\n",temp,theta_ave,temp*R/t0);
        }
        fprintf(f_out, "================================================================\n");
        printf("%f\t%f\t%f\t%f\n",R,t0,qw_pp,dtw);
    }
    
    
    
    fclose(f_in);
    fclose(f_out);
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
