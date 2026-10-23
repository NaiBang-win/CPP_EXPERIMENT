#include <cstdio>
#include <cmath>
#include <iostream>
#include <ostream>
using namespace std;
// TIP 要<b>Run</b>代码，请按 <shortcut actionId="Run"/> 或点击装订区域中的 <icon src="AllIcons.Actions.Execute"/> 图标。
double function(const double a[],int n,double x);

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        int n;
        scanf("%d",&n);
        double a[1001];
        for(int j=0;j<n+1;j++)
        {
            scanf("%lf",&a[j]);
        }
        int times;
        scanf("%d",&times);
        for(int j=0;j<times;j++)
        {
            double x;
            scanf("%lf",&x);
            double result = function(a,n,x);
            printf("%.10e\n", result);
        }
    }
}
double function(const double a[],int n,double x)
{
    double result=0;
    for(int i=0;i<=n;i++)
    {
        result+=a[i]*pow(x,i);
    }
    return result;
}