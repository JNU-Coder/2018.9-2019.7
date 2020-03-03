#include<stdio.h>//—°‘Ò≈≈–Ú∑®£°£° 
int main(void)
{
	int i,j,p,q,s,a[10];
	printf("\n input 10 numbers:\n");
	for(i=0;i<10;i++)scanf("%d",&a[i]);
	for(i=0;i<10;i++){
		p=i;q=a[i];
		for(j=i+1;j<10;j++){
			if(q>a[j]){
				p=j;
				q=a[j];
			}
		}
		if(i!=p){
			s=a[i];
			a[i]=a[p];
			a[p]=s;
		}
		printf("%d\t",a[i]);
	}
}
