#include<stdio.h>
void clear_array(int array[],int n_elements){
	while(n_elements>0)
		array[--n_elements]=0;
} 
int main(void)
{
	int array[100],n,s;
	for(s=0;s<100;s++)
	{
	scanf("%d",array[s]);
	}
    clear_array(array[100],n);
    printf("%d",n);
	return 0;	
}//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！此程序未完，有不少错误，有待修改； 
