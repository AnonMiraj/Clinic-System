#pragma once
#include "Medcin.h"
class Stock
{
private:
	int c_MedcinList;
	Medcin* MedcinList;

public:
	void addMedcinInStock();
	void editMedcin();
	void deleteMecinFromStock();
	int getQuntitiy(int id);  // This Funcion return -1 if This Qntitiy Not Exist
	int SearchId(int id);   // This Function return index if found and return -1 if Not Exist 

	friend ostream& operator<<(ostream& out, const Stock& stock);
};
