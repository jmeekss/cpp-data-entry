/*
* Author:	J Meeks
* Purpose:	This program allows the user to enter employee or customer information
*		and then displays that information
*/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

//defines the person class
class Person {

	//defines variables in person as protected so they can be accessed by subclasses
	protected:
		string first;
		string last;
		string email;
	
	//declare public functions, constructors, and setters/getters
	public:
		//declare class constructor
		Person(string firstN, string lastN, string emailA){
			set_first(firstN);
			set_last(lastN);
			set_email(emailA);
		}

		//setters and getters for Person class
		void set_first(string firstN){
			first = firstN;
		}

		string get_first() const {
			return first;
		}

		void set_last(string lastN){
			last = lastN;
		} 

		string get_last() const{
			return last;
		}

		void set_email(string emailA){
			email = emailA;
		}

		string get_email() const{
			return email;
		}

		//gets string representation of the full name of a Person
		string get_full_name() const {
			return first + ' ' + last;
		}

};

//defines the Customer class that inherits the Person class
class Customer : public Person {

	//defines variable for Customer
	protected:
		string customerNum;

	//declare public functions, constructor, and setters/getters
	public:
		//constructor for Customer class
		Customer(string firstN, string lastN, string emailA, string numIn) : Person(first, last, email){
			set_first(firstN);
                        set_last(lastN);
                        set_email(emailA);
			set_customer_number(numIn);
		}

		//setters and getters for Customer CLass
		void set_customer_number(string numIn){
			customerNum = numIn;
		}

		string get_customer_number() const {
			return customerNum;
		}
};

//defines the Employee class that inherits the Person class
class Employee : public Person {

	//defines variable for Employee
        protected:
                string ssn;

	//declare public functions, constructor, and setters/getters
        public:
		//constructor for Employee class
                Employee(string firstN, string lastN, string emailA, string ssnIn) : Person(first, last, email){
                        set_first(firstN);
                        set_last(lastN);
                        set_email(emailA);
                        set_ssn(ssnIn);
                }

		//setters and getters for Employee class
                void set_ssn(string ssnIn){
                        ssn = ssnIn;
                }

                string get_ssn() const {
                        return ssn;
                }
};

char askReplay();
char askType();

int main() {
	//display program title
	cout << "Customer/Employee Data Entry\n";

	//declare variable for data entry
	string first, last, email, num, ssn;

	//loop for program body
	do {
		//ask user what type of data they're entering(c/e)
		switch(askType()){
			case 'c': //if they enter 'c' ask for required information, and then print it formatted
				cout << "\nDATA ENTRY\n" << "First name: ";
				cin >> first;
				cout << "Last name: ";
				cin >> last;
				cout << "Email: ";
				cin >> email;
				cout << "Number: ";
				cin >> num;
				{Customer newCustomer(first, last, email, num); //create customer object with entered info
				
				//print the formatted customer info
				cout << "\nCUSTOMER" << endl
					<< "Name: " << newCustomer.get_full_name() << endl
					<< "Email: " << newCustomer.get_email() << endl
					<< "Number: " << newCustomer.get_customer_number();
				}
				break;
			case 'e': //if they enter 'e' ask for required information, and then print it formatted
				cout << "\nDATA ENTRY\n" << "First name: ";
                                cin >> first;
                                cout << "Last name: ";
                                cin >> last;
                                cout << "Email: ";
                                cin >> email;
                                cout << "SSN: ";
                                cin >> ssn;
                                {Employee newEmployee(first, last, email, ssn); //create Employee object with entered info

				//print the formatted customer info
                                cout << "\nEMPLOYEE" << endl
                                        << "Name: " << newEmployee.get_full_name() << endl
                                        << "Email: " << newEmployee.get_email() << endl
                                        << "SSN: " << newEmployee.get_ssn();
				}
				break;
			default: //if they enter an invalid choice, notify them
				cout << "Invalid Selection";
		}
	//ask if they want to play again, and repeat program if so
	} while(askReplay() == 'y');

	//print ending message, and return 0 to indicate normal exit
	cout << "\nBye!\n";
	return 0;
}

//asks the user if they want to play again
char askReplay(){
        //variables for valid selection and choice user enters
        int validSelection = 0;
        char choice;

        //loops until user enters valid choice
        while(validSelection == 0){
                        //ask user for choice, and clears buffer after they enter it
                        cout << "\n\nContinue? (y/n): ";
                        cin >> choice;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        //Tells user if their choice is invalid
                        if(tolower(choice) != 'y' && tolower(choice) != 'n'){
                                cout << "Invalid selection\n\n";
                        } else {
                                return tolower(choice);
                        }
                }

        return 'n';
}

//asks the user if they want to enter customer or employee data
char askType(){
        //variables for valid selection and choice user enters
        int validSelection = 0;
        char choice;

        //loops until user enters valid choice
        while(validSelection == 0){
                        //ask user for choice, and clears buffer after they enter it
                        cout << "\nCustomer or employee? (c/e): ";
                        cin >> choice;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        //Tells user if their choice is invalid
                        if(tolower(choice) != 'c' && tolower(choice) != 'e'){
                                cout << "Invalid selection\n\n";
                        } else {
                                return tolower(choice);
                        }
                }

        return 'n';
}
