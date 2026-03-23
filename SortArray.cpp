#include<iostream>
using namespace std;

int main()
{
  int arr[10] = {98,44,51,23,54,67,79,21,56,32};
  for(int i = 0;i<9; i++)
  {
    if(arr[i]<arr[i+1])
    {
      arr[i] = arr[i]^arr[i+1];
      arr[i+1] = arr[i]^arr[i+1];
      arr[i] = arr[i]^arr[i+1];
      i = i -2;
    }
  }
  for(auto a: arr)
  {
    cout<<a<<"\t";
  }
}
