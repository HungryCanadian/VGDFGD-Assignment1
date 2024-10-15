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
vector<string> shop = { "sword", "armor", "shield" };
vector<string> inventory = { "gold pouch" };

int main() {
    while (true) {
        cout << "Welcome to the Caspiran general store! What can I do for you today?\n (b)uy, \n (s)ell, \n (q)uit \n\n";
        cout << "Your inventory: \n";
        for (iter = inventory.begin(); iter != inventory.end(); iter++) {
            cout << *iter << endl;

        }

        cin >> intent;

        if (intent == "q") {
            break; // Exit the loop if user wants to quit
        }

        if (intent == "b") {
            cout << "What would you like to purchase?\n (sh)ield, \n (a)rmor, \n (sw)ord, \n";
            cin >> input;

            if (input == "sw") {
                if (gold >= 15) {
                    cout << "You would like to purchase a sword? That will be 15 gold.\n\n";
                    string itemToFind = "sword";

                    for (it = shop.begin(); it != shop.end(); ++it) {
                        if (*it == itemToFind) {
                            break;
                        }

                    }
                    if (it != shop.end()) {
                        //cout << itemToFind << " is in the vector!" << endl;
                        gold -= 15;
                        inventory.push_back("sword");
                        shop.erase(it);

                    }
                    else {
                        cout << "Sold out!\n";
                    }
                }
                else {
                    cout << "Not enough gold!\n";
                }
            }
            else if (input == "sh") {
                if (gold >= 25) {
                    cout << "You would like to purchase a shield? That will be 25 gold.\n\n";
                    string itemToFind = "shield";

                    for (it = shop.begin(); it != shop.end(); ++it) {
                        if (*it == itemToFind) {
                            break;
                        }

                    }
                    if (it != shop.end()) {
                        //cout << itemToFind << " is in the vector!" << endl;
                        gold -= 25;
                        inventory.push_back("shield");
                        shop.erase(it);

                    }
                    else {
                        cout << "Sold out!\n";
                    }
                }
                else {
                    cout << "Not enough gold!\n";
                }
            }
            else if (input == "a") {
                if (gold >= 100) {
                    cout << "You would like to purchase a set of armor? That will be 100 gold.\n\n";
                    string itemToFind = "armor";

                    for (it = shop.begin(); it != shop.end(); ++it) {
                        if (*it == itemToFind) {
                            break;
                        }

                    }
                    if (it != shop.end()) {
                        //cout << itemToFind << " is in the vector!" << endl;
                        gold -= 100;
                        inventory.push_back("armor");
                        shop.erase(it);

                    }
                    else {
                        cout << "Sold out!\n";
                    }
                }
                else {
                    cout << "Not enough gold!\n";
                }
            }
            else {
                cout << input << " is not a valid option!\n";
            }

            cout << gold << " Gold remaining\n\n";
        }
        else if (intent == "s") {
            cout << "What would you like to sell?\n (sw)ord\n (sh)ield\n (a)rmor\n";
            cin >> input;
            if (input == "sw") {
                cout << "You would like to sell your sword? That will be 15 gold.\n\n";
                string itemToFind = "sword";

                for (it = inventory.begin(); it != inventory.end(); ++it) {
                    if (*it == itemToFind) {
                        break;
                    }

                }
                if (it != inventory.end()) {
                    //cout << itemToFind << " is in the vector!" << endl;
                    gold += 15;
                    shop.push_back("sword");
                    inventory.erase(it);

                }
                else {
                    cout << "you don't have a " << itemToFind << "\n";
                }
            }
            else if (input == "sh") {
                cout << "You would like to sell your shield? That will be 25 gold.\n\n";
                string itemToFind = "shield";

                for (it = inventory.begin(); it != inventory.end(); ++it) {
                    if (*it == itemToFind) {
                        break;
                    }

                }
                if (it != inventory.end()) {
                    //cout << itemToFind << " is in the vector!" << endl;
                    gold += 25;
                    shop.push_back("shield");
                    inventory.erase(it);

                }
                else {
                    cout << "you don't have a " << itemToFind << "\n";
                }
            }
            else if (input == "a") {
                cout << "You would like to sell your armor? That will be 100 gold.\n\n";
                string itemToFind = "armor";

                for (it = inventory.begin(); it != inventory.end(); ++it) {
                    if (*it == itemToFind) {
                        break;
                    }

                }
                if (it != inventory.end()) {
                    //cout << itemToFind << " is in the vector!" << endl;
                    gold += 100;
                    shop.push_back("armor");
                    inventory.erase(it);

                }
                else {
                    cout << "you don't have a set of  " << itemToFind << "\n";
                }
            }
            else {
                cout << input << " is not a valid option!\n";
            }
            //else {
            //    cout << "Invalid option!\n";
            //}
        }

    }
}