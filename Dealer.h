using namespace std;
class Dealer
{
	private:
		char name[30];
		//int Did;
		int earning;

	public:
	    int Did;
		void setData();
		void getData();
		void setfile();
		void setProfit(int arr[],int amount,int n);
		void getDealer(int id);
		void getfile();
        int p_return(int pp[]);
        int n_return(int pp[]);


};
void Dealer::setProfit(int arr[],int amount,int n)
{
	int i;
	int j=0;
	cout<<"n is ="<<n<<endl;
	amount=amount/n;
	fstream infile;
	fstream outfile;
//	for(j=0;j<n;j++)
//	{
		i=0;
	infile.open("dealer.dat",ios::in|ios::binary);
	while(infile.read((char *)&*this,sizeof(class Dealer)))
	{
		for(j=0;j<n;j++)
		if(arr[j]==Did)
		{
	 	outfile.open("dealer.dat",ios::out|ios::in|ios::binary);
	 	outfile.seekp(sizeof(class Dealer)*i,ios::beg);
		earning=earning+amount;
		outfile.write((char *)&*this,sizeof(class Dealer));
		outfile.close();
		i++;
		}
	}
	infile.close();
//	}
}

void Dealer::setData()
{
			cout<<"Enter dealer Name ::";
			cin>>name;
			cout<<"Enter the dealer Id";
			cin>>Did;
			earning=0;
}
void Dealer::getData()
{
	cout<<"\n	Dealer name is ::"<<name<<"	\nDealer ID ::"<<Did<<"\nDealers earnings are ::"<<earning<<endl;
}
void Dealer::getDealer(int id)
{
	int i=0;
	fstream outfile;
	outfile.open("dealer.dat",ios::in|ios::binary);
	while(outfile.read((char *)&*this,sizeof(class Dealer)))
	{
		if(this->Did==id)
		break;
		else
		{
			cout<<"Searching...."<<endl;
		}
	}
}
void Dealer::setfile()
{
	fstream infile;
	infile.open("dealer.dat",ios::app|ios::in|ios::binary);
	infile.write((char *)&*this,sizeof(class Dealer));
	infile.close();

}
void Dealer::getfile()
{
			fstream outfile;
			outfile.open("dealer.dat",ios::in|ios::binary);
			while(outfile.read((char *)&*this,sizeof(class Dealer)))
			{
				this->getData();
			}
			outfile.close();
}
int Dealer::p_return(int pp[])
{
   // return pp;
}

int Dealer::n_return(int pp[])
{
    int n =sizeof(pp)/sizeof(int);
    return n;
}
