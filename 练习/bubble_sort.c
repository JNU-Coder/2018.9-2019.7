void bubble_sort(int a[],n)
{
	int i,j,t,k;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++)
		if(a[j]>a[j+1])
			t=a[j],a[j]=a[j+1],a[j+1]=t;
		for(k=0;k<n;k++)
			printf("%d  ",a[k]);
		printf("\n");
	}
}

