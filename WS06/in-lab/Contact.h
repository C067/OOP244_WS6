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
		//Destructor
		~Contact();
		//Member Functions
		bool isEmpty() const;
		void display() const;
		void SES(); 
	};
}






#endif // !CONTACT_H
