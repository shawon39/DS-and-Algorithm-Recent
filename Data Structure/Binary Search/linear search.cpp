#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,key; cin >> n >> key;
    int arr[n+5];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int occur = -1;
    for(int i=0; i<n; i++) {
        if( arr[i] == key ) {
            occur = i+1;
        }
    }
    cout << occur << endl;
    return 0;
}

