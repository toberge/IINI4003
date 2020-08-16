/*
 * Constraints:
 * No functions, no arrays.
 */

#include <iostream>

using namespace std;

const int length = 5;

int main() {
    // I much prefer printf's syntax
    printf("Du skal skrive inn %d temperaturer\n", length);

    int temperature;
    int under_10 = 0;
    int between_10_and_20 = 0;
    int over_20 = 0;
    for (int i = 1; i <= length; i++) {

        cout << "Temperatur nr " << i << " ";
        cin >> temperature;

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
}
