#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> matrixChainOrder(vector<int> p);
void printOptimalParens(vector<vector<int>> s,int i,int j);
void displaymat(vector<vector<int>> mat);

int main()
{   int n,a;
    vector<int> p;
    cout<<"Enter  n : ";
    cin>>n;

    cout<<"\nEnter value of p : ";
    for(int i=0;i<=n;i++)
    {
        cin>>a;
        p.push_back(a);
    }
   cout<<"  "<<p.size()<<" : ";
    printOptimalParens( matrixChainOrder(p),1,6);
    return 0;
}

vector<vector<int>> matrixChainOrder(vector<int> p)
{
    int n =p.size(),j,q;
    vector<vector<int>> m(n,vector<int>(n,0)),s(n,vector<int>(n,0));

    //displaymat(m);

    for (int l=2;l<=n;l++)
       {
         //cout<<"reached loop 2";
        for(int i=0;i<=n-l;i++)
            {
               j=i+l-1;
               m[i][j]=999999;
           //    cout<<"reached loop 3";
               for(int k=i;k<=j-1;k++)
               {
                   q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
             //      cout<<"multiplication done";
                   if(q<m[i][j])
                   {
                       m[i][j]=q;
                       s[i][j]=k;
                   }
               }

            }
       }
       cout<<"\n";
       displaymat(m);
       displaymat(s);
       return s;
}

void displaymat(vector<vector<int>> mat)
{
    for(int i=1;i<mat.size();i++)
    {
     for(int j=1;j<mat[i].size();j++)
    {
        cout<<mat[i][j]<<" ";
    }
    cout<<"\n";
    }

}

void printOptimalParens(vector<vector<int>> s,int i,int j)
{
    if(i==j)
        cout<<"A"<<i;
    else
    {   cout<<"(";
        printOptimalParens(s,i,s[i][j]);
        printOptimalParens(s,s[i][j]+1,j);
        cout<<")";
    }
}
