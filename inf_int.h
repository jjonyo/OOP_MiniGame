
#ifndef _INF_INT_H_
#define _INF_INT_H_

#include <iostream>

class inf_int
{
private:
	char* digits;
	unsigned int length;
	bool thesign;
	void Add(const char num, const unsigned int index);
	void Sub(const char num, const unsigned int index);
	void Mult(const char num);

public:
	inf_int(); // assign 0 as a default value
	inf_int(int);
	inf_int(const char*);
	inf_int(const inf_int&); // copy constructor
	~inf_int(); // destructor

	bool CheckDigit(char); 
	void Append(char);
	std::string toString();
	inf_int& operator=(const inf_int&); // assignment operator

	friend bool operator==(const inf_int&, const inf_int&);
	friend bool operator!=(const inf_int&, const inf_int&);
	friend bool operator>(const inf_int&, const inf_int&);
	friend bool operator<(const inf_int&, const inf_int&);

	friend const inf_int operator+(const inf_int&, const inf_int&);
	friend const inf_int operator-(const inf_int&, const inf_int&);
	friend const inf_int operator*(const inf_int&, const inf_int&);
	// friend inf_int operator/(const inf_int& , const inf_int&); // not required

	friend std::ostream& operator<<(std::ostream&, const inf_int&);
	// friend istream& operator>>(istream& , inf_int&);    // not required
};

#endif