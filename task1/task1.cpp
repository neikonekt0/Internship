#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
vector<int> sort1(vector<int>& mas)	//even numbers' removal, sort ascending
{

	for (int i = 0; i < mas.size(); i++)	//erasing 
	{
		if (mas[i] % 2 == 0)
		{

			mas.erase(mas.begin() + i);
			i--;
		}
	}
	int tmp;
	for (int i = mas.size() - 1; i > 0; i--)	//sorting
	{
		for (int j = mas.size() - 1; j > 0; j--)
		{
			if (mas[j] < mas[j - 1])
			{
				tmp = mas[j];
				mas[j] = mas[j - 1];
				mas[j - 1] = tmp;
			}
		}
	}

	return mas;
}
vector<int> sort2(vector<int>& mas)	//odd numbers' removal, reverse order sorting
{
	for (int i = 0; i < mas.size(); i++)	//erasing 
	{
		if (mas[i] % 2 != 0)
		{

			mas.erase(mas.begin() + i);
			i--;
		}
	}
	vector<int> buffer(mas.size());
	for (int i = buffer.size() - 1; i >= 0; i--)	//reversing
	{
		buffer[i] = mas[buffer.size() - i - 1];
	}
	mas = buffer;
	return mas;
}
vector<int> sort3(vector<int>& mas)	//sort even(ascending), then odd(descending)
{
	vector<int> even;
	vector<int> odd;
	for (int i = 0; i < mas.size(); i++)	//even buffer
	{
		if (mas[i] % 2 == 0) //buffering even numbers 
		{
			even.emplace_back(mas[i]);
			mas.erase(mas.begin() + i);
			i--;
		}
	}
	odd = mas;								//odd buffer
	int tmp;
	for (int i = even.size() - 1; i > 0; i--)	//sorting
	{
		for (int j = even.size() - 1; j > 0; j--)
		{
			if (even[j] < even[j - 1])
			{
				tmp = even[j];
				even[j] = even[j - 1];
				even[j - 1] = tmp;
			}
		}
	}
	for (int i = odd.size() - 1; i > 0; i--)	//sorting
	{
		for (int j = odd.size() - 1; j > 0; j--)
		{
			if (odd[j] >= odd[j - 1])
			{
				tmp = odd[j];
				odd[j] = odd[j - 1];
				odd[j - 1] = tmp;
			}
		}
	}
	for (int i = even.size() - 1; i >= 0; i--)
		odd.insert(odd.begin(), even[i]);
	mas = odd;
	return mas;
}
int main()
{
	srand(time(NULL));
	int size, var;

	cout << "Specify array size.\n";		//user input
	cin >> size;
	cout << "Choose sorting variation.\n";
	cin >> var;
	vector<int> arr(size);
	for (int i = 0; i < size; i++)		//fill the array with random nums
	{
		arr[i] = rand() % 10 + 0;
		cout << "arr[" << i << "]= " << arr[i] << endl;
	}
	cout << "\n\n";

	switch (var)
	{
	case 1:
		sort1(arr);
		break;
	case 2:
		sort2(arr);
		break;
	case 3:
		sort3(arr);
		break;
	default:
		cout << "There is no variation such as '" << var << "'.Setting variation to '1' by default.\n"; //if none fits
		var = 1;
		sort1(arr);
	}
	for (int i = 0; i < arr.size(); i++)
		cout << "arr[" << i << "]= " << arr[i] << endl;
	system("pause");
	return 0;
}