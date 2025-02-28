//The prey-predator model(modified)
//For Periodic Boundary condition

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ran2.c"
#define N 200              //number of sites
#define Trelax 100000        //timestep   
#define T 1000
#define alpha 0.2
//#define beta 0.02
//#define gamma 0.2

main()
{
long sd =-92789;
int r,s,i,j,k,t,z; 
char a[N],b[N];
double avrA=0,avrB=0; 
double beta,gamma;

FILE *fp,*fpgb,*fpab;
fp=fopen("ppm2.out","w");
fpgb=fopen("gammabeta.out","w");
fpab=fopen("alphabeta.out","w");

for(beta=0.01;beta<0.03;beta+=0.001){
for(gamma=0.1;gamma<0.2;gamma+=0.01){
avrA=0;avrB=0;
for(z=0;z<N;z++){a[z]=ran2(&sd)<0.5;b[z]=ran2(&sd)<0.5;}

for(t=1;t<Trelax;t++){             //for Trelax mcs
for (z=0;z<N;z++){
  i=ran2(&sd)*N; 
  j=(i+1)%N;                       //periodic boundary condition
  k=8*a[i]+4*a[j]+2*b[i]+1*b[j]; 
switch (k){
          case 8 : if(ran2(&sd)<alpha){a[i]=1;a[j]=1;b[i]=0;b[j]=0;} break;
          case 9 : if(ran2(&sd)<alpha){a[i]=1;a[j]=1;b[i]=0;b[j]=1;} break;
          case 10: if(ran2(&sd)<alpha){a[i]=1;a[j]=1;b[i]=1;b[j]=0;} break;
          case 14: if(ran2(&sd)<gamma){a[i]=1;a[j]=0;b[i]=1;b[j]=1;} break;
          case 15: if(ran2(&sd)<beta){a[i]=1;a[j]=1;b[i]=0;b[j]=0;} break;
          case 3 : if(ran2(&sd)<beta){a[i]=0;a[j]=0;b[i]=0;b[j]=0;} break;
          case 6 : if(ran2(&sd)<gamma){a[i]=0;a[j]=0;b[i]=1;b[j]=1;} break;
          case 7 : if(ran2(&sd)<beta){a[i]=0;a[j]=1;b[i]=0;b[j]=0;} break;
          case 11: if(ran2(&sd)<alpha){a[i]=1;a[j]=1;b[i]=1;b[j]=1;}
                   else if(ran2(&sd)<beta){a[i]=1;a[j]=0;b[i]=0;b[j]=0;} break;
          }//1st switch ends
    }//for ends

    //  for(z=0;z<N;z++){avrA+= a[z];avrB+=b[z];} 
//     fprintf(fp,"%d %lf %lf\n",t,avrA/N/t,avrB/N/t);
    
   }//Trelax ends

for(t=1;t<T;t++){         //for T mcs
for (z=0;z<N;z++){
  i=ran2(&sd)*N;
  j=(i+1)%N;
  k=8*a[i]+4*a[j]+2*b[i]+1*b[j]; 
switch (k){
          case 8 : if(ran2(&sd)<alpha){a[i]=1;a[j]=1;b[i]=0;b[j]=0;} break;
          case 9 : if(ran2(&sd)<alpha){a[i]=1;a[j]=1;b[i]=0;b[j]=1;} break;
          case 10: if(ran2(&sd)<alpha){a[i]=1;a[j]=1;b[i]=1;b[j]=0;} break;
          case 14: if(ran2(&sd)<gamma){a[i]=1;a[j]=0;b[i]=1;b[j]=1;} break;
          case 15: if(ran2(&sd)<beta){a[i]=1;a[j]=1;b[i]=0;b[j]=0;} break;
          case 3 : if(ran2(&sd)<beta){a[i]=0;a[j]=0;b[i]=0;b[j]=0;} break;
          case 6 : if(ran2(&sd)<gamma){a[i]=0;a[j]=0;b[i]=1;b[j]=1;} break;
          case 7 : if(ran2(&sd)<beta){a[i]=0;a[j]=1;b[i]=0;b[j]=0;} break;
          case 11: if(ran2(&sd)<alpha){a[i]=1;a[j]=1;b[i]=1;b[j]=1;}
                   else if(ran2(&sd)<beta){a[i]=1;a[j]=0;b[i]=0;b[j]=0;} break;
          }//2nd switch ends
    }//for ends

    for(z=0;z<N;z++){avrA+= a[z];avrB+=b[z];} 
//    fprintf(fp,"%d %lf %lf\n",t,avrA/N/t,avrB/N/t);
     }//T ends

printf("%lf  %lf  %lf  %lf\n",gamma,beta,avrA/N/T, avrB/N/T);
//printf("%lf  %lf  %lf  %lf\n",alpha,beta,avrA/N/t, avrB/N/t);

   }//gamma or alpha loop
printf("\n");
  }//beta loop

fclose(fp);
fclose(fpgb);
fclose(fpab);
//system("gnuplot ppm2.gp");

}//main ends
