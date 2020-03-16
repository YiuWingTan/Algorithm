#pragma once
//红黑树的实现
class RedBlackTree
{
private:

	enum Color
	{
		Red,
		Black
	} ;

	typedef struct Node
	{
		int key;

		int value;

		int count;

		Color color;

		Node* Left;

		Node* Right;

		Node(int _key, int _value, int _count, Color _color)
		{
			key = _key;
			value = _value;
			count = _count;
			color = _color;
			Left = nullptr;
			Right = nullptr;
		}
	};

	Node* root;

	Node* put(Node* x, int key, int value);
	Node* get(Node* x, int key);
	Node* deleted(Node* x, int key);
	bool contain(Node* x, int key);

	//右旋
	Node* rotateRight(Node* x);
	//左旋
	Node* rotateLeft(Node*x);

	//颜色转换
	Node* FilColor(Node* x);
	bool isRed(Node* x);

	int size(Node*);

	Node* deleteMin(Node*);

	void preOrder(Node*);

	Node* deleteMax(Node*);

	void colorFil(Node*);

public:
	RedBlackTree()
	{
		root = nullptr;
	}

	~RedBlackTree() {

	}
	void Put(int key, int value);

	int Get(int key);

	void Deleted(int key);

	bool Contain(int key);

	//删除最小键操作
	void DeleteMin();

	void PreOrder();

	void DeleteMax();
};
