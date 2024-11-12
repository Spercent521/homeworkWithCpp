#include<stdio.h>
int main()
{double speed,limit,x;
 scanf("%lf %lf",&speed,&limit);
 speed=speed*10000000,limit=limit*10000000;
 if(speed<limit*1.1){
     printf("OK\n");
 }else if(speed>=limit*1.1&&speed<limit*1.5){
     x=((speed-limit)/limit)*100;
     printf("Exceed %.0f%%. Ticket 200",x);
 }else if(speed>=limit*1.5){
     x=((speed-limit)/limit)*100;
     printf("Exceed %.0f%%. License Revoked",x);
 }

    return 0;
}