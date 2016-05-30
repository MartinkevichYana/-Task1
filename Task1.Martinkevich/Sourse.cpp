#include<iostream>
#include<fstream>

using namespace std;

const int N = 30;

void ShowContentsFile(char*);
void ContentsFile(char*, char*, char*);

int main()
{
	char fileName1[N] = "", fileName2[N] = "", fileName3[N] = "";
	cout << "Enter the name of 1 file: ";
	cin.getline(fileName1, N, '\n');
	cout << "Contents of 1 file: " << endl;
	ShowContentsFile(fileName1);
	cout << "Enter the name of 2 file: ";
	cin.getline(fileName2, N, '\n');
	cout << "Contents of 1 file: " << endl;
	ShowContentsFile(fileName2);
	cout << "Enter the name of new file: ";
	cin.getline(fileName3, N, '\n');
	ContentsFile(fileName1, fileName2, fileName3);
	cout << "Information has been successfully added in " << fileName3 << "!" << endl;
	system("pause");
	return 0;
}


void ContentsFile(char* fileName1, char* fileName2, char* fileName3)
{
	ifstream streamIn1(fileName1);
	ifstream streamIn2(fileName2);
	ofstream streamIn3(fileName3);
	if (!streamIn1.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	if (!streamIn2.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	int size = sizeof(int);
	int a1, a2;
	int i = 1;
	while (!streamIn1.eof())
	{
		streamIn1.read((char*)&a1, size);
		streamIn2.read((char*)&a2, size);
		while (!streamIn2.eof())
		{
			if (a1 > a2)
			{
				streamIn3.write((char*)&a2, size);
				streamIn2.read((char*)&a2, size);
			}
			else
			{
				streamIn3.write((char*)&a1, size);
				break;
			}
		}
		streamIn2.seekg(i, ios::beg);
		i++;
	}
	streamIn1.close();
	streamIn2.close();
	streamIn3.close();
}

void ShowContentsFile(char* fileName)
{
	ifstream streamIn;
	streamIn.open(fileName);
	if (!streamIn.is_open())
	{
		cout << " Cannot open file " << fileName << " to read!" << endl;
		system("pause");
		exit(1);
	}
	char String[N] = "";
	while (!streamIn.eof())
	{
		streamIn.getline(String, N, '\n');
		cout << String << endl;
	}
}