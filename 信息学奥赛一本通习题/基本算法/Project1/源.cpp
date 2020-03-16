#include<iostream>
#include<vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

	for (int i = 0; i < gas.size(); i++)
	{
		if (gas[i] - cost[i] >= 0)
		{
			//½øÐÐÅÐ¶Ï
			int totalGas = gas[i] - cost[i];
			int index = (i + 1)%gas.size();
			while (totalGas >= 0 && index != i)
			{
				totalGas += gas[index] - cost[index];
				index = (index + 1) % gas.size();
			}

			if (index == i&&totalGas>=0) return i;

		}
	}

	return -1;
}


int main()
{


	getchar();
	return 0;
}



