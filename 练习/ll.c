#include <stdio.h> 
#include <string.h> //һǧTHOUSAND��һǧ��һǧ��һ����MILLION��һ�����һǧ��ʮ��BILLION,�������ֻ�Ƕ�һǧ���µ�������numת�ַ���������λ��ֻ����λ�ָ���������ǧ������ʮ�ڣ���λ���ɡ� 
int num_to_alp(unsigned int num, char * buffer) 
{ 
	if (num == 0) 
	{ 	//����0,��ʾnumΪ0�����ں��治��thousand,billion��λ 
		return 0; 
	} 
		static char *digits[] = {"", "ONE ", "TWO ", "THREE ", "FOUR ", 
		"FIVE ", "SIX ", "SEVEN ", "EIGHT ", "NINE ",
		 "TEN ", "ELEVEN ", "TWELVE ", "THIRTEEN ", "FOURTEEN ",
		  "FIFTEEN ", "SIXTEEN ", "SEVENTEEN ", "EIGHTEEN ",	"NINETEEN "	}; 
		static char *tens[] = {"", "", "TWENTY ", "THIRTY ", "FORTY ", "FIFTY ",
		 "SIXTY ", "SEVENTY ",	"EIGHTY ", "NINETY "};
		  //�����λ����������Ӱ�λ 
		  if (num / 100) 
		  { 
		  int hud = num / 100; 
		  strcat(buffer, digits[hud]); 
		  strcat(buffer, "HUNDRED "); 
		  } 
		  num = num % 100; //��ʮλ�ϵ����жϴ�������20��ty��׺��С��20��digits���ַ��� 
		  int ten = num / 10; 
		  if (ten >= 2) 
		  { 
		  //ʮλ 
		  strcat(buffer, tens[ten]); 
		  //��λ 
		  num = num % 10; 
		  strcat(buffer, digits[num]); 
		  }
		  else
		  { //С��20ֱ����digits�и�λ 
		  strcat(buffer, digits[num]); 
		  } 
		  return 1; 
		  } 
		  //��amount����λ��һ�飬���з��顣�����һλָ���鳤eg 123456789 =>����[3, 789, 456, 123] 
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
			} //��ǧ������ʮ�ڣ���λ 
			static char *magnitudes[] = { "", "THOUSAND ", "MILLION ", "BILLION " }; 
			//�ָ�������ָ�� 
			unsigned int *dived_arr; 
			//�ָ�Ķ��������鳤�� 
			int len; //�ָ����� 
			dived_arr = div_amount(amount);
			 len = dived_arr[0]; //���ֳ�����ʱֻ��Ҫmagnitudesǰ���� 
			 while (len > 0) 
			 {�������������������� 
			 //��ÿ�������ֽ���numת�ַ��� 
			 if (num_to_alp(dived_arr[len], buffer)) 
			 { //�����λ�������㣬��������λ���ĵ�λ 
			 strcat(buffer, magnitudes[len - 1]); 
			 } 
			 len--; 
			 } 
			 }
