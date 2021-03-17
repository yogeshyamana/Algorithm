#include<bits/stdc++.h>
using namespace std;

//Recurisive approch Brute foce Approach O(2^n)
int fibo(int n){
    if(n<=1){
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}

//Memoization top down approch  O(n) use recursively
int fibo_helper(int n , int* ans){
    if(n<=1){
        return n;
    }
    // check value if present or not n answer array
    if(ans[n]!=-1){
        return ans[n];
    }
    // save the output into ans array
    ans[n] = fibo_helper(n-1,ans) + fibo_helper(n-2,ans);

    return ans[n];
}
int fibo_1(int n){
    int *ans = new int[n+1];

    for(int i=0;i<n+1;i++){
        ans[i] =-1;
    }
    return fibo_helper(n,ans);
}

// Dynamic Programming  O(n)  use iteratorily
int fibo_2(int n){
    int *ans = new int[n+1];
    //initialize base condition
    ans[0] =0;
    ans[1] = 1;

    // run loop to initialize all values
    for(int i=2;i<=n;i++){
        ans[i] = ans[i-1] + ans[i-2];
    }
    return ans[n];
}

int main(){
    int num;
    cin>>num;
    cout<<fibo(num)<<endl<<fibo_1(num)<<endl<<fibo_2(num);
}