#include <iostream>
#include <stack>
#include <string>

int priority(char ch)
{
	switch (ch)
	{
	case '+':
		case '-': return 1;
	case '*':
		case '/': return 2;
	default: return -1;
	}
}

int main()
{
	std::string expr;

	std::cout << "Enter expression : " << '\n';
	std::cin >> expr;

	std::stack<char> exitStack;
	std::stack<char> oprtnStack;

	for (int i = 0; i < expr.size(); i++)
	{
		if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
		{
			if (oprtnStack.empty())
			{
				oprtnStack.push(expr[i]);
			}
			else if (priority(expr[i]) > priority(oprtnStack.top()))
			{
				oprtnStack.push(expr[i]);
			}                
			else
			{
				while(!oprtnStack.empty())
				{
					exitStack.push(oprtnStack.top());
					oprtnStack.pop();
				}

				oprtnStack.push(expr[i]);
			}
		}
		else
		{
			exitStack.push(expr[i]);
		}
	}
	while (!oprtnStack.empty())
	{
		exitStack.push(oprtnStack.top());
		oprtnStack.pop();
	}

	while (!exitStack.empty())
	{
		std::cout << exitStack.top() << ' ';
		exitStack.pop();
	}


	system("pause");
	return 0;
}