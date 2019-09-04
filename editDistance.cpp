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
void fprint(int m,int n)
{
    if(m>=n)
    {
        if(m!=0 && n==0)
            while(m--)
            {
                cout<<"delete "<<x[m]<<" at position "<<m<<endl;
                if(m==0)
                    return;
            }
        if(b[m][n]=='c')
        {
            if(x[m-1]!=y[n-1])
                cout<<"replace "<<x[m-1]<<" and "<<y[n-1]<<" at position "<<m-1<<endl;
            fprint(m-1,n-1);
        }
        else if(b[m][n]=='u')
        {
            cout<<"delete "<<x[m-1]<<" at position "<<m-1<<endl;
            fprint(m-1,n);
        }
        else if(b[m][n]=='l')
        {
            cout<<"insert "<<y[m-1]<<" at position "<<m-1<<endl;
            fprint(m,n-1);
        }
    }

    else
    {
        if(m==0 && n!=0)
            while(n--)
            {
                cout<<"delete "<<x[n]<<" at position "<<n<<endl;
                if(n==0)
                    return;
            }
        if(b[m][n]=='c')
        {
            if(x[m-1]!=y[n-1])
                cout<<"replace "<<x[m-1]<<" with "<<y[n-1]<<" at position "<<n-1<<endl;
            fprint(m-1,n-1);
        }
        else if(b[m][n]=='u')
        {
            cout<<"delete "<<x[n-1]<<" at position "<<n-1<<endl;
            fprint(m-1,n);
        }
        else if(b[m][n]=='l')
        {
            cout<<"insert "<<y[n-1]<<" at position "<<n-1<<endl;
            fprint(m,n-1);
        }
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
    cout<<"please enter your two string to see their edit distance\n\n"<<endl;
    gets(x);
    gets(y);
    dist();
    cout<<"\n\nyour operations need to reform string1 to string2 are\n\n";
    fprint(m,n);
    cout<<"\n\nand the edit distance is "<<c[m][n];
    getchar();
    return 0;
}

