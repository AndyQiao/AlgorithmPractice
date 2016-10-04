#include <stack>
#include <iostream>
using namespace std;

void core(stack<int> &s,int n)
{
	int tmp=s.top();
	s.pop();
	int tmp1=s.top();
	s.pop();
	s.push(tmp);
	if(--n)
		core(s,n);
	s.push(tmp1);
}
void ReverseStack(stack<int>& s)
{
	int n=s.size();
	if(n>1)
		while(--n)
			core(s,n);
}
int main()
{
	stack<int> s;
	for(int i=0;i<10;++i)
		s.push(i);
	ReverseStack(s);
	while(s.size())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
	return 0;
}
