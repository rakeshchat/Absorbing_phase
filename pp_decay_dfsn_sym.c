/*Predator population decays with TIME with DIFFUSION, update rules are SYMMETRIC.

gcc -o pp1 pp_decay_dfsn.c -lm
vi job1
chmod +x job1
nohup ./job1 &
*/

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "ran2.c"

# define N      1000
# define beta   0.20
# define gamma  0.9

# define Trelax 1000 
# define M      55                    //for [10*(1.2)^M] limit
# define ENS    1000

//# define alpha 0.330
double alpha;

int main()
{
int i,j,k,t,z,t1,e,tm[M]={}; 
char a[N],b[N];
long sd1 =-987657;
double avrA[M]={},avrB[M]={};

scanf("%lf",&alpha);      //read alpha from "job1" and store it in "temp"

for(t=1;t<Trelax;t++){
for(z=0;z<N;z++){
  i=ran2(&sd1)*N; 
  j=(i+1)%N;
  k=8*a[i]+4*a[j]+2*b[i]+1*b[j]; 
  switch (k){
          
case 1 : a[i]=0;a[j]=0;b[i]=1;b[j]=0; break;
case 2 : a[i]=0;a[j]=0;b[i]=0;b[j]=1; break;
case 3 : if(ran2(&sd1)<beta){a[i]=0;a[j]=0;b[i]=0;b[j]=0;} break;
case 4 : if(ran2(&sd1)<0.5){if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=0;b[j]=0;}}
          else {a[i]=1;a[j]=0;b[i]=0;b[j]=0;} break;
case 5 : if(ran2(&sd1)<0.5){ if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=1;b[j]=0;}}
          else {a[i]=1;a[j]=0;b[i]=1;b[j]=0;} break;
case 6 : if(ran2(&sd1)< 1/3){ if(ran2(&sd1)<gamma){a[i]=0;a[j]=0;b[i]=1;b[j]=1;}}
          else if(1/3 <ran2(&sd1)< 2/3){if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=0;b[j]=1;}}
          else {a[i]=1;a[j]=0;b[i]=0;b[j]=1;} break;
case 7 : if(ran2(&sd1)< 1/3){if(ran2(&sd1)<beta){a[i]=1;a[j]=0;b[i]=0;b[j]=0;}}
          else if(1/3 <ran2(&sd1)< 2/3){if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=1;b[j]=1;}}
          else {a[i]=1;a[j]=0;b[i]=1;b[j]=1;}  break;
case 8 : if(ran2(&sd1)<0.5){if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=0;b[j]=0;}}
          else {a[i]=0;a[j]=1;b[i]=0;b[j]=0;} break;
case 9 : if(ran2(&sd1)< 1/3){if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=1;b[j]=0;}}
          else if(1/3 <ran2(&sd1)< 2/3){if(ran2(&sd1)<gamma){a[i]=0;a[j]=0;b[i]=1;b[j]=1;} }
          else {a[i]=0;a[j]=1;b[i]=1;b[j]=0;} break;
case 10: if(ran2(&sd1)<0.5){if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=0;b[j]=1;}}
          else {a[i]=0;a[j]=1;b[i]=0;b[j]=1;} break;
case 11: if(ran2(&sd1)<0.5){if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=1;b[j]=1;}}
          else if(ran2(&sd1)<beta){a[i]=0;a[j]=1;b[i]=0;b[j]=0;} break;
case 13: if(ran2(&sd1)< 1/3){if(ran2(&sd1)<beta){a[i]=1;a[j]=0;b[i]=0;b[j]=0;}}
         else if(1/3 <ran2(&sd1)< 2/3){if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=1;b[j]=1;}}
         else {a[i]=1;a[j]=0;b[i]=1;b[j]=1;} break;
case 14: if(ran2(&sd1)<0.5){if(ran2(&sd1)<gamma){a[i]=1;a[j]=0;b[i]=1;b[j]=1;}}
          else {a[i]=1;a[j]=1;b[i]=0;b[j]=1;} break;
case 15: if(ran2(&sd1)<beta){a[i]=1;a[j]=1;b[i]=0;b[j]=0;} break;

          }//1st switch ends
         }//N ends
       }//Trelax ends

tm[0]=0; 
for(i=1;i<M;i++){tm[i]=(int)(10.0*pow(1.2,i)) ;}

for(e=0;e<ENS;e++){

for(z=0;z<N;z++){a[z]=0; b[z]=0; }
for(z=0;z<N;z++){a[z]=ran2(&sd1)<0.5; b[z]=ran2(&sd1)<0.5; 
                 avrA[0]+=a[z]; avrB[0]+=b[z]; }    //for avrB[0] value
//printf("0 %lf\n", avrB/N );

for(t=1;t<M;t++){
for(t1=tm[t-1];t1<tm[t];t1++){

//-------------------------------------------------------------------------
for(z=0;z<N;z++){
  i=ran2(&sd1)*N; j=(i+1)%N;
  k=8*a[i]+4*a[j]+2*b[i]+1*b[j]; 
  switch (k){
          
case 1 : a[i]=0;a[j]=0;b[i]=1;b[j]=0; break;
case 2 : a[i]=0;a[j]=0;b[i]=0;b[j]=1; break;
case 3 : if(ran2(&sd1)<beta){a[i]=0;a[j]=0;b[i]=0;b[j]=0;} break;
case 4 : if(ran2(&sd1)<0.5){if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=0;b[j]=0;}}
          else {a[i]=1;a[j]=0;b[i]=0;b[j]=0;} break;
case 5 : if(ran2(&sd1)<0.5){ if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=1;b[j]=0;}}
          else {a[i]=1;a[j]=0;b[i]=1;b[j]=0;} break;
case 6 : if(ran2(&sd1)< 1/3){ if(ran2(&sd1)<gamma){a[i]=0;a[j]=0;b[i]=1;b[j]=1;}}
          else if(1/3 <ran2(&sd1)< 2/3){if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=0;b[j]=1;}}
          else {a[i]=1;a[j]=0;b[i]=0;b[j]=1;} break;
case 7 : if(ran2(&sd1)< 1/3){if(ran2(&sd1)<beta){a[i]=1;a[j]=0;b[i]=0;b[j]=0;}}
          else if(1/3 <ran2(&sd1)< 2/3){if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=1;b[j]=1;}}
          else {a[i]=1;a[j]=0;b[i]=1;b[j]=1;}  break;
case 8 : if(ran2(&sd1)<0.5){if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=0;b[j]=0;}}
          else {a[i]=0;a[j]=1;b[i]=0;b[j]=0;} break;
case 9 : if(ran2(&sd1)< 1/3){if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=1;b[j]=0;}}
          else if(1/3 <ran2(&sd1)< 2/3){if(ran2(&sd1)<gamma){a[i]=0;a[j]=0;b[i]=1;b[j]=1;} }
          else {a[i]=0;a[j]=1;b[i]=1;b[j]=0;} break;
case 10: if(ran2(&sd1)<0.5){if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=0;b[j]=1;}}
          else {a[i]=0;a[j]=1;b[i]=0;b[j]=1;} break;
case 11: if(ran2(&sd1)<0.5){if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=1;b[j]=1;}}
          else if(ran2(&sd1)<beta){a[i]=0;a[j]=1;b[i]=0;b[j]=0;} break;
case 13: if(ran2(&sd1)< 1/3){if(ran2(&sd1)<beta){a[i]=1;a[j]=0;b[i]=0;b[j]=0;}}
         else if(1/3 <ran2(&sd1)< 2/3){if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=1;b[j]=1;}}
         else {a[i]=1;a[j]=0;b[i]=1;b[j]=1;} break;
case 14: if(ran2(&sd1)<0.5){if(ran2(&sd1)<gamma){a[i]=1;a[j]=0;b[i]=1;b[j]=1;}}
          else {a[i]=1;a[j]=1;b[i]=0;b[j]=1;} break;
case 15: if(ran2(&sd1)<beta){a[i]=1;a[j]=1;b[i]=0;b[j]=0;} break;

          }//switch ends
        }//N ends
//-------------------------------------------------------------------------

       }//t1 loop ends here

    for(z=0;z<N;z++){avrB[t] += b[z]; } 

    }//M ends

  }//ENS ends
  
  for(t=0;t<M;t++) printf("%d  %lf\n",tm[t],avrB[t]/N/ENS); 


}//main ends

