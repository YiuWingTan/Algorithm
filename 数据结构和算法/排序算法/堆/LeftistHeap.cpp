#include"LeftistHeap.h"

template<class T>
LHNode<T>* LeftistHeap<T>::createCopy(LHNode<T>* node)
{
	if(node == nullptr) 
		return nullptr;
	LHNode<T>* copy = new LHNode<T>(node->val,node->npl,nullptr,nullptr);

	copy->left = createCopy(node->left);
	copy->right = createCopy(node->right);

	return copy;
}

template<class T>
void LeftistHeap<T>::initByVector(const std::vector<T> &arr)
{
	
	for (int i = 0; i < arr.size(); i++)
		insert(arr[i]);
}

template<class T>
LHNode<T>* LeftistHeap<T>::merge(LHNode<T>* x, LHNode<T>* y)
{
	if (x == nullptr) return y;
	if (y == nullptr) return x;

	if (x->val > y->val)
	{
		auto mid = x;
		x = y;
		y = mid;
	}

	x->right = merge(x->right,y);

	if (x->left == nullptr)
	{
		auto mid = x->left;
		x->left = x->right;
		x->right = mid;
	}
	else if (x->right != nullptr&&x->left < x->right)
	{
		auto mid = x->left;
		x->left = x->right;
		x->right = mid;
	}

	x->npl = x->right == nullptr ? 0 : x->right->npl + 1;

	return x;
}

template<class T>
void LeftistHeap<T>::destory(LHNode<T>* node)
{
	if (node == nullptr) return;

	destory(node->left);
	destory(node->right);

	delete node;

	

}

template<class T>
void LeftistHeap<T>::preOrder(LHNode<T>* node, std::vector<T>& arr)
{
	if (node == nullptr) return;

	arr.push_back(node->val);
	preOrder(node->left,arr);
	preOrder(node->right,arr);
}

template<class T>
void LeftistHeap<T>::midOrder(LHNode<T>* node, std::vector<T>& arr)
{
	if (node == nullptr) return;
	midOrder(node->left,arr);
	arr.push_back(node->val);
	midOrder(node->right,arr);
}

template<class T>
void LeftistHeap<T>::backOrder(LHNode<T>* node, std::vector<T>& arr)
{
	if (node == nullptr) return;
	backOrder(node->left,arr);
	backOrder(node->right,arr);
	arr.push_back(node->val);
}

template<class T>
 LeftistHeap<T>::LeftistHeap():size(0),root(nullptr),isdelete(true)
{
}

 template<class T>
 LeftistHeap<T>::LeftistHeap(const std::vector<T>& arr):size(0),root(nullptr),isdelete(true)
 {
	 
	 initByVector(arr);
 }

 template<class T>
 LeftistHeap<T>::LeftistHeap(const LeftistHeap<T>& object)
 {
	 root = createCopy(object.root);
	 size = object.size;
 }

 template<class T>
 LeftistHeap<T>& LeftistHeap<T>::operator=(const LeftistHeap & object)
 {
	 // TODO: 在此处插入 return 语句
	 if (&object == this) return object;

	 root = createCopy(object.root);
	 size = object.size;
	 isdelete = true;
 }

 template<class T>
 LeftistHeap<T>::~LeftistHeap()
 {
	 destroy();
 }

 template<class T>
 T LeftistHeap<T>::top()
 {
	 if (size == 0)
	 {
		 throw "左倾堆为空";
	 }

	 T val = root->val;
	 return val;
 }

 //左倾堆合并操作
 template<class T>
 void LeftistHeap<T>::merge(LeftistHeap<T>tree)
 {
	 tree.isdelete = false;//不要释放内存标志位
	 root = merge(root,tree.root);
	 size += tree.size;
	 cout << size << endl;
 }

 template<class T>
 void LeftistHeap<T>::pop()
 {
	 if (size == 0) {
		 throw "左倾堆为空";
	 }
	 auto x = root->left;
	 auto y = root->right;
	 delete root;
	 root = merge(x,y);
	 size--;
 }

 template<class T>
 void LeftistHeap<T>::insert(T val)
 {
	 if (size == 0)
	 {
		 root = new LHNode<T>(val, 0, nullptr, nullptr);
	 }
	 else
	 {
		 LHNode<T> *node = new LHNode<T>(val, 0, nullptr, nullptr);
		 root = merge(root, node);
	 }
	 
	 size++;
 }

 template<class T>
 void LeftistHeap<T>::destroy()
 {
	 if (!isdelete) return;
	 destory(root);
	 root = nullptr;
	 size = 0;
	 printf("堆成功被删除\n");
 }

 template<class T>
 bool LeftistHeap<T>::empty()
 {
	 return size == 0?true:false;
 }

 template<class T>
 void LeftistHeap<T>::printfLeftistHeap()
 {
	 std::vector<T> pre;
	 preOrder(pre);

	 std::vector<T> mid;
	 midOrder(mid);

	 std::vector<T> back;
	 backOrder(back);

	 printf("前序遍历为: ");
	 for (int i = 0; i < pre.size(); i++)
		 cout << pre[i]<<" ";
	 cout << endl;

	 printf("中序遍历为: ");
	 for (int i = 0; i < mid.size(); i++)
		 cout << mid[i]<<" ";
	 cout << endl;

	 printf("后序遍历为: ");
	 for (int i = 0; i < back.size(); i++)
		 cout << back[i]<<" ";
	 cout << endl;
	 cout << endl;

 }

 template<class T>
 void LeftistHeap<T>::preOrder(std::vector<int>& arr)
 {
	 preOrder(root,arr);
 }

 template<class T>
 void LeftistHeap<T>::midOrder(std::vector<int>& arr)
 {
	 midOrder(root,arr);
 }

 template<class T>
 void LeftistHeap<T>::backOrder(std::vector<int>& arr)
 {
	 backOrder(root,arr);
 }

 template<class T>
 int LeftistHeap<T>::count()
 {
	 return size;
 }
