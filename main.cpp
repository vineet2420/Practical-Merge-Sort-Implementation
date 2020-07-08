#include "Student.h"
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

/*------------------*/
//overload < operator to know how to compare two students (objects)
bool operator<(const Student &sLeft, const Student &sRight){

		return sLeft.getId()<sRight.getId();
}

bool operator<=(const Student &sLeft, const Student &sRight){
		return sLeft.getId()<=sRight.getId();
}

bool operator>(const Student &sLeft, const Student &sRight) {
			return sLeft.getId()>sRight.getId();
}

bool operator>=(const Student &sLeft, const Student &sRight) {
			return sLeft.getId()>sRight.getId();
}

bool operator==(const Student &sLeft, const Student &sRight){
   return sLeft.getId()==sRight.getId() && sLeft.getName()==sRight.getName();;
}

bool operator!=(const Student &sLeft, const Student &sRight){
    return !(sLeft == sRight);
}
/*------------------*/


//overload << operator for printing objects
ostream& operator<<(ostream& out, const Student& studentObject){
	out << "Name: " <<studentObject.getName()<<" ID: "<<studentObject.getId();
  return out;
}
/*------------------*/


//display function-generic
//standard form for a function template
template <typename ElementType>
void display(vector<ElementType> &v, ostream &out){
//using an iterator to run throught the vector types

	//iteration are being done in O(n) time
	for(typename vector<ElementType>::iterator it = v.begin(); it != v.end(); ++it){
			//output the elements
			out<< *it<<endl;

	}
	out<<endl;

	//TIME COMPLEXITY:
	//The time complexity for displaying a vector is O(n) since we are iterating through each element sequentially
	//Going element by element is linear time
}
/*------------------*/


void mergeFunc(vector<Student> &smallerVals, vector<Student> &largerVals, vector<Student> &sVec, int sizeOfSmlVals, int sizeOfLrgVals){

		//set a counter for each array to know values to compare to
		int smlValsCounter  = 0;
    int lrgValsCounter = 0;
    int sVecLoopCounter = 0;


//smallerVals holds the first index value of sVec
//largerVals holds the second index value of sVec
//both vector sizes are therefore 1

//for ascending order:
    while (lrgValsCounter < sizeOfSmlVals && sVecLoopCounter < sizeOfLrgVals){
			//run when first value is < second value
			//if smallerVals vector in 0th index < largerVals vector in 0th index
			//represents the first and second values in sVec

        if (smallerVals[lrgValsCounter] < largerVals[sVecLoopCounter]) {

						//then make the first index of sVec = the smallerVals first index
						//since we just found that it is smaller than the second index
            sVec[smlValsCounter] = smallerVals[lrgValsCounter];

            lrgValsCounter++;
					//	cout<<"value of lrgValsCounter: "<<lrgValsCounter<<endl;
        }

				//otherwise the second index value is less than the first index
        else {

						//set the first index of sVec = the largerVals first index - ascedning order
						//since we just found the second index(stored in largerVals) is larger than the first
            sVec[smlValsCounter] = largerVals[sVecLoopCounter];
						//then increase the count of our vector
            sVecLoopCounter++;
        }
        smlValsCounter++;

    }

	//setting the value for when second index value is < first index value
	//we never changed lrgValsCounter, sizeOfSmlVals was initially 1 since we had the first index value of sVec stored
    while (lrgValsCounter < sizeOfSmlVals){

					//set the next index of sVec (index 1) = the smallerVals first index(0)
        sVec[smlValsCounter] = smallerVals[lrgValsCounter];
				//this was n operation, setting teh assignment
        lrgValsCounter++;
				smlValsCounter++;
    }

		//we need this again when the second value is < first value
    while (sVecLoopCounter < sizeOfLrgVals){
			//setting the value for the index of our vector = the larger value which is the second element
        sVec[smlValsCounter] = largerVals[sVecLoopCounter];
				//Time complexity for assignment operator is 1 computation
        sVecLoopCounter++;
				smlValsCounter++;
    }
		//TIME COMPLEXITY:
		//We are iterating through n items so this adds the other part of the mergeSortFunc to be O(nlog(n)) instead of just log(n): splitting part

	}
/*------------------*/



void mergeSortFunc(vector<Student> &sVec) {
			//2 computations done: asignment operator and dot operator
			int firstIndexValue = sVec[0].getId(); //obtain the value of the student vector's first ID number

			//1 computation done
			int lastIndex = sVec.size()-1;	//obtain the index of the student vector's last ID number
			//2 computations done
			int lastIndexValue = sVec[lastIndex].getId();  //obtain the value of the student vector's last ID number
			//2 computations done
			int vectorSize = sVec.size();		//know the size of the vector to determine empty or not
			//2 computations done
			int high = sVec.size()-1;
			//1 computation done
			int mid = (0 + high)/2;


			//base case
		if (vectorSize <= 1){
			return;//The elements in the student vector only contain 1 student or none,t oo small to be sorted.
			//Do nothing because we can not compare anything when we only have 1 or 0 elements
		}

		//recursive case:
			else {

			int middleOfVector = vectorSize / 2; //need to find the middle of the vector to cut in half
			int aboveMiddleOfVector = vectorSize - middleOfVector; //this portion consists of the values above the middle of the vector (upper half)

			//create a new array/vector to store the smaller values
			vector<Student> smallerVals;
			//smaller values since we are indexing below the middle of the vector that we cut in half
			for (int i = 0; i < middleOfVector; i++){
					smallerVals.push_back(sVec[i]);//push the values into the new smaller vector
			}

			//this is log n time complexity, when we continually break down the vector into smaller vectors
			mergeSortFunc(smallerVals);//performing the recursive call in the stack


			//create a new array/vector to store the higher values. like a temporary container
			vector<Student> largerVals;
			//higher values since we are indexing above the middle of the vector that we cut in half
			for (int j = 0; j < aboveMiddleOfVector; j++){
					largerVals.push_back(sVec[middleOfVector + j]);//push the values into the new smaller vector
			}
			//also log n time complexity, need to split the upper value vector as well
			mergeSortFunc(largerVals);//performing the recursive call in the stack

			//both size 1:
			int sizeOfSmlVals = smallerVals.size(); //size of the lower portion of the vector that we cut in half
			int sizeOfLrgVals = largerVals.size();	//size of the upper portion of the vector that we cut in half

			//now that we have simply cut the vector in half, need to actually perform the merging operation:
			mergeFunc(smallerVals, largerVals, sVec, sizeOfSmlVals, sizeOfLrgVals);//calling mergeFunc to compare the indexes


			//TIME COMPLEXITY:
			//When we call the mergeSortFunc recursively, we are splitting the array of elements each time which is n/2
			//this gives part of the time complexity log(n)
		}

}
/*------------------*/



//driver program
void studentMenu(){
	//vector of type student
	vector <Student> sVec;

	//1 computation
	int numOfStudents = 0;//user will define how many students they want to input
	string userGivenStudentName = "";//user will eneter the name here
	int id = 0; 	//user will give the ID number here


	string studRandName = ""; //empty string to insert the unique characters and then push that as objects of the Student class


	string usrMenuOptionStr = ""; //user option to select from given menu

	cout<<endl;



	cout<<"Welcome to the student creator program. \n Enter \"ctrl + c\" to exit anytime. Here are the menu options: \n Enter \"add\", \"sort\" or \"print\" for the corresponding options."<<endl;

	cout<<"1. Add student. "<<endl;
	cout<<"2. Sort the list of students with merge sort. "<<endl;
	cout<<"3. Display all students. "<<endl;

	//condition will always be true unless program ended by user ctrl + c
	while(true){

		cout<<endl;//add a space

		cout<<"Please choose an option: "<<endl;
		cin>> usrMenuOptionStr; //retrieve the task that the user wants

		cout<<endl;
		//condition to add student into the vector
		if(usrMenuOptionStr == "add" || usrMenuOptionStr == "ADD"){

				cout<<"Enter number of students: "<<endl;
				cin>>numOfStudents; //know how many times we need to ask the user for a student to push into the vector

				for(int i =0; i<numOfStudents; i++){
					Student studName;// student object

					srand(time(0));	//set random time = 0;
					for(unsigned int i = 0; i < 5; ++i){
							//studRandName is the empty string we set before. This will be our new student object
							studRandName += studName.getRandomName();
							//generated studName object so i can retrieve the getRandom() function from the Student class
					 }

					//cout<<"Student Name = "<<studRandName<<endl; //test case to see if random strings are being generated

						Student studRandName; //Student object created that is unique from other objects


						cout<<"Enter a student's name: "<<endl;
						cin>>userGivenStudentName; //retrieve the student's name from the user. will use setName() in the constructor
						cout<<"Enter a student's ID number: "<<endl;
						cin>>id; //retrieve the student's name from the user. will use setId() in the constructor


						studRandName.setName(userGivenStudentName); //use the inline setName() function
						studRandName.setId(id);			//use the inline getName() function

						//Student studRandName(userGivenStudentName,id);	//cretae the student object with the explicit value constructor

						sVec.push_back(studRandName);	//push the student into the vector

						//TIME COMPLEXITY:
						//The time complexity for the vector add function is O(1) since a vector is built from a dynamic array
						//This is constant time because most of the time we are just adding an element to the array.
						//in the worst case this will be O(n) if we need to reallocate memory

				}

		}


		//sort option created to know if we should run the SAME mergeSortFunc with parameter 0 for ascending or 1 for descending
		int sortOption = 0;
		//condition to add student into the vector
		if(usrMenuOptionStr == "sort" || usrMenuOptionStr == "SORT"){
			cout<<"Would you like to (1)sort ascending or (2)descending?"<<endl;
			cin>>sortOption;//retrieve the user's option to perform

				if(sortOption == 1){
					//we are sending in parameter 0 which is a temporary parameter. Allows the function to determine ascedning or descending code to run
					mergeSortFunc(sVec);
				}
				else{
					//to output descending order: just need to apply merge sort for ascending order
					mergeSortFunc(sVec);
					//then print out the output in reverse order
					reverse(sVec.begin(),sVec.end());//Not an STL sort function so we can use "reverse"
				}
		}



		//condition to perform the display option
		if(usrMenuOptionStr == "print" || usrMenuOptionStr == "PRINT"){
			//call on the display function which calls on the overload "<<" operators and uses iterators to sift through the elements
			//give an error if empty vector, but do not crash the program so the user can add students
			if(sVec.empty()){
				cout<<"error: no students added"<<endl;
			}
			else{
				cout<<"Displaying all students: "<<endl;
				display(sVec,cout);
				//cout<<"Vector size after push: "<<sVec.size()<<endl;
			}
		}

		cout<<endl;
	}//bracket for while(true) condition

}



int main(){

	//call the function that displays all the operations of the program
	studentMenu();



	return 0;
}
