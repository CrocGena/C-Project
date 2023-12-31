#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void start();
void Read(vector<string>&, string);
void inputchar(vector<string>);
void printlist(vector<string>&);
void findname(const vector<string>&);
void instr(const vector<string>&);
void backup(const vector<string>&);

int main()
{
	ifstream ifs("Text.txt");

	vector<string> Names;
	start();
	inputchar(Names);
	
}

void start()
{
	cout << " use commands:\n\n"
		<< " Type l names from the file.\n"
		<< " Type s list all names sorted A - Z.\n"
		<< " Type k find name.  input the name you are looking for.\n"
		<< " Type f filter. If you type f, You will need to input a string.\n"
		<< " Type b backup. The program create a backup copy of the input file.\n"
		<< endl;

}

void inputchar(vector<string> name)
{
	ifstream ifs("Text.txt");

	char character;
	while (true)
	{
		cout << "\nEnter command: ";
		cin >> character;
		switch (character)
		{
		case'l': Read(name, "Text.txt"); break;
		case's': printlist(name); break;
		case'k': findname(name); break;
		case'f': instr(name); break;
		case'b': backup(name); break;
		default: cout << "wrong command!" << endl; break;
		}
	}
}
void Read(vector<string>& name, string file)
{
	ifstream fin(file);
	string names;
	cout << "Names :" << endl;
	while (fin >> names)
	{
		name.push_back(names);
		cout << names << " ";

	}
	cout << endl;

}



void printlist(vector<string>& name)
{
	int size = name.size();

	sort(name.begin(), name.end());

	cout << endl;
	for (size_t i(0); i < size; ++i)
	{
		if (i % 5 == 0)
			cout << endl;
		cout << setw(10) << name[i] << " ";
	}

}



void findname(const vector<string>& name)
{
	string names;
	cout << "Enter name: ";
	cin >> names;

	int c{};
	int size = name.size();
	for (int i = 0; i < size; ++i)
	{
		if (name[i] == names)
			++c;
	}
	cout << "Name- " << names << " found - " << c << " times" << endl;
}

void instr(const vector<string>& name)
{


	string add;
	cout << "Enter input string: " << endl;
	cin >> add;
	int size = name.size();
	vector<string>tmp;

	for (int i = 0; i < size; ++i)
	{
		tmp.push_back(name[i]);
	}
	tmp.insert(tmp.begin(), add);
	printlist(tmp);

}

void backup(const vector<string>& name)
{
	int size = name.size();
	int exist{};

	if (exist > 0)
	{
		char answer;
		while (true)
		{
			cout << "already exist.\n would you like to override it? (y or n) ";
			cin >> answer;

			if (answer == 'y')
			{
				cout << "Copy is overrided!" << endl;
				break;
			}
			else if (answer == 'n')
			{
				cout << "New Copy is created!" << endl;
				++exist;
				break;
			}
			else
				cout << "Wrong input" << endl;
		}
	}
	else
	{
		cout << "File is created" << endl;
		++exist;
	}

	string fname = to_string(exist) + ".txt";

	ofstream fout(fname);


	for (auto i = 0; i < size; ++i)
		fout << name[i] << endl;

}