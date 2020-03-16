#include"Sort.h"
#include<algorithm>
#include"DataStruct.h"
#include<math.h>
#include<string>
using namespace std;


/*������̨��*/

void frogJumpStep()
{
	int n = 1;
	vector<int> arr;
	arr.resize(n+3,0);
	arr[1] = 1;
	arr[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		arr[i] = arr[i-1] + arr[i-2];
	}

	printf("������%d��̨�׵ķ����ܹ���%d��\n",n,arr[n]);

}


//�����㷨�ܽ�
void Sort()
{
	vector<int> arr = { 1,2,66,2,15,85,33,5,45,52,89,3,35,22,52,0,2,3,6,8,54,1,58,11,51,15,51,36,9,11,5,6,25,20,31,61 };

	SelectSort(arr);
	MaoPaoSort(arr);
	InsertSort(arr);
	GuiBingSort(arr);
	QuickSort(arr);
	headSort(arr);
	TongSort(arr);
	JiShuSort(arr);
	cout << endl << endl;
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}


/*********************��ת��������С����*******/

int nFind(vector<int> &arr,int lo,int hi)
{
	if (hi >= arr.size() || hi < 0) return INT_MIN;
	if(lo >= arr.size() || lo < 0) return INT_MIN;
	int result = arr[lo];
	while (lo <= hi)
	{
		if (result > arr[lo])
		{
			result = arr[lo];
		}
		lo++;
	}
	return result;
}

void findMinNumber()
{
	vector<int> arr = {12,0,1,1,1};

	int lo = 0;
	int hi = arr.size()-1;
	int mid = 0;
	int result = 0;
	if (arr[hi] > arr[lo])result = arr[0];

	while (hi - lo != 1)
	{

		mid = (hi - lo) / 2 + lo;
		if (arr[mid] > arr[lo]) lo = mid;
		else if(arr[mid] < arr[lo]) hi = mid;
		else if (arr[mid] == arr[hi] && arr[mid] == arr[lo])
		{
			result = nFind(arr,lo,hi);
			break;
		}
		if (hi - lo == 1) result = arr[hi];
	}
	
	printf("��Сֵ��%d\n",result);
}

/**********************************************/

/*�����е�·��*/

bool findPath(vector<vector<char>> &matrix, int row, int col, int ri, int cj,string &target,int index)
{
	if (matrix.size() == 0) 
		return false;
	if (target.size() == index) 
		return true;
	bool isFind = false;
	char c;
	for (int i = -1; i <= 1&&!isFind; i++)
	{
		if (i != 0&& ri + i >= 0 && ri + i < row)
		{
			if (matrix[ri + i][cj] == target[index])
			{
				c = matrix[ri + i][cj];
				matrix[ri + i][cj] = '.';
				isFind = findPath(matrix, row, col, ri + i, cj, target, index + 1);
				matrix[ri + i][cj] = c;
			}
		}
	}

	for (int i = -1; i <= 1&&!isFind; i++)
	{
		if (i != 0 && cj + i >= 0 && cj + i < col)
		{
			if (matrix[ri][cj+i] == target[index])
			{
				c = matrix[ri][cj+i];
				matrix[ri][cj+i] = '.';
				isFind = findPath(matrix, row, col, ri, cj+i, target, index + 1);
				matrix[ri][cj+i] = c;
			}
		}
	}
	
	return isFind;
}

//�Ӿ������ҵ�·��
void findPathInMatrix()
{
	string target = "fgs";
	vector<vector<char>> m =
	{
		{'a','b','t','g'},
		{ 'c','f','c','s' },
		{ 'j','d','e','h' }
	};
	vector<vector<char>> m1 = { { 'a','b','f','g','s','a' } };
	int row = 3;
	int col = 4;
	bool ishasPath = false;


	for (int i = 0; i < 1 && !ishasPath; i++)
	{
		for (int j = 0; j < 6 && !ishasPath; j++)
		{
			if(m1[i][j] == target[0])
				ishasPath |= findPath(m1,1,6,i,j, target,1);
		}
	}
	printf("%s\n", ishasPath ? "��·��" : "û��·��");
	cout << endl;

	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 6; j++)
			cout << m1[i][j] << "  ";
		cout << endl;
	}

	
}

/**************/


/*��е�˵��˶���Χ*/

bool checkIndex(int i,int j,int target)
{
	int num = 0;
	while (i > 0||j>0)
	{
		num += i % 10;
		num += j % 10;
		j /= 10;
		i /= 10;
	}
	if (num > target) 
		return false;
	return true;
}
int find(bool*&visited,int row,int col,
		  int i,int j,int target)
{
	if (i < 0 || i >= row) return 0;
	if (j < 0 || j >= col) return 0;
	if (visited[i*col + j]) return 0;

	if (checkIndex(i, j,target ))
	{
		visited[i*col + j] = true;
		return 1 
			+ find(visited,row,col,i+1,j,target)
			+find(visited,row,col,i-1,j,target)
			+find(visited,row,col,i,j+1,target)
			+find(visited,row,col,i,j-1,target);
	}
	return 0;
}

void FindExtend()
{
	int count = 0;
	int target = 0;
	int row = 1;
	int col = 5;
	bool *visited = new bool[row*col];

	for (int i = 0; i < row*col; i++)
	{
		visited[i] = false;
	}

	if (row == 0 && col == 0) count = 0;
	else 
		count = find(visited,row,col,0,0,target);

	printf("��е�����ߵĸ�������%d\n",count);

	delete visited;
}

/*********/


/*�����Ӽ��������ʹ���εĳ˻����*/

//��̬�滮
int cut(int length)
{
	if (length == 0) return 0;
	if (length == 1) return 1;
	if (length == 2) return 2;
	if (length == 3) return 3;

	vector<int> f(length+1,0);
	f[0] = 0;
	f[1] = 1;
	f[2] = 2;
	f[3] = 3;
	int max;
	for (int i = 4; i <= length; i++)
	{
		max = 0;
		for (int j = 1; j <= i / 2; j++)
		{
			if (max < f[j] * f[i - j])
			{
				max = f[j] * f[i-j];
			}
		}
		f[i] = max;
	}
	return f[length];
}
//̰���㷨
int cut2(int length)
{
	if (length == 0) return 0;
	if (length == 1) return 1;
	if (length == 2) return 2;
	if (length == 3) return 3;

	int timesof3 = length / 3;

	if ((length - timesof3 * 3) == 1) timesof3 -= 1;

	int timeof2 = (length - timesof3 * 3) / 2;

	return (int)pow(3,timesof3)*(int)pow(2,timeof2);
}

void CutRope()
{
	int length = 8;

	int max = cut(length);

	printf("��̬�滮���ֵ��%d\n",max);
	max = cut2(length);
	printf("̰���㷨���ֵ��%d\n",max);
}

/**********************************/

/*ͳ�����ֶ������е�λ��*/

void countBit1()
{
	int num = -7;
	int count = 0;
	//��numΪ������ʱ��������ѭ��
	while (num != 0)
	{
		if (num & 1 == 1) count++;
		num = num >> 1;
	}
	printf("������1�ĸ���Ϊ%d\n",count);
}

void countBit2()
{
	int num = 0x80000000;
	unsigned int flag = 1;
	int count =0;
	while (flag != 0)
	{
		if ((num&flag)==flag) count++;
		flag = flag << 1;
	}
	printf("�����еı���λ��Ϊ%d\n",count);
}

//���Ľⷨ
void countBit3()
{
	int count = 0;
	int num = -5;
	while (num)
	{
		num = num&(num - 1);
		count++;
	}
	printf("�����еı���λ��Ϊ%d\n", count);
}

/************************/

/*��ֵ�������η�*/

//��̫�õ�ʵ��
double power(double base,int exponent)
{
	double n;
	double result = 1;
	if (exponent > 0) n = base;
	else if (exponent < 0) n = 1 / base;
	else return 1.0f;
	if (base == 0) return 1;
	exponent = exponent > 0 ? exponent : -exponent;

	for (int i = 1; i <= exponent; i++)
	{
		result *= n;
	}
	return result;
}

int equals(double a, double b) {
	return fabs(a - b) < 0.000001;
}
bool isFailed = false;
double caulate(double val,int exponent)
{
	if (exponent == 1) return val;
	if (exponent == 0) return 0.0;
	if (val == 0) return 0.0;
	double result = caulate(val,exponent>>1);
	result *= result;
	if (exponent & 0x1 == 1) result *= val;
	return result;
}
double power2(double base,int exponent)
{
	isFailed = false;
	if (equals(base, 0.0) && exponent < 0)
	{
		isFailed = true;
		return 0.0;
	}
	
	double result = caulate(base,(int)fabs(exponent));
	if (exponent < 0) result = 1 / result;
	return result;
}

void Power()
{
	double n = power2(2,-2);
	if (isFailed) { printf("����\n"); }
	printf("�����%f",n);
}


/****************/


/*��ӡ����nλ��*/

void getMaxNumber(int n)
{
	if (n < 0)
	{
		isFailed = true;
		return ;
	}
	else if (n == 0) return;
	string result(n+2,' ');
	result[n + 1] = '\0';
	result[n] = '1';
	int i = 0;
	
	while (result[0] != '1')
	{
		cout << result.c_str()<<endl;
		int i = n;
		for (; i >= 0&&result[i]=='9'; i--)
		{
			result[i] = '0';
		}
		if (result[i] == ' ')result[i] = '1';
		else result[i] += 1;
	}
}

void printMaxNumber()
{
	int n = -12;//n��ʾλ��
	getMaxNumber(n);
	//cout << INT_MAX<<endl;
}

/*****************/


/*******************�������*******************/

void addBigNumber(string s1,string s2)
{
	if (s1.size() <= 0)
	{
		cout << s2.c_str() << endl;
		return;
	}
	if (s2.size() <= 0)
	{
		
		cout << s1.c_str() << endl;
		return;
	}

	if (s1[0] == '-' || s2[0] == '-')
	{
		printf("���ڸ���\n");
		isFailed = true;
		return;
	}

	for (int i = 1; i < s1.size(); i++)
	{
		if ((s1[i]<'0'||s1[i]>'9'))
		{
			isFailed = true;
			printf("�������������");
			return;
		}
	}
	for (int i = 1; i < s2.size(); i++)
	{
		if ((s2[i]<'0'||s2[i]>'9'))
		{
			isFailed = true;
			printf("�������������");
			return;
		}
	}

	string t1(max(s1.size(),s2.size())+1,'0');
	string t2(max(s1.size(),s2.size())+1,'0');

	int k = s1.size() - 1;
	for (int i = t1.size() - 1; i >= 0; i--,k--)
	{
		if(k>=0)
			t1[i] = s1[k];

	}
	k = s2.size() - 1;
	for (int i = t2.size() - 1; i >= 0; i--, k--)
	{
		if(k>=0)
			t2[i] = s2[k];
	}
	
	cout << t1.c_str()<<endl;
	cout << t2.c_str() << endl;

	int a = 0;
	int b = 0;
	int rank = 0;
	for (int i = t1.size() - 1; i >= 0; i--)
	{
		a = t1[i] - '0';
		b = t2[i] - '0';

		t1[i] = (a + b + rank) % 10 + '0';
		if ((a + b + rank) >= 10) rank = 1;
		else rank = 0;
	}
	
	cout << t1.c_str() << endl;
	return;
}


void AddBigNumber()
{
	
	string s1 = "1253265555.5555555555";
	string s2 = "4564646";

	addBigNumber(s1,s2);
}

/**********************************************/


/**************************������ʽƥ��**********************************/

//���ݽ������
bool cmp(string &target,string &s,int n,int p)
{
	if (n == target.size()&&p == s.size()) 
		return  true;
	if (p >= s.size()) return false;
	bool result = false;
	bool isSame = false;
	int k = p+1;
	if (p + 1 < s.size() && s[p + 1] == '*')
	{
		while (k < s.size() && s[k] == '*') k++;
		isSame = true;
	}
	if (n<target.size()&&(target[n] == s[p] || s[p] == '.'))
	{
		if (isSame)
		{
			result |= cmp(target, s, n, k);
			for (int i = 0;(n + i) < target.size() && (target[n + i] == s[p]||s[p] == '.'); i++)
				result |= cmp(target,s,n+i+1,k);
		}
		else result |= cmp(target,s,n+1,p+1);
	}
	else
	{
		if (isSame)
		{
			result |= cmp(target, s, n, k);
		}
	}


	return result;
	
}
/*
"aasdfasdfasdfasdfas"
"aasdf.*asdf.*asdf.*asdf.*s"

"aaa"
"ab*a*c*a"

"mississippi"
"mis*is*p*."
*/

void CmpStr()
{
	string target = "mississippi";
	string s = "mis*is*p*.";

	bool isOk = cmp(target,s,0,0);

	printf("%s\n",isOk?"ģʽƥ��\n":"ģʽ��ƥ��\n");
}

/**************************************************************************/


/***************************��ʾ��ֵ���ַ���*******************************/
bool isNumber(char*&);

bool scanUnsignedNumber(char *&str)
{
	char* prev = str;

	for (; (*str) != '\0' && (*str) >= '0' && (*str) <= '9'; str++);

	return str>prev;
}
bool scanNumber(char *&str)
{
	if ((*str) == '+' || (*str) == '-')
		++str;
	return scanUnsignedNumber(str);
}

//����һ���ַ����Ƿ��ʾ��ֵ
bool isNumber(char *&str)
{
	if (str == NULL) return false;
	bool result = scanNumber(str);

	if ((*str) != '\0'&&(*str) == '.')
	{
		str++;
		result |= scanUnsignedNumber(str);
	}

	if ((*str) != '\0' && (*str) == 'e')
	{
		str++;
		result &=  scanNumber(str);
	}

	return result&&(*str) == '\0';
}

//�����Ƿ�������
void IsNumber()
{
	char *str = "100";
	bool result =  isNumber(str);
	printf("%s\n",result?"������\n":"��������\n");
}

/**********************************************************/

/************************��������ʹ����λ������ǰ��ż��λ���������**********************************/

typedef bool(*OrderRule)(int);
//�ж��Ƿ�������
bool isOddNumber(int num)
{
	return (num & 1 == 1);
}
bool isNegative(int num)
{
	return num > 0;
}
void placeNumber(int *arr,int len,OrderRule func)
{
	if (arr == nullptr||len == 0) return;
	int *p = arr;
	int *n = arr + len-1;
	while (p < n)
	{
		if (!func(*p))
		{
			//*p��ǰ��һ��ż��
			int m = (*p);
			*p = (*n);
			*n = m;
			n--;
		}
		else p++;
	}

}

void placeNumberInArray()
{
	int arr[] = {1};
	int len = sizeof(arr) / sizeof(int);
	printf("���������к�\n");

	placeNumber(nullptr,len, isNegative);
	for (int i = 0; i < len; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;

}

/****************************************************************************************************/

/*************************************��ȡ����ĵ�����k���ڵ�************************************************/

SingleListNode<int>* getKNode(SingleListNode<int>*list,int k)
{

	if (list == nullptr) return nullptr;

	SingleListNode<int> *p = list;
	SingleListNode<int> *pp = list;
	int n = 1;
	for (; n < k&&pp->next != nullptr; n++, pp = pp->next);
	if (n != k)
	{
		printf("����Ľڵ��������%d��,ֻ��%d��\n",k,n);
		return nullptr;
	}

	while (pp->next != nullptr)
	{
		pp = pp->next;
		p = p->next;
	}
	return p;
}
void KnumberInLinkList()
{
	vector<int> arr = { 5,6,3,2,14,5,8,9,151,51,1,5 };
	int k = 15;
	SingleListNode<int>* list = nullptr;
	CreateSingleList(arr,list);
	ShowList(list);
	auto node = getKNode(list, k);
	if (node != nullptr)
		printf("\n�ҵ��Ľڵ�Ϊ%d\n",node->val);
}

/*****************************************************************/


/****************************************�����л�����ڽڵ�*************************************/
//����һ����������ڽڵ��ǵ�����k��Ԫ��
bool CreateCycle(SingleListNode<int>*list,int k)
{
	if (list == nullptr)
	{
		printf("�����������nullptr\n");
		return false;
	}
	if (k <= 0) { printf("������������Ľڵ���kС�ڵ���0\n"); return false; }
	SingleListNode<int> *p = list;
	SingleListNode<int>* pp = list;

	while (k > 1&&pp->next!=nullptr)
	{
		pp = pp->next;
		k--;
	}
	if (k != 1)
	{
		printf("�����еĽڵ�ĸ�������%d��\n",k);
		return false;
	}
	while (pp->next != nullptr)
	{
		pp = pp->next;
		p = p->next;
	}
	pp->next = p;
	printf("���������\n");
	return true;
}
SingleListNode<int>* getCycle(SingleListNode<int>*list)
{
	if (list == nullptr)
	{
		printf("�����������һ��nullptr\n");
		return nullptr;
	}

	SingleListNode<int>* pSlow = list;
	SingleListNode<int>* pFast = list;
	while (pFast != nullptr&&pFast->next!=pSlow)
	{
		pSlow = pSlow->next;
		pFast = pFast->next;
		if (pFast != nullptr)
		{
			pFast = pFast->next;
		}
	}
	//�ж��Ƿ�
	if (pFast == nullptr) {
		printf("�����в����ڻ�\n");
		return nullptr;
	}
	pFast = pSlow;
	int k = 1;//��ʾ�����л��ĳ���
	while (pFast->next != pSlow)
	{
		pFast = pFast->next;
		k++;
	}

	pSlow = list;
	pFast = list;
	for (int i = 1; i < k; i++) pFast = pFast->next;
	while (pFast->next != pSlow)
	{
		pFast = pFast->next;
		pSlow = pSlow->next;
	}

	return pSlow;
}
//�ҵ������л�����ڽڵ�
void FindCycleofLinkList()
{
	vector<int> arr = {1};
	SingleListNode<int> *list = nullptr;
	int k = 1;
	CreateSingleList(arr,list);
	ShowList(list);
	cout << endl;
	CreateCycle(nullptr,k);
	auto node = getCycle(nullptr);
	if(node!=nullptr)
		printf("�����л��Ŀ�ʼ�ڵ���%d\n",node->val);
	else printf("�����в����ڻ�\n");
}

/**************************************��ת����*********************************************************/

SingleListNode<int>* reverseLinkList(SingleListNode<int>*list)
{
	if (list == nullptr)
	{
		printf("����������ǿյ�\n");
		return nullptr;
	}
	if (list->next == nullptr) return list;

	SingleListNode<int> *p = list;
	SingleListNode<int> *pp = list->next;
	SingleListNode<int> *mid = pp;

	while (pp->next != nullptr)
	{
		mid = pp->next;
		pp->next = p;
		p = pp;
		pp = mid;
	}
	pp->next = p;
	list->next = nullptr;
	return pp;
}
//��ת����
void ReverseLinkList()
{
	vector<int> arr = {1,2,3};
	SingleListNode<int> *list = nullptr;
	CreateSingleList(arr, list);
	ShowList(list);

	list = reverseLinkList(list);
	ShowList(list);
	DeleteSingleList(list);
}

/*******************************************************************************************************/

/*********************************�ϲ�������������**********************************/
SingleListNode<int>* merge(SingleListNode<int>* l1,SingleListNode<int>* l2) {

	if (l1 == nullptr) return l2;
	if (l2 == nullptr) return l1;

	SingleListNode<int> *p = nullptr;
	if (l1->val > l2->val)
	{
		p = l2;
		p->next = merge(l1,l2->next);
	}
	else
	{
		p = l1;
		p->next = merge(l1->next,l2);
	}

	return p;
}

void MergeLinkList()
{
	vector<int> arr1 = {1,3,5,7};
	vector<int> arr2 = {2,4,6,8};
	SingleListNode<int>*l1 = nullptr;
	SingleListNode<int>*l2 = nullptr;
	CreateSingleList(arr1,l1);
	CreateSingleList(arr2,l2);
	ShowList(l1);
	ShowList(l2);

	SingleListNode<int> *np = merge(l1,l2);
	ShowList(np);
	DeleteSingleList(np);
}

/***********************************************************************************/




int main()
{

	MergeLinkList();
	getchar();
	return 0;
}