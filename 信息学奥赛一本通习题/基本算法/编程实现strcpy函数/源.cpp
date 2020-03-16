#include<iostream>
#include<vector>
#include<cassert>
using namespace std;


char* my_strncpy(char* dest,char*src,int n)
{
	assert((dest!=nullptr)&&(src !=nullptr));


	char* result = dest;

	for (int i = 0; i < n; i++)
	{
		if (src != '\0')
		{
			*dest++ = *src++;
		}
		else {
			*dest++ = '\0';
		}
	}
	return result;
}



int main()
{
	char dest[10];
	char* src = "hello";
	int n = 1;
	my_strncpy(dest,nullptr,n);
	for (int i = 0; i < n; i++)
		cout << dest[i]<<" ";

	getchar();
	return 0;
}

