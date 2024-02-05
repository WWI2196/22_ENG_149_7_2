#include <iostream>
using namespace std;

int main() {

	int numberOfComplexes;
	cout << "Enter the number of housing complexes: ";
	cin >> numberOfComplexes;

	int**** housingComplex = new int*** [numberOfComplexes];

	for (int i = 0; i < numberOfComplexes; i++) {

		housingComplex[i] = new int** [2];

		int numberOfApartments;
		cout << "Enter the number of apartments in complex " << char('A' + i) << ": ";
		cin >> numberOfApartments;

		housingComplex[i][1] = new int* [numberOfApartments + 1]; // +1 to account for the total number of apartments

		housingComplex[i][1][0] = new int[1]; // Allocate space to store the total number of apartments
		*housingComplex[i][1][0] = numberOfApartments; // Store the total number of apartments

		for (int j = 1; j <= numberOfApartments; j++) { // Start from 1 as 0 is used to store the total number of apartments

			housingComplex[i][1][j] = new int[6];

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

	// Display the details of all apartments in all complexes
	for (int i = 0; i < numberOfComplexes; i++) {
		cout << "\nComplex " << char('A' + i) << " has " << *housingComplex[i][1][0] << " apartments. Here are their details:\n";
		for (int j = 1; j <= *housingComplex[i][1][0]; j++) {
			cout << "\nDetails for apartment " << j << ":\n";
			cout << "Number of doors: " << housingComplex[i][1][j][0] << "\n";
			cout << "Number of windows: " << housingComplex[i][1][j][1] << "\n";
			cout << "Number of rooms: " << housingComplex[i][1][j][2] << "\n";
			cout << "Number of washrooms: " << housingComplex[i][1][j][3] << "\n";
			cout << "Total floor area: " << housingComplex[i][1][j][4] << "\n";
			cout << "Estimated building cost: " << housingComplex[i][1][j][5] << "\n";
		}
	}
}
