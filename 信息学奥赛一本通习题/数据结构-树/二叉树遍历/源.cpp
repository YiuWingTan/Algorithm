/*
���˼·
�������ȸ��ݲ������ȷ������Ȼ�����������ҵ�����Ӧ�������������������֡�Ȼ�������ڵݹ�ģ���������������Ľڵ㡣
�ܳ��󿴴���
*/


#include<iostream>
#include<cstring>
#include<string>
using namespace std;




string in, layer;
void pre(int inl, int inr, int layerl, int layerr) {
	int i, j, t;
	//Ϊʲô��Ҫ˫��ѭ���أ���Ϊ����������ұߵ�ֵ�п��������������п�����������,������Ҫ��������������Ľڵ㡣
	for (i = layerl; i <= layerr; i++) {
		int b = 0;
		for (j = inl; j <= inr; j++) {
			if (layer[i] == in[j]) {
				cout << in[j];
				b = 1;
				t = i;
				break;
			}
		}
		if (b) break;
	}
	if (j > inl) pre(inl, j - 1, t, layerr);
	if (j < inr) pre(j + 1, inr, t, layerr);
}
int main() {
	cin >> in >> layer;
	pre(0, in.size() - 1, 0, layer.size() - 1);
	return 0;
}
