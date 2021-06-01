// FileWithGit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Shoes {
    int id;
    string brand, material, color;
    float size, price;

    Shoes(string defStr = "", float defNum = 0) {
        id = defNum;
        brand = defStr;
        material = defStr;
        color = defStr;
        size = defNum;
        price = defNum;
    }
};

void enterShoeDetails(Shoes*, int);
void printShoeList(Shoes*, int);
void searchShoe(Shoes*, int);

int main()
{
    const int MAX = 2;
    struct Shoes shoe[MAX];

    enterShoeDetails(shoe, MAX);
    printShoeList(shoe, MAX);
    searchShoe(shoe, MAX);
    return 0;
}

void printShoeList(Shoes* shoe, int max) {
    fstream infile;
    string myData;

    infile.open("C:/Users/270115050/OneDrive - UP Education/Desktop/Lab4/member1/FileWithGit/shoes.txt", ios::in);
    while (getline(infile, myData)) {
        cout << myData << endl;
    }
    infile.close();
}

void enterShoeDetails(Shoes* shoe, int max) {
    ofstream outfile;
    outfile.open("C:/Users/270115050/OneDrive - UP Education/Desktop/Lab4/member1/FileWithGit/shoes.txt", ios::app);

    for (int i = 0; i < max; i++) {
        cout << "Enter shoe id: ";
        cin >> shoe[i].id;

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

        outfile << "\nShoe id: " << shoe[i].id
            << "\nShoe brand: " << shoe[i].brand
            << "\nShoe material: " << shoe[i].material
            << "\nShoe color: " << shoe[i].color
            << "\nShoe size: " << shoe[i].size
            << "\nShoe price: " << shoe[i].price;       
    }
    outfile.close();
}

void searchShoe(Shoes* shoe, int max) {
    string shoeID, myData, srchDetail;
    bool stdFound = false;

    cout << "Search shoe by ID: ";
    cin >> shoeID;

    fstream myFile("C:/Users/270115050/OneDrive - UP Education/Desktop/Lab4/member1/FileWithGit/shoes.txt", ios::in | ios::out);

    while (getline(myFile, myData)) {
        srchDetail = myData.substr(9, 1);
        if (srchDetail == shoeID) {
            stdFound = true;
            break;
        }
    }
    myFile.close();

    if (stdFound)
        cout << "Shoe Found\n";
    else
        cout << "Shoe Not found\n";
}