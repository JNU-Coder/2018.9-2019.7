#include <iostream>
#include <string.h>
#include <stack>
#include <queue>
using namespace std;

template<class T>
struct BiNode								//�������ڵ�
{
	T data;
	BiNode<T>* lchild, *rchild;
 
};
 
template<class T>							//ģ����
class BiTree
{
public:
	BiTree();								//Ĭ�Ϲ��캯��
	~BiTree();								//��������
	BiNode<T>* GetRoot();					//���ظ��ڵ�
	void PreOrder(BiNode<T>* node);			//�������
	void InOrder(BiNode<T>* node);			//�������
	void PostOrder(BiNode<T>* node);		//�������
	void LevelOrder(BiNode<T>* node);		//��α���
 
 
	//ѡ���ǵݹ�ʵ��
	void PreOrderNonRec(BiNode<T>* node);	//��
	void InOrderNonRec(BiNode<T>* node);	//��
	void PostOrderNonRec(BiNode<T>* node);	//��
 
 
	//ѡ�����,�ڵ���,Ҷ�ӽڵ���,
	int NodesNum(BiNode<T>* node);			//�ڵ���
	int TreeDepth(BiNode<T>* node);			//���
	int LeafNum(BiNode<T>* node);			//Ҷ�ӽڵ���
 
 
	//ѡ����������
	void SwapChild(BiNode<T>* node);		//��������
 
 
private:
	BiNode<T>* m_root;						//��ȡ���ڵ�
	BiNode<T>* Create();					//����������
};
 
template<class T>
BiTree<T>::BiTree()
{
	m_root = new BiNode<T>;
	m_root = Create();
}
 
template<class T>
BiTree<T>::~BiTree(){}
 
template<class T>
BiNode<T>* BiTree<T>::Create()				//1. ���������й���һ�ö��������ʾ�Ķ�����T��
{
	char ch=getchar();
	BiNode<T>* pnode;
 
	if (ch == ' ')
		pnode = NULL;
	else
	{
		pnode = new BiNode<T>;
		pnode->data = ch;
		pnode->lchild = Create();
		pnode->rchild = Create();
	}
	return pnode;
}
 
template<class T>
BiNode<T>* BiTree<T>::GetRoot()
{
	return m_root;
}
 
template<class T>
void BiTree<T>::PreOrder(BiNode<T>* node)
{
	if (!node)
		return;
	else
	{
		cout << node->data;
		PreOrder(node->lchild);
		PreOrder(node->rchild);
	}
}
 
template<class T>
void BiTree<T>::InOrder(BiNode<T>* node)
{
	//ǰ�󶨸�����������
	if (!node)
		return;
	else
	{
		InOrder(node->lchild);
		cout << node->data;
		InOrder(node->rchild);
	}
 
}
 
template<class T>
void BiTree<T>::PostOrder(BiNode<T>* node)
{
	if (!node)
		return;
	else
	{
		PostOrder(node->lchild);
		PostOrder(node->rchild);
		cout << node->data;
	}
 
}
 
template<class T>
void BiTree<T>::LevelOrder(BiNode<T>* node)
{
	//��α�����Ҫqueue��ʵ�֣�˼·��
	//@1��ʼ��queue
	//	if rootΪ�� ����
	//@2 push(root)
	//@3 while(queue��Ϊ��)
	//		s <-- queue.front()
	//		queue.pop()
	//		����s.data
	//		if(s������������)
	//			s�����������
	//		if(s������������)
	//			s�����������
 
	queue<BiNode<T>*> q;
	BiNode<T>* s = node;
	if (!s)
		return;
	q.push(s);
	while (!q.empty())
	{
		s = q.front();
		q.pop();
		cout << s->data;
		if (s->lchild)
			q.push(s->lchild);
		if (s->rchild)
			q.push(s->rchild);
 
	}
}
 
 
//��������ǵݹ���Ҫ����stack s��ʵ�֣�ģ��ݹ����
//�ܵ�ѭ���߽��ǵ�ǰ�ڵ㲻Ϊ�ջ���stack���գ�
template<class T>
void BiTree<T>::PreOrderNonRec(BiNode<T>* node)
{
	stack<BiNode<T>*> s;
	BiNode<T>* p = node;
	while (p|| !s.empty())
	{
		/*
		@1.ÿ���ҵ�ǰ�Ľڵ�����ӽڵ�ֱ����Ϊ��,�����Ľڵ���ջ,
		@2.Ȼ�󵯳���ǰ�ڵ�,����һ���ҽڵ�,���pΪ�ղ���s�����˳��������@1
		*/
		while (p)//����ִ��VL
		{
			cout << p->data;//V
			s.push(p);//���ʹ��ļ���ջ
			p = p->lchild;//L
		}
		if (!s.empty())//����ִ��R
		{
			p = s.top();
			s.pop();
			p = p->rchild;//R
		}
	}
 
 
}
 
template<class T>
void BiTree<T>::InOrderNonRec(BiNode<T>* node)
{
	//@1 �ڵ�ǰ�ڵ�p�ǿ�ʱ�򣬽�p��ջs,p������������p,��֤������������ջ
	//	pΪ��ʱ��Ҳ��������������߷��ʵ��ˣ���ʱ����ջ�ǿյ�ʱ��
	//@2 ȡջ����p������p����ջ����ʱ����ײ������߽ڵ�����ˣ���p������������p���ظ�@1
	stack<BiNode<T>*> s;
	BiNode<T>* p = node;
	while (p|| !s.empty())
	{
		while (p)//����ִ��L
		{
			s.push(p);
			p = p->lchild;
		}
		if (!s.empty())//����ִ��VR
		{
			p = s.top();
			cout << p->data;
			s.pop();
			p = p->rchild;
		}
	}
}
 
template<class T>
void BiTree<T>::PostOrderNonRec(BiNode<T>* node)
{
	//�����ӽڵ������������
	//1.��ǰ�ڵ�����ҽڵ㶼Ϊ��,����ֱ�ӷ���
	//2.ǰһ�������ʵĽڵ��ǵ�ǰ�ڵ���ӽڵ�
	//��������Ҫ����ָ��,һ��ָ��ǰһ��ָ��ǰһ�������ʵĽڵ�
	//Ȼ��֤��ջ˳������������,(������ѹ����ѹ��,������������,���ȷ�����)
	if (!node)
		return;
	stack<BiNode<T>*> s;
	s.push(node);
	BiNode<T>* pre = NULL;
	BiNode<T>* cur;
	while (!s.empty())
	{
		cur = s.top();
		if (!cur->lchild&& !cur->rchild ||(pre != NULL) && (pre == cur->lchild || pre == cur->rchild))//��һ�η��ʵ��ǵ�ǰ�ڵ��������
		{
			cout << cur->data;
			s.pop();
			pre = cur;//pre��ǰһ�������ʵĽڵ�
		}
		else
		{
			if (cur->rchild)
				s.push(cur->rchild);
			if (cur->lchild)
				s.push(cur->lchild);
 
		}
	}
 
}
 
template<class T>
int BiTree<T>::LeafNum(BiNode<T>* node)
{
	//�ݹ�˼·:�ҵ�Ҷ�ӽڵ㷵��ֵ��һ,����ֵ����
	//2�����
	//1.�ڵ�Ϊ��,���� 0,���ݻ�ȥ
	//2.ÿ������Ҷ�ӽڵ�,���� 1,���ݸ���һ�㺯��
	if (!node)
		return 0;
	if (!node->lchild&&!node->rchild)
		return 1;
	return LeafNum(node->lchild) + LeafNum(node->rchild);
}
 
template<class T>
int BiTree<T>::TreeDepth(BiNode<T>* node)
{
	/*
	�ݹ�˼·:
	ÿ���ڵ㶼���Լ�����������,
	ÿ�η��ص�ǰ�ڵ������������ȴ���Ǹ�
	1.������ڵ�Ϊ�գ������Ϊ0������0���ݹ�ĳ���
	2.�����������Ϊ1��Ȼ���ۼ�����������������ȣ�
	*/
	int LChildDep = 1, RChildDep = 1;
	if (!node)
		return 0;
	LChildDep += TreeDepth(node->lchild);//ÿ�η���֮ǰ�����ĳ���
	RChildDep += TreeDepth(node->rchild);
	return (LChildDep>RChildDep) ? (LChildDep) : (RChildDep);
 
}
 
template<class T>
int BiTree<T>::NodesNum(BiNode<T>* node)
{
	//˼·,�ݹ�������нڵ�,������ǿսڵ�Ļ�,�ݹ鷵��ֵ��1
	if (!node)
		return 0;
	return NodesNum(node->lchild) + NodesNum(node->rchild) + 1;
 
}
 
template<class T>
void BiTree<T>::SwapChild(BiNode<T>* node)
{
	//˼·,�������нڵ�Ľڵ�,ÿ���ڵ���һ��
	if (node)
	{
		swap(node->lchild, node->rchild);
		SwapChild(node->lchild);
		SwapChild(node->rchild);
	}
}
 
 
/*
��������:
ABC  DE G  F    �L
�������:
������һ�ö�����,������ڵ��ֵ:ABC  DE G  F   
�������.
����:ABCDEGF
����:CBEGDFA
����:CGEFDBA
����:ABCDEFG
ѡ����1:���÷ǵݹ��㷨ʵ�ֶ���������
����:ABCDEGF
����:CBEGDFA
����:CGEFDBA
ѡ����2:������������/�����Ŀ/Ҷ�����Ŀ
TreeDepth is 5
NodesNum is 7
LeafNum is 3
ѡ����3:��������ÿ������������������λ�á�
�������.
����:ABDFEGC
����:AFDGEBC
����:FGEDCBA
����:ABDCFEG
*/
 
int main()
{
	cout << "������һ�ö�����,������ڵ��ֵ:";
	BiTree<char> bitree;
	cout << "�������." << endl;
	cout << "����:";
	bitree.PreOrder(bitree.GetRoot());
	cout << endl;
	cout << "����:";
	bitree.InOrder(bitree.GetRoot());
	cout << endl;
	cout << "����:";
	bitree.PostOrder(bitree.GetRoot());
	cout << endl;
	cout << "����:";
	bitree.LevelOrder(bitree.GetRoot());
	cout << endl;
	cout << "ѡ����1:���÷ǵݹ��㷨ʵ�ֶ���������" << endl;
	cout << "����:";
	bitree.PreOrderNonRec(bitree.GetRoot());
	cout << endl;
	cout << "����:";
	bitree.InOrderNonRec(bitree.GetRoot());
	cout << endl;
	cout << "����:";
	bitree.PostOrderNonRec(bitree.GetRoot());
	cout << endl;
	cout << "ѡ����2:������������/�����Ŀ/Ҷ�����Ŀ" << endl;
	cout << "���Ϊ    : " << bitree.TreeDepth(bitree.GetRoot()) << endl;
	cout << "�����Ŀ  : " << bitree.NodesNum(bitree.GetRoot()) << endl;
	cout << "Ҷ�����Ŀ: " << bitree.LeafNum(bitree.GetRoot()) << endl;
	cout << "ѡ����3:��������ÿ������������������λ�á�" << endl;
	bitree.SwapChild(bitree.GetRoot());
	cout << "�������." << endl;
	cout << "����:";
	bitree.PreOrder(bitree.GetRoot());
	cout << endl;
	cout << "����:";
	bitree.InOrder(bitree.GetRoot());
	cout << endl;
	cout << "����:";
	bitree.PostOrder(bitree.GetRoot());
	cout << endl;
	cout << "����:";
	bitree.LevelOrder(bitree.GetRoot());
	cout << endl;
	system("pause");
}

