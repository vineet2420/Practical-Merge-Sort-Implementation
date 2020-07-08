#ifndef STUDENT_H
#define STUDENT_H

#include <string>
//not a good idea to use namespace, would be forcing namesapce on everything else
class Student{

	public:
		//default construtor declared
		Student();

		char getRandomName(void);//random character generator to push unique student objects

		//declaring the explicit value constructor
		Student(std::string name, int id);

		//inline functions
		void setName(std::string name){
			m_name = name;

		}

		std::string getName() const {
			return m_name;
		}

		void setId(int id){
			m_id = id;
			//cout<<"id is set!"<<endl;
		}

		int getId() const {
			return m_id;
		}




//const Student & operator=(const Student & rightHandSide);



	private:
		//data members
		int m_id;
		std::string m_name;


};

#endif
