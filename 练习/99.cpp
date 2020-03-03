#include <stdio.h>
#include <string.h>
/**
 *它把amount表示的值转换为单词形式，并储存于buffer中。
 *这个函数可以在一个打印支票的程序中使用。例如，如果amount的值是16312，
 *那么buffer中存储的字符串应该是
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

