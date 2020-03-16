#include<iostream>

using namespace std;

//不能检查带符号
bool isNumber(char**string)
{
	if (*string == nullptr||**string == '\0') return true;
	if (**string == '.') ++(*string);

	char*str = *string;

	while (**string >= '0'&&**string <= '9') ++(*string);

	if (**string == '\0' || **string == 'e' || **string == 'E') return true;

	return *string != str;
}

//能检查带符号的
bool isNumber_by(char**string)
{
	if (**string == '-'|| **string == '+') ++(*string);

	char*str = *string;

	while (**string >= '0'&&**string <= '9') ++(*string);

	//if (**string == '\0'||**string == 'e'|| **string == 'E') return true;

	return str!=*string;
}

bool isNumeric(char* string)
{
	if (string == nullptr) return false;

	if (!isNumber_by(&string)&&*string!='.') return false;

	isNumber(&string);

	if (*string == 'e' || *string == 'E')
	{
		++string;
		if (*string == '\0') return false;
		isNumber_by(&string);
	}
		

	return *string == '\0';
}




int main()
{
	cout << isNumeric("-1E-16") << endl;

	getchar();
	return 0;
}


