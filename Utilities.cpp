// Name:  Kenneth Yue
// Seneca Student ID: 127932176
// Seneca email:  kyue3@myseneca.ca
// Date of completion: Nov 2, 2018
//
// I confirm that the content of this file is created by me,
// with exception of the parts provided to me by my professor

// Workshop 8 - Smart Pointers
// Utilities.cpp
#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace w8
{
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		// Student Portion
		// builds a list of products using raw pointers
		for (size_t i = 0; i < desc.size(); ++i) {
			for (size_t j = 0; j < price.size(); ++j) {
				if (desc[i].code == price[j].code) {
					Product* newptr = new Product(desc[i].desc, price[j].price);
					newptr->validate();
					priceList += newptr;
					delete newptr;
					newptr = nullptr;
					break;
				}
			}
		} // end of Student Portion

		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		// Student Portion
		// Buids a list of products using smart pointers
		for (size_t i = 0; i < desc.size(); ++i) {
			for (size_t j = 0; j < price.size(); ++j) {
				if (desc[i].code == price[j].code) {
					std::unique_ptr<Product> smartptr(new Product(desc[i].desc, price[j].price));
					smartptr->validate();
					priceList += smartptr;
					break;
				}
			}
		} // end of Student Portion

		return priceList;
	}
}