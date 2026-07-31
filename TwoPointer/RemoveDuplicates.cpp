#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& a) {

    int n = a.size();

    if(n == 0)
    return 0;

    int off = 0;
    int res = 1;
    int cm = 1;

    while(cm < n){

        if(a[cm] == a[cm-1]) {
            cm++;
            continue;
        }

        a[off + 1] = a[cm];
        off++;
        res++;
        cm++;
    }
    return res;
}
int main(){

    vector<int> nums ={1, 1, 2, 2, 3, 3 , 4, 5, 5};

    int k = removeDuplicates(nums);
    cout<< "Number of unique elements: "<< k << endl;

    cout << "Array after removing duplicates: ";

    for(int i = 0; i < k; i++) {
        cout << nums[i] <<" ";
    }
    cout << endl;

    return 0;
}
