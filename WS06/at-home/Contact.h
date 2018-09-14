#ifndef CONTACT_H
#define CONTACT_H

#define MAX_LENGTH 20

namespace sict {

	class Contact {
		//Data Members
		char name[MAX_LENGTH];
		long long *phoneNumber;
		int NOP;

	public:
		//Constructors
		Contact();
		Contact(const char *n_name, long long *PN, int num);
		Contact(const Contact &contact);
		//Destructor
		~Contact();
		//Member Functions
		bool isEmpty() const;
		void display() const;
		void SES(); 
		//Operator Function
		Contact& operator+=(const long long number);
		Contact& operator=(const Contact &contact);
	};
}






#endif // !CONTACT_H
