void reverse(char s[])
{
	int c,j,k;
	for(j=0,k=strlen[s]-1;j<k;j++,k--)
	    c=s[j],s[j]=s[k],s[k]=c};
}
int strlen(char s[])
{
	int j=0;
	while(s[j]!='\0') j++;
	return j;
} 
