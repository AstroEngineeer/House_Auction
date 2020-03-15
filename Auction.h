#include "Bidder.h"
using namespace std;
void heapify(int arr[],int n,int i,int arr1[])
{
    int L=i;
    int l=(2*i)+1;
    int r=(2*i)+2;
    if (l<n && arr[l]>arr[L])
        L=l;
    if (r<n && arr[r]>arr[L])
        L=r;
    if (L!=i)
    {
        swap(arr[i],arr[L]);
        swap(arr1[i],arr1[L]);
        heapify(arr,n,L,arr1);
    }
}

void insert_auction(int arr[],int arr1[],int &n,int &min_amt)
{
    int temp,temp1;
    cout<<"\n\t\tEnter Bidder ID:";
    cin>>temp1;
    cout<<"\n\t\tEnter Bid Amount:";
    cin>>temp;
    if(temp<min_amt)
    {
        cout<<"\n\t\tThe amount is less than the minimum bid amount!!\n\t\tPlease enter a valid amount!!";
        return;
    }
    else
    {
        arr1[n]=temp1;
        arr[n]=temp;
        min_amt=temp;
    }
    n++;
    for (int i=(n/2)-1;i>=0;i--)
        heapify(arr,n,i,arr1);
}
void print(int arr[],int n,int arr1[])
{
    cout<<"\n#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#**#*#*#*#*#*#*#*#*#*#*#*#**#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#\n";
    for (int i=0;i<n;i++)
        cout<<"Price:"<<arr[i]<<"Rs.    ID:"<<arr1[i]<<"\n";
    cout<<"\n#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#**#*#*#*#*#*#*#*#*#*#*#*#**#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#\n";
}

void end_auction(int arr[],int &n,int arr1[])
{
    Bidder bb;
    if(n==0)
    {
        cout<<"\t\tEmpty\n";
        return;
    }
    cout<<"\t\tThe Highest Bid is:"<<arr[0]<<"\n";
    cout<<"\t\tThe ID of the highest bidder is:"<<arr1[0]<<"\n";
    cout<<"\n\t$$$$$$$$$$$$$$$$$$$$$ THANK YOU $$$$$$$$$$$$$$$$$$$$$";
    bb.getBidder(arr1[0]);
    bb.getData();
   //exit(1);
}
