#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

//implementation of the default constructor
	Student::Student(){

		setName("null");
		setId(-1);

	}


	//implementing the explicit value constructor
		Student::Student(std::string name, int id){

			m_name = name;
			m_id = id;

	}

	//implementation of the unqiue object generator
	char Student::getRandomName(void){

		const char letters [] = { "abcdefghijklmnopqrstuvwxyz"};//array of letters
		int strLen = sizeof(letters) - 1;	//retrieve size


	    return letters[rand() % strLen];//function to generate random letter combinations
	}




/*
const Student & Student::operator=(const Student & rightHandSide) {

	if (this != &rightHandSide)  {
			m_id = rightHandSide.getId();
		}
return m_id;

}
*/
