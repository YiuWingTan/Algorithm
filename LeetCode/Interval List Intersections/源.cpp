#include<iostream>
#include<vector>

using namespace std;

int min(int i,int j) {
	return i > j ? j : i;
}

int max(int i, int j) {
	return i > j ? i : j;
}

vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {

	if (A.size() == 0 || B.size() == 0) return{};

	int i = 0, j = 0;
	vector<vector<int>> result;


	while (i < A.size() && j < B.size())
	{
		if (A[i][0] > B[j][1]) {
			//A在前面
			j++;
			continue;
		}
		if (A[i][1] < B[j][0]) {
			//B在前面
			i++;
			continue;
		}

		result.push_back({max(A[i][0],B[j][0]),min(A[i][1],B[j][1])});

		if (A[i][1] > B[j][1]) j++;
		else i++;


	}
	return result;
}


int main()
{


	
}
