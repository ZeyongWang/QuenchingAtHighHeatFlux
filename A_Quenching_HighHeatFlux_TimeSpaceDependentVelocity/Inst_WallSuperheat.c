/*==========================================================================================================
 
 Programmer:    Zeyong Wang
 
 Date:          Mar-29-2017
 
 Model:         Instantaneous Wall Superheat
 
 Objective:     Given time tau and location X, solve for wall superheat. Only for the case X<=X_ref. 
                As this value will integrated over an circle area to get space averaged wall sueprheat, it
                is multiplied by 2X to be integrated in Theta_SpaceAverage.c. (pi has been canceled out).
 
 ==========================================================================================================*/

#include <stdio.h>
#include <math.h>
#include "share.h"

double Inst_WallSuperheat(double X) {
    
    double theta;
    
    double tau_0;
    double a,b,c;
    
    a=U0;
    b=-2.*U0;
    c=-2.*((X-pow(X, 2.)/2.)-U0*(tau_global-pow(tau_global, 2.)/2.));
    
    tau_0=1.-sqrt(pow(b, 2.)-4.*a*c)/2/U0;
    
    theta=2*sqrt(D/PI*fabs((tau_global-tau_0)))*2*X;
    
    return theta;
}
