/*==========================================================================================================
 
 Programmer:    Zeyong Wang
 
 Date:          Mar-29-2017
 
 Model:         Effect of U0 on the Average Wall Superheat (Space and Time)
 
 Objective:     Given U0, Solve for Time and Space Averaged Wall Superheat, and subtract it by experimental
                wall superheat. This routine is called by Bisection.c to solve for U0
 
 ==========================================================================================================*/
#include <stdio.h>
#include <math.h>
#include "share.h"

double U0Effect (double U) {
    
    double theta_ave;
    
    U0=U;
    
    // Time needed for particle at X=0 at tau=0 to travel to X=1
    if (U0>1.) {
        tau_star=1.-sqrt(pow(U0, 2.)-U0)/U0;
    }
    else {
        tau_star=1.;
    }
    
    theta_ave=ComSimpInt(Theta_SpaceAverage, 0., 1., 200)-theta_exp;
    
    return theta_ave;
}
