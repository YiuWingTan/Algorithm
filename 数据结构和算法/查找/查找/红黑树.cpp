#include"红黑树.h"
#include<iostream>
bool RedBlackTree::Contain(int key)
{
	return false;
}

bool RedBlackTree::contain(Node* x, int key)
{
	return false;
}

void RedBlackTree::Deleted(int key)
{
	
}

RedBlackTree::Node* RedBlackTree::deleted(Node* x, int key)
{
	return nullptr;
}

int RedBlackTree::Get(int key)
{
	Node* x = get(root, key);
	if (x != nullptr)
	{
		return x->value;
	}
	return -1;
}

RedBlackTree::Node* RedBlackTree::get(Node* x, int key)
{
	if (x == nullptr) return nullptr;
	else if (x->key == key) return x;
	else if (x->key > key) return get(x->Left, key);
	else return get(x->Right, key);
}

void RedBlackTree::Put(int key, int value)
{
 	root =  put(root,key,value);
	root->color = Black;
}

RedBlackTree::Node* RedBlackTree::put(Node* x, int key, int value)
{
	static bool same = false;

	if (x == nullptr) return new Node(key ,value,1,Red);

	if (key == x->key) { same = true; }
	else if (key > x->key) {
		x->Right = put(x->Right,key ,value);
	}
	else {
		x->Left = put(x->Left, key, value);
	}

	if (!same)
	{
		if (!isRed(x->Left) && isRed(x->Right)) x = rotateLeft(x);
		if (isRed(x->Left) && isRed(x->Left->Left)) x = rotateRight(x);
		if (isRed(x->Left) && isRed(x->Right)) x = FilColor(x);
		x->count = size(x->Left) + size(x->Right) + 1;
	}

	return x;
	
}

RedBlackTree::Node* RedBlackTree::FilColor(Node* x)
{
	if (x == nullptr) return x;
	if (x->Left != nullptr)
		x->Left->color = x->Left->color == Red ? Black : Red;
	if (x->Right != nullptr)
		x->Right->color = x->Right->color == Red ? Black : Red;

	x->color = x->color == Red ? Black : Red;

	return x;
}

RedBlackTree::Node* RedBlackTree::rotateLeft(Node* x)
{
	Node* n = x->Right;

	x->Right = n->Left;

	n->Left = x;
	n->color = x->color;
	x->color = Red;

	n->count = x->count;

	x->count = size(x->Left)+ size(x->Right) + 1;

	return n;
}

RedBlackTree::Node* RedBlackTree::rotateRight(Node* x)
{
	Node* n = x->Left;

	x->Left = n->Right;

	n->Right = x;
	n->color = x->color;
	x->color = Red;

	n->count = x->count;

	x->count = size(x->Left) + size(x->Right) + 1;

	return n;
}

bool RedBlackTree::isRed(Node* x)
{
	if (x == nullptr) return false;
	if (x->color == Red) return true;
	return false;
}

int RedBlackTree::size(Node* x)
{
	if (x == nullptr) return 0;

	return x->count;
}

/*删除操作*/
RedBlackTree::Node* RedBlackTree::deleteMin(Node* x)
{
	if (x == nullptr) return x;
	if (x->Left == nullptr) { if(x->Right!=nullptr) x->Right->color = Red; return x->Right; }

	//处理根节点的情况
	if (!isRed(x) && !isRed(x->Left) && !isRed(x->Right)) { colorFil(x); }

	//当左子节点不是一个红节点
	if (!isRed(x->Left) && !isRed(x->Left->Left))
	{
		//当右子节点的左子节点不是一个红节点时
		if (x->Right!=nullptr&&!isRed(x->Right->Left))
		{
			colorFil(x);
		}
		else
		//当右子节的左子节点是一个红节点的时候
		if (x->Right != nullptr&&isRed(x->Right->Left))
		{
			colorFil(x);
			
			//右子节的左子节点先进行右旋
			x->Right = rotateRight(x->Right);
			//右子节点进行左旋
			x = rotateLeft(x);
			FilColor(x);
		}
	}


	x->Left = deleteMin(x->Left);

	//进行修复
	if (!isRed(x->Left)&&isRed(x->Right)) x = rotateLeft(x);
	if (isRed(x->Left) && isRed(x->Left->Left)) x = rotateRight(x);
	if (isRed(x->Left) && isRed(x->Right)) FilColor(x);

	x->count = size(x->Left) + size(x->Right)+1;

	return x;

}

void RedBlackTree::DeleteMin()
{
	root = deleteMin(root);
	if(root!=nullptr)
	root->color = Black;
}

void RedBlackTree::DeleteMax()
{
	if (!isRed(root->Left) && !isRed(root->Right))
		root->color = Red;
	root = deleteMax(root);
	root->color = Black;
}

RedBlackTree::Node * RedBlackTree::deleteMax(Node* x)
{
	if (x == nullptr) return x;
	if (x->Right == nullptr) return nullptr;
	if (isRed(x->Right->Left))
	{
		if (x->Left != nullptr&&!isRed(x->Left->Left))
		{
			colorFil(x);
		}
		else if (x->Left != nullptr && isRed(x->Left->Left))
		{
			colorFil(x);
			x = rotateRight(x);
			colorFil(x);
		}
	}

	x->Right = deleteMax(x->Right);

	if (!isRed(x->Left) && isRed(x->Right)) x = rotateLeft(x);
	if (isRed(x->Left) && x->Left != nullptr&&isRed(x->Left->Left)) x = rotateRight(x);
	if (isRed(x->Left) && isRed(x->Right)) colorFil(x);
	x->count = size(x->Left) + size(x->Right)+1;

	return x;
}

void RedBlackTree::PreOrder()
{
	preOrder(root);
}

void RedBlackTree::preOrder(Node* x)
{
	if (x == nullptr) return;

	preOrder(x->Left);
	std::cout << x->key << " ";
	preOrder(x->Right);
}
//颜色反转
void RedBlackTree::colorFil(Node* x)
{
	if (x == nullptr) return;
	if(x->Left!=nullptr)
	x->Left->color = x->Left->color == Red?Black:Red;
	if(x->Right!=nullptr)
		x->Right->color = x->Right->color == Red ? Black : Red;

	x->color = x->color == Red ? Black : Red;
}
