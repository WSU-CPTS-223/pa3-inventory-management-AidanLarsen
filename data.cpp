#include "data.hpp"

Data::Data(string newId, string newProdName, string newBrand, string newAsin, string cat)
{
    this->id = newId;
    this->productName = newProdName;
    this->brand = newBrand;
    this->asin = newAsin;
    this->categories = cat;
}

void Data::setId(string newId)
{
    this->id = newId;
}

void Data::setProductName(string newProdName)
{
    this->productName = newProdName;
}

void Data::setBrand(string newBrand)
{
    this->brand = newBrand;
}

void Data::setCategories(string newCategories)
{
    this->categories = newCategories;
}

void Data::print()
{
    cout << "ID: " << this->id << endl;
    cout << "Product: " << this->productName << endl;
    cout << "Brand: " << this->brand << endl;
    cout << "Asin: " << this->asin << endl;
    cout << "Categories: " << this->categories << endl;

}

string Data::getId() const
{
    return this->id;
}

string Data::getProdName() const
{
    return this->productName;
}

string Data::getBrand() const
{
    return this->brand;
}

string Data::getCategories() const
{
    return this->categories;
}
