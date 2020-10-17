/*这道题主要是让一条链表合入到另一条，并让他们排序*/
#include <stdio.h>
#define Max 100005//where Address is the position of the node, Data is a positive integer no more than 100005
typedef struct
{
	int address;
	int data;
	int next;
}node;
node list[Max];
int a[Max], b[Max], c[Max];
node list_c[Max];
int m1 = 0, m2 = 0;
void merge(int* _a, int* _b, int num_a, int num_b)//a的长度永远大于b
{
	int k1 = 0, k2 = 0, len_c = 0;
	int len2 = num_b - 1;//较短链表的长度
	
	//printf("num_a=>%d,num_b=>%d\n", num_a, num_b);
	while (k1 < num_a || k2 < num_b)
	{
		if (k1 < num_a)//将长链先加入到list_c
		{
			c[len_c++] = _a[k1];
			//printf("address=>%05d,k1=%d\n", _a[k1],k1);
			k1++;
		}
		if (k1 < num_a)//长链每次需要加入2个
		{
			c[len_c++] = _a[k1];
			//printf("address=>%05d,_k1=%d\n", _a[k1],k1);
			k1++;
		}
		if (k2 < num_b)//倒序插入短链
		{
			
			c[len_c++] = _b[len2 - k2];
			//printf("address=>%05d,k2=%d\n", _b[len2 - k2],len2-k2);
			k2++;
		}
	}
	int i = 0;
	for (i = 0; i < len_c - 1; i++)
	{
		int u = c[i];
		printf("%05d %d %05d\n", list[u].address, list[u].data, list[c[i+1]].address);//注意这里要输出下一个链表地址，因此不要用next而是用i+1的address
	}
	int u = c[len_c - 1];
	printf("%05d %d -1", list[u].address, list[u].data);
	
}
int main()
{
	/*输入的数据格式
	Address Data Next
	当前节点地址 当前节点数据 下一个节点的地址
	*/
	/*当下一个节点的地址为-1的时候代表当前节点结束了*/
	/*It is guaranteed that no list is empty, and the longer list is at least twice as long as the shorter one.*/
	/*没有链表是空的，因此我们不需要判断是否为空*/
	/*我们需要一个结构体来存储更方便*/
	int num_a = 0, num_b = 0;
	int f1, f2, n, flag = 0;//flag == 0 ->a链表 flag == 1->b链表
	/*the first line contains the two addresses of the first nodes of L1 and L2*/
	scanf("%d %d %d", &f1, &f2, &n);
	int t_a, t_d, t_n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &t_a, &t_d, &t_n);//全部加入到list数组
		list[t_a].next = t_n;
		list[t_a].data = t_d;
		list[t_a].address = t_a;
		
	}
	int p1 = f1;//第一条链表
	while (p1 != -1)//当下一节点地址不为-1的时候
	{
		a[m1++] = p1;//记录a链表每个节点的地址
		p1 = list[p1].next;
	}
	int p2 = f2;//遍历第二条链
	while (p2 != -1) {
		b[m2++] = p2;
		p2 = list[p2].next;
	}
	
	if (m1 > m2)/*选出较长链表*/
	{
		merge(a, b,m1,m2);
	}
	else
	{
		merge(b, a,m2,m1);
	}
}
