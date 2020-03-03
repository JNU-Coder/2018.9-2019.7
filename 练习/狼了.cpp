#include<stdio.h>
#include<string.h>
 
/*
** Conver a numeric value to words.
*/
 
const char  *digits[] = {
	"","ONE ","TWO ","THREE ","FOUR ","FIVE ","SIX ","SEVEN ","EIGHT ","NINE ","TEN ",
	"ELEVEN ","TWELVE ","THIRTEEN ","FOURTEEN ","FIVTEEN ","SIXTEEN ","SEVENTEEN ",
	"EIGHTEEN ","NINTEEN "
};
 
const char *tens[] = {
	"","","TWENTY ","THIRTY ","FORTY ","FIFTY ","SIXTY ","SEVENTY ","EIGHTY ","NINETY "
};
 
static char *magnitudes[] = {
	"", "THOUSAND ", "MILLION ", "BILLION " 
};
 
const void do_one_groud(unsigned int amount, char *buffer, char **magnitude)
{
	int value;
	
	value = amount / 1000;
	if(value > 0)
		do_one_groud(value,buffer,magnitude+1);
	
	amount %= 1000;
	value = amount / 100;
	if(value > 0)
	{
		strcat(buffer,digits[value]);
		strcat(buffer,"HUNRED ");
	}
	
	value = amount % 100;
	if(value >= 20)
	{
		strcat(buffer,tens[value/10]);
		value %= 10;
	}
	if(value > 0)
		strcat(buffer,digits[value]);
	if(amount > 0)
		strcat(buffer,*magnitude);
}
 
void written_amount(unsigned int amount, char *buffer)
{
	if( amount == 0)
		strcpy(buffer, "ZERO");
	else
	{
		*buffer = '\0';
		do_one_groud(amount, buffer, magnitudes);
	}
}
 
int main(void)
{
	int amount;
	char buffer[1000];
	printf("please input amount :\n");
	scanf("%d",&amount);
	written_amount(amount,buffer);
	puts(buffer);
	return 1;
}


