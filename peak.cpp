#include<fstream>
#include<iostream>
#include <string>
#include <vector>
#include<math.h>

using namespace std;

//Name: Enas Alikhashashneh.

//FindPeak Algorithm in 1D.
std::pair<int, int> findpeak(vector<int> arrayofint, int start, int end)
{
	//if the array contains only one integer
	if (end == start)
	{
		return std::make_pair(arrayofint[start], start);
	}
	//if the array contains at least 2 integers
	else{
		//Divide by finding the mid point constant time Theta(1)
		int mid = (end - start) / 2 + start;

		/* Conqure phase by check if the mid value is peak (it is greater than both of its neighbours) then
		return it, else If the left neighbour is greater, then find the peak recursively in the left side of the array.
		else If the right neighbour is greater, then find the peak recursively in the right side of the array*/

		if ((mid == 0 || arrayofint[mid - 1] <= arrayofint[mid]) && (mid == end || arrayofint[mid + 1] <= arrayofint[mid]))
		{
			return std::make_pair(arrayofint[mid], mid);
		}
		else {
			if (mid > 0 && arrayofint[mid - 1] > arrayofint[mid])
			{
				return findpeak(arrayofint, start, mid - 1);
			}

			else {
				if (arrayofint[mid + 1] > arrayofint[mid])
				{
					return findpeak(arrayofint, mid + 1, end);
				}
			}
		}
	}
}

//Read the series of integers from the Text file
vector<int> read(){
	//Local variables
	ifstream openfile;
	string filename, linee;
	vector<int> arrayofint;
	int num;
	
	//Name of text file	
	filename = "peak.txt";

	//Open the file and Check if it exists
	openfile.open(filename);
	if (openfile.fail()) {
		std::cout << "No data file"<< endl;
		exit(1);
	}
	//If file exist in the Dir start reading
	else{
		while (!openfile.eof()) {
			getline(openfile, linee);
			num = atoi(linee.c_str());
			arrayofint.push_back(num);
		}

		openfile.close();

		//print out the Integer values
		std::cout << "\nA = [";
		for (int i = 0; i < arrayofint.size(); i++){
			std::cout << "  " << arrayofint.at(i);
		}
		std::cout << " ]\n" << endl;
	}
	return arrayofint;
}

//Main function
int main()
{
	//Local variables
	vector<int> arrayofint;
	std::pair< int, int> peakinfo;

	//Read the series of integers from the Text file
	arrayofint = read();

	//Find Peak Value and Index
	peakinfo = findpeak(arrayofint, 0, arrayofint.size() - 1);

	//print out the peak information
	std::cout << "The Peak Value: " + to_string(peakinfo.first) + "\nThe Peak Index: " + to_string(peakinfo.second) << endl;
	return 0;
}
