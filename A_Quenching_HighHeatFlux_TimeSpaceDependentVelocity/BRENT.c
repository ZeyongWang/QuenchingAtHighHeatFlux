/*==========================================================================================================
 
 Programmer:    Zeyong Wang
 
 Date:          Mar-29-2017
 
 Model:         BRENT Root-Finding Algorithm
 
 Objective:     Solve for the root of func between a and b given tollerance tol.
 
 ==========================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "share.h"

double BRENT (double a,double b,double tol,double (*func) (double)) {
    
    double c,s,d,temp;
    
    int FLAG=1;
    int i;
    
    if ((func(a)*func(b))>0.) {
        printf("The root is not bracketed!\n");
        b=0.;
        return b;
        //exit(EXIT_FAILURE);
    }
    
    if (fabs(func(a))<fabs(func(b))) {
        temp=a;
        a=b;
        b=temp;
    }
    c=a;
    
    for (i=0; i<10000; i++) {
        if ((func(a)!=func(c)) && (func(b)!=func(c))) {
            s=a*func(b)*func(c)/(func(a)-func(b))/(func(a)-func(c))+b*func(a)*func(c)/(func(b)-func(a))/(func(b)-func(c))+c*func(a)*func(b)/(func(c)-func(a))/(func(c)-func(b));
        }
        else {
            s=b-func(b)*(b-a)/(func(b)-func(a));
        }
        
        if (((s<(3*a+b)/4)||(s>b)) || ((FLAG==1)&&(fabs(s-b)>=(fabs(b-c)/2))) || ((FLAG==0)&&(fabs(s-b)>=(fabs(c-d)/2))) || ((FLAG==1)&&(fabs(b-c)<fabs(tol))) || ((FLAG==0)&&(fabs(c-d)<fabs(tol)))) {
            s=(a+b)/2;
            FLAG=1;
        }
        else {
            FLAG=0;
        }
        
        d=c;
        c=b;
        
        if ((func(a)*func(s))<0.) {
            b=s;
        }
        else {
            a=s;
        }
        
        if (fabs(func(a))<fabs(func(b))) {
            temp=a;
            a=b;
            b=temp;
        }
        
        
        if ((fabs(func(b))<tol) || (fabs(func(s))<tol) || (fabs(b-a)<tol)) {
            break;
        }
        
        if (i==9999) {
            printf("Iteration Reaches Maximum");
            exit(EXIT_FAILURE);
        }
    }
    
    
    return b;
    
}
