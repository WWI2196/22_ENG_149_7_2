#include <iostream>
using namespace std;

void swapApartments(float* x, float* y);
void copyApartment(float* copy, float* arrayToCopy);

void copyApartment(float* copy, float* arrayToCopy) { //copy the values of apartment to another array
	for (int i = 0; i < 6; i++) {
		copy[i] = arrayToCopy[i];
	}
}

void swapApartments(float* x, float* y) { // Function to swap the values of two apartments for sorting
	float temp[6]; // Temporary array to store the values of a before swapping

	for (int i = 0; i < 6; i++) { 
		temp[i] = x[i];
		x[i] = y[i];
		y[i] = temp[i];
	}
}

int main() {

	int numberOfComplexes;
	cout << "Enter the number of housing complexes: ";
	cin >> numberOfComplexes; // Get the number of housing complexes

	float**** housingComplex = new float*** [numberOfComplexes]; // 4D array to store the details of the housing complexes

	for (int i = 0; i < numberOfComplexes; i++) {

		housingComplex[i] = new float** [2]; //	array of pointer to pointer to store the details of the apartments in each housing complex

		int numberOfApartments;
		cout << "\nEnter the number of apartments in complex " << char('A' + i) << ": ";
		cin >> numberOfApartments; // Get the number of apartments in the housing complex

		housingComplex[i][1] = new float* [numberOfApartments + 1]; // array to store the details of the apartments in the housing complex

		housingComplex[i][1][0] = new float[1]; // Allocate space to store the total number of apartments
		*housingComplex[i][1][0] = numberOfApartments; // Store the total number of apartments

		for (int j = 1; j <= numberOfApartments; j++) { // Start from 1 as 0 is used to store the total number of apartments in a complex

			housingComplex[i][1][j] = new float[6]; // space to store the details of each apartment

			cout << "\nEnter the details for apartment " << j << " in complex " << char('A' + i) << ":\n";

			cout << "Number of doors\t\t\t\t: "; 
			int doors = 0;
			cin>> doors;

			while (cin.fail()) { // Check if the door is an integer value
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Invalid input. Please enter an integer value. ";
				cin >> doors;
			}
			housingComplex[i][1][j][0] = doors;
			

			cout << "Number of windows\t\t\t: ";
			int windows = 0;
			cin >> windows;

			while (cin.fail()) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Invalid input. Please enter an integer value. ";
				cin >> windows;
			}
			housingComplex[i][1][j][1] = windows;
			

			cout << "Number of rooms\t\t\t\t: ";
			int rooms = 0;
			cin >> rooms;

			while (cin.fail()) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Invalid input. Please enter an integer value. ";
				cin >> rooms;
			}
			housingComplex[i][1][j][2] = rooms;
			

			cout << "Number of washrooms\t\t\t: ";
			int washrooms = 0;
			cin >> washrooms;

			while (cin.fail()) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Invalid input. Please enter an integer value. ";
				cin >> washrooms;
			}
			housingComplex[i][1][j][3] = washrooms;

			cout << "Total floor area\t\t\t: ";
			float floorArea = 0;
			cin >> floorArea;

			while (cin.fail()) { // Check if the floor area is a float value
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Invalid input. Please enter a float value. ";
				cin >> floorArea;
			}
			housingComplex[i][1][j][4] = floorArea;

			cout << "Estimated building cost(millions)\t: ";
			float cost = 0;
			cin >> cost;

			while (cin.fail()) { // Check if the cost is a float value
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Invalid input. Please enter a float value. ";
				cin >> cost;
			
			}
			housingComplex[i][1][j][5] = cost;
		}
	}

	while (true) {

		cout << endl;

		cout << "\nChoose to see the details from the following available complexes:" << endl;
		for (int i = 0; i < numberOfComplexes; i++) {
			cout << char('A' + i) << "-" << "For Complex " << char('A' + i) << endl;
		}

		char selectedComplex;
		cin >> selectedComplex; // Input for the complex letter
		selectedComplex = toupper(selectedComplex); // Convert the input to uppercase

		if (selectedComplex < 'A' || selectedComplex >= 'A' + numberOfComplexes) { // Check if the input is valid
			cout << "Invalid input." << ".\n";
			continue; // Skip the rest of the loop and go back to selecting the complex if the input is invalid
		}

		cout << "\n*****************************************************" << endl;

		cout << "\nComplex " << selectedComplex << " has " << *housingComplex[selectedComplex - 'A'][1][0] << " apartments.\n"; // Show the number of apartments in the selected complex

		cout << "\nSelect the option to sort the apartments:\n1 - by Floor area\n2 - by Cost" << endl; // Option to sort the apartments based on floor area or cost

		int option;
		cin >> option;

		cout << "\nSelect the order you want:\n1 - Ascending order\n2 - Descending order" << endl; // Option to select the order of sorting

		int order;
		cin >> order;

		cout << endl;

		
		float** sortedApartments = new float* [*housingComplex[toupper(selectedComplex) - 'A'][1][0] + 1]; // Create a temporary copy of the apartments for sorting
		int* originalIndices = new int[*housingComplex[toupper(selectedComplex) - 'A'][1][0] + 1]; // Create an array to store the original indices of the apartments

		for (int j = 1; j <= *housingComplex[toupper(selectedComplex) - 'A'][1][0]; j++) {
			sortedApartments[j] = new float[6];
			copyApartment(sortedApartments[j], housingComplex[toupper(selectedComplex) - 'A'][1][j]); // Copy the values of the apartments to the temporary copy
			originalIndices[j] = j;
		}

		for (int i = 1; i <= *housingComplex[toupper(selectedComplex) - 'A'][1][0]; i++) { // Bubble sort the floor area/cost based on the selected option
			for (int j = i + 1; j <= *housingComplex[toupper(selectedComplex) - 'A'][1][0]; j++) {
				if ((order == 1 && sortedApartments[i][option == 1 ? 4 : 5] > sortedApartments[j][option == 1 ? 4 : 5]) || // Ascending order
					(order == 2 && sortedApartments[i][option == 1 ? 4 : 5] < sortedApartments[j][option == 1 ? 4 : 5])) { // Descending order
					swapApartments(sortedApartments[i], sortedApartments[j]);
					swap(originalIndices[i], originalIndices[j]);
				}
			}
		}

		for (int j = 1; j <= *housingComplex[toupper(selectedComplex) - 'A'][1][0]; j++) { // Display the sorted apartments
			cout << "\nDetails for apartment " << originalIndices[j] << ":\n";
			cout << "Number of doors\t\t\t\t: " << sortedApartments[j][0] << "\n";
			cout << "Number of windows\t\t\t: " << sortedApartments[j][1] << "\n";
			cout << "Number of rooms\t\t\t\t: " << sortedApartments[j][2] << "\n";
			cout << "Number of washrooms\t\t\t: " << sortedApartments[j][3] << "\n";
			cout << "Total floor area\t\t\t: " << sortedApartments[j][4] << "\n";
			cout << "Estimated building cost(millions)\t: " << sortedApartments[j][5] << "\n";
		}

		cout << "\n*****************************************************" << endl;

		for (int j = 1; j <= *housingComplex[toupper(selectedComplex) - 'A'][1][0]; j++) { // Deallocate the memory for the temporary copy of the apartments
			delete[] sortedApartments[j];
		}
		delete[] sortedApartments;

		cout<<"\nDo you wish to look into another complex? (y/n)"<<endl; // Ask the user if they want to look into another complex
		char continueLooking;
		cin>>continueLooking;

		if (continueLooking == 'n') {
			break;
		}
	}
	
	for (int i = 0; i < numberOfComplexes; i++) { // Deallocate the memory for the housing complexes
		for (int j = 0; j <= *housingComplex[i][1][0]; j++) {
			delete[] housingComplex[i][1][j];
		}
		delete[] housingComplex[i][1];
		delete[] housingComplex[i];
	}


	return 0;
}
