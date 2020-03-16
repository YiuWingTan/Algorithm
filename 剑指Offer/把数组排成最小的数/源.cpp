#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


int compare(const string &s1, const string s2)
{
	string r1;
	string r2;

	r1 = s1 + s2;
	r2 = s2 + s1;

	return strcmp(r1.c_str(), r2.c_str());
}


void quickSort(vector<string>&arr,int lo,int hi)
{
	if (lo >= hi) return;
	int i = lo+1;
	int j = hi;
	int k = lo;

	while (i <= j)
	{
		if (compare(arr[k], arr[i]) < 0) swap(arr[i],arr[j--]);
		else if (compare(arr[k], arr[i]) > 0) swap(arr[k++],arr[i++]);
		else i++;
	}

	quickSort(arr,lo,j);
	quickSort(arr,j+1,hi);
}




string minNumber(vector<int> &arr)
{
	vector<string> tmp;
	string str;
	for (int i = 0; i < arr.size(); i++)
	{
		tmp.push_back(to_string(arr[i]));
	}

	quickSort(tmp,0,tmp.size()-1);

	string result = "";

	for (int i = 0; i < tmp.size(); i++)
	{
		result += tmp[i];
	}
	return result;

}





int main()
{
	vector<int> arr = { 3,32,321 };

	string result = minNumber(arr);

	cout << result << endl;

	getchar();
	return 0;
}