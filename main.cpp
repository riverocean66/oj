#include<iostream>
#include<algorithm>
using namespace std;
long long m,n,q,a[500005],b[500005],s[500005],c[500005],x;
int main()
{
    cin>>m>>n>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
        s[a[i]]++;
        b[i]=(s[a[i]]-1)*n+a[i];
    }
    sort(b+1,b+1+m);
    for(int i=1;i<=m;i++)
        c[i]=b[i]-i;

    for(int i=1;i<=q;i++)
    {
        cin>>x;
        if(x>b[m])
        {
            long long k=x%n;
            if(k==0) k=n;
            cout<<k<<endl;
            continue;
        }
        x-=m;
        for(int i=1;i<=m;i++)
        {
            if(x>c[i] && x<=c[i+1])
            {
                long long ans=b[i]+x-c[i];
                long long k=ans%n;
                if(k==0) k=n;
                cout<<k<<endl;
                break;
            }
        }
    }
    return 0;
}
