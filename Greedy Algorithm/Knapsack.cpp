#include<bits/stdc++.h>
using namespace std;

//Without using STL O(NlogN)

struct Item{
    int value;
    int weight;
    
    // Item(int value , int weight)
    //     : value(value), weight(weight)
    // {

    // }
};

// comparision of struct accoroding value / weight
bool compare(struct Item a , struct Item b){
    double frac1 = (double)a.value / a.weight;
    double frac2 = (double)b.value / b.weight;
    return frac1 > frac2;
}

double fractionalKnapsack(struct Item arr[], int W , int size ){

    sort(arr , arr + size, compare);

    int currentWeight = 0;

    double finalValue = 0.0;

    //looping all items
    for(int i = 0; i < size; i++){

        //If adding item ids not overflow
        if(currentWeight + arr[i].weight <= W){
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
        }

        else{
            int remain = W - currentWeight;
            finalValue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }

        return finalValue;
    }
    return finalValue;
}

// Using STL O(N)

double FractionalKnapsackSTL(int capicity, vector<int> val, vector<int> we){
    
    int n = val.size();
    int i;
    multimap<double, int> ratio;

    double max_profit=0;
    for(i = 0; i < n; i++){

        ratio.insert(make_pair((double)val[i] / we[i] ,i));
    }

    multimap<double, int>:: reverse_iterator it;

    for(it = ratio.rbegin(); it != ratio.rend(); it++){
        double fraction = (double)capicity / we[it->second];

        if(capicity >= 0 && capicity >= we[it->second]){
            max_profit += val[it->second];

            capicity -= we[it->second];
        }

        else if (capicity < we[it->second]){
            max_profit += fraction * val[it->second];
            break;
        }
    }

    return max_profit;
}

int main(){
    int n;
    int capacity;
    cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    Item item[n];
    for (int i = 0; i < n; i++) {
        cin >> values[i] >> weights[i];
    }

    for(int i = 0; i < n ; i++){
        item[i] = {values[i], weights[i]};
    }
    cout<<FractionalKnapsackSTL(capacity , values , weights)<<endl<<fractionalKnapsack(item, capacity, n);

}
