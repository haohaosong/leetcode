#pragma once

/*
* author:haohaosong
* date:2017/4/18
* note:逆波兰表达式求解
*/

#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<stack>
#include<assert.h>

class Solution {
public:
	int evalRPN(vector<string> &tokens)
	{
        if(tokens.size() == 0)
            return 0;
		stack<int> s;
		for (int i = 0; i<tokens.size(); ++i)
		{
			string tmp = tokens[i];
			if (tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/")
			{
                if(s.size() < 2)
                    return 0;
				int num2 = s.top();
				s.pop();
				int num1 = s.top();
				s.pop();


				if (tmp == "+")
					s.push(num1 + num2);
				if (tmp == "-")
					s.push(num1 - num2);
				if (tmp == "*")
					s.push(num1 * num2);
				if (tmp == "/")
				{	if (num2 == 0)
						assert(false);
					else
						s.push(num1 / num2);
				}
			}
			else
			{
				s.push(atoi(tmp.c_str()));
			}
		}
		if (s.size() == 1)
			return s.top();
		else
			assert(false);
	}
};