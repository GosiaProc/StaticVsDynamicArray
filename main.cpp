#include<iostream>
#include <stdexcept>
#include <algorithm>

class DynamicArr {
	int arraySize;
	int numberOfElement;
	int* arr;

public:
	DynamicArr() {
		arraySize = 4;
		numberOfElement = 0;
		arr = new int[arraySize];
	}
	~DynamicArr() {
		delete[] arr;
	}
	void push_back(int item) {
		if (numberOfElement >= arraySize) {
			resize();
		}
		arr[numberOfElement] = item;
		numberOfElement++;
	}

	void resize() {
		int arraySize2 = 2 * arraySize;
		int* arr2 = new int[arraySize2];
		std::copy(arr, arr + arraySize, arr2);
		delete[] arr;
		arr = arr2;
		arraySize = arraySize2;
	}
		
	int get(int index) {
		validateIndex(index);
		return arr[index];
	}

	void set(int index, int value) {
		validateIndex(index);
		arr[index] = value;
	}

	void validateIndex(int index) {
		if (index > numberOfElement) {
			throw std::overflow_error("Index spoza zakresu");
		}
	}
	int operator[](int index) {
		return get(index);
	}
	void clear() {
		arraySize = 0;
		delete[] arr;
	}

	int getSize() {
		return arraySize;
	}
 };

int main() {
	
	DynamicArr arr1;

	char choice = 0;
	int index;
	int element;
try{
	while (true) {
		std::cout << "MENU" << std::endl;
		std::cout << "-----------------" << std::endl;
		std::cout << "1. Push_back" << std::endl;
		std::cout << "2. Get value for index" << std::endl;
		std::cout << "3. Set value for index" << std::endl;
		std::cout << "4. Disply array" << std::endl;
		std::cout << "5. Clear arr " << std::endl;

		choice = getchar();
		switch (choice) {
		case '1':
			std::cout << "Push_back value";
			std::cout << "Enter value:";
			std::cin >> element;
			arr1.push_back(element);
			break;
		case '2':
			std::cout << "Get value for index";
			std::cout << "Enter index:";
			std::cin >> index;
			std::cout << arr1.get(index)<< "\n";
			break;
		case '3':
			std::cout << "Set value for index:";
			std::cout << "Enter index:";
			std::cin >> index;
			std::cout << "Enter value:";
			std::cin >> element;
			arr1.set(index, element);
			break;
		case '4':
			std::cout << "\n";
			for (int i = 0; i < arr1.getSize(); i++)
				std::cout << arr1[i] << "\n";
			break;
		case 5:

			std::cout << "Clear Array";
			arr1.clear();
			break;


		default:
			break;
		}
		getchar();
	}
	
	}
	catch (std::overflow_error& e)
	{
		std::cerr << "wyjatek zlapany  :  " << e.what() << std::endl;
		return -1;
	}
		
	return 0;
}