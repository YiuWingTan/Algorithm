#pragma once
//�������ʵ��
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

	//����
	Node* rotateRight(Node* x);
	//����
	Node* rotateLeft(Node*x);

	//��ɫת��
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

	//ɾ����С������
	void DeleteMin();

	void PreOrder();

	void DeleteMax();
};
