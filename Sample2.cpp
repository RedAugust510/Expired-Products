//  This is a function designed to alert users if their purchased medication
//  is recalled or not. Data referenced by portion of lot number and portion of UPC code.

#include <iostream>
#include <iomanip>
using namespace std;

int         linearSearch(const int [], int, int);
const int   SIZE = 17;

int main()
{
	int     FlaggedTylenol[SIZE] = {31266, 32242, 37112, 56266, 87266, 105266, 316112, 322266, 325266, 351112, 368112, 376112, 379266, 388112, 422122, 435112, 458112};
	double  LotAndUPC;	    // Last digits of LOT and last 3 digits of UPC
	int     linearResult;	// Linear results

	cout << "A recall was issued for:\n\n";
	cout << "Tylenol 8 Hour Caps, 24 & 100 count\n\n";
	cout << "To find out if your purchase is on the list,\n\n";
	cout << "Please enter 1) The last 3 digits of the Lot # and \n";
	cout << "2) The last 4 digits of the UPC Code\n\n\n";
	cout << "(For example: 032 + 258 => 0327258)\n\n";
	cin >> LotAndUPC;

	linearResult = linearSearch(FlaggedTylenol, SIZE, LotAndUPC);       // Apply linear search to Lot and UPC numbers

	if (linearResult == -1)     // If linearSearch return -1, you're good
	{
		cout << "Your Tylenol is safe! Have a great day :)\n";
	}
	else
	{
		cout << "\a\n\nALERT!! DO NOT USE!!!\n";                        // I Like beeps
		cout << "Please return the product to your nearest pharmacy\n\n";
	}
	return 0;
	}

/********************************************************************
    Function performs linear search on the numbers (lot & upc) in   *
    the form of an array.                                           *
    SIZE = the # of elements in the array                           *
********************************************************************/

int linearSearch(const int FlaggedTylenol[], int SIZE, int LotAndUPC)
{
	int index = 0;
	int position = -1;
	bool found = false;                         // FLAG

	while (index < SIZE && !found)
	{
		if (FlaggedTylenol[index] == LotAndUPC)	// If number is found
		{
			found = true;					    // Set FLAG
			position = index;
		}
		index++;
	}
	return position;						// Return the position, or -1
}
