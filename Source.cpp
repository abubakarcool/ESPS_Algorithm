#include<iostream>
#include<string>
#include <sstream>
using namespace std;
string n;
int tableno; int boom = 0; int car = 0; int radium = 0; int comparevalue = 0;

struct node
{
	unsigned int val;
	node*left;
	int pos[3];
	node*right;
	node()
	{
		val = 0; pos[0] = 0; pos[1] = 0; pos[2] = 0;
		left = NULL; right = NULL;
	}
};
struct tree
{
	node*root;
	tree()
	{
		root = NULL;
	}
	////////////////////////////////////////////////////
	node *notfonud;
	void insert(unsigned int a,int pos)
	{
		if (root == NULL)
		{
			node*n = new node;
			n->val = a;
			n->pos[0] = pos;
			root = n;
		}
		else
		{
			node*temp = root;
			node *prev = temp;
			while (temp != NULL)
			{
				if (a>temp->val)
				{
					prev = temp;
					temp = temp->right;
				}
				else if (a<temp->val)
				{
					prev = temp;
					temp = temp->left;
				}
				else
				{
					if (temp->pos[1] == 0)
						temp->pos[1] = pos;
					else
						temp->pos[2] = pos;
					return;
				}
			}
			node*n = new node;
			n->val = a;
			n->pos[0] = pos;
			if (a>prev->val)
				prev->right = n;
			else
				prev->left = n;
		}
	}
	//////////////////////////////////
	void search(unsigned int a)
	{
		//notfonud->left = NULL; notfonud->right = NULL; notfonud->val = 0;
		comparevalue=0;//at every search it gives zero value to comparisons
		if (root == NULL)
		{
		  //return NULL; 
			cout<<"Not found";
		}
		else
		{
			node*temp = root;
			while (temp != NULL)
			{
				if (a>temp->val)
				{
					comparevalue++;
					temp = temp->right;
				}
				else if (a<temp->val)
				{
					comparevalue++;
					temp = temp->left;
				}
				else
				{
					comparevalue++;
					cout << "\nFOUND!! its positon is " << temp->pos[0];
					if (temp->pos[1] != 0)
					cout << " "<< temp->pos[1];
					if (temp->pos[2] != 0)
					cout << " " << temp->pos[2];
					break;
				}
			}
			if (temp == NULL)
			{
				cout << "Not found";
				//temp->left = NULL; temp->right = NULL; temp->val = 0;
				//return notfonud;
			}
		}
	}
	void postorder(node*temp)
	{
		if (temp != NULL)
		{
			postorder(temp->left);
			postorder(temp->right);
			cout << temp->val << " \t" << temp->pos[0] << " " << temp->pos[1] << " " << temp->pos[2] << endl;
		}
	}
	/////////////////////////////////////////////////////
	~tree()
	{
		remove(root);
	}
	void remove(node* temp)
	{
		if (temp == NULL)
			return;
		remove(temp->left);
		remove(temp->right);
		delete temp;
	}
};
struct nodee
{
	int startposition[3];
	unsigned int hashvalue;
	nodee()
	{
		startposition[0] = 0; hashvalue = 0;
		startposition[1] = 0; startposition[2] = 0;
		startposition[3] = 0;
	}
};

struct table{
	//node *p = new node[10];
	nodee p[10];
};

struct ESPS {
	//table *q = new table[tableno]; //created the no.s of tables
	table q[5]; tree treee;
	////////-----------------//////////
	unsigned int sdbm_hash(string word)
	{
		unsigned int hashAddress = 0;
		for (int counter = 0; word[counter] != '\0'; counter++){
			hashAddress = word[counter] + (hashAddress << 6) + (hashAddress << 16) - hashAddress;
		}return hashAddress;
	}


	void  insert(string a, int strtpostn){
		unsigned int sdbmval = sdbm_hash(a); int gala = strtpostn;
		treee.insert(sdbmval, ++++gala); // side wise inserting hash value & position in BST tree nodes
		if (boom != 0 && q[car].p[0].hashvalue == sdbmval){
			if (q[car].p[0].startposition[0] == 0)
				q[car].p[0].startposition[0] = ++++strtpostn;
			else if (q[car].p[0].startposition[1] == 0)
				q[car].p[0].startposition[1] = ++++strtpostn;
			else if (q[car].p[0].startposition[2] == 0)
				q[car].p[0].startposition[2] = ++++strtpostn;
		}
		else if (boom != 0 && q[car].p[1].hashvalue == sdbmval){
			if (q[car].p[1].startposition[0] == 0)
				q[car].p[1].startposition[0] = ++++strtpostn;
			else if (q[car].p[1].startposition[1] == 0)
				q[car].p[1].startposition[1] = ++++strtpostn;
			else if (q[car].p[1].startposition[2] == 0)
				q[car].p[1].startposition[2] = ++++strtpostn;
		}
		else if (boom != 0 && q[car].p[2].hashvalue == sdbmval){
			if (q[car].p[2].startposition[0] == 0)
				q[car].p[2].startposition[0] = ++++strtpostn;
			else if (q[car].p[2].startposition[1] == 0)
				q[car].p[2].startposition[1] = ++++strtpostn;
			else if (q[car].p[2].startposition[2] == 0)
				q[car].p[2].startposition[2] = ++++strtpostn;
		}
		else if (boom != 0 && q[car].p[3].hashvalue == sdbmval){
			if (q[car].p[3].startposition[0] == 0)
				q[car].p[3].startposition[0] = ++++strtpostn;
			else if (q[car].p[3].startposition[1] == 0)
				q[car].p[3].startposition[1] = ++++strtpostn;
			else if (q[car].p[3].startposition[2] == 0)
				q[car].p[3].startposition[2] = ++++strtpostn;
		}
		else if (boom != 0 && q[car].p[4].hashvalue == sdbmval){
			if (q[car].p[4].startposition[0] == 0)
				q[car].p[4].startposition[0] = ++++strtpostn;
			else if (q[car].p[4].startposition[1] == 0)
				q[car].p[4].startposition[1] = ++++strtpostn;
			else if (q[car].p[4].startposition[2] == 0)
				q[car].p[4].startposition[2] = ++++strtpostn;
		}
		else if (boom != 0 && q[car].p[5].hashvalue == sdbmval){
			if (q[car].p[5].startposition[0] == 0)
				q[car].p[5].startposition[0] = ++++strtpostn;
			else if (q[car].p[5].startposition[1] == 0)
				q[car].p[5].startposition[1] = ++++strtpostn;
			else if (q[car].p[5].startposition[2] == 0)
				q[car].p[5].startposition[2] = ++++strtpostn;
		}
		else if (boom != 0 && q[car].p[6].hashvalue == sdbmval){
			if (q[car].p[6].startposition[0] == 0)
				q[car].p[6].startposition[0] = ++++strtpostn;
			else if (q[car].p[6].startposition[1] == 0)
				q[car].p[6].startposition[1] = ++++strtpostn;
			else if (q[car].p[6].startposition[2] == 0)
				q[car].p[6].startposition[2] = ++++strtpostn;
		}
		else if (boom != 0 && q[car].p[7].hashvalue == sdbmval){
			if (q[car].p[7].startposition[0] == 0)
				q[car].p[7].startposition[0] = ++++strtpostn;
			else if (q[car].p[7].startposition[1] == 0)
				q[car].p[7].startposition[1] = ++++strtpostn;
			else if (q[car].p[7].startposition[2] == 0)
			q[car].p[7].startposition[2] = ++++strtpostn;
		}
		else if (boom != 0 && q[car].p[8].hashvalue == sdbmval){
			if (q[car].p[8].startposition[0] == 0)
				q[car].p[8].startposition[0] = ++++strtpostn;
			else if (q[car].p[8].startposition[1] == 0)
				q[car].p[8].startposition[1] = ++++strtpostn;
			else if (q[car].p[8].startposition[2] == 0)
				q[car].p[8].startposition[2] = ++++strtpostn;
		}
		else
		{
			q[car].p[boom].hashvalue = sdbmval;
			q[car].p[boom].startposition[0] = ++++strtpostn; boom++;
		} radium++;//it detects if the tables has not ended
		if (radium == 10) { car++; boom = 0; radium = 0; }  if (radium == 20) { car++; boom = 0; radium = 0; }
		if (radium == 30) { car++; boom = 0; radium = 0; }  if (radium == 40) { car++; boom = 0; radium = 0; }
		}
		///////////////////--------------------////////////////////////
	int CountWords(string sentence){
		int numberOfWords = 0;
		size_t i;

		if (isalpha(sentence[0])) {
			numberOfWords++;
		}

		for (i = 1; i < sentence.length(); i++) {
			if ((isalpha(sentence[i])) && (!isalpha(sentence[i - 1]))) {
				numberOfWords++;
			}
		}

		return numberOfWords;
	}
		//////////////--------------------------////////////////
	void inputname(string ch)
		{
			float rr; int arrr[50]; int j = 0; int y = 0;
			int r = CountWords(ch); rr = r; //r is the words in string
			std::string arr[50];
			float kk = ceil(rr / 10);  tableno = kk;// rounded the table no.s to ceil of integars
			int v = 0; int i = 0; int k = 10;
			stringstream ssin(ch);
			while (ssin.good() && i < r){ //addded all the words to string-arr[]
				ssin >> arr[i]; arrr[i] = i;//tokennizing string ch
				++i;
			}
			for (int a = 0; a < r; a++){
				if (a == 0)
					j = -1;
				else
				{
					for (i = y; i < ch.length(); i++){
						if (ch[i] == ' '){
							j = i; break;
						}
					}
				} y = j; y++;
				insert(arr[a], j);//fills the tables, j is start postion with ----
			}
		}
		//////////////
		~ESPS()
		{ delete q;}
		//////////////////////
};

int main()
{
	ESPS hf;
	string ch; string wordtosearch;
	cout << "Enter string\n";
	getline(cin, ch);
	cout << endl;
	hf.inputname(ch);
	cout << "\nNo. of tables created: "<<tableno;
	cout << "\n\n--->>TABLE 1<<---";
	cout << "\nHash value\tstratposition\n";
	cout << hf.q[0].p[0].hashvalue << "\t " << hf.q[0].p[0].startposition[0] << " " << hf.q[0].p[0].startposition[1] << " " << hf.q[0].p[0].startposition[2] << endl;
	cout << hf.q[0].p[1].hashvalue << "\t " << hf.q[0].p[1].startposition[0] << " " << hf.q[0].p[1].startposition[1] << " " << hf.q[0].p[1].startposition[2] << endl;
	cout << hf.q[0].p[2].hashvalue << " \t" << hf.q[0].p[2].startposition[0] << " " << hf.q[0].p[2].startposition[1] << " " << hf.q[0].p[2].startposition[2] << endl;
	cout << hf.q[0].p[3].hashvalue << "\t " << hf.q[0].p[3].startposition[0] << " " << hf.q[0].p[3].startposition[1] << " " << hf.q[0].p[3].startposition[2] << endl;
	cout << hf.q[0].p[4].hashvalue << "\t " << hf.q[0].p[4].startposition[0] << " " << hf.q[0].p[4].startposition[1] << " " << hf.q[0].p[4].startposition[2] << endl;
	cout << hf.q[0].p[5].hashvalue << "\t " << hf.q[0].p[5].startposition[0] << " " << hf.q[0].p[5].startposition[1] << " " << hf.q[0].p[5].startposition[2] << endl;
	cout << hf.q[0].p[6].hashvalue << "\t " << hf.q[0].p[6].startposition[0] << " " << hf.q[0].p[6].startposition[1] << " " << hf.q[0].p[6].startposition[2] << endl;
	cout << hf.q[0].p[7].hashvalue << "\t " << hf.q[0].p[7].startposition[0] << " " << hf.q[0].p[7].startposition[1] << " " << hf.q[0].p[7].startposition[2] << endl;
	cout << hf.q[0].p[8].hashvalue << " \t" << hf.q[0].p[8].startposition[0] << " " << hf.q[0].p[8].startposition[1] << " " << hf.q[0].p[8].startposition[2] << endl;
	cout << hf.q[0].p[9].hashvalue << " \t" << hf.q[0].p[9].startposition[0] << " " << hf.q[0].p[9].startposition[1] << " " << hf.q[0].p[9].startposition[2] << endl;
	if (tableno > 1)
	{
		cout << "\n---->>TABLE 2<<---\n";
	cout << hf.q[1].p[0].hashvalue << " \t" << hf.q[1].p[0].startposition[0] << " " << hf.q[1].p[0].startposition[1] << " " << hf.q[1].p[0].startposition[2] << endl;
	cout << hf.q[1].p[1].hashvalue << " \t" << hf.q[1].p[1].startposition[0] << " " << hf.q[1].p[1].startposition[1] << " " << hf.q[1].p[1].startposition[2] << endl;
	cout << hf.q[1].p[2].hashvalue << " \t" << hf.q[1].p[2].startposition[0] << " " << hf.q[1].p[2].startposition[1] << " " << hf.q[1].p[2].startposition[2] << endl;
	cout << hf.q[1].p[3].hashvalue << " \t" << hf.q[1].p[3].startposition[0] << " " << hf.q[1].p[3].startposition[1] << " " << hf.q[1].p[3].startposition[2] << endl;
	cout << hf.q[1].p[4].hashvalue << " \t" << hf.q[1].p[4].startposition[0] << " " << hf.q[1].p[4].startposition[1] << " " << hf.q[1].p[4].startposition[2] << endl;
	cout << hf.q[1].p[5].hashvalue << " \t" << hf.q[1].p[5].startposition[0] << " " << hf.q[1].p[5].startposition[1] << " " << hf.q[1].p[5].startposition[2] << endl;
	cout << hf.q[1].p[6].hashvalue << " \t" << hf.q[1].p[6].startposition[0] << " " << hf.q[1].p[6].startposition[1] << " " << hf.q[1].p[6].startposition[2] << endl;
	cout << hf.q[1].p[7].hashvalue << " \t" << hf.q[1].p[7].startposition[0] << " " << hf.q[1].p[7].startposition[1] << " " << hf.q[1].p[7].startposition[2] << endl;
	cout << hf.q[1].p[8].hashvalue << " \t" << hf.q[1].p[8].startposition[0] << " " << hf.q[1].p[8].startposition[1] << " " << hf.q[1].p[8].startposition[2] << endl;
	cout << hf.q[1].p[9].hashvalue << " \t" << hf.q[1].p[9].startposition[0] << " " << hf.q[1].p[9].startposition[1] << " " << hf.q[1].p[9].startposition[2] << endl;
	}
	if (tableno > 2)
	{
		cout << "\n--->>>TABLE 3<<<---\n";
		cout << hf.q[2].p[0].hashvalue << " \t" << hf.q[2].p[0].startposition[0] << " " << hf.q[2].p[0].startposition[1] << " " << hf.q[2].p[0].startposition[2] << endl;
		cout << hf.q[2].p[1].hashvalue << " \t" << hf.q[2].p[1].startposition[0] << " " << hf.q[2].p[1].startposition[1] << " " << hf.q[2].p[1].startposition[2] << endl;
		cout << hf.q[2].p[2].hashvalue << " \t" << hf.q[2].p[2].startposition[0] << " " << hf.q[2].p[2].startposition[1] << " " << hf.q[2].p[2].startposition[2] << endl;
		cout << hf.q[2].p[3].hashvalue << " \t" << hf.q[2].p[3].startposition[0] << " " << hf.q[2].p[3].startposition[1] << " " << hf.q[2].p[3].startposition[2] << endl;
		cout << hf.q[2].p[4].hashvalue << " \t" << hf.q[2].p[4].startposition[0] << " " << hf.q[2].p[4].startposition[1] << " " << hf.q[2].p[4].startposition[2] << endl;
		cout << hf.q[2].p[5].hashvalue << " \t" << hf.q[2].p[5].startposition[0] << " " << hf.q[2].p[5].startposition[1] << " " << hf.q[2].p[5].startposition[2] << endl;
		cout << hf.q[2].p[6].hashvalue << " \t" << hf.q[2].p[6].startposition[0] << " " << hf.q[2].p[6].startposition[1] << " " << hf.q[2].p[6].startposition[2] << endl;
		cout << hf.q[2].p[7].hashvalue << " \t" << hf.q[2].p[7].startposition[0] << " " << hf.q[2].p[7].startposition[1] << " " << hf.q[2].p[7].startposition[2] << endl;
		cout << hf.q[2].p[8].hashvalue << " \t" << hf.q[2].p[8].startposition[0] << " " << hf.q[2].p[8].startposition[1] << " " << hf.q[2].p[8].startposition[2] << endl;
		cout << hf.q[2].p[9].hashvalue << " \t" << hf.q[2].p[9].startposition[0] << " " << hf.q[2].p[9].startposition[1] << " " << hf.q[2].p[9].startposition[2] << endl;
	}
	if (tableno > 3)
	{
		cout << "\n->>>TABLE 4-<<<\n";
		cout << hf.q[3].p[0].hashvalue << " \t" << hf.q[3].p[0].startposition[0] << " " << hf.q[3].p[0].startposition[1] << " " << hf.q[3].p[0].startposition[2] << endl;
		cout << hf.q[3].p[1].hashvalue << " \t" << hf.q[3].p[1].startposition[0] << " " << hf.q[3].p[1].startposition[1] << " " << hf.q[3].p[1].startposition[2] << endl;
		cout << hf.q[3].p[2].hashvalue << " \t" << hf.q[3].p[2].startposition[0] << " " << hf.q[3].p[2].startposition[1] << " " << hf.q[3].p[2].startposition[2] << endl;
		cout << hf.q[3].p[3].hashvalue << " \t" << hf.q[3].p[3].startposition[0] << " " << hf.q[3].p[3].startposition[1] << " " << hf.q[3].p[3].startposition[2] << endl;
		cout << hf.q[3].p[4].hashvalue << " \t" << hf.q[3].p[4].startposition[0] << " " << hf.q[3].p[4].startposition[1] << " " << hf.q[3].p[4].startposition[2] << endl;
		cout << hf.q[3].p[5].hashvalue << " \t" << hf.q[3].p[5].startposition[0] << " " << hf.q[3].p[5].startposition[1] << " " << hf.q[3].p[5].startposition[2] << endl;
		cout << hf.q[3].p[6].hashvalue << " \t" << hf.q[3].p[6].startposition[0] << " " << hf.q[3].p[6].startposition[1] << " " << hf.q[3].p[6].startposition[2] << endl;
		cout << hf.q[3].p[7].hashvalue << " \t" << hf.q[3].p[7].startposition[0] << " " << hf.q[3].p[7].startposition[1] << " " << hf.q[3].p[7].startposition[2] << endl;
		cout << hf.q[3].p[8].hashvalue << " \t" << hf.q[3].p[8].startposition[0] << " " << hf.q[3].p[8].startposition[1] << " " << hf.q[3].p[8].startposition[2] << endl;
		cout << hf.q[3].p[9].hashvalue << " \t" << hf.q[3].p[9].startposition[0] << " " << hf.q[3].p[9].startposition[1] << " " << hf.q[3].p[9].startposition[2] << endl;
	}
	if (tableno > 4)
	{
		cout << "\n--->>TABLE 5<<-----\n";
		cout << hf.q[4].p[0].hashvalue << " \t" << hf.q[4].p[0].startposition[0] << " " << hf.q[4].p[0].startposition[1] << " " << hf.q[4].p[0].startposition[2] << endl;
		cout << hf.q[4].p[1].hashvalue << " \t" << hf.q[4].p[1].startposition[0] << " " << hf.q[4].p[1].startposition[1] << " " << hf.q[4].p[1].startposition[2] << endl;
		cout << hf.q[4].p[2].hashvalue << " \t" << hf.q[4].p[2].startposition[0] << " " << hf.q[4].p[2].startposition[1] << " " << hf.q[4].p[2].startposition[2] << endl;
		cout << hf.q[4].p[3].hashvalue << " \t" << hf.q[4].p[3].startposition[0] << " " << hf.q[4].p[3].startposition[1] << " " << hf.q[4].p[3].startposition[2] << endl;
		cout << hf.q[4].p[4].hashvalue << " \t" << hf.q[4].p[4].startposition[0] << " " << hf.q[4].p[4].startposition[1] << " " << hf.q[4].p[4].startposition[2] << endl;
		cout << hf.q[4].p[5].hashvalue << " \t" << hf.q[4].p[5].startposition[0] << " " << hf.q[4].p[5].startposition[1] << " " << hf.q[4].p[5].startposition[2] << endl;
		cout << hf.q[4].p[6].hashvalue << " \t" << hf.q[4].p[6].startposition[0] << " " << hf.q[4].p[6].startposition[1] << " " << hf.q[4].p[6].startposition[2] << endl;
		cout << hf.q[4].p[7].hashvalue << " \t" << hf.q[4].p[7].startposition[0] << " " << hf.q[4].p[7].startposition[1] << " " << hf.q[4].p[7].startposition[2] << endl;
		cout << hf.q[4].p[8].hashvalue << " \t" << hf.q[4].p[8].startposition[0] << " " << hf.q[4].p[8].startposition[1] << " " << hf.q[4].p[8].startposition[2] << endl;
		cout << hf.q[4].p[9].hashvalue << " \t" << hf.q[4].p[9].startposition[0] << " " << hf.q[4].p[9].startposition[1] << " " << hf.q[4].p[9].startposition[2] << endl;
	}
	cout << endl;
	cout << endl << "Traversal of tree created is :\n";
	hf.treee.postorder(hf.treee.root);
	//////----searching in tree -----//////////////////////////////////////////////////**********////

	cout<< endl << "Input the word you want to search: ";
	cin>>wordtosearch; 
	unsigned int key = hf.sdbm_hash(wordtosearch);
	hf.treee.search(key);
	cout << "\n No of comparisions: " << comparevalue;
	
	////////////////////-------------------/////////////////////////////////////////////////////////
	cout << endl << endl << "Input the word you want to search: ";
	cin>> wordtosearch;
	key = hf.sdbm_hash(wordtosearch);
	hf.treee.search(key);
	cout << "\n No of comparisions: " << comparevalue;
	system("pause");
	return 0;
}