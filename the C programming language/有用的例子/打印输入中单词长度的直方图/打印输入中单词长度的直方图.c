#include<stdio.h>
#define maxhist 15   //max length of the histogram
#define maxword 11   //max legth of the word
#define in 1
#define out 0//打印单词长度的直方图； 
int main(void)
{
	int c,i,nc,state;
	int len;
	int maxvalue;
	int ovflow;
	int wl[maxword];
	
	state=out;
	nc=0;
	ovflow=0;
	for(i=0;i<maxword;++i);
	    wl[i]=0;
	while ((c=getchar())!=EOF){
	    if(c==' '||c=='\n'||c=='\t'){
	    	state=out;
	    	if(nc>0)
	    	    if(nc<maxword)
	    	        ++wl[nc];
	    	    else
	    	        ++ovflow;
	    	nc=0;
	}else if (state==out){
		state=in;
		nc=1;
	}else
	++nc;
    }
    maxvalue=0;
    for(i=1;i<maxword;++i){
    	printf("%5d-%5d:",i,wl[i]);
    	if (wl[i]>0){
    		if((len=wl[i]*maxhist/maxvalue)<=0)
    		    len=1;
		}else
		    len=0;
		while (len>0){
			putchar('*');
			--len;
		}
		putchar('\n');
	}
	if (ovflow>0)
	printf("There are %d words >=%d\n",ovflow,maxword);
	return 0; 
 } 
