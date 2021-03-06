#include <stdio.h>
#include "double_link.h"

// 创建队列
int create_dlink_queue() 
{
	return create_dlink();
}

// 销毁队列
int destroy_dlink_queue() 
{
	return destroy_dlink();
}

// 将val添加到队列的末尾
int add(int val) 
{
	return dlink_append_last(val);
}

// 返回“队列开头元素”
int front() 
{
	return dlink_get_first();
}

// 返回并删除“队列开头元素”
int pop() 
{
	int ret = dlink_get_first();
	dlink_delete_first();
	return ret;
}

// 返回“队列”的大小
int size() 
{
	return dlink_size();
}

// 返回“队列”是否为空
int is_empty()
{
	return dlink_is_empty();
}

void main()
{
	int tmp=0;

	// 创建“队列”
	create_dlink_queue();

	// 将10, 20, 30 依次队列中
	add(10);
	add(20);
	add(30);

	// 将“队列开头的元素”赋值给tmp，并删除“该元素”
	tmp = pop();
	printf("tmp=%d\n", tmp);


	// 销毁队列
	destroy_dlink_queue();
}
