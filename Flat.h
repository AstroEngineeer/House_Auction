#include<string.h>
using namespace std;
class flat
{
 	private:
 		int fno;
 		int floor;
 		int sold;
 		int rate;
 		char cname[30];
 		int Did;
 		int lenght;
 		int width;
 		int bhk;
 		int price;
 	public:
 		void setData();
		void getData();
		void setfile();
		void getfile();
		void getflat(int fno);
		bool getstatus(int fno);
        void changestatus();
        int updatefile(int x);



};

void flat::getData()
{
			cout<<"flat number"<<fno<<"	floor number ::"<<floor<<"	Price of the flat ::"<<price<<"	BHK"<<bhk<<endl;
			cout<<"	length ::"<<this->lenght<<"	width"<<width<<endl;
			if(this->sold)
			{
				cout<<"	Customer Name ::"<<cname<<"	dealer Id"<<Did<<"	rate for which the flat sold::"<<rate<<endl;
			}
}
void flat::setData()
{
 			cout<<"\nEnter The flat number ::";
 			cin>>fno;
 			cout<<"\nEnter floor number ::";
 			cin>>floor;
 			cout<<"\nEnter the price of the flat ::";
 			cin>>price;
 			cout<<"\nEnter Number of BHk ::";
 			cin>>bhk;
 			cout<<"\nEnter the length of flat ::";
 			cin>>lenght;
 			cout<<"\nEnter the width of flat ::";
 			cin>>width;
 			cout<<"\nIs the flat sold or not 1)Yes or 0)No";
 			cin>>sold;
 			if(sold)
 			{
 				cout<<"\nEnter the rate for which it sold for ::";
 				cin>>rate;
 				cout<<"\nEnter the customer name ::";
 				cin>>cname;
 				cout<<"\nEnter dealer ID ::";
 				cin>>Did;
			}
			else
			{
				rate=0;
				Did=0;
			}
}
void flat::getflat(int fno)
{
	fstream outfile;
	outfile.open("flat.dat",ios::in|ios::binary);
	while(outfile.read((char *)&*this,sizeof(class flat)))
	{
		if(fno==this->fno)
		{
			break;
		}
		else
		{
			cout<<"Searching...\n";
		}
	}
	outfile.close();
}
void flat::setfile()
{
	fstream infile;
	infile.open("flat.dat",ios::app|ios::in|ios::binary);
	infile.write((char *)&*this,sizeof(class flat));
	infile.close();
}
void flat::getfile()
{
			fstream outfile;
			outfile.open("flat.dat",ios::in|ios::binary);
			while(outfile.read((char *)&*this,sizeof(class flat)))
			{
				this->getData();
			}
			outfile.close();
}
bool flat::getstatus(int fno)
{
    	fstream outfile;
	outfile.open("flat.dat",ios::in|ios::binary);
	while(outfile.read((char *)&*this,sizeof(class flat)))
	{
		if(fno==this->fno)
		{
			if(this->sold==1)
            {
                cout<<"\nThis flat is already sold";
                return 1;
            }
            else
            {
                cout<<"\nThis flat is for sale";
                return 0;
            }
		}
		else
		{
			cout<<"Searching...\n";
		}
	}
	outfile.close();
}
/*void flat::changestatus()
{
			fstream outfile;
			outfile.open("flat.dat",ios::in|ios::binary);
			while(outfile.read((char *)&*this,sizeof(class flat)))
			{
				this->sold=1;
			}
			outfile.close();
}*/
int flat::updatefile(int x)
{
                    int k=0;
                    int a,b;
                    char c[30];
                    cout<<"\nEnter the dealer ID :: ";
                    cin>>a;
                    cout<<"Enter the rate for which it sold for ::";
                    cin>>b;
                    cout<<"Enter the customer name ::";
                    cin>>c;
                    sold=1;
                    fstream file;
                    fstream infile;
                    file.open("flat.dat",ios::in|ios::binary);
                    while(file.read((char *)&*this,sizeof(class flat)))
                    {
                        if(x==this->fno)
                        {   //cout<<"sdfdf";
                            infile.open("flat.dat",ios::out|ios::in|ios::binary);
                            infile.seekp(sizeof(class flat)*k,ios::beg);
                            Did=a;
                            rate=b;
                            sold=1;
                            strcpy(cname,c);
                            //this->getData();
                            infile.write((char *)&*this,sizeof(class flat));
                            infile.close();
                            k++;
                        }
                        //k++;
                    }
                    file.close();
                    //cout<<pp[0];
                    return b;
}

