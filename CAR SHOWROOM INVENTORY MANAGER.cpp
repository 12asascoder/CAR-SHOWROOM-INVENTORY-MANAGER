#include <iostream>
using namespace std;

class Car {
private:
    string brand;
    string model;
    double price;
    int year;
    static int totalCars;

public:
    Car(string carBrand, string carModel, double carPrice, int carYear) {
        brand = carBrand;
        model = carModel;
        price = carPrice;
        year = carYear;
        totalCars++;
    }

    static int getTotalCars() {
        return totalCars;
    }

    void displayCarInfo() const {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Price: " << price << endl;
        cout << "Year: " << year << endl;
    }
};

int Car::totalCars = 0;

int main() {
    int numCars;
    cout << "Enter number of cars: ";
    cin >> numCars;

    Car* cars[numCars];
    for (int i = 0; i < numCars; ++i) {
        string brand, model;
        double price;
        int year;

        cout << "Enter brand: ";
        cin >> brand;
        cout << "Enter model: ";
        cin >> model;
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter year: ";
        cin >> year;

        cars[i] = new Car(brand, model, price, year);
    }

    cout << "\nCar Inventory:\n";
    for (int i = 0; i < numCars; ++i) {
        cars[i]->displayCarInfo();
        cout << endl;
    }

    cout << "Total cars in inventory: " << Car::getTotalCars() << endl;

    for (int i = 0; i < numCars; ++i) {
        delete cars[i];
    }

    return 0;
}
```