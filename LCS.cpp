#include<bits/stdc++.h>
using namespace std;
int i,j,m,n,c[1000][1000];
char x[1000],y[1000],b[1000][1000];
void print(int i,int j)
{
    if(i==0 || j==0)
        return;
    if(b[i][j]=='c')
    {
        print(i-1,j-1);
        cout<<x[i-1];
    }
    else if(b[i][j]=='u')
        print(i-1,j);
    else
        print(i,j-1);
}
void lcs()
{
    m=strlen(x);
    n=strlen(y);
    for(i=0;i<=m;i++)
        c[i][0]=0;
    for(i=0;i<=n;i++)
        c[0][j]=0;
        for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                b[i][j]='c';
                c[i][j]=c[i-1][j-1]+1;
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                b[i][j]='u';
                c[i][j]=c[i-1][j];
            }
            else
            {
                b[i][j]='l';
                c[i][j]=c[i][j-1];
            }
        }
}
int main()
{
    cout<<"please enter your two string to see their longest common sub-sequence"<<endl;
    gets(x);
    gets(y);
    lcs();
    cout<<"your lcs is ";
    print(m,n);
    cout<<" ";
    cout<<"and the length of lcs is "<<c[m][n];
    getchar();
    return 0;
}

