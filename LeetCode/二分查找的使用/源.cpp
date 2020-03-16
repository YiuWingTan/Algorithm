#include<iostream>
#include<vector>
using namespace std;

//�ж��Ƿ���ڻ����ǵ��ڱ��ָ�Ĵ���
bool is_ok(vector<float>&arr,float val,int k)
{
	int count = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		count += arr[i] / val;
	}


	return count >= k;
}

//��ȡ���ָ�����ĳ���
float getMax(vector<float>&arr,int n)
{
	if (arr.size() == 0) return 0.0;
	float x = 0.0;

	float st = 0.0;
	float ed = INT_MAX;
	float mid = 0.0;
	for (int i = 0; i < 100; i++)
	{
		mid = st + (ed - st) / 2.0;
		if (is_ok(arr, mid, n))
		{
			ed = mid;
		}
		else
		{
			st = mid;
		}
	}

	return mid;

}


int main()
{
	int k = 11;
	vector<float> arr = {8.02f,7.43f,4.57f,5.39f};

	cout << "���ķָ��Ϊ"<< getMax(arr,k)<<endl;

	getchar();
	return 0;
}
