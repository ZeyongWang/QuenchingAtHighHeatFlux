
//
//  share.h
//  Integration_Algorithm
//
//  Created by zeyong wang on 3/8/17.
//  Copyright © 2017 zeyong wang. All rights reserved.
//

#ifndef share_h
#define share_h


#endif /* share_h */

#define MIN(a,b) ((a<b)?a:b)

#define PI 3.1415926

double ComSimpInt(double (*func) (double x), double lmt_low, double lmt_up, int N);

double Theta_SpaceAverage(double tau);

double Inst_WallSuperheat(double X);
double U0Effect (double U);
double BRENT (double a,double b,double tol,double (*func) (double));



extern double U0,tau_star,tau_global,D,theta_exp;
