#include <iostream>
#include <fstream>
#include <string>

int* readArrayFromFile(std::ifstream& ifs, const int size);
void moveArray(int* array, const int size, int distance);
void printArrayToFile(std::ofstream& ofs, int* array, const int size);


int main()
{
	setlocale(LC_ALL, "rus");

	std::ifstream ifs("in.txt");

	if (!ifs.is_open()) {
		std::cout << "Ошибка при открытии файла!\n";
		return 1;
	}

	int input = 0;
	ifs >> input;
	const int SIZE1 = input;

	int* array1 = readArrayFromFile(ifs, SIZE1);

	ifs >> input;
	const int SIZE2 = input;

	int* array2 = readArrayFromFile(ifs, SIZE2);

	ifs.close();

	moveArray(array1, SIZE1, -1);
	moveArray(array2, SIZE2, 1);

	std::ofstream ofs("out.txt");
	if (!ofs.is_open()) {
		std::cout << "Ошибка при записи файла!\n";
		return 1;
	}

	printArrayToFile(ofs, array2, SIZE2);
	printArrayToFile(ofs, array1, SIZE1);

	ofs.close();

	delete[] array1;
	delete[] array2;

	return 0;
}

int* readArrayFromFile(std::ifstream& ifs, const int size) {
	int* array = new int[size]();
	for (int i = 0; i < size; i++) {
		ifs >> array[i];
	}
	return array;
}

// вдохновлялся тут https://github.com/openjdk/jdk/blob/master/src/java.base/share/classes/java/util/Collections.java#L809
void moveArray(int* array, const int size, int distance) {
	if (size == 0) {
		return;
	}
	distance = distance % size;
	if (distance < 0) {
		distance += size;
	}
	if (distance == 0) {
		return;
	}
	for (int start = 0, moved = 0; moved != size; start++) {
		int temp = array[start];
		int i = start;
		do {
			i += distance;
			if (i >= size) {
				i -= size;
			}
			int old = array[i];
			array[i] = temp;
			temp = old;
			moved++;
		} while (i != start);
	}
}

void printArrayToFile(std::ofstream& ofs, int* array, const int size) {
	ofs << size << '\n';
	for (int i = 0; i < size; i++) {
		ofs << array[i] << ' ';
	}
	ofs << '\n';
}