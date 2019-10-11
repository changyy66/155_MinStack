// 155_MinStack.cpp : 定义控制台应用程序的入口点。
//
/*
设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-stack
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include "stdafx.h"
#include <stack>
//#include <list>
#include <vector>
#include <iostream>

using namespace std;


class MinStack {
private:
	stack<int> s;
	stack<int> mins;
public:
	/** initialize your data structure here. */
	MinStack() {
		
	}

	void push(int x) {
		s.push(x);
		if (mins.size()==0 || x<=mins.top())
		{
			mins.push(x);
		}
		else
		{
			mins.push(mins.top());
		}
	}

	void pop() {
		mins.pop();
		s.pop();
	}

	int top() {
		return s.top();
	}

	int getMin() {
		return mins.top();
	}
};


int main()
{
	MinStack m;
	m.push(0);
	m.push(-1);
	m.push(-3);
	m.push(3);
	cout << m.top() << endl;
	cout << m.getMin() << endl;
	m.pop();
	cout << m.top();
	m.pop();
	cout << m.getMin() << endl;
    return 0;
}

