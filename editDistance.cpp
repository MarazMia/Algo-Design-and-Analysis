#include<bits/stdc++.h>
using namespace std;
int i,j,m,n,c[1000][1000],cnt;
char x[1000],y[1000],b[1000][1000];
int miin(int a,int b,int c)
{
    return min(min(a,b),c);
}
char trc(int a,int b,int c)
{
    if(a==b && b==c)
        return 'c';
    else if(a==miin(a,b,c))
        return 'c';
    else if(b==miin(a,b,c))
        return 'u';
    else
        return 'l';
}
void print(int i,int j)
{
    if(j==0 && i!=0)
    while(i--)
        cout<<"delete "<<x[i]<<" at position "<<i<<endl;
    if(b[i][j]=='c')
    {
        if(x[i-1]!=y[j-1])
            cout<<"replace "<<x[i-1]<<" with "<<y[j-1]<<" at position "<<i-1<<endl;
        print(i-1,j-1);
    }
    else if(b[i][j]=='u')
    {
        cout<<"delete "<<x[i-1]<<" at position "<<i-1<<endl;
        print(i-1,j);
    }
    else if(b[i][j]=='l')
    {
        cout<<"insert "<<y[i]<<" at position "<<j-1<<endl;
        print(i,j-1);
    }
}
void dist()
{
    m=strlen(x);
    n=strlen(y);
    for(i=0; i<=m; i++)
        c[i][0]=i;
    for(j=0; j<=n; j++)
        c[0][j]=j;

    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
        {
            if(x[i-1]==y[j-1])
                cnt=0;
            else
                cnt=1;

            c[i][j]=miin(c[i-1][j-1]+cnt,c[i-1][j]+1,c[i][j-1]+1);
            b[i][j]=trc(c[i-1][j-1]+cnt,c[i-1][j]+1,c[i][j-1]+1);
        }
}
int main()
{
    cout<<"please enter your two string to see their edit distance"<<endl;
    gets(x);
    gets(y);
    dist();
    cout<<"your operations need to reform string1 to string2\n";
    print(m,n);
    cout<<"and the edit distance is "<<c[m][n];
    getchar();
    return 0;
}

