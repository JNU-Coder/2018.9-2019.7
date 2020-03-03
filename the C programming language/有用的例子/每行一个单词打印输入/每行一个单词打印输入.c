#include<stdio.h>
#define IN 1    //inside a word
#define OUT 0   //outside a word
//print input one word per line
int main(void)
{
	int c,state;
	state=OUT;
	while((c=getchar())!=EOF){
		if (c==' '||c=='\n'||c=='\t'){
			putchar('\n');//finish the word
			state=OUT;
		}else if (state==OUT){
			state=IN;//beginning of word
			putchar(c);
		}else        //inside aword
		putchar(c);
	}
	return 0;
}
