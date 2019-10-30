#include <bits/stdc++.h>
using namespace std;

int bSearch(int arr[], int x, int n)
{
    int high = n-1, low = 0;

    while( low <= high )
    {
        int mid = (low+high)/2;

        if( arr[mid] == x ) {
            return mid;
        }
        else if( arr[mid] > x ) {
            high = mid-1;
        }
        else low = mid+1;
    }
}

int main()
{
    int n; cin >> n;
    int arr[n+5];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int q; cin >> q;
    while(q--) {
        int x; cin >> x;
        cout << bSearch(arr,x,n)+1 << endl;
    }
    return 0;
}
