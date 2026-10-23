#include <iostream>
using namespace std;
string removeZore(string s)
{
    string a = "";
    int j = 0;
    for (int i=0;i<s.length();i++)
    {
        if (s[i]!='0')
        {
            j=i;
            break;
        }
    }
    a.append(s,j,s.length()-j);
    return a;
}
string add(string a,string b)
{
    while (a.length()<b.length())
    {
        a="0"+a;
    }
    while (a.length()>b.length())
    {
        b="0"+b;
    }
    string result="";
    int jinwei = 0;
    for (int i=a.length()-1;i>=0;i--)
        {
            int A = a[i] - '0';
            int B = b[i] - '0';
            int sum = A+B+jinwei;
            if (sum>=10)
            {
                sum = sum-10;
                jinwei = 1;
            }
            else
            {
                jinwei = 0;
            }
            char cur = sum +'0';
            result = cur+result;
        }
    if (jinwei==1)
    {
        result ='1'+result;
    }
    if (result=="")
    {
        return "0";
    }
    return result;
}
int main()
{
    int T;
    int caseNum = 1;

    while (cin >> T) {
        for (int i = 1; i <= T; ++i) {
            string A, B;
            cin >> A >> B;
            string SUM = add(removeZore(A), removeZore(B));

            cout << "Case " << caseNum << ":\n";
            caseNum++;
            cout << A << " + " << B << " = " << SUM << "\n";
            if (i<T)
            {
                cout<<"\n";
            }
        }
    }
    return 0;
}
