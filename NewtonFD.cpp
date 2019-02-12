/**
    @Caution: Remove all comments and change functions names before showing.
    @Author: Nadim & Shuvo;
    @Version: 1/0.0;
    @return 0;
*/

#include <bits/stdc++.h>
using namespace std;
double fdtable[10][10];///Forward difference table
double xr[10],yr[10];/// y=f(x),given x & y values
class forwarddiff{
    public:
    void makeTable(int points){
        ///Entening given values to table
        for(int i=0;i<points;i++){
            fdtable[i][0]=yr[i];
        }
        ///Creating table
        for(int i=1;i<points;i++){
            for(int j=0;j<points-i;j++){
                fdtable[j][i]=fdtable[j+1][i-1]-fdtable[j][i-1];
            }
        }
    }
    double fact(int n){
        int fct=1;
        for(int i=1;i<=n;i++){
            fct *= i;
        }
        return fct;
    }
    /**
        @formula y=f(x)..................
    */
    double calculate(double x,int points){
        double h,u,sum = 0,tmpu=1;
        h=xr[1]-xr[0];
        u=(x-xr[0])/h;
        for(int i = 0;i<points;i++){
            sum +=  (tmpu/fact(i))*fdtable[0][i];
            tmpu *= (u-i);
        }
        return sum;
    }
};

int main()
{
    int i,j,a,b,ts,f=1,cn=0,n,points;
    forwarddiff ffd;
    freopen("newtonfd.txt","r",stdin);
    scanf("%d",&points);///number of given points
    for(i=0;i<points;i++){1
        scanf("%lf %lf",&xr[i],&yr[i]);
    }
    double x;
    scanf("%lf",&x);///we have to find y=f(x) for this given x
    ffd.makeTable(points);
    double ans = ffd.calculate(x,points);
    ///Printing table. Remove it.
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%5.3lf ",fdtable[i][j]);
        }
        puts("");
    }
    printf("%lf\n",ans);
    return 0;
}
