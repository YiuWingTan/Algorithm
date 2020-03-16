#include"Heap.h"


template<class T>
Heap<T>::Heap(Compare _sinkFunc, Compare _swinFunc) :container(20), size(0), swinFunc(_swinFunc),
data(nullptr), sinkFunc(_sinkFunc)
{
	data = new T[container];
}

template<class T>
Heap<T>::Heap(const Heap<T> & object) :size(object.size), container(object.container), sinkFunc(object.sinkFunc),swinFunc(object.swinFunc)
{
	//自我拷贝也已经考虑进去了
	T *oldData = data;
	T *newData = new T[object.container];
	for (int i = 0; i < object.container; i++)
	{
		newData[i] = object.data[i];
	}
	this->data = newData;
	delete oldData;

}

template<class T>
Heap<T>& Heap<T>::operator=(const Heap<T> &object)
{
	// TODO: 在此处插入 return 语句
	T *newData = new T[object.container];
	for (int i = 0; i < object.container; i++)
	{
		newData[i] = object.data[i];
	}
	this->data = newData;
	delete oldData;

	size = object.size;
	container = object.container;
	swinFunc = object.swimFunc;
	sinkFunc = object.sinkFunc;
}

template<class T>
Heap<T>::~Heap()
{
	if (data)
		delete data;
	data = nullptr;
	swinFunc = nullptr;
	sinkFunc = nullptr;
	printf("堆中的数据已经被删除\n");
}

template<class T>
void Heap<T>::insert(T a)
{
	size++;
	data[size - 1] = a;
	swim(size - 1, size);
	if (size == container) expand();
}

template<class T>
T Heap<T>::top()
{
	if (empty()) throw "堆为空";

	T val = data[0];

	return val;
}

template<class T>
void Heap<T>::Pop()
{
	if (empty()) throw "当想要进行Pop操作时，堆为空";

	swap(0, size - 1);
	size--;
	sink(0, size - 1);
}

template<class T>
bool Heap<T>::del(int index)
{
	if (index >= size||index<0) return false;

	swap(index, size - 1);
	size--;
	sink(index, size - 1);
	return true;
}

template<class T>
bool Heap<T>::empty()
{
	return size == 0 ? true : false;
}

template<class T>
int Heap<T>::count()
{
	return size;
}

template<class T>
void Heap<T>::show()
{
	for (int i = 0; i < size; i++)
		cout << data[i] << " ";
	cout << endl;
}


template<class T>
inline bool Heap<T>::expand()
{
	container *= 2;

	T *newData = new T[container];

	for (int i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}

	delete data;

	data = newData;
	return true;
}

template<class T>
void Heap<T>::swim(int i, int n)
{
	if (i > n) return;

	int par;

	while (i >= 1)
	{
		par = Parent(i);
		if (swinFunc(data[i], data[par])) swap(i, par);
		i = par;
	}

}

template<class T>
void Heap<T>::sink(int i, int n)
{
	if (i >= n) return;

	int k;

	while (LEFT(i) < n)
	{
		k = LEFT(i);
		if (k + 1 <= n&&sinkFunc(data[k], data[k + 1])) k++;
		if (sinkFunc(data[i], data[k])) swap(i, k);
		else break;
		i = k;
	}


}

template<class T>
inline void Heap<T>::swap(int i, int j)
{
	T mid = data[i];
	data[i] = data[j];
	data[j] = mid;
}
