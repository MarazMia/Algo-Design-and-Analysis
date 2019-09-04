#include<bits/stdc++.h>
using namespace std;
int m,n,i,j,c[1000][1000],cost,cc[1000][1000];
char x[1000],y[1000],b[1000][1000],bb[1000][1000];
int miin(int a,int b,int c)
{
    return min(min(a,b),c);
}
void print(int m,int n)
{
    if(m==0 || n==0)
        return;
    else if(b[m][n]=='c')
    {
        print(m-1,n-1);
        cout<<x[m-1];
    }
    else if(b[m][n]=='u')
        print(m-1,n);
    else
        print(m,n-1);
}
void lcs()
{
    m=strlen(x);
    n=strlen(y);
    for(i=0; i<=m; i++)
        c[i][0]=0;
    for(j=0; j<=n; j++)
        c[0][j]=0;
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
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
char trace(int a,int b,int c)
{
    if(a==b && b==c)
        return 'c';
    else if(miin(a,b,c)==a)
        return 'c';
    else if(miin(a,b,c)==b)
        return 'u';
    else
        return 'l';
}
void dist()
{
    m=strlen(x);
    n=strlen(y);
    for(i=0; i<=m; i++)
        cc[i][0]=i;
    for(j=0; j<=n; j++)
        cc[0][j]=j;

    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
        {
            if(x[i-1]==y[j-1])
                cost=0;
            else
                cost=1;
            cc[i][j]=miin(cc[i-1][j-1]+cost,cc[i-1][j]+1,cc[i][j-1]+1);
            bb[i][j]=trace(cc[i-1][j-1]+cost,cc[i-1][j]+1,cc[i][j-1]+1);
        }
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
        if(bb[m][n]=='c')
        {
            if(x[m-1]!=y[n-1])
                cout<<"replace "<<x[m-1]<<" and "<<y[n-1]<<" at position "<<m-1<<endl;
            fprint(m-1,n-1);
        }
        else if(bb[m][n]=='u')
        {
            cout<<"delete "<<x[m-1]<<" at position "<<m-1<<endl;
            fprint(m-1,n);
        }
        else if(bb[m][n]=='l')
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
        if(bb[m][n]=='c')
        {
            if(x[m-1]!=y[n-1])
                cout<<"replace "<<x[m-1]<<" with "<<y[n-1]<<" at position "<<n-1<<endl;
            fprint(m-1,n-1);
        }
        else if(bb[m][n]=='u')
        {
            cout<<"delete "<<x[n-1]<<" at position "<<n-1<<endl;
            fprint(m-1,n);
        }
        else if(bb[m][n]=='l')
        {
            cout<<"insert "<<y[n]<<" at position "<<n-1<<endl;
            fprint(m,n-1);
        }
    }
}
int main()
{
    cout<<"please enter your two string to see their LCD and edit distance\n\n"<<endl;
    gets(x);
    gets(y);
    lcs();
    cout<<"\n\nyour lcs is"<<endl;
    print(m,n);
    cout<<" of length "<<c[m][n]<<endl;
    dist();
    cout<<"\nthe edit distance between this two strings is "<<cc[m][n]<<endl;
    cout<<"\n\nand you need to perform below operations into source string for turning source string to destination string\n\n"<<endl;
    fprint(m,n);
    return 0;
}
