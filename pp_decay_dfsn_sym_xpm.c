//Predator population decays with time with DIFFUSION, SYMMETRIC update - plot xpm


# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "ran2.c"

# define N 1000

# define alpha 0.318
# define beta  0.20
# define gamma 1.0

# define tmax 100000

int main()
{
int i,j,k,t,z,t1; 
char a[N],b[N];
long sd1 =-98765;

for(z=0;z<N;z++){a[z]=0; b[z]=0; }
for(z=0;z<N;z++){a[z]=ran2(&sd1)<0.5; b[z]=ran2(&sd1)<0.5; }

//print-------------------------
printf("/* XPM */");printf("\n");
printf("static char * MyArray[] = {");printf("\n");
printf("\"1000 1000 3 1\",");printf("\n");
printf("\"       c #FFFFFF\",");printf("\n");
printf("\"0      c #FFFFCC\",");printf("\n");
printf("\"1      c #62C664\",");printf("\n");    //for a[z]
//printf("\"1      c #1638E5\",");printf("\n");    //for b[z]
//print-------------------------

for(t=1;t<=tmax;t++){

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

if(t>54800 && t<=55800){
printf("\"");
for(z=0;z<N;z++) printf("%d",a[z]);
printf("\",");printf("\n");
    }

  }//tmax ends

printf("};");

}//main ends
