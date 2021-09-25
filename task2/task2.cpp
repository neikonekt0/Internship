#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
class Table
{
public:
	Table(vector<string> vec)
	{
		
		for (int i = 0; i < vec.size() / 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				switch (j)
				{
				case 0:
					Name.push_back(vec[i*4+j]);
					break;
				case 1:
					QueryPerHour.push_back(stoi(vec[i * 4 + j]));
					break;
				case 2:
					Hours.push_back(stoi(vec[i * 4 + j]));
					break;
				case 3:
					Info.push_back(vec[i * 4 + j]);
					break;
				}
			}
					TotalQueries.push_back(QueryPerHour[i] * Hours[i]);
		}
		for (int i = 0; i < Name.size(); i++)//for each name in Name vec
		{
			for (int j = i+1; j < Name.size(); j++)
			{
				if (Name[i] == Name[j])
				{
					QueryPerHour[i] += QueryPerHour[j];
					Hours[i] += Hours[j];
					TotalQueries[i] += TotalQueries[j];
					Name.erase(Name.begin()+j);
					QueryPerHour.erase(QueryPerHour.begin() + j);
					Hours.erase(Hours.begin() + j);
					TotalQueries.erase(TotalQueries.begin() + j);
					Info.erase(Info.begin() + j);
					j--;
				}
			}
			
		} 
		for (int i = Name.size() - 1; i > 0; i--)	//sorting
		{
			for (int j = Name.size() - 1; j > 0; j--)	
			{
				if (Name[j] < Name[j - 1])
				{
					swap(Name[j],Name[j - 1]);
					swap(QueryPerHour[j], QueryPerHour[j - 1]);
					swap(Hours[j], Hours[j - 1]);
					swap(Info[j],Info[j-1]);
				}
			}
		}
		ofstream OutFile("Output.txt");
		for (int i = 0; i < Name.size(); i++)
		{
			OutFile << Name[i] << " " << QueryPerHour[i] << " " << Hours[i] << " " << TotalQueries[i] << " " << Info[i] << endl;
		}
		OutFile.close();
	}	
private:
		vector<string> Name;
		vector<int> QueryPerHour;
		vector<int> Hours;
		vector<int> TotalQueries;
		vector<string> Info;
};
int main()
{
	ifstream InFile;
	string ListName;
	setlocale(0, "");
	cout << "Type in the name of the file (filename.txt)" << endl;
	cin >> ListName;//file name input
	InFile.open(ListName);//open file stream
	if (!InFile)
	{
		cout << "Unable to open file";
		exit(1);
	}
	vector<string> InputVec;
	string s;
	while (!InFile.eof())//put lines into vector
	{
		InFile >> s;
		InputVec.push_back(s);
	}
	Table table(InputVec);
	InFile.close();
	return 0;
}


