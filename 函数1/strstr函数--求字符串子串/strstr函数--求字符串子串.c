int strstr(char cs[],char ct[])
{
	int j=0,k;
	for(;cs[j]!='\0';j++)
	    if(cs[j]==ct[0]){
	    	k=1;
	    	while (cs[j+k]==ct[k]&&ct[k]!='\0')
	    	    k++;
	    	    if(k==strlen(ct))
	    	        return j;
		}
	return -1;
 } 
