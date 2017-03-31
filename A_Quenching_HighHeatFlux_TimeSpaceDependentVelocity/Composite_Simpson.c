
/*==========================================================================================================
 
 Programmer:    Zeyong Wang
 
 Date:          Mar-29-2017
 
 Model:         Composite Simpson Integration Algorith
 
 Objective:     To Approximate the integral of func(x) from x=lmt_low to x=lmt_up. 
                The interval is divided into N subintervals, where N is even positive integer.
 
 ==========================================================================================================*/
#include <stdio.h>

double ComSimpInt(double (*func) (double x), double lmt_low, double lmt_up, int N) {
    double int_value;
    
    double h;
    double sum0,sum1,sum2;
    double x;
    
    int i;
    
    h=(lmt_up-lmt_low)/N;
    sum0= func(lmt_low)+func(lmt_up);
    sum1=0.;
    sum2=0.;
    
    for (i=1; i<N; i++) {
        x=lmt_low+i*h;
        if (i%2==0) {
            sum2+=func(x);
        }
        else {
            sum1+=func(x);
        }
    }
    int_value=h*(sum0+2.*sum2+4.*sum1)/3.;
    
    return  int_value;
}
