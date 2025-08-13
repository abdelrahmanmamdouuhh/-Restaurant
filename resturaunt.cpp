#include <iostream>
using namespace std;

int main() {
    
    string drinks[] = {"Water", "Coca-Cola", "Orange Juice"};
    double drink_prices[] = {5.0, 15.0, 25.0};

    string mains[] = {"Burger", "Pizza", "Pasta"};
    double main_prices[] = {50.0, 100.0, 85.0};

    string desserts[] = {"Ice Cream", "Cake", "Basbousa"};
    double dessert_prices[] = {25.0, 40.0, 30.0};


    int q_drinks[3] = {0};
    int q_mains[3] = {0};
    int q_desserts[3] = {0};

    cout << "** Welcome to C++ Restaurant **\n";

    while (true) {
        cout << "Select a category: \n";
        cout << "1- Drinks\n";
        cout << "2- Main Dishes\n";
        cout << "3- Desserts\n";
        cout << "0- Finish Order\n";
        cout << "Enter your choice: ";

        int category;
        cin >> category;

        if (category == 0) break;
        if (category < 1 || category > 3) {
            cout << "Invalid category!\n";
            continue;
        }

        
        if (category == 1) {
            cout << " .. Drinks ..\n";
            for (int i = 0; i < 3; i++) {
                cout << i+1 << "- " << drinks[i] << " > " << drink_prices[i] << " EGP\n";
            }
        } else if (category == 2) {
            cout << " ..  Main Dishes  ..\n";
            for (int i = 0; i < 3; i++) {
                cout << i+1 << ") " << mains[i] << " > " << main_prices[i] << " EGP\n";
            }
        } else if (category == 3) {
            cout << " ..  Desserts  .. \n";
            for (int i = 0; i < 3; i++) {
                cout << i+1 << ") " << desserts[i] << " > " << dessert_prices[i] << " EGP\n";
            }
        }

        cout << "0) Back to categories\n";
        cout << "Select item number: ";
        int item;
        cin >> item;

        if (item == 0) continue;
        if (item < 1 || item > 3) {
            cout << "Invalid item!\n";
            continue;
        }

        cout << "Enter quantity: ";
        int qty;
        cin >> qty;

        if (category == 1) q_drinks[item-1] += qty;
        else if (category == 2) q_mains[item-1] += qty;
        else if (category == 3) q_desserts[item-1] += qty;

        cout << qty << " × added to your order.\n";
    }

    
    cout << " *** Receipt ***\n";
    double total = 0;

    
    for (int i = 0; i < 3; i++) {
        if (q_drinks[i] > 0) {
            double line_total = drink_prices[i] * q_drinks[i];
            cout << drinks[i] << " × " << q_drinks[i] << " = " << line_total << " EGP\n";
            total += line_total;
        }
    }
    
    for (int i = 0; i < 3; i++) {
        if (q_mains[i] > 0) {
            double line_total = main_prices[i] * q_mains[i];
            cout << mains[i] << " × " << q_mains[i] << " = " << line_total << " EGP\n";
            total += line_total;
        }
    }
    
    for (int i = 0; i < 3; i++) {
        if (q_desserts[i] > 0) {
            double line_total = dessert_prices[i] * q_desserts[i];
            cout << desserts[i] << " × " << q_desserts[i] << " = " << line_total << " EGP\n";
            total += line_total;
        }
    }

    cout << "Total: " << total << " EGP\n";
    cout << "     Thank you .";

    return 0;
}