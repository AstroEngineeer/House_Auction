using namespace std;
int MARKER=-1;
struct node
{
	node *right,*left,*rt;
	int id;
};
int i;
fstream file;
void serialize(node *root)
{
	// If current node is NULL, store marker
	if (root == NULL)
	{
		file.open("abcd.txt",ios::out|ios::binary);
		file.write((char *)&MARKER,sizeof(int));
		file.close();
		//fprintf(fp, "%d ", MARKER);
		return;
	}

	// Else, store current node and recur for its children
	//fprintf(fp, "%d ", root->key);
		file.open("abcd.txt",ios::app);
		file.write((char *)&root->id,sizeof(int));
		file.close();
	serialize(root->left);
	serialize(root->right);
}
node* newNode(int key)
{
	node* temp = new node;
	temp->id = key;
	temp->left = temp->right =temp->rt= NULL;
	return (temp);
}
void deSerialize(node *&root)
{
	// Read next item from file. If theere are no more items or next
	// item is marker, then return
	int val;
	file.open("abcd.txt",ios::in);
	//if ( !fscanf(fp, "%d ", &val) || val == MARKER)
	if ( !file.read((char *)&val,sizeof(int)) || val == MARKER)
	{
		return;
		file.close();
		}

	// Else create node with this item and recur for children
	root = newNode(val);
	deSerialize(root->left);
	deSerialize(root->right);
}
struct node* display(struct node* R)
{
	if(R==NULL)
		return NULL;
	display(R->left);
	cout<<"\t"<<R->id;
	display(R->right);
}
void search(struct node* root,int x,int *p)
{
	stack<node *> nodeStack;
    	nodeStack.push(root);
  	while (nodeStack.empty() == false)
    	{
     	struct node *node = nodeStack.top();
     	if (node->id == x)
     	{
     		struct node *z;
     		z=node;
     		i=0;
			while(z->rt!=NULL)
			{
				p[i]=z->id;
				i++;
				z=z->rt;
			}
			p[i]=z->id;
			return;
	    }
     	nodeStack.pop();
     	if (node->right)
          	nodeStack.push(node->right);
     	if (node->left)
          	nodeStack.push(node->left);
	}
  	cout<<"No Dealer found..\n\n";
}
void PrintTree(struct node *root,int spaces )
{
	int i;
	if( root != NULL )
	{
		PrintTree( root->right, spaces + 3 );
		for( i = 0; i < spaces; i++ )
			cout <<' ';
		cout << root->id<<endl;
		PrintTree( root->left, spaces + 3 );
  	}
}
void FindSubDealers(struct node* root)
{
	int x;
	cout<<"Enter the member id whose sub-members want to be found : \n";
	cin>>x;
	stack<node *> nodeStack;
    	nodeStack.push(root);
  	while (nodeStack.empty() == false)
    	{
     	struct node *node = nodeStack.top();
     	if (node->id == x)
     	{
			PrintTree(node,0);
			break;
	    }
     	nodeStack.pop();
     	if (node->right)
          	nodeStack.push(node->right);
     	if (node->left)
          	nodeStack.push(node->left);
	}
  	cout<<"No Dealer found..\n\n";
}
struct node* Insert(struct node *root,int ii)
{
	int m;
	cout<<"Enter the member id to be inserted : ";
	m=ii;
	if(root==NULL)
	{
		root=new node;
		root->id=m;
		root->left=root->right=root->rt=NULL;
		cout<<"Congratulations you are the first member in this concern..\n";
		serialize(root);
		return root;
	}
	else
	{
		struct node* s=new node;
		int x;
		s->id=m;
		s->left=s->right=s->rt=NULL;
		cout<<"Enter the Id of the member whom u want to Add : ";
		cin>>x;
		stack<node *> nodeStack;
    		nodeStack.push(root);
  		while (nodeStack.empty() == false)
    		{
     		struct node *node = nodeStack.top();
     		if (node->id == x)
	     	{
     	   		if(node->left==NULL)
          	  	{
            			node->left=s;
         				node->left->rt=node;
         				serialize(root);
					return root;
				}
				else if(node->right==NULL)
				{
					node->right=s;
					node->right->rt=node;
					serialize(root);
					return root;
				}
				else
					cout<<"The dealer already has 2 sub-dealers..Try again with another dealer..\n\n";
	    		}
     		nodeStack.pop();
	     	if (node->right)
     	     	nodeStack.push(node->right);
     		if (node->left)
          		nodeStack.push(node->left);
		}
  		cout<<"No Dealer found..\n\n";
	}
}
int pp[100];

void FindParent(struct node* root)
{
	int x;
	cout<<"Enter the member whose parents are to be found : ";
	cin>>x;
	stack<node *> nodeStack;
    	nodeStack.push(root);
  	while (nodeStack.empty() == false)
    	{
     	struct node *node = nodeStack.top();
     	if (node->id == x)
     	{
     		struct node *z;
     		z=node;
     		i=0;
			while(z->rt!=NULL)
			{
				pp[i]=z->id;
				i++;
				z=z->rt;
			}
			pp[i]=z->id;
			break;
	    }
     	nodeStack.pop();
     	if (node->right)
          	nodeStack.push(node->right);
     	if (node->left)
          	nodeStack.push(node->left);
	}
  	for(int k=0;k<=i;k++)
		cout<<"\t"<<pp[k];
	//cout<<"\n\n";
}
