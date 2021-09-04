#include "MathQ.h"

int MathQ::ZJ_1()
{
    int n, last;
    cin >> n >> last;
    vector<long long> nums(n);
    for(long long& i:nums)
    {
        cin >> i;
    }
    last -= 1; //向量下标应该从0开始
 
    long long min_val = *min_element(nums.begin(), nums.end());
    for(long long& i:nums){i -= min_val;}
    long long count = min_val * nums.size();
    while(nums[last] > 0)
    {
        --nums[last];
        ++count;
        --last;
        if(last == -1){
            last = n - 1;
        }
    }
    nums[last] = count;
 
    for(auto& i:nums){cout << i << ' ';}
    return 0;

    // long n,x,mn=LONG_MAX, s=0;         //必须都是long
    // cin>>n>>x;
    // vector<long> a(n);
    // for(int i=0;i<n;++i)
    // {
    //     cin>>a[i];
    //     if(a[i]<mn)
    //     mn=a[i];
    // }
    // int k=x-1;
    // while(a[k]!=mn)
    //     k=(k+n-1)%n;
    // for(int i=0;i<n;++i)
    //     a[i]-=mn;
    // for(int i=x-1;i!=k;)
    // {
    //     --a[i];
    //     ++s;
    //     i=(i+n-1)%n;
    // }
    // a[k]+=s+n*mn;
    // for(int i=0;i<n;++i)
    //     cout<<a[i]<<" ";  
    // return 0;
}