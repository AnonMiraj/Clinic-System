#pragma once
#include "Medcin.h"
#include <fstream>
#include <iomanip>
#include "other.h"
//#include<windows.h>
class Stock
{

private:
	int c_MedcinList;
  int MedcinListSize;
	Medcin* MedcinList;
	int* Quntitiy;
public:
	Stock();
	~Stock();

	// Setter
	void setQuantity(int Quntitiy,int index);
	void addMedcinInStock();
	void editMedcin();
	void deleteMecinFromStock();
	int getQuntitiy(int id);  /// This Funcion return -1 if This Quantity Not Exist
	int SearchId(int id);   /// This Function return index if found and return -1 if Not Exist
    int SearchIdByName(string med);
	double getSalePriceOfMedcin(int index);
    int getMedcinListCount();

	void addMedcinInStockByFiles();
    void saveInfo();

	friend ostream& operator<<(ostream& out, const Stock& stock);
};
