#include<bits/stdc++.h>
using namespace std;
int m[1000][1000],s[1000][1000];
void printBrackets(int i,int j)
{
    if(i==j)
    {
        cout<<"a"<<i;
        return;
    }
    cout<<"(";
    printBrackets(i,s[i][j]);
    printBrackets(s[i][j]+1,j);
    cout<<")";
}
void miniCost(int p[],int n)
{
    int i,j,k,d,q;
    for(int ii=1; ii<n; ii++)
        m[ii][ii]=0;
    for(d=2; d<n; d++)
    {
        for(int i=1; i<n-d+1; i++)
        {
            j=i+d-1;
            m[i][j]=696969;
            for(k=1; k<=j-1; k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }

    cout<<"maximum number of multiplication operations are : "<<m[1][n-1]<<endl;
    cout<<"the sequence of multiplication is : ";
    printBrackets(1,n-1);
}
int main()
{
    int n;
    //int p[] = {40, 20, 30, 10, 30};  //little help from geek for geek
    //int n = sizeof(p)/sizeof(p[0]);
    cout<<"input the number of matrices dimensions\n";
    cin>>n;
    int p[n];
    cout<<"enter the dimension\n";
    for(int i=0; i<n; i++)
        cin>>p[i];
    miniCost(p,n);
    return 0;
}
