#include <iostream>
#include <stack>
#include "inventory.h"
#include <string>

using namespace std;




int main() {

    int serial,lotNum ;
    string manufactDate;
    StoreItem storeItem1;
    char menuOption;

    Inventory item1;

    cout << "Welcome to inventory management!" << endl;



    do {

        cout << "Would you like to store(s) an item, remove(r) an item, or exit(e)? (s/r/e): ";
        cin >> menuOption;

        if (menuOption == 's') {
            cout << "Serial Number: ";
            cin >> serial;
            item1.setSerial(serial);

            cout << "Manufacture Date: ";
            cin >> manufactDate;
            item1.setManufactDate(manufactDate);

            cout << "Lot Number: ";
            cin >> lotNum;
            item1.setLotNum(lotNum);

            storeItem1.store(item1);
            cout << endl << "Your part has been stored in the inventory." << endl << endl;

        } else if (menuOption == 'r') {
            cout << endl << "The item you have removed is: " << endl;
            storeItem1.removeItem();
            cout << endl;
        }

    } while (menuOption != 'e');


    cout << endl << "The item(s) remaining in your inventory are: " << endl;

    storeItem1.renderFullInventory();

    cout << endl << "Thank You for choosing Inventory Management. Good Bye!" << endl;








    return 0;


}


void Inventory::setSerial(int userSerial) {
    serialNum = userSerial;
}

void Inventory::setManufactDate(string userManufactDate) {
    manufactDate = userManufactDate;
}
void Inventory::setLotNum(int userLotNum) {
    lotNum = userLotNum;
}
int Inventory::getSerialNum() {
    return serialNum;
}
string Inventory::getManufactDate() {
    return manufactDate;
}
int Inventory::getLotNum() {
    return lotNum;
}

void StoreItem::store(Inventory inventory) {
    inventoryStack.push(inventory);
}

void StoreItem::removeItem() {
    if (inventoryStack.empty()) {
        cout << "Your inventory is empty." << endl;
    } else if (!inventoryStack.empty()) {
        Inventory inventory = inventoryStack.top();
        inventoryStack.pop();

        cout << "Serial Number: " << inventory.getSerialNum() << endl;
        cout << "Manufacture Date: " << inventory.getManufactDate() << endl;
        cout << "Lot Number: " << inventory.getLotNum() << endl;
    }

}

void StoreItem::renderFullInventory() {
    if (!inventoryStack.empty()) {
        while (!inventoryStack.empty()) {
            Inventory inventory = inventoryStack.top();
            inventoryStack.pop();

            cout << endl;
            cout << "Serial Number: " << inventory.getSerialNum() << endl;
            cout << "Manufacture Date: " << inventory.getManufactDate() << endl;
            cout << "Lot Number: " << inventory.getLotNum() << endl;
        }
    } else if (inventoryStack.empty()) {
            cout << endl << "Your inventory is empty." << endl;
        }
}


