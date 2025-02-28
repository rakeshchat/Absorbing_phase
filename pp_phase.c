//The prey-predator model, alpha_critical = 0.1484
// awk '{print $1,$2,$3,$3*$3}' phase>phase1

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "ran2.c"

# define N      1000
# define Trelax 1000
# define T      10000

# define r      0.3

int main()
{

int a[N],b[N],z,t,i,j,k;
long sd1 =-98765;
double avrA,avrB;
double p,q;


for(p=1.0;p>0.0;p-=0.05){
for(q=0.001;q<0.075;q+=0.001){

avrA=0;avrB=0;
for(z=0;z<N;z++){a[z]=0;b[z]=0;}
for(z=0;z<N;z++){a[z]=ran2(&sd1)<0.5; b[z]=ran2(&sd1)<0.5;}

for(t=1;t<Trelax;t++){
for(z=0;z<N;z++){
  i=ran2(&sd1)*N; 
  j=(i+1)%N;
  k=8*a[i]+4*a[j]+2*b[i]+1*b[j]; 
  switch (k){
          case 8 : if(ran2(&sd1)<p){a[i]=1;a[j]=1;b[i]=0;b[j]=0;} break;
          case 9 : if(ran2(&sd1)<p){a[i]=1;a[j]=1;b[i]=0;b[j]=1;} break;
          case 10: if(ran2(&sd1)<p){a[i]=1;a[j]=1;b[i]=1;b[j]=0;} break;
          case 14: if(ran2(&sd1)<r){a[i]=1;a[j]=0;b[i]=1;b[j]=1;} break;
          case 15: if(ran2(&sd1)<q){a[i]=1;a[j]=1;b[i]=0;b[j]=0;} break;
          case 3 : if(ran2(&sd1)<q){a[i]=0;a[j]=0;b[i]=0;b[j]=0;} break;
          case 6 : if(ran2(&sd1)<r){a[i]=0;a[j]=0;b[i]=1;b[j]=1;} break;
          case 7 : if(ran2(&sd1)<q){a[i]=0;a[j]=1;b[i]=0;b[j]=0;} break;
          case 11: if(ran2(&sd1)<p){a[i]=1;a[j]=1;b[i]=1;b[j]=1;}
               else if(ran2(&sd1)<q){a[i]=1;a[j]=0;b[i]=0;b[j]=0;} break;
          }//1st switch ends
         }//N ends
       }//Trelax ends

for(t=1;t<T;t++){         //for T mcs
for(z=0;z<N;z++){
  i=ran2(&sd1)*N; j=(i+1)%N;
  k=8*a[i]+4*a[j]+2*b[i]+1*b[j]; 
  switch (k){
          case 8 : if(ran2(&sd1)<p){a[i]=1;a[j]=1;b[i]=0;b[j]=0;} break;
          case 9 : if(ran2(&sd1)<p){a[i]=1;a[j]=1;b[i]=0;b[j]=1;} break;
          case 10: if(ran2(&sd1)<p){a[i]=1;a[j]=1;b[i]=1;b[j]=0;} break;
          case 14: if(ran2(&sd1)<r){a[i]=1;a[j]=0;b[i]=1;b[j]=1;} break;
          case 15: if(ran2(&sd1)<q){a[i]=1;a[j]=1;b[i]=0;b[j]=0;} break;
          case 3 : if(ran2(&sd1)<q){a[i]=0;a[j]=0;b[i]=0;b[j]=0;} break;
          case 6 : if(ran2(&sd1)<r){a[i]=0;a[j]=0;b[i]=1;b[j]=1;} break;
          case 7 : if(ran2(&sd1)<q){a[i]=0;a[j]=1;b[i]=0;b[j]=0;} break;
          case 11: if(ran2(&sd1)<p){a[i]=1;a[j]=1;b[i]=1;b[j]=1;}
               else if(ran2(&sd1)<q){a[i]=1;a[j]=0;b[i]=0;b[j]=0;} break;
          }/*2nd switch ends*/
       }//N ends
   for(z=0;z<N;z++){avrB += b[z];}  
      }//T ends

if(avrB/N/T<0.001){printf("%lf  %lf  %lf\n",p,q,avrB/N/T);q=0.075;}


  }//p loop
 }//q loop

}//main ends
