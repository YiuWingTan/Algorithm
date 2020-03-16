#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {

	if (rooms.size() == 0) return true;

	vector<bool> mark; mark.resize(rooms.size(),false);
	stack<int> st;
	st.push(0);
	mark[0] = true;
	int num = 0;
	while (!st.empty())
	{
		int index = st.top(); st.pop();
		num++;
		for (auto const&x : rooms[index])
		{
			if (!mark[x])
			{
				mark[x] = true;
				st.push(x);
				
			}
		}
	}

	return num == rooms.size();

}

int main()
{
	vector<vector<int>> arr = 
	{
		{1},
		{2},
		{3},
		{}
	};

	cout<<canVisitAllRooms(arr)<<endl;

	getchar();
	return 0;
}