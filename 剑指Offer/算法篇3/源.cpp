#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<functional>
#include"DataStruct.h"
using namespace std;

template <class Type>
Type stringToNum(const string& str) {
	istringstream iss(str);
	Type num;
	iss >> num;
	return num;
}

bool ReadStream(istream &stream,int *number)
{
	string str = "";
	char s = '1';
	stream.read(&s, 1);
	if (s<'0' || s>'9') return false;

	while (s >= '0'&&s <= '9')
	{
		str += s;
		stream.read(&s, 1);
	}
	*number = stringToNum<int>(str);
	return true;
}

void SerializeTree(BinaryTreeNode<int> *node,ostream &stream)
{
	if (node == nullptr)
	{
		stream << "$,";
		return;
	}
	stream << node->val << ",";
	SerializeTree(node->left,stream);
	SerializeTree(node->right,stream);
}


BinaryTreeNode<int>* DeSerializeTree(istream &stream)
{

	BinaryTreeNode<int> *node = nullptr;
	int val = 0;
	if (ReadStream(stream, &val))
	{
		node = new BinaryTreeNode<int>(val);
		node->left = DeSerializeTree(stream);
		node->right = DeSerializeTree(stream);
	}

	return node;

}

//序列化和反序列化一颗树
void SerializeAndDeSerializeOfTree()
{

}

/*组合字符串*/

void swap(vector<char> &arr,int i,int j)
{
	char c = arr[i];
	arr[i] = arr[j];
	arr[j] = c;
}

void myCombiation(vector<char> &arr,int begin,int n,int len,vector<string> &result, string &str)
{
	if (n == len)
	{
		result.push_back(str);
		return;
	}
	n++;
	for (int i = begin; i < arr.size(); i++)
	{
		str.push_back(arr[i]);
		myCombiation(arr,i+1,n,len,result,str);
		str.pop_back();
	}
}

void Combiation()
{
	vector<char> arr = {'1','2','3','4'};
	vector<string> result;
	string str = "";
	for(int i = 1;i<=arr.size();i++)
		myCombiation(arr,0,0,i,result,str);

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i]<<endl;
	}
	cout << endl;
}


/******无重复的组合字符串******/

void myNoDuplicateCombiation(vector<char> &arr, int begin, int n, int len, vector<string> &result, string &str)
{
	if (n == len)
	{
		result.push_back(str);
		return;
	}
	n++;
	char prevChar;
	if(begin<arr.size())
		prevChar = arr[begin];
	for (int i = begin; i < arr.size(); i++)
	{
		if (i!=begin&&arr[i] == prevChar) continue;
		str.push_back(arr[i]);
		myNoDuplicateCombiation(arr,i+1,n,len,result,str);
		str.pop_back();
		prevChar = arr[i];
	}
}

void NoDuplicateCombiation()
{
	vector<char> arr = { '1','1','2','2','3','3' };
	vector<string> result;
	string str = "";
	for (int i = 1; i <= arr.size(); i++)
		myNoDuplicateCombiation(arr, 0, 0, i, result, str);

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
	cout << endl;
}

/******************************/

/********************寻找数组中出现次数超过一半的数字**************/

void swap(vector<int> &arr,int i,int j)
{
	int mid = arr[i];
	arr[i] = arr[j];
	arr[j] = mid;
}

//解法一切分
int par(vector<int> &arr,int lo,int hi)
{
	if (lo >= hi) return lo;
	int i = lo+1;
	int j = hi;
	int n = lo;

	while (i <= j)
	{
		if (arr[n] < arr[i]) swap(arr,i,j--);
		else if (arr[n] > arr[i]) swap(arr,n++,i++);
		else i++;
	}

	return j;
}

bool isduplicateNumber(vector<int> &arr,int target)
{
	int count = 0;
	for (int i = 0; i < arr.size(); i++)
		if (target == arr[i]) count++;
	if (count > arr.size() / 2) return true;
	return false;
}

//利用切分
int findDuplicateNumber1(vector<int> &arr)
{
	if (arr.size() == 0) return INT_MIN;
	int n = 0;
	int lo = 0;
	int hi = arr.size()-1;
	int len = arr.size();
	do
	{
		n = par(arr,lo,hi);
		if (n < len / 2) lo = n + 1;
		else hi = n - 1;

	} while (n!=len/2);

	if (isduplicateNumber(arr, arr[n])) return arr[n];
	printf("输入的数组中没有重复超过一半的元素\n");
	return INT_MIN;
}

//利用数组的特性,没有改变数组元素的位置
int findDuplicateNumber2(vector<int> &arr)
{	
	if (arr.size() == 0) return INT_MIN;
	int count = 1;
	int n = arr[0];

	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i] != n) count--;
		else count++;
		if (count == 0)
		{
			count = 1;
			n = arr[i];
		}
	}

	if (isduplicateNumber(arr,n)) return n;
	printf("输入的数组中没有重复超过一半的元素\n");
	return INT_MIN;
}

void textFindDuplicateNumber()
{
	vector<int> arr = {1,2,3,2,2,2,5,4,2};
	int n = findDuplicateNumber2(arr);
	if (n == INT_MIN) 
		printf("没有找到目标元素\n");
	else
		printf("出现次数超过一半的元素是%d\n",n);
}

/******************************************************************/





/*******************寻找最小的k个数*******************************/
//最大堆
class MaxHeap
{
private:
	int count;
	int capcity = 20;
	int *arr;
	void swap(int i,int j)
	{
		if (i < 0 || i > count) return;
		if (j < 0 || j > count) return;
		int mid = arr[i];
		arr[i] = arr[j];
		arr[j] = mid;
	}
	void sink(int i)
	{
		if (i < 0 || i > count) return;
		int n = i;
		int maxChild = 0;

		while ((n * 2)<=count)
		{
			maxChild = n * 2;
			if ((n * 2 + 1) <= count&&arr[n * 2 + 1] > arr[maxChild]) maxChild = n * 2 + 1;
			if (arr[n] < arr[maxChild]) swap(n,maxChild);
			n = maxChild;
		}
	}
	void swim(int i)
	{
		if (i > count) return;
		int n = i;
		while (n/2 >=1&&arr[n]>=arr[n/2])
		{
			swap(n,n/2);
			n /= 2;
		}
	}
	void increase()
	{
		auto narr = new int[capcity*2];
		for (int i = 0; i < capcity; i++)
			narr[i] = arr[i];
		delete arr;
		arr = narr;
		capcity *= 2;
	}
public:
	MaxHeap() {
		count = 0;
		arr = new int[capcity];

	}
	void push(int val)
	{
		count++;
		if (count == capcity) increase();
		arr[count] = val;
		swim(count);
	}
	int delMax()
	{
		if (count == 0) throw exception("The maxHeap is empty");
		int max = arr[1];
		swap(1,count);
		count--;
		sink(1);
		return max;
	}
	int size()
	{
		return count;
	}
	~MaxHeap()
	{
		delete arr;
		arr = nullptr;
		count = 0;
	}
	bool empty()
	{
		return count == 0;
	}
	void show()
	{
		for (int i = 1; i <= count; i++)
			cout << arr[i]<<" ";
	}
	int top()
	{
		if (count == 0) throw exception("The maxHeap is empty");

		return arr[1];
	}
};


//解法一利用了切分
vector<int> findMinKNumber1(vector<int> &arr,int k)
{
	vector<int> result;
	if (arr.size() < k||k == 0) return result;
	int n = 0;
	int lo = 0;
	int hi = arr.size() - 1;
	int len = arr.size();
	do
	{
		n = par(arr, lo, hi);
		if (n < (k-1)) lo = n + 1;
		else hi = n - 1;

	} while (n != (k - 1));

	for (int i = 0; i <= n; i++)
		result.push_back(arr[i]);

	return result;
}

//解法二利用大顶堆
vector<int> findMinKNumber2(vector<int> &arr, int k)
{
	vector<int> result;
	if (arr.size() < k) return result;
	MaxHeap mh;
	
	for (int i = 0; i < arr.size(); i++)
		if (mh.size() != k) mh.push(arr[i]);
		else if(mh.top()>arr[i]){
			mh.delMax();
			mh.push(arr[i]);
		}

		while (!mh.empty()) result.push_back(mh.delMax());

	return result;
}

void textFindMinKNumber()
{
	vector<int> arr = {5,6,3,1,4,7,4,12,-1,-1};
	int k = 1;
	auto list = findMinKNumber2(arr,k);

	printf("最小的%d个数是\n",k);
	for (vector<int>::iterator n = list.begin(); n != list.end(); n++)
	{
		cout << (*n)<<" ";
	}
	cout << endl;
}

/*****************************************************************/



/**************************************获取数据流中的中位数*******************************************/


int getMidNumber(vector<int> &datas)
{
	if (datas.size() == 0) return INT_MIN;
	if (datas.size() == 1) return datas[0];
	vector<int> minHeap;
	vector<int> maxHeap;
	int num = 1;
	int min;
	int max;
	minHeap.push_back(datas[0]);
	push_heap(minHeap.begin(),minHeap.end(),less<int>());



	for (int i = 1; i < datas.size(); i++)
	{
		if (num & 1 == 1)
		{
			//奇数
			minHeap.push_back(datas[i]);
			push_heap(minHeap.begin(),minHeap.end(),less<int>());
			min = minHeap[0];
			pop_heap(minHeap.begin(),minHeap.end(),less<int>());
			minHeap.pop_back();
			maxHeap.push_back(min);
			push_heap(maxHeap.begin(),maxHeap.end(),greater<int>());
		}
		else
		{
			//偶数
			maxHeap.push_back(datas[i]);
			push_heap(maxHeap.begin(),maxHeap.end(),greater<int>());
			max = maxHeap[0];
			pop_heap(maxHeap.begin(),maxHeap.end(),greater<int>());
			maxHeap.pop_back();
			minHeap.push_back(max);
			push_heap(minHeap.begin(),minHeap.end(),less<int>());
		}

		num++;
	}

	if (num & 1 == 1)
	{
		//奇数
		return minHeap[0];
	}

	return (minHeap[0] + maxHeap[0]) / 2;

}

//获取中位数
void GetMidNumber()
{
	vector<int> datas = {};//模拟数据流

	int midNumber = getMidNumber(datas);

	printf("中位数为%d\n",midNumber);
}

/*****************************************************************************************************/


/*连续子数组的最大和*/

int maxSumInArray(vector<int>&arr)
{
	if (arr.size() == 0) return INT_MIN;

	int max = 0;
	int add = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		add += arr[i];
		if (add < arr[i])
		{
			add = arr[i];
		}
		max = max > add ? max : add;
	}

	return max;
}

//连续子数组的最大和
void MaxSumInArray()
{
	vector<int>arr = {3,10,-4,7,2};
	
	int max = maxSumInArray(arr);

	printf("最大和是%d\n",max);
}

/********************/


/*数字序列中的某一位的数字*/

//获取数字中的某一位的数
int getNumber(int n,int i,int c)//c表示这个数字总共有多少位
{
	int count = c;
	while (count != i)
	{
		n /= 10;
		count--;
	}
	return n % 10;
}

int findInNumberString(int n)
{
	if (n <= 10) return n - 1;
	int num = 90;//表示有多少个数
	int sum = 10;
	int begin = 10;
	int k = 2;
	for (; (num*k) < n; k++, num *= 10)
	{
		sum += (num*k);
		begin *= 10;
	}

	n -= sum;
	begin = (n - 1) / k + begin;
	n = n  % k;
	return getNumber(begin,n+1,k);
}

void GetIndexOfNumberString()
{
	int n = 1001;

	int val = findInNumberString(n);

	printf("序列中第%d个数字是%d\n",n,val);
}

/**************************/
int main()
{
	/*vector<int> arr = {1,6,2,5,1,8,9,4,85,5,15,65,25,25,96};
	MaxHeap mh;

	for (int i = 0; i < arr.size(); i++)
		mh.push(arr[i]);
	while (!mh.empty())
		cout << mh.delMax()<<" ";
	cout << endl;*/
	GetIndexOfNumberString();
	system("pause");
	return 0;
}