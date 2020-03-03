#include <stdio.h> 
#include <string.h> //一千THOUSAND，一千的一千倍一百万MILLION，一百万的一千倍十亿BILLION,下面的数只是对一千以下的数进行num转字符串，更高位的只需三位分隔开，加上千，百万，十亿，单位即可。 
int num_to_alp(unsigned int num, char * buffer) 
{ 
	if (num == 0) 
	{ 	//返回0,标示num为0，便于后面不加thousand,billion单位 
		return 0; 
	} 
		static char *digits[] = {"", "ONE ", "TWO ", "THREE ", "FOUR ", 
		"FIVE ", "SIX ", "SEVEN ", "EIGHT ", "NINE ",
		 "TEN ", "ELEVEN ", "TWELVE ", "THIRTEEN ", "FOURTEEN ",
		  "FIFTEEN ", "SIXTEEN ", "SEVENTEEN ", "EIGHTEEN ",	"NINETEEN "	}; 
		static char *tens[] = {"", "", "TWENTY ", "THIRTY ", "FORTY ", "FIFTY ",
		 "SIXTY ", "SEVENTY ",	"EIGHTY ", "NINETY "};
		  //如果百位有数，先添加百位 
		  if (num / 100) 
		  { 
		  int hud = num / 100; 
		  strcat(buffer, digits[hud]); 
		  strcat(buffer, "HUNDRED "); 
		  } 
		  num = num % 100; //对十位上的数判断处理，大于20用ty后缀，小于20用digits中字符串 
		  int ten = num / 10; 
		  if (ten >= 2) 
		  { 
		  //十位 
		  strcat(buffer, tens[ten]); 
		  //个位 
		  num = num % 10; 
		  strcat(buffer, digits[num]); 
		  }
		  else
		  { //小于20直接用digits中个位 
		  strcat(buffer, digits[num]); 
		  } 
		  return 1; 
		  } 
		  //将amount按三位分一组，进行分组。数组第一位指定组长eg 123456789 =>数组[3, 789, 456, 123] 
		  unsigned int * div_amount(unsigned int amount) { unsigned int arr_amount[100]; 
		  unsigned int amount_dived; 
		  int loc = 1; 
		  do
		   { 
		   arr_amount[loc] = amount % 1000; 
		   amount /= 1000; loc++; 
		   }
		    while (amount); 
			arr_amount[0] = loc - 1; 
			return arr_amount; 
			} 
			void written_amount(unsigned int amount, char *buffer) 
			{ 
			if (amount == 0) 
			{ 
			strcat(buffer, "zero "); 
			} //上千，百万，十亿，单位 
			static char *magnitudes[] = { "", "THOUSAND ", "MILLION ", "BILLION " }; 
			//分割后的数组指针 
			unsigned int *dived_arr; 
			//分割的段数，数组长度 
			int len; //分隔数字 
			dived_arr = div_amount(amount);
			 len = dived_arr[0]; //当分成三组时只需要magnitudes前三个 
			 while (len > 0) 
			 {　　　　　　　　　　 
			 //对每三个数字进行num转字符串 
			 if (num_to_alp(dived_arr[len], buffer)) 
			 { //如果三位数不是零，加上这三位数的单位 
			 strcat(buffer, magnitudes[len - 1]); 
			 } 
			 len--; 
			 } 
			 }
