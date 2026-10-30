#include <iostream>
#include<cstring>
#include<string>
#include<stack>
int priority(char c)
{
    if (c=='*'||c=='/')
    {
        return 2;
    }
    else if (c=='+'||c=='-')
    {
        return 1;
    }
    else if (c=='(')
    {
        return 0;
    }
    else
    {
        return 0;
    }

}
std::string transform(char* zhong)
{
    std::string result;
    std::string s= "+-*/(";
    std::stack<char> st;
    for (int i=0;i<strlen(zhong);i++)
    {
        char c = zhong[i];
        if (c==' ')
        {
            continue;
        }
        else if (c>='0'&&c<='9'||c>='a'&&c<='z'||c=='.'
            ||c=='-'&&(i==0||s.find(zhong[i-1])!=std::string::npos))
        {
            result+=c;
        }
        else if (c=='(')
        {
            st.push('(');
        }
        else if (c==')')
        {
            while (st.top()!='(')
            {
                result+=st.top();
                st.pop();
            }
            st.pop();
        }
        else if (c=='+'&&(i==0||s.find(zhong[i-1])!=std::string::npos))
        {
            continue;
        }
        else if (st.empty())
        {
            st.push(c);
        }
        else if (priority(c)>priority(st.top()))
        {
            st.push(c);
        }
        else
        {
            while (!st.empty()&&priority(c)<=priority(st.top()))
            {
                result+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        result+=st.top();
        st.pop();
    }
    return result;
}
int main()
{
    char input[500] = {'\0'};
    while (std::cin.getline(input,400))
    {
        if (strlen(input) ==0)
        {
            continue;
        }
        std::cout <<transform(input)<<std::endl;
    }
}
