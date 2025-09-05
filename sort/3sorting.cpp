// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
void insertion(vector<int> &arr, int n)
{

   for(int i=1;i<n;i++){
    int prev=i-1;
    int curr=arr[i];
    while(arr[prev]>curr && prev>=0){
        arr[prev+1]=arr[prev];
        prev--;
    }
    arr[prev+1]=curr;
   }
}
void selection(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int si = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[si])
                si = j;
        }
        swap(arr[si], arr[i]);
    }
}
void bubblesort(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void p(vector<int> &arr, int n)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {1, 5, 6, 4, 2, 5, 7, 43, 2};
    int n = arr.size();
    //   bubblesort(arr,arr.size());

    selection(arr, arr.size());

    //  bubblesort(arr,arr.size());
    // insertion(arr,n);
    p(arr, arr.size());

    return 0;
}
