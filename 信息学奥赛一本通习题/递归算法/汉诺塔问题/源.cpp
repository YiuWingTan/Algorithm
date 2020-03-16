

/*

1205：汉诺塔问题

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 9582     通过数: 3467
【题目描述】
约19世纪末，在欧州的商店中出售一种智力玩具，在一块铜板上有三根杆，最左边的杆上自上而下、由小到大顺序串着由64个圆盘构成的塔。目的是将最左边杆上的盘全部移到中间的杆上，条件是一次只能移动一个盘，且不允许大盘放在小盘的上面。

这是一个著名的问题，几乎所有的教材上都有这个问题。由于条件是一次只能移动一个盘，且不允许大盘放在小盘上面，所以64个盘的移动次数是：18,446,744,073,709,551,615

这是一个天文数字，若每一微秒可能计算(并不输出)一次移动，那么也需要几乎一百万年。我们仅能找出问题的解决方法并解决较小N值时的汉诺塔，但很难用计算机解决64层的汉诺塔。

假定圆盘从小到大编号为1, 2, ...

【输入】
输入为一个整数(小于20）后面跟三个单字符字符串。

整数为盘子的数目，后三个字符表示三个杆子的编号。

【输出】
输出每一步移动盘子的记录。一次移动一行。

每次移动的记录为例如 a->3->b 的形式，即把编号为3的盘子从a杆移至b杆。

【输入样例】
2 a b c
【输出样例】
a->1->c
a->2->b
c->1->b



算法分析】
	我们通过使用递归的思想，将n的输入规模减少为n-1.考虑将n个盘子从a移动到b，想要将n个盘子移动到b那么必须先将n-1个盘子移动到c中，然后将第n个盘子移动到b，再然后将已经在c中的n-1个盘子移动到b中
	。根据这个递归的思想我们可以创建一个函数f(n,from,to).其中n表示n个盘子。from表示n个盘子原先放置的位置
	。to表示要将n个盘子移动的目标盘子。f的含义是将n个盘子从from编号的盘子移动到to编号的盘子。

*/
#include<iostream>
#include<stdio.h>
using namespace std;
int n;
char panel[3];

inline int getOther(int i,int j)
{
	return 3 - i - j;
}

void slove(int count,int from,int to)
{
	if (count == 1) {
		printf("%c->%d->%c\n",panel[from], count,panel[to]);
		return;
	}
	
	slove(count-1,from,getOther(from,to));

	printf("%c->%d->%c\n", panel[from],count, panel[to]);

	slove(count - 1,getOther(from,to),to);

}


int main()
{



	cin >> n;

	cin >> panel[0] >> panel[1]>>panel[2];

	slove(n,0,1);


	return 0;
}

