#include<stdio.h>
float square(int xa,int xb,int xc,int xd,int ya,int yb,int yc,int yd){
	float s;
	printf("please input зјБъ of zhe four dots:\n");
	scanf("%d,%d,%d,%d,%d,%d,%d,%d",&xa,&ya,&xb,&yb,&xc,&yc,&xd,&yd);
	s=(xa+xb)*(ya-yb)/2.0-(xb+xc)*(yc-yb)/2.0-(xd+xc)*(yd-yc)/2.0-(xa+xd)*(ya-yd)/2.0;
	return s;
} 
int main(void)
{
	int xa,xb,xc,xd,ya,yb,yc,yd;
	float s;
	double l; 
	s=square(xa,xb,xc,xd,ya,yb,yc,yd);
	l=s*650.0;
	printf("%lf",l);
	return 0;
}
