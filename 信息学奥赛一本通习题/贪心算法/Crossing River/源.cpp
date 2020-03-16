
#include<iostream>
#include<vector>
using namespace std;

int arr[10000];

void qSort(int lo,int hi)
{
	if (lo >= hi) return;


	int i = lo + 1,k = lo,j = hi;

	while (i <= j)
	{
		if (arr[i] < arr[k])
		{
			swap(arr[i++],arr[k++]);
		}
		else if (arr[i] > arr[k])
		{
			swap(arr[i],arr[j--]);
		}
		else
		{
			i++;
		}

	}
	qSort(lo,k-1);
	qSort(j+1,hi);
}


int main()
{
	vector<int> re;
	int t;
	cin >> t;


	while (t > 0)
	{
		int totalTime = 0;
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) cin >> arr[i];

		qSort(0,n-1);

		int consume = 0;
		int num = n;

		while (true)
		{
			if (num <= 3)
			{
				if(num == 3||num == 1)
				for (int i = 0; i < num; i++)
				{
					consume += arr[i];
					
				}
				else {
					consume += arr[1];
				}
				break;
			}

			int plan1 = arr[0] + arr[1] * 2 + arr[num-1];
			int plan2 = arr[num-1] + arr[num-2] + 2*arr[0];

			consume += plan1 > plan2 ? plan2 : plan1;
			num -= 2;
		}
		
		re.push_back(consume);
		t--;
	}

	for (int i = 0; i < re.size(); i++)
	{
		cout << re[i]<<endl;
	}


	return 0;
}


