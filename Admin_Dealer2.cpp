#include<iostream>
#include<stdlib.h>
#include <stack>
#include <bits/stl_stack.h>
#include<fstream>
#include "Dealer_Tree.h"
#include "Flat.h"
#include "Dealer.h"
#include "Auction.h"
#define clrscr system("cls");
using namespace std;


int main()
{

    int xyz;
   int xxx,yyy,zzz;
    flat f;
    Dealer d;
    int arr3[]={159,357,123,124,125},w=1,ww=1,arr[100];
    node *root=NULL;
    Bidder b;
    int o,x,n_a=0;
    int arr1[100];
    int min_amt,temp,temp1;
    int p,nb;
    while(1)
    {
    		//clrscr;
        cout<<"\n\n\t\t\tCHOOSE YOUR TYPE : \n\n\t\t1.ADMIN\n\n\t\t2.DEALER\n\n\t\t3.EXIT\n\n\n\tEnter your choice : ";
        cin>>xxx;
        switch(xxx)
        {
        case 1:
             while(1)
        {//clrscr;
        	cout<<"\n\n\t1.ADD FLAT\n\n\t2.DISPLAY ALL FLATS\n\n\t3.DISPLAY SPECIFIC FLAT\n\n\t4.ADD DEALER\n\n\t5.DISPLAY DEALERS\n\n\t6.PENT HOUSE BIDDINg\n\n\t7.SELL A FLAT\n\n\t8.EXIT\n\n\t\tENTER YOUR CHOICE : ";
      //  cout<<"Enter the option";
        cin>>yyy;
        switch(yyy)
        {
        case 1://this case will get the flat details and store into the file
        	clrscr;
            f.setData();
            f.setfile();
            break;
        case 2://this will display the flat details
        	clrscr;
            f.getfile();
            break;
        case 3://this will display specific flat details
        	clrscr;
            int x;
			cout<<"Enter the flat number  ::";
			cin>>x;
			f.getflat(x);
			f.getData();
			break;
        case 4://this will add dealer details
        	clrscr;
        	d.setData();
            root=Insert(root,d.Did);
			d.getData();
			d.setfile();
			break;
        case 6://this is the bidding for the penthouse
        	clrscr;
            cout<<"Enter no.of bidders";
            cin>>nb;
            for(int j=0;j<nb;j++)
            {
                b.setData();
                b.setfile();
            }
			cout<<"Enter Penthouse ID:";
            cin>>p;
            cout<<"Enter starting bid amount:";
            cin>>min_amt;
            while(w==1)
            {
                cout<<"\n1.Insert\n2.Print All Bids\n3.End Auction\n4.Exit\n\tEnter your option:";
                cin>>o;
                switch(o)
                {
                    case 1:
                        insert_auction(arr,arr1,n_a,min_amt);
                        break;
                    case 2:
                        print(arr,n_a,arr1);
                    break;
                    case 4:
                        w=0;
                        break;
                    case 3:
                        end_auction(arr,n_a,arr1);
                }
            }
            break;
        case 5://THIS WILL DISPLAY DEALER DETAILS
        	clrscr;
            d.getfile();
            cout<<"\n$$$$$\n";
            display(root);
            break;

        case 8://EXIT THIS MODULE
        	clrscr;
            break;
        case 7://SELLING THE FLATS
        	clrscr;
            bool ch;
                int y,rate,cname,k=0;
                cout<<"\n\tFlat Details";
                f.getfile();
                int fno;
                cout<<"\n\nEnter the flat number  ::";
                cin>>fno;
                ch=f.getstatus(fno);
                if(ch==0)
                {
                    int xy;
                    xy=f.updatefile(fno);
                    f.getfile();
                         cout<<"\nThe flat has been sold to you";
                         d.setProfit(arr3,xy/0.05
                                     ,5);
                }
                else
                {
                    break;
                }

            }
            break;
        }
    break;
        case 2:{
             while(ww==1)
    {//clrscr;
    		cout<<"\n\n\t\t1.VIEW DEALER DETAILS\n\n\t\t2.VIEW FLAT DETAILS\n\n\t\t3.FIND THE SUBDEALERS\n\n\t\t4.FIND THE SUPERIOR DEALERS\n\n\t\t5.EXIT\n\n\tEnter your choice : ";
       // cout<<"Enter option:";
        cin>>zzz;
        switch(zzz)
        {
        case 1://VIEW SPECIFIC DEALER
        	//clrscr;
            int x;
			cout<<"enter the dealer Id ::";
			cin>>x;
            d.getDealer(x);
            //insert(root);
			d.getData();
            break;
        case 2://VIEW ALL FLATS
        	clrscr;
            f.getfile();
            break;
        case 3://DISPLAY THE SUBDEALERS
        	clrscr;
            FindSubDealers(root);
            break;
        case 4://FIND THE SUPERIOR DEALER
        	clrscr;
            FindParent(root);
            break;
        case 5:
        	clrscr;
            ww=0;

        }
    }
            break;

        }
    }
}
}
