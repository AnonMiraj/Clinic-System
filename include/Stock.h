#pragma once
#include "other.h"
#include "Medcin.h"
#include<fstream>
class Stock
{
private:
	int c_MedcinList;
	Medcin* MedcinList;

public:
	Stock();
	~Stock();
	void addMedcinInStock();
	void addMedcinInStockByFiles();
	void editMedcin();
	void deleteMecinFromStock();
	int getQuntitiy(int id);  // This Funcion return -1 if This Qntitiy Not Exist
	int SearchId(int id);   // This Function return index if found and return -1 if Not Exist 
	ifstream input;// file

	friend ostream& operator<<(ostream& out, const Stock& stock);
};
