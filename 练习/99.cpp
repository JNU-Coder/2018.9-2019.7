#include <stdio.h>
#include <string.h>
/**
 *����amount��ʾ��ֵת��Ϊ������ʽ����������buffer�С�
 *�������������һ����ӡ֧Ʊ�ĳ�����ʹ�á����磬���amount��ֵ��16312��
 *��ôbuffer�д洢���ַ���Ӧ����
 *SIXTEEN THOUSAND THREE HUNDRED TWELVE
 *
 */
void written_amount(unsigned int amount, char *buffer)
{
     char value1_9[10][10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE",
                              "SIX", "SEVEN", "EIGHT", "NINE" };
     char value10_19[10][10] = {"TEN", "ELEVEN", "TWELVE", "THIRTEEN", "FOURTEEN", "FIFTEEN",
                              "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN" };
     char value_ty[10][10] = { "", "", "TWENTY", "THIRTY", "FORTY", "FIFTY",
                              "SIXTY", "SEVENTY", "EIGHTY", "NINETY" };
	 char value_splite[10][10] = { "HUNDRED", "THOUSAND", "MILLION", "BILLION" };
     if (amount == 0)
     {
        strcat(buffer, value1_9[0]);
        return;
     }
     static int count = 0;
     unsigned int tmp = amount / 1000;
 
     if (tmp)
     {
        ++count;
        written_amount(tmp, buffer);
     }
     printf("amount is %d\n", amount);
     int val = amount % 1000;
     printf("val is %d\n", val);
     if (val == 0)
     {
        count = 0;
        return;
     }
     if (val >= 100)
     {
        strcat(buffer, value1_9[val / 100]);
        strcat(buffer, " ");
        strcat(buffer, value_splite[0]);
        val %= 100;
     }
     if (val >= 20 && val <= 99)
     {
        strcat(buffer, " ");
        strcat(buffer, value_ty[val / 10]);
        val %= 10;
     }
     if (val >= 10 && val < 19)
     {
        strcat(buffer, " ");
        strcat(buffer, value10_19[val % 10]);
     }
     if (val > 0 && val <= 9)
     {
        strcat(buffer, " ");
        strcat(buffer, value1_9[val]);
     }
     if (count > 0)
     {
        strcat(buffer, " ");
        strcat(buffer, value_splite[count--]);
        strcat(buffer, " ");
     }
}
int main()
{
	printf("please input amount:\n");
    unsigned int num;
    scanf("%u", &num);
    char buffer[100] = {0};
    written_amount(num, buffer);
    puts(buffer);
}

