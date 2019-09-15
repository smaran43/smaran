#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coeffs.h"


 int  main(void)
{
	
//Defining variables	
    double *P,*m;
    double len,k;
    len = 100;
    
    
//Defining Files
    FILE *fx;
    FILE *fy;
    FILE *fz;
    FILE *fP;
    
//Retriving data

    m = loadtxtvec("./data/m.dat",2);
    P = loadtxtvec("./data/P.dat",2);
    
    
//Opening Files w.r.t its names
    
    fx = fopen("./data/x_values.dat","w");
    fy = fopen("./data/y_values.dat","w");
    fz = fopen("./data/z_values.dat","w");
    fP = fopen(".data/P.dat","w");
    
//Creating loop for finding x and y values
    for(int i = 0;i<len;i++)
    {
		k = -10 + (i*20)/(len-1);
		
		//For creating x values
		fprintf(fx,"%lf\n",k);
		//For creating y values
		fprintf(fy,"%lf\n",(3*pow(k,2)+72)/4);
		//For creating z values
		fprintf(fz,"%lf\n",(((-m[0]/m[1])*(k-P[0]))+P[1]);
	}
	
//Closing and saving .dat files
    fclose(fx);
    fclose(fy);
    fclose(fz);
    
	return 0;
	
}
