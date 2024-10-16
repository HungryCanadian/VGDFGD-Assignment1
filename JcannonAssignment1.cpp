// JcannonAssignment1.cpp : 
// By Jonathon Cannon

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::endl;
vector<string>::iterator it;
vector<string>::const_iterator iter;

string input = "";
int gold = 150;
string intent = "";
vector<string> shop = { "sword", "armor", "shield", "potion", "crossbow", "rations" };
vector<string> inventory = { "gold pouch" };

struct Item {
    string name;
    int price;
    int quantity;
};

// this should make it easier to add more items and check for their prices.
vector<Item> items = {
    { "sword", 15, 1 },
    { "shield", 25, 1 },
    { "potion", 5, 3 },
    { "crossbow", 20, 1 },
    { "rations", 10, 3 },
    { "armor", 100, 1 }
};
int sellItem(const string& input);
int purchaseItem(const string& input);
void displayShopInventory();
void displayPlayerInventory();


int main() {
    while (true) {
        cout << "Welcome to the Caspiran general store! What can I do for you today?\n buy, \n sell, \n quit \n\n";
        string intent;
        cin >> intent;

        if (intent == "quit") {
            break; // Exit the loop if user wants to quit
        }

        string input;
        if (intent == "buy") {
            cout << "What would you like to purchase?\n";
            displayShopInventory();
            cin >> input;
            purchaseItem(input);
        }
        else if (intent == "sell") {
            cout << "What would you like to sell?\n";
            displayPlayerInventory();
            cin >> input;
            sellItem(input);
        }

        cout << gold << " Gold remaining\n\n";
    }
}


// display merchant items
void displayShopInventory() {
    cout << "\nMerchant items: \n";

    for (iter = shop.begin(); iter != shop.end(); iter++) {
        cout << *iter << endl;
    }
}
// display player items
void displayPlayerInventory() {
    cout << "\nYour items: \n";

    for (iter = inventory.begin(); iter != inventory.end(); iter++) {
        cout << *iter << endl;
    }
}
// this function should handle all the purchasing, instead of having blocks of repetitive code.
int purchaseItem(const string& input) {
    for (const auto& item : items) {
        if (input == item.name) {
            if (gold < item.price) {
                cout << "Not enough gold!\n";
                return 0;
            }

            cout << "You would like to purchase a " << item.name << "? That will be " << item.price << " gold.\n\n";
            auto it = std::find(shop.begin(), shop.end(), item.name);
            if (it == shop.end()) {
                cout << "Sold out!\n";
                return 0;
            }

            gold -= item.price;
            inventory.push_back(item.name);
            shop.erase(it);
            return 1;
        }
    }

    cout << input << " is not a valid option!\n";
    return 0;
}
// this function should handle all the selling, if it doesnt work try swapping 'int' to 'bool'
int sellItem(const string& input) {
    for (const auto& item : items) {
        if (input == item.name) {
            cout << "You would like to sell your " << item.name << "? That will be " << item.price << " gold.\n\n";
            auto it = std::find(inventory.begin(), inventory.end(), item.name);
            if (it != inventory.end()) {
                gold += item.price;
                shop.push_back(item.name);
                inventory.erase(it);
                return 1;
            }
            else {
                cout << "You don't have a " << item.name << "\n";
                return 0;
            }
        }
    }
    cout << input << " is not a valid option!\n";
    return 0;
}