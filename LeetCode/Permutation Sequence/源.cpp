#include<string>
#include<vector>
#include<iostream>

using namespace std;

void swap(string &str,int i,int j)
{
	char c = str[i];
	str[i] = str[j];
	str[j] = c;
}

//不高效的解决方案
//void Permutation(string arr ,string &result,int begin,int k,int &count)
//{
//	if (count == k) return;
//	if (begin == arr.size()-1)
//	{
//		count++;
//		if (count == k)
//		{
//			result = arr;
//			cout << result<<endl;
//		}
//		return;
//	}
//
//	for (int i = begin; i < arr.size()&&count!=k; i++)
//	{
//		swap(arr,begin,i);
//		Permutation(arr,result,begin+1,k,count);
//	}
//
//}
//
//string getPermutation(int n, int k) {
//
//	if (k == 0 || n == 0) return "";
//	string arr = "";
//	for (int i = 1; i <= n; i++)
//		arr += (i + '0');
//	string result = "";
//	int count = 0;
//	Permutation(arr,result,0,k,count);
//	cout << count<<endl;
//	if (count == k) return result;
//
//	return "";
//}

//高效的解决方案

string getPermutation(int n, int k)
{
	if (n == 0 || k == 0) return "";
	string result = "";
	vector<int> p;
	vector<char> nums = {'1','2','3','4','5','6','7','8','9'};
	p.resize(n+1);
	p[1] = 0;
	for (int i = 2; i <=n; i++)
	{
		if (i == 2) p[2] = 1;
		else p[i] = p[i - 1] * (i - 1);
	}
	
	if (n != 1 && k != 1 && (p[n] * n) < k) return "-131";

	int index = 0;
	k--;
	while (n > 0)
	{
		if (p[n] != 0)
		{
			index = k / p[n];
			k = k % p[n];
		}
		else
		{
			k = index = 0;
		}
		result += nums[index];
		nums.erase(nums.begin() + index);//移除相应的位置
		n--;
	}



	return result;

}



int main()
{
	int n = 4;
	int k = 9;
	string str = getPermutation(n,k);

	cout << str<<endl;

	getchar();
	return 0;
}