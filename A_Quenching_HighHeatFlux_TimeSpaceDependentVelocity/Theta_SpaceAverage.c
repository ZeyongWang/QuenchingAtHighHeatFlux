/*==========================================================================================================
 
 Programmer:    Zeyong Wang
 
 Date:          Mar-29-2017
 
 Model:         Space Averaged Wall Superheat
 
 Objective:     Given time tau, solve for space averaged wall superheat
 
 ==========================================================================================================*/

#include <stdio.h>
#include <math.h>
#include "share.h"

double Theta_SpaceAverage(double tau) {

    double theta_bar;
    
    double x_ref;
    
    tau_global=tau;
    
    if (tau<tau_star) {
        x_ref=1.-sqrt(1.-U0*(2.*tau-pow(tau, 2.)));
        theta_bar=ComSimpInt(Inst_WallSuperheat, 0., x_ref, 200)+2.*sqrt(D/PI*tau)*(1.-pow(x_ref, 2.));
    }
    else {
        theta_bar=ComSimpInt(Inst_WallSuperheat, 0., 1., 200);
    }
    
    return theta_bar;
}
