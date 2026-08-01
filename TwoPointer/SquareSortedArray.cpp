#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sortedSquares(vector<int>& nums){

    int siz = nums.size();

    vector<int> neg;
    vector<int> pos;
    // Separate negative and positive numbers
    for(int i=0; i<siz; i++){

        if(nums[i]< 0)
        neg.push_back(nums[i]);
        else
        pos.push_back(nums[i]);
    }
    //no negative elements 
    if(neg.size() == 0){
        
        for(int i=0; i<pos.size(); i++)
        pos[i]=pos[i]*pos[i];
        return pos;
    }
    //no positive elements
    if(pos.size()==0){
        for(int i=0; i<neg.size(); i++)
        neg[i]=neg[i]*neg[i];
        reverse(neg.begin(),neg.end());
        return neg;
    }
    // Square the negative numbers and reverse them
    for(int i=0; i<neg.size(); i++)
    neg[i]=neg[i]*neg[i];
    reverse(neg.begin(),neg.end());

    // Square the positive numbers
    for(int i=0; i<pos.size(); i++)
    pos[i]=pos[i]*pos[i];


    // Merge the two sorted arrays
    int i=0;
    int j=0;
    int id=0;

    int n = neg.size();
    int m = pos.size();

    vector<int> res(n+m);

    // Merge the two sorted arrays
    while(i<n and j<m){
        if(neg[i]<pos[j]){
            res[id]=neg[i];
            i++; id++;
        }else{
            res[id]=pos[j];
            j++; id++;
        }
    }
    // If there are remaining elements in the negative array
    while(j<m){
        res[id]=pos[j];
        j++; id++;
    }
    // If there are remaining elements in the positive array
    while(i<n){
        res[id]=neg[i];
        i++; id++;
    }
    return res;
}

int main(){
       vector<int> nums = {-4, -1, 0, 3, 10};

    vector<int> ans = sortedSquares(nums);

    cout << "Sorted Squares: ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
