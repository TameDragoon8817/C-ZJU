#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
struct vector{
    double x;
    double y;
}v1,v2,v;
int main (void)
{
    scanf("%lf%lf%lf%lf", &v1.x, &v1.y, &v2.x, &v2.y);
    v.x = v1.x + v2.x;
    v.y = v1.y + v2.y;
    if (fabs(v.x) < 0.05) v.x = fabs(v.x);
	if (fabs(v.y) < 0.05) v.y = fabs(v.y);
    printf("(%.1f, %.1f)", v.x, v.y);
    return 0;
}