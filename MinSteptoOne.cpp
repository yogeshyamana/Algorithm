#include<bits/stdc++.h>
using namespace std;

//recursion call Brute force 
int MinStep(int n){
    if(n<=1){
        return 0;
    }

    int x = MinStep(n-1);
    int y=INT_MAX, z=INT_MAX;
    if(n%2==0){
        y = MinStep(n/2);
    }
    if(n%3==0){
        z= MinStep(n/3);
    }
    return min(x, min(y,z))+1;
}

//memoziation 
int MinStepHelper(int n , int* ans){
    if(n<=1){
        return 0;
    }
    if(ans[n] != -1){
        return ans[n];
    }

    int x = MinStepHelper( n-1, ans);

    int y = INT_MAX, z=INT_MAX;
    if(n%2==0){
        y = MinStepHelper(n/2 , ans);
    }
    if(n%3==0){
        z = MinStepHelper(n/3, ans);
    }
    //sace output for futer use

    int output = min(x, min(y,z))+1;

    return output;
}
int MinStep_1(int n){
    int *ans = new int[n+1];

    for(int i=0;i<=n;i++){
        ans[i] = -1;
    }
    return MinStepHelper(n , ans);
}

// DP 

int MinStep_2(int n){
    int* ans = new int[n+1];

    ans[0]=0;
    ans[1]=0;

}

int main(){
    int num;
    cin>>num;

    cout<<MinStep(num)<<endl<<MinStep_1(num)<<endl;
}