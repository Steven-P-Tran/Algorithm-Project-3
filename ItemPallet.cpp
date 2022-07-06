#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "ItemPallet.hpp"

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

// function to return the hash value based on the first digit
unsigned int hashfct1(unsigned int sku) {
  // TODO: implement this function, then delete the return statement below
	return sku/100000 % 10;
}

// function to return the hash value based on the second digit
unsigned int hashfct2(unsigned int sku) {
   // TODO: implement this function, then delete the return statement below
	return sku/10000 % 10;
}

// function to return the hash value based on the third digit
unsigned int hashfct3(unsigned int sku) {
   // TODO: implement this function, then delete the return statement below
	return sku/1000 % 10;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct4(unsigned int sku) {
   // TODO: implement this function, then delete the return statement below
	return sku/100 % 10;
}

// function to return the hash value based on the fifth digit
unsigned int hashfct5(unsigned int sku) {
    // TODO: implement this function, then delete the return statement below
	return sku/10 % 10;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct6(unsigned int sku) {
    // TODO: implement this function, then delete the return statement below
	return sku/1 % 10;
}

// Constructor for struct Item
Item::Item(string itemName, unsigned int sku):itemName_(itemName), sku_(sku)
{};

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void ItemPallet::readTextfile(string filename) {
  ifstream myfile(filename);

  if (myfile.is_open()) {
    cout << "Successfully opened file " << filename << endl;
    string itemName;
    unsigned int sku;
    while (myfile >> itemName >> sku) {
			if (itemName.size() > 0)
      	addItem(itemName, sku);
    }
    myfile.close();
  }
  else
    throw std::invalid_argument("Could not open file " + filename);
}

void ItemPallet::addItem(string itemName, unsigned int sku) {
  // TO BE COMPLETED
  // function that adds the specified SKU to the pallet (i.e., to all hash tables)

  hT1[itemName, sku];
  hT2[itemName, sku];
  hT3[itemName, sku];
  hT4[itemName, sku];
  hT5[itemName, sku];
  hT6[itemName, sku];
    
}

bool ItemPallet::removeItem(unsigned int sku) {
   // TODO: implement this function, then delete the return statement below

  // function that removes the pair of glasses specified by the sku from the display
  // if pair is found, then it is removed and the function returns true
  // else returns false

  hT1.erase(sku);
  hT2.erase(sku);
  hT3.erase(sku);
  hT4.erase(sku);
  hT5.erase(sku);
  hT6.erase(sku);
  
    return true;
}

unsigned int ItemPallet::bestHashing() {

  unsigned int balance[6];
	

  int minloc = hT1.bucket_size(0);
  int maxloc = hT1.bucket_size(0);
  for (unsigned i=0; i<10; ++i) 
  {
    if (minloc >= hT1.bucket_size(i))
      minloc = hT1.bucket_size(i);
    if (maxloc <= hT1.bucket_size(i))
      maxloc = hT1.bucket_size(i);
  }
  balance[0] = maxloc - minloc;

  minloc = hT2.bucket_size(0);
  maxloc = hT2.bucket_size(0);
  for (unsigned i=0; i<10; ++i) 
  {
    if (minloc >= hT2.bucket_size(i))
      minloc = hT2.bucket_size(i);
    if (maxloc <= hT2.bucket_size(i))
      maxloc = hT2.bucket_size(i);
  }
  balance[1] = maxloc - minloc;

  minloc = hT3.bucket_size(0);
  maxloc = hT3.bucket_size(0);
  for (unsigned i=0; i<10; ++i) 
  {
    if (minloc >= hT3.bucket_size(i))
      minloc = hT3.bucket_size(i);
    if (maxloc <= hT3.bucket_size(i))
      maxloc = hT3.bucket_size(i);
  }
  balance[2] = maxloc - minloc;

  minloc = hT4.bucket_size(0);
  maxloc = hT4.bucket_size(0);
  for (unsigned i=0; i<10; ++i) 
  {
    if (minloc >= hT4.bucket_size(i))
      minloc = hT4.bucket_size(i);
    if (maxloc <= hT4.bucket_size(i))
      maxloc = hT4.bucket_size(i);
  }
  balance[3] = maxloc - minloc;

  minloc = hT5.bucket_size(0);
  maxloc = hT5.bucket_size(0);
  for (unsigned i=0; i<10; ++i) 
  {
    if (minloc >= hT5.bucket_size(i))
      minloc = hT5.bucket_size(i);
    if (maxloc <= hT5.bucket_size(i))
      maxloc = hT5.bucket_size(i);
  }
  balance[4] = maxloc - minloc;

  minloc = hT6.bucket_size(0);
  maxloc = hT6.bucket_size(0);
  for (unsigned i=0; i<10; ++i) 
  {
    if (minloc >= hT6.bucket_size(i))
      minloc = hT6.bucket_size(i);
    if (maxloc <= hT6.bucket_size(i))
      maxloc = hT6.bucket_size(i);
  }
  balance[5] = maxloc - minloc;

  //calculate lowest value
  int a;
  a=balance[0];	  

      for (int i = 0; i < 6; i++)
  {
    if(a > balance[i])
      a = balance[i];
  }
  for (int i=0; i<6; i++)
  {
    if (a == balance[i])
    return i+1;
  }
}

// ALREADY COMPLETED
size_t ItemPallet::size() {
    if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size())|| (hT1.size() != hT6.size()) )
  	throw std::length_error("Hash table sizes are not the same");
    
	return hT1.size();
}