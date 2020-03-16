

#include<iostream>

using namespace std;


bool f(int k,int y)
{
	if (k == y) return true;
	if (k < y) return false;
	
	
	return f(k,y*2+1)||f(k,y*3+1);
}


int main()
{

	int k, y;

	cin >> k >> y;
	 std::swap(k,y);


	if (f(k, y)) cout << "YES"<<endl;
	else cout << "NO"<<endl;

	return 0;
}



