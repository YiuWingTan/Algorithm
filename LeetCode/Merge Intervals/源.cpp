#include<vector>
#include<iostream>
using namespace std;


 struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
	
};

 int compare(const Interval& a, const Interval& b)
 {
	 if (a.start == b.start) return a.end - b.end;
	 return a.start - b.start;
 }
 void swap(vector<Interval>&arr,int i,int j)
 {
	 Interval mid = arr[i];
	 arr[i] = arr[j];
	 arr[j] = mid;
 }
 int max(int i, int j)
 {
	 return i > j ? i : j;
 }
 int min(int i,int j)
 {
	 return i > j ? j : i;
 }
 void QuickSort(vector<Interval>&arr,int lo,int hi)
 {
	 if (lo >= hi) return;

	 int k = lo;
	 int i = lo + 1;
	 int j = hi;
	 int cmp = 0;

	 while (i <= j)
	 {
		 cmp = compare(arr[k],arr[i]);
		 if (cmp < 0) swap(arr,i,j--);
		 else if (cmp > 0) swap(arr,k++,i++);
		 else i++;
	 }
	 QuickSort(arr,lo,k-1);
	 QuickSort(arr,i,hi);
 }

 



vector<Interval> merge(vector<Interval>& intervals) {

	vector<Interval> result;
	if (intervals.size() == 0) return result;

	QuickSort(intervals,0,intervals.size()-1);

	result.push_back(intervals[0]);
	int index = 0;
	for (int i = 1; i < intervals.size(); i++)
	{
		if (intervals[i].start == result[index].start)
		{
			result[index].end = max(intervals[i].end, result[index].end);
		}
		else if (result[index].end >= intervals[i].start)
		{
			result[index].end = max(intervals[i].end, result[index].end);
		}
		else {
			result.push_back(intervals[i]);
			index++;
		}
	}


	/*for (int i = 0; i < intervals.size(); i++)
		printf("[%d,%d] ",intervals[i].start,intervals[i].end);
	cout << endl;*/
	return result;
}


int main()
{
	vector<Interval> arr = 
	{
		{ 1,4 }
	};
	auto list = merge(arr);

	for (int i = 0; i < list.size(); i++)
		printf("[%d,%d] ",list[i].start,list[i].end);

	getchar();
	return 0;
}