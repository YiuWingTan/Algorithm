#include<iostream>
#include<vector>
using namespace std;

float value[11]
{
	0,1,5,8,9,10,17,17,20,24,30
};

vector<float> big;

int main() {

	big.push_back(0);
	big.push_back(1);

	int length = 0;

	cout << "请输入钢条的长度:";
	cin >> length;

	for (int i = 2; i <=length; i++)
	{
		float max = value[i];
		for (int j = 1; j <= i; j++)
		{
			if ((i - j) < 0) break;

			if (max < (value[j] + big[i - j]))
			{
				max = (value[j] + big[i - j]);
			}
		}
		big.push_back(max);
	}

	cout << "最大为"<<big[length];

	getchar();
	getchar();

	return 0;
}