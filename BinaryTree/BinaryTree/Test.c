#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Queue.h"
typedef int BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType date;


}BTNode;

BTNode* BuyNode(BTDataType x)
{
	BTNode* newnode =(BTNode*) malloc(sizeof(BTNode));
	assert(newnode);
	newnode->date = x;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);


	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node2->right = node7;
	return node1;
}

//前序遍历
void PreOrder(BTNode* root)
{
	if (root==NULL)
	{
		printf("# ");
		return;
	}
	printf("%d ", root->date);
	PreOrder(root->left);
	PreOrder(root->right);

}

//中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	
	InOrder(root->left);
	printf("%d ", root->date);
	InOrder(root->right);

}
//后序遍历
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);

	printf("%d ", root->date);

}

//int count;
//void TreeSize(BTNode* root )
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	++count;
//	TreeSize(root->left);
//	TreeSize(root->right);
//
//}

int TreeSize1(BTNode* root)
{
	return	root == NULL  ?  0 : 
		TreeSize1(root->left) + TreeSize1(root->right) + 1;
}

//求叶子结点的数量
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if(root->left==NULL&&root->right==NULL)
		return 1;

	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

//求第K层的结点数量
int TreeKLevel(BTNode* root, int k)
{
	assert(k >= 1);
	if (root==NULL)
	{
		return 0;
	}
	if (k==1)
	{
		return 1;
	}
	return TreeKLevel(root->left, k - 1) + TreeKLevel(root->right, k - 1);
}

//求二叉树的深度
int TreeDepth(BTNode* root)
{
	int i = 1;
	int dep = 0;
	while (TreeKLevel(root,i++ ))
	{
		dep++;
	}
	
	return dep;

}

//二叉树查找值为x的结点
BTNode* TreeFind(BTNode* root,BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->date==x)
		return root;

	BTNode* ret1 = TreeFind(root->left, x);
	if (ret1)
		return ret1;
	
	BTNode* ret2 = TreeFind(root->right, x);
	if (ret2)
		return ret2;
	

	return NULL;

}

//销毁
void TreeDestroy(BTNode* root)
{
	if (root == NULL)
		return;

	TreeDestroy(root->left);
	TreeDestroy(root->right);
	free(root);

}


//层序遍历
//队列实现

void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q,root);//如果root 不等于空 放进队列
	}
	while (!QueueEmpty(&q))//队列不等于空就继续
	{
		BTNode* front = QueueFront(&q);
		printf("%d ", front->date);
		QueuePop(&q);
		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}
	printf("\n");
	QueueDestroy(&q);

}

//判断二叉树是否是完全二叉树
int TreeComplete(BTNode* root)
{
	//层序遍历 如果是完全二叉树 非空集中在一起 空集中在一起 1 1 1 1 1 1 N N N N N N 
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);//如果root 不等于空 放进队列
	}
	while (!QueueEmpty(&q))//队列不等于空就继续
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)//队列首元素存在
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
		else
		{
			//遇到空以后，则跳出层序遍历
			break;
		}
	}
	
	//如果后面全是空，则是完全二叉树
	//如果 空 后面还有 非空      则不是完全二叉树
	while (!QueueEmpty(&q))//队列不等于空就继续
	{
		BTNode* front = QueueFront(&q);

		QueuePop(&q);//记得Pop

		if (front)//空 后面还有 非空      则不是完全二叉树
		{
			QueueDestroy(&q);//Destroy 一下 不Destroy一下 内存泄露

			return false;
		}
	}
	 
	QueueDestroy(&q);
	return true;
}

//
int main()
{
	BTNode* root = CreatBinaryTree();
	
	PreOrder(root);
	printf("\n");
	
	InOrder(root);
	printf("\n");

	PostOrder(root);
	printf("\n");

	//count = 0;
	//TreeSize(root);
	//printf("TreeSize:%d\n", count);
//
	//count = 0;
	//TreeSize(root);
	//printf("TreeSize:%d\n", count);
	//printf("TreeSize:%d ",TreeSize1(root));
	//printf("\n");

	//printf("TreeSize:%d ", TreeSize1(root));
	//TreeSize1LeafSize(root);
	//printf("TreeSize:%d ", TreeSizeLeafSize(root));

	//printf("TreeLeaf:%d\n", TreeLeafSize(root));
	//printf("TreeLeaf:%d\n", TreeLeafSize(root));

	//TreeKLevel(root, 2);
	//printf("TreeKLevel:%d ", TreeKLevel(root, 4));

	printf("\n");
	//BTNode* ret = TreeFind(root,10);
	//printf("\n");
	//printf("BTNode* ret：%d ", ret->date);
	//printf("\n");


	/*int ret3 = TreeDepth(root);
	printf("TreeDepth：%d ", ret3);*/


	//层序遍历
	LevelOrder(root);

	//判断是否是完全二叉树
	printf("TreeComplete:%d ", TreeComplete(root));
	//销毁
	TreeDestroy(root);
	return 0;
}