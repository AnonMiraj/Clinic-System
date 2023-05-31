#pragma once
#include "Medcin.h"
#include <fstream>
#include <iomanip>
class Stock
{
private:
	int c_MedcinList;
	Medcin* MedcinList;
	int* Quntitiy;
public:
	Stock();
	~Stock();

	// Setter 
	void setQuantity(int Quntitiy,int index);
	void addMedcinInStock();
	void addMedcinInStockByFiles();
	void editMedcin();
	void deleteMecinFromStock();
	int getQuntitiy(int id);  // This Funcion return -1 if This Qntitiy Not Exist
	int SearchId(int id);   // This Function return index if found and return -1 if Not Exist 
	ifstream input;// file
	//ofstream output; // read

	friend ostream& operator<<(ostream& out, const Stock& stock);
};
