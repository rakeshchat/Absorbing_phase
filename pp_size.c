//Predator population decays with time,for different system size (N),for fixed alpha value.

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "ran2.c"

//# define N 1000
int N;
# define beta 0.02
# define gamma 0.9

# define M 60                   //for [10*(1.2)^M] limit
# define ENS 1000              //ensemble averaging

# define alpha 0.140

int main()
{

scanf("%d",&N);

int i,j,k,t,z,t1,e,tm[M]={};
char a[N],b[N];
long sd1 =-98765;
double avrA[M]={},avrB[M]={};

tm[0]=0; for (i=1;i<M;i++) tm[i] = (int) (10.*pow(1.2,i));

for(e=0;e<ENS;e++){

for(z=0;z<N;z++){a[z]=0; b[z]=0; }
for(z=0;z<N;z++){a[z]=ran2(&sd1)<0.5; b[z]=ran2(&sd1)<0.9; 
                 avrA[0]+=a[z]; avrB[0]+=b[z]; }    

for(t=1;t<M;t++){
for(t1=tm[t-1];t1<tm[t];t1++){

//-------------------------------------------------------------------------
for(z=0;z<N;z++){
  i=ran2(&sd1)*N; j=(i+1)%N;
  k=8*a[i]+4*a[j]+2*b[i]+1*b[j]; 
  switch (k){
          case 8 : if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=0;b[j]=0;} break;
          case 9 : if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=0;b[j]=1;} break;
          case 10: if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=1;b[j]=0;} break;
          case 14: if(ran2(&sd1)<gamma){a[i]=1;a[j]=0;b[i]=1;b[j]=1;} break;
          case 15: if(ran2(&sd1)<beta){a[i]=1;a[j]=1;b[i]=0;b[j]=0;} break;
          case 3 : if(ran2(&sd1)<beta){a[i]=0;a[j]=0;b[i]=0;b[j]=0;} break;
          case 6 : if(ran2(&sd1)<gamma){a[i]=0;a[j]=0;b[i]=1;b[j]=1;} break;
          case 7 : if(ran2(&sd1)<beta){a[i]=0;a[j]=1;b[i]=0;b[j]=0;} break;
          case 11: if(ran2(&sd1)<alpha){a[i]=1;a[j]=1;b[i]=1;b[j]=1;}
               else if(ran2(&sd1)<beta){a[i]=1;a[j]=0;b[i]=0;b[j]=0;} break;
          }//switch ends
        }//N ends
//-------------------------------------------------------------------------

       }//t1 loop ends here

    for(z=0;z<N;z++){avrA[t] += a[z]; avrB[t] += b[z]; } 

    }//M ends

  }//ENS ends
  
  for(t=0;t<M;t++) printf("%d  %lf  %lf\n",tm[t],avrA[t]/N/ENS,avrB[t]/N/ENS); 

}//main ends
