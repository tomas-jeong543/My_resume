#pragma once
#include <iostream>
using namespace std;

class Cat {
public:
	Cat() {
		cout << "Cat Constructor ... \n";
	}

	~Cat() {
		cout << "Cat Distructor ... \n";
	};

	Cat(Cat&) {
		cout << "simple Cat constructor ... \n";
	}

};

Cat Function_One(Cat theCat);
Cat* Function_Two(Cat* theCat);