/**
    @Caution: Remove all comments and change functions names before showing.
    @Author: Nadim & Shuvo;
    @Version: 1/0.0;
    @return 0;
*/

#include <bits/stdc++.h>
using namespace std;

double xr[10],yr[10];/// y=f(x),given x & y values
class Interpolation{
    public:
    /**
        @formula y=f(x)..................
    */
    double calculate(double x,int points){
        double result = 0;
        for (int i=0; i<points; i++)
        {
            double term = yr[i];
            for (int j=0;j<points;j++)
            {
                if (j!=i)
                    term = term*(x - xr[j])/double(xr[i] - xr[j]);
            }
            result += term;
        }
        return result;
    }
};

int main()
{
    int i,j,a,b,ts,f=1,cn=0,n,points;
    Interpolation lgIp;
    freopen("Lagrange.txt","r",stdin);
    scanf("%d",&points);///number of given points
    for(i=0;i<points;i++){
        scanf("%lf %lf",&xr[i],&yr[i]);
    }
    double x;
    scanf("%lf",&x);///we have to find y=f(x) for this given x
    double ans = lgIp.calculate(x,points);
    printf("%lf\n",ans);
    return 0;
}

