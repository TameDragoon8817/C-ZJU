#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct time{
    int hour;
    int minute;
    int second;
}tim;
int main (void)
{
    tim.hour = tim.second = tim.minute = 0;
    int plus;
    scanf("%d:%d:%d %d", &tim.hour, &tim.minute, &tim.second,&plus);
    tim.second = tim.second + plus;
    if (tim.second>=60) {
        tim.minute++;
        tim.second = tim.second - 60;
    }
    if(tim.minute>=60){
        tim.hour++;
        tim.minute = tim.minute - 60;
    } 
    if(tim.hour>=24){
        tim.hour = tim.hour - 24;
    }
    printf("%02d:%02d:%02d",tim.hour,tim.minute,tim.second);
    return 0;
}