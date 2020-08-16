#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

void read_temperatures(double temperatures[], int length);

const char *filename;

int main(int argc, char **argv) {
    const int length = 5;

    if (argc == 2) {
        filename = argv[1];
    } else {
        filename = "temperatures.txt";
    }

    // Fill array with temperatures
    double temperatures[length] = {'\0'};
    read_temperatures((double*) &temperatures, length);

    int under_10 = 0;
    int between_10_and_20 = 0;
    int over_20 = 0;

    // Count through contents of array
    for (int i = 0; i < length; i++) {
        int temperature = temperatures[i];
        if (temperature < 10) {
            under_10++;
        } else if (temperature <= 20) {
            between_10_and_20++;
        } else {
            over_20++;
        }
    }

    cout << "Antall under 10 er " << under_10 << endl;
    cout << "Antall mellom 10 og 20 er " << between_10_and_20 << endl;
    cout << "Antall over 20 er " << over_20 << endl;

    return EXIT_SUCCESS;
}

void read_temperatures(double temperatures[], int length) {
    ifstream file;
    file.open(filename);
    if (!file) {
        fprintf(stderr, "file.open() failed\n");
        exit(EXIT_FAILURE);
    }

    int temperature;
    int i = 0;
    while (i < length && file >> temperature) {
        temperatures[i++] = temperature;
    }

    file.close();
}
