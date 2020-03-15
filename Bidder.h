
class Bidder
{
	private:
		int Bid;
		char bname[30];
		long int phone;
		char Addr[100];
	public:
		void setData();
		void getData();
		void setfile();
		void getBidder(int id);
};
void Bidder::getBidder(int id)
{
	fstream outfile;
	outfile.open("Bidder.dat",ios::in|ios::binary);
	while(outfile.read((char *)&*this,sizeof(class Bidder)))
	{
		if(id==this->Bid)
		{
		 getData();
		 break;
		}
		else
		cout<<"Bidder does not exist"<<endl;
	}
	outfile.close();
	//getData();
}
void Bidder::setData()
{
	cout<<"Enter the Bidder Id ::";
	cin>>Bid;
	cout<<"Enter the bidder name ::";
	cin>>bname;
	cout<<"Enter the bidder phone Number ::";
	cin>>phone;
	cout<<"Enter Address of bidder ::";
	cin>>Addr;
}
void Bidder::getData()
{
	cout<<"Bidder Id ::"<<Bid<<endl;
	cout<<"Bidder Name ::"<<bname<<endl;
	cout<<"Phone Numbre ::"<<phone<<endl;
	cout<<"Address ::"<<Addr<<endl;
}
void Bidder::setfile()
{
	fstream infile;
	infile.open("Bidder.dat",ios::app|ios::binary);
	infile.write((char *)&*this,sizeof(class Bidder));
	infile.close();
}
