#include<iostream>
#include<vector>

using namespace std;

int min(int n1,int n2,int n3)
{
	return n1 > n2 ? n2 > n3 ? n3 : n2 : n1 > n3 ? n3 : n1;
}


//获取丑数
vector<int> getUglyNumbers(int nums)
{
	if (nums == 0) return{};

	vector<int> result;
	result.resize(nums);
	result[0] = 1;

	int nextIndex = 1;
	int index2 = 0;
	int index3 = 0;
	int index5 = 0;

	while (nextIndex < nums)
	{
		int val = min(result[index2]*2,result[index3]*3,result[index5]*5);
		result[nextIndex] = val;

		while (result[index2] * 2 <= val) index2++;
		while (result[index3] * 3 <= val) index3++;
		while (result[index5] * 5 <= val) index5++;

		nextIndex++;
	}
	return result;
}

void text1()
{
	int number = 0;
	auto result = getUglyNumbers(number);

	printf("%d个丑数的结果为\n",number);
	for (int i = 0; i < result.size(); i++)
		cout << result[i]<<" ";
	cout << endl << endl;
}
void text2()
{
	int number = 1;
	auto result = getUglyNumbers(number);

	printf("%d个丑数的结果为\n", number);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	cout << endl << endl;
}
void text3()
{
	int number = 2;
	auto result = getUglyNumbers(number);

	printf("%d个丑数的结果为\n", number);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	cout << endl << endl;
}
void text4()
{
	int number = 25;
	auto result = getUglyNumbers(number);

	printf("%d个丑数的结果为\n", number);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	cout << endl<<endl;
}

int main()
{
	text1();
	text2();
	text3();
	text4();


	getchar();
	return 0;
}
