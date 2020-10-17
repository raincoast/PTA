#include<stdio.h>
#define Max 100005
int main()
{
	//Address Data Next 需要对Data进行排序
	int Data[Max];
	int Next[Max];
	int list[Max];
	int FirstAdd, N/*节点的总数*/, K/*要被调换的子节点数量，每k个链表调换一波*/;
	scanf("%d %d %d", &FirstAdd, &N, &K);
	for (int i = 0; i < N; i++)
	{
		int t_add, t_data, t_next;
		scanf("%d %d %d", &t_add, &t_data, &t_next);//读入当前的Address Data Next的地址
		Data[t_add] = t_data;//用Data数组来模拟一个节点,让地址为Address地方的data为t_data
		Next[t_add] = t_next;//让地址为Address地方的next节点的地址为t_next

	}
	int sum = 0;//有效节点数
	while (FirstAdd != -1)// The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.
	{
		list[sum++] = FirstAdd;//记录所有的节点
		FirstAdd = Next[FirstAdd];//让FirstAdd为下一个节点的地址，找到下一个节点，当FirstAdd为-1时即为输入结束了

	}
	for (int i = 0; i < sum - sum % K; i += K)//根据题目,如果剩余节点数不够K个，则不发生反转
	{
		for (int j = 0; j < K / 2; j++)//反转链表
		{
			/*整个反转过程*/
			int t = list[i + j];//t为第i组第j个元素的节点
			list[i + j] = list[i + K - j - 1];//进行反转
			list[i + K - j - 1] = t;
		}
	}
	for (int i = 0; i < sum - 1; i++)
	{
		printf("%05d %d %05d\n", list[i], Data[list[i]], list[i + 1]);//输出所有节点

	}
	printf("%05d %d -1\n", list[sum - 1], Data[list[sum - 1]]);//输出结尾节点
}
