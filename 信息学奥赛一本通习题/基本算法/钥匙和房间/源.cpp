#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
	
	if (rooms.size() == 0) return true;

	vector<bool> marked(rooms.size(),false);
	int count = 0;

	stack<int> st;
	st.push(0);

	while (!st.empty())
	{
		int k = st.top(); st.pop();

		marked[k] = true;
		count++;

		for (auto n : rooms[k])
		{
			if (!marked[n]) {

				st.push(n);
			}
		}
	}
	return count == rooms.size();
}





