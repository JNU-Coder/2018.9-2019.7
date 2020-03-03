#include <iostream>
#include <string.h>
#include <stack>
#include <queue>
using namespace std;

template<class T>
struct BiNode								//二叉数节点
{
	T data;
	BiNode<T>* lchild, *rchild;
 
};
 
template<class T>							//模板类
class BiTree
{
public:
	BiTree();								//默认构造函数
	~BiTree();								//析构函数
	BiNode<T>* GetRoot();					//返回根节点
	void PreOrder(BiNode<T>* node);			//先序遍历
	void InOrder(BiNode<T>* node);			//中序遍历
	void PostOrder(BiNode<T>* node);		//后序遍历
	void LevelOrder(BiNode<T>* node);		//层次遍历
 
 
	//选做非递归实现
	void PreOrderNonRec(BiNode<T>* node);	//先
	void InOrderNonRec(BiNode<T>* node);	//中
	void PostOrderNonRec(BiNode<T>* node);	//后
 
 
	//选做深度,节点数,叶子节点数,
	int NodesNum(BiNode<T>* node);			//节点数
	int TreeDepth(BiNode<T>* node);			//深度
	int LeafNum(BiNode<T>* node);			//叶子节点数
 
 
	//选做交换子树
	void SwapChild(BiNode<T>* node);		//交换子树
 
 
private:
	BiNode<T>* m_root;						//获取根节点
	BiNode<T>* Create();					//创建二叉树
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
BiNode<T>* BiTree<T>::Create()				//1. 按先序序列构造一棵二叉链表表示的二叉树T；
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
	//前后定根，中序定左右
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
	//层次遍历需要queue来实现，思路：
	//@1初始化queue
	//	if root为空 返回
	//@2 push(root)
	//@3 while(queue不为空)
	//		s <-- queue.front()
	//		queue.pop()
	//		输入s.data
	//		if(s的左子树不空)
	//			s的左子树入队
	//		if(s的右子树不空)
	//			s的右子树入队
 
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
 
 
//先序遍历非递归需要借助stack s来实现，模拟递归调用
//总的循环边界是当前节点不为空或者stack不空，
template<class T>
void BiTree<T>::PreOrderNonRec(BiNode<T>* node)
{
	stack<BiNode<T>*> s;
	BiNode<T>* p = node;
	while (p|| !s.empty())
	{
		/*
		@1.每次找当前的节点的左子节点直到左为空,经过的节点入栈,
		@2.然后弹出当前节点,搜索一次右节点,如果p为空并且s空则退出否则继续@1
		*/
		while (p)//这里执行VL
		{
			cout << p->data;//V
			s.push(p);//访问过的加入栈
			p = p->lchild;//L
		}
		if (!s.empty())//这里执行R
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
	//@1 在当前节点p非空时候，将p入栈s,p的左子树赋给p,保证左子树都能入栈
	//	p为空时候，也就是左子树最左边访问到了，这时候在栈非空的时候
	//@2 取栈顶给p，输入p，出栈，这时候最底层的最左边节点访问了，将p的右子树赋给p，重复@1
	stack<BiNode<T>*> s;
	BiNode<T>* p = node;
	while (p|| !s.empty())
	{
		while (p)//这里执行L
		{
			s.push(p);
			p = p->lchild;
		}
		if (!s.empty())//这里执行VR
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
	//访问子节点的条件有两种
	//1.当前节点的左右节点都为空,可以直接访问
	//2.前一个被访问的节点是当前节点的子节点
	//这样就需要两个指针,一个指向当前一个指向前一个被访问的节点
	//然后保证入栈顺序是先右再左,(这里先压右再压左,这样左在上面,就先访问左)
	if (!node)
		return;
	stack<BiNode<T>*> s;
	s.push(node);
	BiNode<T>* pre = NULL;
	BiNode<T>* cur;
	while (!s.empty())
	{
		cur = s.top();
		if (!cur->lchild&& !cur->rchild ||(pre != NULL) && (pre == cur->lchild || pre == cur->rchild))//上一次访问的是当前节点的左子树
		{
			cout << cur->data;
			s.pop();
			pre = cur;//pre是前一个被访问的节点
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
	//递归思路:找到叶子节点返回值加一,返回值计数
	//2种情况
	//1.节点为空,返回 0,传递回去
	//2.每当到达叶子节点,返回 1,传递给上一层函数
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
	递归思路:
	每个节点都有自己的左右子树,
	每次返回当前节点左右子树长度大的那个
	1.如果根节点为空，则深度为0，返回0，递归的出口
	2.否则深度至少为1，然后累加他们左右子树的深度，
	*/
	int LChildDep = 1, RChildDep = 1;
	if (!node)
		return 0;
	LChildDep += TreeDepth(node->lchild);//每次返回之前子树的长度
	RChildDep += TreeDepth(node->rchild);
	return (LChildDep>RChildDep) ? (LChildDep) : (RChildDep);
 
}
 
template<class T>
int BiTree<T>::NodesNum(BiNode<T>* node)
{
	//思路,递归遍历所有节点,如果不是空节点的话,递归返回值加1
	if (!node)
		return 0;
	return NodesNum(node->lchild) + NodesNum(node->rchild) + 1;
 
}
 
template<class T>
void BiTree<T>::SwapChild(BiNode<T>* node)
{
	//思路,交换所有节点的节点,每个节点走一遍
	if (node)
	{
		swap(node->lchild, node->rchild);
		SwapChild(node->lchild);
		SwapChild(node->rchild);
	}
}
 
 
/*
样例输入:
ABC  DE G  F    ↙
样例输出:
先序建立一棵二叉树,请输入节点的值:ABC  DE G  F   
建立完毕.
先序:ABCDEGF
中序:CBEGDFA
后序:CGEFDBA
层序:ABCDEFG
选做题1:采用非递归算法实现二叉树遍历
先序:ABCDEGF
中序:CBEGDFA
后序:CGEFDBA
选做题2:求二叉树的深度/结点数目/叶结点数目
TreeDepth is 5
NodesNum is 7
LeafNum is 3
选做题3:将二叉树每个结点的左右子树交换位置。
交换完毕.
先序:ABDFEGC
中序:AFDGEBC
后序:FGEDCBA
层序:ABDCFEG
*/
 
int main()
{
	cout << "先序建立一棵二叉树,请输入节点的值:";
	BiTree<char> bitree;
	cout << "建立完毕." << endl;
	cout << "先序:";
	bitree.PreOrder(bitree.GetRoot());
	cout << endl;
	cout << "中序:";
	bitree.InOrder(bitree.GetRoot());
	cout << endl;
	cout << "后序:";
	bitree.PostOrder(bitree.GetRoot());
	cout << endl;
	cout << "层序:";
	bitree.LevelOrder(bitree.GetRoot());
	cout << endl;
	cout << "选做题1:采用非递归算法实现二叉树遍历" << endl;
	cout << "先序:";
	bitree.PreOrderNonRec(bitree.GetRoot());
	cout << endl;
	cout << "中序:";
	bitree.InOrderNonRec(bitree.GetRoot());
	cout << endl;
	cout << "后序:";
	bitree.PostOrderNonRec(bitree.GetRoot());
	cout << endl;
	cout << "选做题2:求二叉树的深度/结点数目/叶结点数目" << endl;
	cout << "深度为    : " << bitree.TreeDepth(bitree.GetRoot()) << endl;
	cout << "结点数目  : " << bitree.NodesNum(bitree.GetRoot()) << endl;
	cout << "叶结点数目: " << bitree.LeafNum(bitree.GetRoot()) << endl;
	cout << "选做题3:将二叉树每个结点的左右子树交换位置。" << endl;
	bitree.SwapChild(bitree.GetRoot());
	cout << "交换完毕." << endl;
	cout << "先序:";
	bitree.PreOrder(bitree.GetRoot());
	cout << endl;
	cout << "中序:";
	bitree.InOrder(bitree.GetRoot());
	cout << endl;
	cout << "后序:";
	bitree.PostOrder(bitree.GetRoot());
	cout << endl;
	cout << "层序:";
	bitree.LevelOrder(bitree.GetRoot());
	cout << endl;
	system("pause");
}

