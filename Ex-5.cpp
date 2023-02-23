#include <iostream>
#include <string>
using namespace std;

struct Person {
    string name;
};

void bubbleSort(Person arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].name > arr[j+1].name) {
                Person temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    const int SIZE = 5;
    Person people[SIZE];

    cout << "Enter " << SIZE << " names:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cin >> people[i].name;
    }

    bubbleSort(people, SIZE);

    cout << "Sorted names:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << people[i].name << endl;
    }

    return 0;
}

