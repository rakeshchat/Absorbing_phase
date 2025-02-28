//The prey-predator model(simplified).  

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "ran2.c"
# define N 10  //number of sites
# define T 100 //timestep
# define pi_1  0.5
# define eta_1  0.5     
# define pi_2  0.5
# define eta_2  0.5     
# define alpha  0.5     
# define beta  0.5    
# define gamma  0.5     

int main()
{
int r,s,i,j,k,t,z,a[N],b[N];
long sd =-96767;

for(z=0;z<N;z++)  {a[z]=0;b[z]=0;}

for(z=0;z<N;z++){a[z]=ran2(&sd)<0.5;}
for(z=0;z<N;z++){b[z]=ran2(&sd)<0.5;}

printf("Initial conf:\n");   
for (z=0;z<N;z++) printf("%d    %d\n", a[z],b[z]);

for(t=0;t<T;t++){         //for T mcs

for (z=0;z<N;z++) {
r=ran2(&sd)*N;
if(z==r){ 
switch (r){
        case 0    :if (a[0]==0){if(ran2(&sd)>pi_1){a[0]=1;}} 
                   else if (a[0]==1){if(ran2(&sd)<eta_1){a[0]=0;}
                   else if(a[1]==0){a[1]=1;a[0]=0;}}break;
        case (N-1):if (a[N-1]==1){if(ran2(&sd)<eta_2){a[N-1]=0;}
                   else if(a[N-2]==0){a[N-1]=0;a[N-2]=1;}}
                   else if (a[N-1]==0){if(ran2(&sd)>pi_2){a[N-1]=1;}}break;
        default   :if(a[r]==1){     
                   if(a[r+1]==0 && a[r-1]==1){a[r]=0;a[r+1]=1;}
                   else if(a[r+1]==1 && a[r-1]==0){a[r]=0;a[r-1]=1;}
                   else if(a[r+1]==0 && a[r-1]==0){if(ran2(&sd)<0.5){a[r]=0;a[r-1]=1;}
                   else{a[r]=0;a[r+1]=1;}}}break;
          }/*1st switch ends*/
         }// if ran2 ends   
       }//for z<N ends

for (z=0;z<N;z++) {
s=ran2(&sd)*N;
if(z==s){ 
switch (s){
        case 0    :if (b[0]==0){if(ran2(&sd)>pi_1){b[0]=1;}} 
                   else if (b[0]==1){if(ran2(&sd)<eta_1){b[0]=0;}
                   else if(b[1]==0){b[1]=1;b[0]=0;}}break;
        case (N-1):if (b[N-1]==1){if(ran2(&sd)<eta_2){b[N-1]=0;}
                   else if(b[N-2]==0){b[N-1]=0;b[N-2]=1;}}
                   else if (b[N-1]==0){if(ran2(&sd)>pi_2){b[N-1]=1;}}break;
        default   :if(b[s]==1){     
                   if(b[s+1]==0 && b[s-1]==1){b[s]=0;b[s+1]=1;}
                   else if(b[s+1]==1 && b[s-1]==0){b[s]=0;b[s-1]=1;}
                   else if(b[s+1]==0 && b[s-1]==0){if(ran2(&sd)<0.5){b[s]=0;b[s-1]=1;}
                   else{b[s]=0;b[s+1]=1;}}}break;
          }/*2nd switch ends*/
         }// if ran2 ends   
       }//for z<N ends

for(z=0;z<N;z++){
i=ran2(&sd)*N;
j=(i+1);
if(i<N-2){          //for the last site we can't take a 2x2 block, so its excluded
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
          }/*3rd switch ends*/
         }//if ends
        }//for ends

    }//T ends

printf("Final conf:\n");   
for (z=0;z<N;z++) printf("%d    %d\n", a[z],b[z]);

}//main ends
