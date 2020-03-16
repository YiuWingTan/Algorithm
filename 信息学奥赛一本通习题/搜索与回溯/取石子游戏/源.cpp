
#include<iostream>
using namespace std;


bool judge(int a,int b,bool isfirst)
{
	if (a == 0 || b == 0) return !isfirst;

	if (b > a) std::swap(a,b);

	if (a / b >= 2) return isfirst;

	return judge(a -b,b,!isfirst);

 }


int main()
{
	int a, b;

	while (cin >> a >> b) {

		if (a == 0 && b == 0) break;
		if (judge(a, b,true))
		{
			cout << "win"<<endl;
		}
		else {
			cout << "lose"<<endl;
		}

	}


	return 0;
}





