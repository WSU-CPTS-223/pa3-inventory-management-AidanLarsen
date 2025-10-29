#pragma once

#include <iostream>
#include <string>
#include <array>

using namespace std;

class Data
{
public:
    Data(string newId = "", string newProdName = "", string newBrand = "", string newAsin = "", string cat = "");

    void setId(string newId);
    void setProductName(string newProdName);
    void setBrand(string newBrand);
    void setCategories(string newCategories);
    void print();
    
    string getId() const;
    string getProdName() const;
    string getBrand() const;
    string getCategories() const;

    
private:
    string id;
    string productName;
    string brand;
    string asin;
    string categories;

    /*string upcEanCode;
    string listPrice;
    string sellingPrice;
    string quantity;
    string modelNumber;
    string aboutProduct;
    string productSpecs;
    string techDetails;
    string shipWeight;
    string prodDim;
    string img;
    string varients;
    string sku;
    string prodUrl;
    string stock;*/
    
};

