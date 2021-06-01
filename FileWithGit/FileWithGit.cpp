// FileWithGit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

struct Shoes {
    string brand, material, color;
    float size, price;

    Shoes(string defStr = "", float defNum = 0) {
        brand = defStr;
        material = defStr;
        color = defStr;
        size = defNum;
        price = defNum;
    }
};

void enterShoeDetails(Shoes*, int);
void printShoeList(Shoes*, int);
int main()
{
    const int MAX = 5;
    struct Shoes shoe[MAX];

    enterShoeDetails(shoe, MAX);
    printShoeList(shoe, MAX);
    return 0;
}

void printShoeList(Shoes* shoe, int max) {
    for (int i = 0; i < max; i++) {
        cout << "\nShoe brand: " << shoe[i].brand  
         << "\nShoe material: " << shoe[i].material
         << "\nShoe color: " << shoe[i].color
         << "\nShoe size: " << shoe[i].size
         << "\nShoe price: " << shoe[i].price;
    }
}

void enterShoeDetails(Shoes* shoe, int max) {
    ofstream outfile;
    outfile.open("C:/Users/270115050/OneDrive - UP Education/Desktop/Lab4/member2/FilesWithGit/shoes.txt", ios::app);

    for (int i = 0; i < max; i++) {
        cout << "Enter shoe brand: ";
        cin >> shoe[i].brand;

        cout << "Enter shoe material: ";
        cin >> shoe[i].material;

        cout << "Enter shoe color: ";
        cin >> shoe[i].color;

        cout << "Enter shoe size: ";
        cin >> shoe[i].size;

        cout << "Enter shoe price: ";
        cin >> shoe[i].price;

        outfile << "\nShoe brand: " << shoe[i].brand
            << "\nShoe material: " << shoe[i].material
            << "\nShoe color: " << shoe[i].color
            << "\nShoe size: " << shoe[i].size
            << "\nShoe price: " << shoe[i].price;       
    }
    outfile.close();
}