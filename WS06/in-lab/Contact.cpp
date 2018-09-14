
#include "Contact.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace sict {

	Contact::Contact() {
		//SAFE EMPTY STATE
		for (int cnt = 0; cnt < 21; cnt++) {
			name[cnt] = '\0';
		}
		phoneNumber = nullptr;
		NOP = 0;
	}

	Contact::Contact(const char * n_name, long long *PN, int num) {
		long long tempArray[15];
		long long phoneArray[5];
		long long temp;
		int max = 15;
		int NOD = 0;

		if (n_name != nullptr) {
			strncpy(name, n_name, 20);
			NOP = 0;

			if (!isEmpty()) {

				if (PN != nullptr) {
					
					for (int cnt = 0; cnt < num; cnt++) {	
						temp = PN[cnt];
						NOD = 0;

						for (int i = 0; i < max; i++) {
							if (temp != 0) {
								tempArray[i] = temp % 10;
								temp = temp / 10;
								NOD += 1;
							}
						}

						if ( NOD == 11 ) {
							if (tempArray[10] > 0 && tempArray[9] > 0 && tempArray[6] > 0) {
								phoneArray[NOP] = PN[cnt];
								NOP += 1;
							}
							else {
								PN[cnt] = 0;
							}
						}

						else if (NOD == 12) {
							if (tempArray[11] > 0 && tempArray[10] > 0 && tempArray[9] > 0 && tempArray[6] > 0) {
								phoneArray[NOP] = PN[cnt];
								NOP += 1;
							}
							else {
								PN[cnt] = 0;
							}
						}
						else {
							PN[cnt] = 0;
						}
					}

					phoneNumber = nullptr;
					phoneNumber = new long long [NOP];

					for (int cnt = 0; cnt < NOP; cnt++) {
						phoneNumber[cnt] = phoneArray[cnt];
					}
				}
				else
				{
					phoneNumber = nullptr;
					NOD = 0;
				}
			}
			else {
				SES();
			}
		}
		else {
			SES();
		}
	}

	Contact::~Contact() {
		delete[] phoneNumber;
	}

	bool Contact::isEmpty() const {

		bool result;

		if (name[0] == '\0' || name == nullptr){
			result = true;
		}
		else {
			result = false;
		}

		return result;
	}
	
	void Contact::display() const {
		long long tempArray[12];
		long long temp;
		int NOD = 0;
		int max = 12;

		if (!isEmpty()) {
	
			//Contact's Name
			cout << name << endl;

			for (int cnt = 0; cnt < NOP; cnt++) {
				
				temp = phoneNumber[cnt];

				NOD = 0;
				for (int i = 0; i < max; i++) {
					if (temp != 0) {
						tempArray[i] = temp % 10;
						temp = temp / 10;
						NOD += 1;
					}
				}

				if (NOD == 11) {
					//Country Code
					cout << "(+" << tempArray[10] << ") ";
					//Area Code
					cout << tempArray[9] << tempArray[8] << tempArray[7];
					//Numbers
					cout << " " << tempArray[6] << tempArray[5] << tempArray[4] << "-" << tempArray[3] << tempArray[2] << tempArray[1] << tempArray[0] << endl;
				}
				else if (NOD == 12) {
					//Country Code
					cout << "(+" << tempArray[11] << tempArray[10] << ") ";
					//Area Code
					cout << tempArray[9] << tempArray[8] << tempArray[7];
					//Numbers
					cout << " " << tempArray[6] << tempArray[5] << tempArray[4] << "-" << tempArray[3] << tempArray[2] << tempArray[1] << tempArray[0] << endl;
				}

			}
		}
		else {
			cout << "Empty contact!" << endl;
		}
	}

	void Contact::SES() {
		for (int cnt = 0; cnt < 21; cnt++) {
			name[cnt] = '\0';
		}
		phoneNumber = nullptr;
		NOP = 0;
	}


}