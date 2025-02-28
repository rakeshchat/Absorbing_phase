//The prey-predator model with symmetric DIFFUSION, but update rules are asymmetric.

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "ran2.c"

# define N 1000

# define Trelax 10000
# define T 1000000

# define beta 0.1
# define gamma 0.9

int main()
{

int r,s,i,j,k,t,z; 
char a[N],b[N];
long sd1 =-98765;
double avrA,avrB;
double alpha;

for(alpha=0.220;alpha<=0.350;alpha+=0.001){
//for(beta=0.02;beta<=0.13;beta+=0.005){

avrA=0;avrB=0;
for(z=0;z<N;z++){a[z]=0;b[z]=0;}
for(z=0;z<N;z++){a[z]=ran2(&sd1)<0.5; b[z]=ran2(&sd1)<0.5;}

for(t=1;t<Trelax;t++){
for(z=0;z<N;z++){
  i=ran2(&sd1)*N; 
  j=(i+1)%N;
  k=8*a[i]+4*a[j]+2*b[i]+1*b[j]; 
  switch (k){
          case 4 : if(ran2(&sd1)<alpha){a[i]=1;a[j]=0;b[i]=0;b[j]=0;} break;
          case 2 : if(ran2(&sd1)<alpha){a[i]=0;a[j]=0;b[i]=0;b[j]=1;} break;
          case 5 : if(ran2(&sd1)<alpha){a[i]=1;a[j]=0;b[i]=1;b[j]=0;} break;
          case 1 : if(ran2(&sd1)<alpha){a[i]=1;a[j]=0;b[i]=0;b[j]=0;} break;
          case 13: if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=1;b[j]=0;} break;
          case 9 : if(ran2(&sd1)<0.5){if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=1;b[j]=0;}}
                   else {a[i]=0;a[j]=1;b[i]=1;b[j]=0;} break;
          case 8 : if(ran2(&sd1)<0.5){if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=0;b[j]=0;}}
                   else {a[i]=0;a[j]=1;b[i]=0;b[j]=0;} break;
          case 10: if(ran2(&sd1)<0.5){if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=0;b[j]=1;}}
                   else {a[i]=0;a[j]=1;b[i]=0;b[j]=1;} break;
          case 14: if(ran2(&sd1)<0.5){if(ran2(&sd1)<gamma){a[i]=1;a[j]=0;b[i]=1;b[j]=1;}}
                   else {a[i]=1;a[j]=1;b[i]=0;b[j]=1;} break;
          case 15: if(ran2(&sd1)<beta){a[i]=1;a[j]=1;b[i]=0;b[j]=0;} break;
          case 3 : if(ran2(&sd1)<beta){a[i]=0;a[j]=0;b[i]=0;b[j]=0;} break;
          case 6 : if(ran2(&sd1)<0.5){
                   if(ran2(&sd1)<gamma){a[i]=0;a[j]=0;b[i]=1;b[j]=1;}}
                   else {a[i]=1;a[j]=0;b[i]=0;b[j]=1;}  break;
          case 7 : if(ran2(&sd1)<beta){a[i]=1;a[j]=0;b[i]=0;b[j]=0;} break;
          case 11: if(ran2(&sd1)<0.5){if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=1;b[j]=1;}}
                   else if(ran2(&sd1)<beta){a[i]=0;a[j]=1;b[i]=0;b[j]=0;} break;
          }//1st switch ends
         }//N ends
       }//Trelax ends

for(t=1;t<T;t++){         //for T mcs
for(z=0;z<N;z++){
  i=ran2(&sd1)*N; j=(i+1)%N;
  k=8*a[i]+4*a[j]+2*b[i]+1*b[j]; 
  switch (k){
          case 4 : if(ran2(&sd1)<alpha){a[i]=1;a[j]=0;b[i]=0;b[j]=0;} break;
          case 2 : if(ran2(&sd1)<alpha){a[i]=0;a[j]=0;b[i]=0;b[j]=1;} break;
          case 5 : if(ran2(&sd1)<alpha){a[i]=1;a[j]=0;b[i]=1;b[j]=0;} break;
          case 1 : if(ran2(&sd1)<alpha){a[i]=1;a[j]=0;b[i]=0;b[j]=0;} break;
          case 13: if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=1;b[j]=0;} break;
          case 9 : if(ran2(&sd1)<0.5){if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=1;b[j]=0;}}
                   else {a[i]=0;a[j]=1;b[i]=1;b[j]=0;} break;
          case 8 : if(ran2(&sd1)<0.5){if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=0;b[j]=0;}}
                   else {a[i]=0;a[j]=1;b[i]=0;b[j]=0;} break;
          case 10: if(ran2(&sd1)<0.5){if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=0;b[j]=1;}}
                   else {a[i]=0;a[j]=1;b[i]=0;b[j]=1;} break;
          case 14: if(ran2(&sd1)<0.5){if(ran2(&sd1)<gamma){a[i]=1;a[j]=0;b[i]=1;b[j]=1;}}
                   else {a[i]=1;a[j]=1;b[i]=0;b[j]=1;} break;
          case 15: if(ran2(&sd1)<beta){a[i]=1;a[j]=1;b[i]=0;b[j]=0;} break;
          case 3 : if(ran2(&sd1)<beta){a[i]=0;a[j]=0;b[i]=0;b[j]=0;} break;
          case 6 : if(ran2(&sd1)<0.5){
                   if(ran2(&sd1)<gamma){a[i]=0;a[j]=0;b[i]=1;b[j]=1;}}
                   else {a[i]=1;a[j]=0;b[i]=0;b[j]=1;}  break;
          case 7 : if(ran2(&sd1)<beta){a[i]=1;a[j]=0;b[i]=0;b[j]=0;} break;
          case 11: if(ran2(&sd1)<0.5){if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=1;b[j]=1;}}
                   else if(ran2(&sd1)<beta){a[i]=0;a[j]=1;b[i]=0;b[j]=0;} break;
          }/*2nd switch ends*/
       }//N ends
   for(z=0;z<N;z++){ avrA+= a[z]; avrB+= b[z];}  
      }//T ends
   printf("%lf  %lf  %lf\n",alpha,avrA/N/T,avrB/N/T); 
  
  }//alpha loop

//  printf("\n"); }//beta loop


}//main ends
