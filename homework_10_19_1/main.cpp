#include <iostream>

#include <iostream>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    string expr;
    while (cin >> expr)
    {
        stack<double> st;
        for (char c : expr)
        {
            if (isdigit(c))
            {
                st.push(c - '0');
            }
            else
            {
                double right = st.top();
                st.pop();
                double left  = st.top();
                st.pop();
                double res;
                switch (c)
                {
                case '+':
                    res = left + right;
                    break;
                case '-':
                    res = left - right;
                    break;
                case '*':
                    res = left * right;
                    break;
                case '/':
                    res = left / right;
                    break;
                }
                st.push(res);
            }
        }
        printf("%f\n", st.top());
    }
    return 0;
}

