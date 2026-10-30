#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <list>
//请在此处补充calculate函数的实现。
double calculate(char* c)
{
    std::stack<double> st;
    for (int i = 0;i<strlen(c);i++)
    {
        char ch = c[i];
        if (ch>='0'&&ch<='9')
        {
            st.push(ch-'0');
        }
        else
        {
            double r = st.top();
            st.pop();
            double l = st.top();
            st.pop();
            switch (ch)
            {
            case'+':
                st.push(r+l);
                break;
            case'-':
                st.push(l-r);
                break;
            case'/':
                st.push(l/r);
                break;
            case '*':
                st.push(l*r);
                break;
            }
        }
    }
    return st.top();
}
//--------------------------------//
int main(int argc, const char * argv[])
{
    char input[500] = {'\0'};
    std::cin.getline(input, 400);
    printf("%f\n", calculate(input));
    return 0;
}