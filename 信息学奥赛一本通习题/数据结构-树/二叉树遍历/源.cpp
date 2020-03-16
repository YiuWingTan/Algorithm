/*
解决思路
我们首先根据层序遍历确定根，然后在中序中找到根对应的左子树和右子树部分。然后我们在递归的，优先输出左子树的节点。
很抽象看代码
*/


#include<iostream>
#include<cstring>
#include<string>
using namespace std;




string in, layer;
void pre(int inl, int inr, int layerl, int layerr) {
	int i, j, t;
	//为什么需要双重循环呢，因为层序遍历中右边的值有可能是左子树又有可能是右子树,我们需要优先输出左子树的节点。
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
