

#include<iostream>
#include<string>
#include<vector>
using namespace std;


int caluate(int n)
{
	if (n == 0) return 1;
	if (n == 1) return 2011;
	int tmp = caluate(n/2);

	int val = (tmp*tmp)%10000;

	if (n % 2 == 1)
	{
		//ÆæÊý
		val = (val * 2011) % 10000;
	}

	return val;
}


int main()
{
	
	int n;
	vector<int> re;
	string str;
	cin >> n;

	while (n > 0)
	{
		cin >> str;
		int p = 0;
		for (int i = 4>str.size()?str.size():4; i >0 ; i--)
		{
			p = p * 10 + (str[str.size() - i] - '0');
		}

		p = p % 500;
 
		re.push_back(caluate(p));
		n--;
	}



	for (int i = 0; i < re.size(); i++)
	{
		cout << re[i]<<endl;
	}
	return 0;
}

