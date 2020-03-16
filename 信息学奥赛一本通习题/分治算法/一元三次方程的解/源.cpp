
#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

float a, b, c, d;

inline float cal(float x)
{
	return a * x*x*x+ b * x*x + c * x + d;
}

inline float abs_f(float a)
{
	return a > 0.0f ? a : -a;
}

float cmp(float x1,float x2)
{
	float y1 = cal(x1);
	float y2 = cal(x2);

	return y1*y2;
}


float binaryFind(float lo,float hi)
{
	

	while (hi - lo >= 0.001f)
	{
		int mid = (hi + lo) / 2.0f;
		if (cmp(lo, mid) <= 0)
		{
			hi = mid;
		}
		else {
			lo = mid;
		}
	}
	return lo;
}


int main()
{
	vector<float> re;

	cin >> a >> b >> c >> d;

	
	for (float i = -100.0f; i < 100.0f&&re.size()<3; i++)
	{
		float tmp = cmp(i,i+1.0f);

		if (tmp < 0)
		{
			//存在等于零
			//进行二分查找
			re.push_back(binaryFind(i,i+1));
		}
		else if (tmp == 0.0f)
		{
			if (cal(i) == 0.0f) re.push_back(i);
		}

	}

	
	for (int i = 0; i < re.size(); i++)
	{
		printf("%.2f ",re[i]);
	}
	cout << endl;
	return 0;
}


