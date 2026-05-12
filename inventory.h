#ifndef CIS_242_ASSIGNMENTS_OFFICIAL_INVENTORY_H
#define CIS_242_ASSIGNMENTS_OFFICIAL_INVENTORY_H


#include <string>
#include <stack>
using namespace std;

class Inventory {
    private:
        int  serialNum;
        string manufactDate;
        int lotNum;
    public:
        Inventory() {
            serialNum = 0;
            manufactDate = " ";
            lotNum = 0;
        };

        void setSerial(int userSerial);
        void setManufactDate(string userManufactDate);
        void setLotNum(int userLotNum);
        int getSerialNum();
        string getManufactDate();
        int getLotNum();

};

class StoreItem {
    private:
         stack<Inventory> inventoryStack;
    public:
        void store(Inventory inventory);
        void removeItem();
        void renderFullInventory();
};











#endif //CIS_242_ASSIGNMENTS_OFFICIAL_INVENTORY_H
