//JcannonAssignment.cpp
//By Jonathon Cannon

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::endl;

int gold = 150;
string intent = "";
string input = "";

// Struct for items
struct Item {
    string name;
    int price;
    int quantity;
};

// Shop items
vector<Item> items = {
    { "sword", 15, 1 },
    { "shield", 25, 1 },
    { "potion", 5, 3 },
    { "crossbow", 20, 1 },
    { "rations", 10, 3 },
    { "armor", 100, 1 }
};

// Player inventory
vector<Item> inventory = {
    { "gold pouch", 0, 1 }
};

int sellItem(const string& input);
int purchaseItem(const string& input);
void displayShopInventory();
void displayPlayerInventory();

int main() {
    while (true) {
        cout << gold << " Gold remaining\n\n";
        cout << "Welcome to the Caspiran general store! What can I do for you today?\n buy \n sell \n inventory \n quit \n\n";
        cin >> intent;

        if (intent == "quit") {
            break; // Exit the loop if user wants to quit
        }
        if (intent == "inventory") {
            system("cls");
            displayPlayerInventory();
            continue; // Go back to the start of the loop
        }

        if (intent == "buy") {
            system("cls");
            cout << "What would you like to purchase?\n";
            displayShopInventory();
            string input;
            cin >> input;
            purchaseItem(input);
            system("cls");
        }
        else if (intent == "sell") {
            system("cls");
            cout << "What would you like to sell?\n";
            displayPlayerInventory();
            string input;
            cin >> input;
            sellItem(input);
            system("cls");
        }
        else {
            cout << "Invalid option! Please enter 'buy', 'sell', 'inventory', or 'quit'.\n";
        }
    }
}

// Display merchant items
void displayShopInventory() {
    cout << "\nMerchant items: \n\n";
    cout << "You have: " << gold << " gold pieces!\n\n";

    for (const auto& item : items) {
        cout << item.quantity << " x " << item.name << " - " << item.price << " gold each\n";
    }
}

// Display player items
void displayPlayerInventory() {
    cout << "\nYour items: \n";
    for (const auto& item : inventory) {
        cout << item.quantity << " x " << item.name << endl;
    }
}

// Handle purchasing items
int purchaseItem(const string& input) {
    while (true) {  
        bool found = false;  // Track if item was found
        for (auto& item : items) {
            if (input == item.name) {
                found = true;
                if (gold < item.price) {
                    cout << "Not enough gold!\n";
                    return 0;
                }

                if (item.quantity <= 0) {
                    cout << "Sold out!\n";
                    return 0;
                }

                gold -= item.price;
                item.quantity--;

                // Check if the item already exists in the inventory
                auto invIter = std::find_if(inventory.begin(), inventory.end(), [&](const Item& invItem) {
                    return invItem.name == item.name;
                    });

                if (invIter != inventory.end()) {
                    invIter->quantity++;
                }
                else {
                    inventory.push_back({ item.name, item.price, 1 }); // Add new item to inventory
                }

                cout << "You have purchased a " << item.name << "!\n";

                // Ask if they want to purchase more
                string again;
                string input;
                cout << "Would you like to purchase anything else? (yes/no)\n";
                cin >> again;
                system("cls");

                if (again == "yes") {
                    cout << "What would you like to purchase?\n";
                    displayShopInventory();
                    cin >> input;  
                }
                else {
                    return 1;  // Exit the purchase loop
                }

                break;  // Exit the inner loop if we found a match
            }
        }
        if (!found) {
            cout << input << " is not a valid option!\n";
            return 0;  // If item was not found, exit the function
        }
    }
}

// Handle selling items
int sellItem(const string& input) {
    while (true) { 
        bool found = false; 
        for (const auto& item : items) {
            if (input == item.name) {
                found = true;
                cout << "You would like to sell your " << item.name << "? That will be " << item.price << " gold.\n\n";

                
                auto invIter = std::find_if(inventory.begin(), inventory.end(), [&](const Item& invItem) {
                    return invItem.name == item.name;
                    });

                if (invIter != inventory.end() && invIter->quantity > 0) {
                    gold += item.price;
                    invIter->quantity--;

                    auto shopIter = std::find_if(items.begin(), items.end(), [&](const Item& shopItem) {
                        return shopItem.name == item.name;
                        });

                    if (shopIter != items.end()) {
                        shopIter->quantity++;
                    }

                    // If quantity drops to 0, remove the item from inventory
                    if (invIter->quantity == 0) {
                        inventory.erase(invIter);
                    }

                    cout << "You have successfully sold a " << item.name << "!\n";

                    // Ask if they want to sell more
                    string again;
                    string input;
                    cout << "Would you like to sell anything else? (yes/no)\n";
                    cin >> again;
                    system("cls");

                    if (again == "yes") {
                        cout << "What would you like to sell?\n";
                        displayPlayerInventory();
                        cin >> input; // Get new input for the next sell
                    }
                    else {
                        return 1; 
                    }

                    break; 
                }
                else {
                    cout << "You don't have a " << item.name << "\n";
                    return 0;
                }
            }
        }
        if (!found) {
            cout << input << " is not a valid option!\n";
            return 0; 
        }
    }
}