#include <iostream>
using namespace std;

void swapApartments(float* a, float* b);
void copyApartment(float* dest, float* src);

void copyApartment(float* dest, float* src) {
	for (int i = 0; i < 6; i++) {
		dest[i] = src[i];
	}
}

// Function to swap two apartments
void swapApartments(float* a, float* b) {
	float temp[6];
	for (int i = 0; i < 6; i++) {
		temp[i] = a[i];
		a[i] = b[i];
		b[i] = temp[i];
	}
}

int main() {

	int numberOfComplexes;
	cout << "Enter the number of housing complexes: ";
	cin >> numberOfComplexes;

	float**** housingComplex = new float*** [numberOfComplexes];

	for (int i = 0; i < numberOfComplexes; i++) {

		housingComplex[i] = new float** [2];

		int numberOfApartments;
		cout << "Enter the number of apartments in complex " << char('A' + i) << ": ";
		cin >> numberOfApartments;

		housingComplex[i][1] = new float* [numberOfApartments + 1]; // +1 to account for the total number of apartments

		housingComplex[i][1][0] = new float[1]; // Allocate space to store the total number of apartments
		*housingComplex[i][1][0] = numberOfApartments; // Store the total number of apartments

		for (int j = 1; j <= numberOfApartments; j++) { // Start from 1 as 0 is used to store the total number of apartments

			housingComplex[i][1][j] = new float[6];

			cout << "Enter the details for apartment " << j << " in complex " << char('A' + i) << ":\n";

			cout << "Number of doors: ";
			cin >> housingComplex[i][1][j][0];

			cout << "Number of windows: ";
			cin >> housingComplex[i][1][j][1];

			cout << "Number of rooms: ";
			cin >> housingComplex[i][1][j][2];

			cout << "Number of washrooms: ";
			cin >> housingComplex[i][1][j][3];

			cout << "Total floor area: ";
			cin >> housingComplex[i][1][j][4];

			cout << "Estimated building cost: ";
			cin >> housingComplex[i][1][j][5];
		}
	}

	while (true) {
		cout << endl;
		cout << "Choose to see the details from the following available complexes:" << endl;
		for (int i = 0; i < numberOfComplexes; i++) {
			cout << i + 1 << "." << "For Complex " << char('A' + i) << " select " << char('A' + i) << endl;
		}

		char selectedComplex;
		cin >> selectedComplex;

		// Display the details of all apartments in all complexes

		cout << "\nComplex " << char(toupper(selectedComplex)) << " has " << *housingComplex[toupper(selectedComplex) - 'A'][1][0] << " apartments.\n";

		cout << "Select the option to sort the apartments;\n 1 - by Floor area\n 2 - by Cost" << endl;

		int option;
		cin >> option;

		cout << "Do you want it in,\n 1 - Ascending order\n 2 - Descending order" << endl;

		int order;
		cin >> order;

		cout << endl;

		// Create a temporary copy of the apartments for sorting
		float** sortedApartments = new float* [*housingComplex[toupper(selectedComplex) - 'A'][1][0] + 1];
		int* originalIndices = new int[*housingComplex[toupper(selectedComplex) - 'A'][1][0] + 1];
		for (int j = 1; j <= *housingComplex[toupper(selectedComplex) - 'A'][1][0]; j++) {
			sortedApartments[j] = new float[6];
			copyApartment(sortedApartments[j], housingComplex[toupper(selectedComplex) - 'A'][1][j]);
			originalIndices[j] = j;
		}

		// Sort the apartments
		for (int i = 1; i <= *housingComplex[toupper(selectedComplex) - 'A'][1][0]; i++) {
			for (int j = i + 1; j <= *housingComplex[toupper(selectedComplex) - 'A'][1][0]; j++) {
				if ((order == 1 && sortedApartments[i][option + 3] > sortedApartments[j][option + 3]) ||
					(order == 2 && sortedApartments[i][option + 3] < sortedApartments[j][option + 3])) {
					swapApartments(sortedApartments[i], sortedApartments[j]);
					swap(originalIndices[i], originalIndices[j]);
				}
			}
		}

		// Print the sorted apartments
		for (int j = 1; j <= *housingComplex[toupper(selectedComplex) - 'A'][1][0]; j++) {
			cout << "\nDetails for apartment " << originalIndices[j] << ":\n";
			cout << "Number of doors: " << sortedApartments[j][0] << "\n";
			cout << "Number of windows: " << sortedApartments[j][1] << "\n";
			cout << "Number of rooms: " << sortedApartments[j][2] << "\n";
			cout << "Number of washrooms: " << sortedApartments[j][3] << "\n";
			cout << "Total floor area: " << sortedApartments[j][4] << "\n";
			cout << "Estimated building cost: " << sortedApartments[j][5] << "\n";
		}

		//delete sortedApartments
		for (int j = 1; j <= *housingComplex[toupper(selectedComplex) - 'A'][1][0]; j++) {
			delete[] sortedApartments[j];
		}
		delete[] sortedApartments;

		cout<<"\nDo you wish to look into another complex? (y/n)"<<endl;
		char continueLooking;
		cin>>continueLooking;

		if (continueLooking == 'n') {
			break;
		}
	}
	
	for (int i = 0; i < numberOfComplexes; i++) {
		for (int j = 0; j <= *housingComplex[i][1][0]; j++) {
			delete[] housingComplex[i][1][j];
		}
		delete[] housingComplex[i][1];
		delete[] housingComplex[i];
	}


	return 0;
}
