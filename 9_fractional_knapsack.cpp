#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
    double ratio;
};


bool compare(pair<double, int>& a, pair<double, int>& b) {
    return a.first > b.first; // Descending order of ratio
}


     double fractionalKnapsack(int W, vector<int>& values, vector<int>& weights) {
    vector<pair<double, int>> ratioItems; // Pair of ratio and index
    
    // Calculate value-to-weight ratio for each item and store it in ratioItems
    for (int i = 0; i < values.size(); i++) {
        double ratio = (double)values[i] / weights[i];
        ratioItems.push_back({ratio, i});
    }
    
    sort(ratioItems.begin(), ratioItems.end(), compare); // Sort items by ratio

    double totalValue = 0.0;
    
    for (auto& item : ratioItems) {
        int index = item.second;
        if (W >= weights[index]) { 
            W -= weights[index];
            totalValue += values[index];
        } else { 
            totalValue += values[index] * ((double)W / weights[index]);
            break; 
        }
    }
    
    return totalValue;
}

int main() {
    int item, weightcapacity;
    cout << "Enter number of items and  weightcapacity: ";
    cin >> item >> weightcapacity;
    
    vector<int>value(item);
    vector<int>weight(item);
    cout << "Enter weight and value for each item: " << endl;
    for (int i = 0; i < item; i++) {
        cin >> value[i];
    }
    for (int i = 0; i < item; i++) {
        cin >> value[i];
    }
    
    double maxValue = fractionalKnapsack(weightcapacity, value, weight);
    cout << "Max value in knapsack: " << maxValue << endl;
    return 0;
}
