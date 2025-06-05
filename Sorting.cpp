#include <iostream>

using namespace std;

class sort {
public:
	sort(int n[10]);
	void bubblesort();
	void insertionsort();
	void selectionsort();
	void quicksort(int low, int high);
	void print();
private:
	int numbers[10];
};

sort::sort(int n[10]) {
	for (int i = 0; i < 10; i++) {
		numbers[i] = n[i];
	}
}

void sort::bubblesort() {
	for (int i = 0; i < 10; i++) {
		for (int a = 0; a < 10 - i - 1; a++) {
			if (numbers[a] > numbers[a + 1]) {
				swap(numbers[a], numbers[a + 1]);
			}
		}
	}
}

void sort::insertionsort() {
	for (int i = 1; i < 10; i++) {
		int key = numbers[i];
		int j = i - 1;
		while (j >= 0 && numbers[j] > key) {
			numbers[j + 1] = numbers[j]; --j;
		}
		numbers[j + 1] = key;
	}
}

void sort::selectionsort() {
	for (int i = 0; i < 9; i++) {
		int min = i;
		for (int j = i + 1; j < 10; ++j)
		{
			if (numbers[j] < numbers[min]) {
				min = j;
			}
		}
		swap(numbers[i], numbers[min]);
	}
}

void sort::quicksort(int low = 0, int high = 9) {
	if (low >= high) return;

	int pivot = numbers[high];
	int i = low - 1;

	for (int j = low; j < high; ++j) {
		if (numbers[j] < pivot) {
			swap(numbers[++i], numbers[j]);
		}
	}
	swap(numbers[i + 1], numbers[high]);
	int pi = i + 1;

	quicksort(low, pi - 1);
	quicksort(pi + 1, high);
}

void sort::print() {
	for (int i = 0; i < 10; i++) {
		cout << numbers[i] << endl;
	}
}

int main() {
	int nums[10];
	for (int i = 0; i < 10; i++) {
		cin >> nums[i];
	}
	sort s(nums);
	//s.bubblesort();
	//s.insertionsort();
	//s.selectionsort();
	//s.quicksort();
	s.print();
}
