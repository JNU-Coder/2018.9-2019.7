#include<stdio.h>
#include<math.h>
struct point{
	int x;int y;
}; 
struct line{
	char name[6];
	struct point start;
	struct point end;
};
int main(void)
{
	struct line a={"abc",{1,1},{10,10}};
	double dx2,dy2,length;
	printf("line name is %s\n",a.name);
	printf("starting point:(%d,%d)\n",a.start.x,a.start.y);
	printf("end point:(%d,%d)\n",a.end.x,a.end.y);
	scanf("%s",a.name);
	scanf("%d%d",&a.start.x,&a.start.y);
	a.end.x=100;a.end.y=100;
	dx2=(a.end.x-a.start.x)*(a.end.x-a.start.x);
	dy2=(a.end.y-a.start.y)*(a.end.y-a.start.y);
	length=sqrt(dx2+dy2);
	printf("the length is %lf\n",length);
	return 0;
}

