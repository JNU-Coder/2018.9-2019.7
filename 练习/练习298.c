#include<stdio.h>//����棨Լɪ�����⣩ 
struct serial
{
    int num;
    struct serial *next;
};
void main()
{
    int n,i;
    struct serial peo[100],*p,*q;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        peo[i].num=i+1;
    for(i=0;i<n-1;i++)
        peo[i].next=&peo[i+1];
    peo[n-1].next=peo;
    q=p=peo;
    while(p!=p->next )
    {
        for(i=0;i<2;i++)
        {
            q=p;
            p=p->next;
        }
        q->next =p->next ;
        printf("��ɾ����Ԫ��:%-4d\n",p->num);
        p=q->next ;
    }
    printf("\n��󱨺ų�������ԭ����:%d\n",p->num);
 
}

