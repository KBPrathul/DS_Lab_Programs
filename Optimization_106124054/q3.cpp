//q3    Subarray with first element having lowest value

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Enter value:";
        cin>>arr[i];
    }
    vector<int> nextsmall(n,n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            nextsmall[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += (nextsmall[i] - i);
    }
    cout<<count;
}

/*Enter the size of array: 5
Enter value:3
Enter value:2
Enter value:1
Enter value:4
Enter value:5
8*/