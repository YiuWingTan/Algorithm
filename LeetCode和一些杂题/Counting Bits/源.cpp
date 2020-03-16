#include<iostream>
#include<vector>

using namespace std;

int count(int n)
{
	int num = 0;
	while (n >= 1)
	{
		if (n % 2 == 1) num++;
		n /= 2;
	}
	return num;
}

vector<int> binary;
vector<int> countBits(int num) {

	
	binary.push_back(0);
	if (num <= 0) return  binary;
	binary.push_back(1);
	for (int i = 2; i <= num; i++)
	{
		if (i > binary.size()-1)
		{
			binary.push_back(count(i));
		}
	}
	return binary;
}



int main()
{
	int n = 0;

	vector<int> result = countBits(n);

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i]<<"  ";
	}


	getchar();
}