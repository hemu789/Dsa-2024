#include <iostream>
#include <vector>
using namespace std;


vector<int> calculatePrefixSum( vector<int> arr){
    int n = arr.size();
    vector<int> prefix_sum(n+1,0);

    if (n == 1)
    {
        prefix_sum[0] = arr[0];
    }

    for(int i=1;i<=n;i++){

        prefix_sum[i+1] = prefix_sum[i] + arr[i];
    }

    return prefix_sum;
}

int sumInRange(vector<int> arr, int L ,int R){

    if (L < 0 || R >= arr.size() || L > R)
    {
        return -1; // Return a sentinel value or handle the error as needed
    }
    vector<int> prefixSum = calculatePrefixSum(arr);
    int result = prefixSum[R+1] - prefixSum[L];
    return result;
}

int main() {
    // Example usage:
    vector<int> myArray = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int L;
    cout<<"L"<<endl;
    cin>>L;
    int R ;
    cout<<"R"<<endl;
    cin>>R;

    int result = sumInRange(myArray, L, R);

    if (result != -1) {
        std::cout << "The sum of elements in the range [" << L << ", " << R << "] is: " << result << std::endl;
    }

    return 0;
}
