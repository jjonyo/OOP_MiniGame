#define _CRT_SECURE_NO_WARNINGS
#include "inf_int.h"

inf_int::inf_int()
{
	this->digits = new char[2];
	this->digits[0] = '0';		// default : 0
	this->digits[1] = '\0';
	this->length = 1;
	this->thesign = true;
}


inf_int::inf_int(int n) {
	char buf[100];
	if (n < 0) {		// 음수 처리
		this->thesign = false;
		n = -n;
	}
	else {
		this->thesign = true;
	}

	int idx = 0;
	while (n > 0) {			// 숫자를 문자열로 변환하는 과정
		buf[idx] = n % 10 + '0';

		n /= 10;
		idx++;
	}

	if (idx == 0) {	// 숫자의 절댓값이 0일 경우
		new (this) inf_int();	// 생성자 재호출...gcc에서 컴파일에러가 있다고 함. inf_int()의 경우 별개의 인스턴스가 생성됨. 
	}
	else {
		buf[idx] = '\0';

		this->digits = new char[idx + 1];
		this->length = idx;
		strcpy(this->digits, buf);
	}
}

inf_int::inf_int(const char* str)
{
	int i, j;
	//sign set
	if (str[0] == '-') {
		this->thesign = false;
	}
	else {
		this->thesign = true;
	}
	//length set
	this->length = 0;
	i = 0;
	if (this->thesign == false) //str[0]='-'
		i++; 
	while (str[i] != '\0')
	{
		if (!CheckDigit(str[i]))
		{
			this->digits = new char[2];
			this->digits[0] = '#'; // error
			this->digits[1] = '\0';
			this->length = 1;
			return;
		}
		this->length++; //증가			
		i++;
	}

	//digit set
	this->digits = new char[length + 1];

	i = 0; //i init
	if (this->thesign == false)
		i++; 

	j = length-1; //str index
	while (j >= 0) {
		digits[j] = str[i];
		i++;
		j--;
	}

	digits[length] = '\0'; //널 문자 삽입
}

inf_int::inf_int(const inf_int& a) {
	this->digits = new char[a.length + 1];
	strcpy(this->digits, a.digits);
	this->length = a.length;
	this->thesign = a.thesign;
}

inf_int::~inf_int() {
	delete digits;		// 메모리 할당 해제
}

bool inf_int::CheckDigit(char ch)
{
	if (ch < '0' || ch>'9') return false;
	else return true;
}

std::string inf_int::toString()
{
	int i;
	std::string ret="";
	if (thesign == false) {
		ret+='-';
	}

	if (length == 1)
		ret+=digits;
	else
	{
		bool firstDigitzero = true; //출력시 맨 앞에 나오는 0 제거 위한 변수
		for (i = length - 1; i >= 0; i--) {
			if (digits[i] == '0' && firstDigitzero) continue;
			ret+=digits[i];
			firstDigitzero = false;
		}
	}

	return ret;
}

void inf_int::Append(char ch)
{
	if (CheckDigit(ch))
	{
		this->digits = (char*)realloc(this->digits, this->length + 2);
		this->length += 1;
		int len = this->length;
		char temp = this->digits[len - 2];
		for (int i = len - 1; i > 0; i--)
		{
			this->digits[i] = this->digits[i - 1];
		}
		this->digits[len] = temp;
		this->digits[0] = ch;
	}
}

inf_int& inf_int::operator=(const inf_int& a)
{
	if (this->digits) {
		delete this->digits;		// 이미 문자열이 있을 경우 제거.
	}
	this->digits = new char[a.length + 1];

	strcpy(this->digits, a.digits);
	this->length = a.length;
	this->thesign = a.thesign;

	return *this;
}

bool operator==(const inf_int& a, const inf_int& b)
{
	// we assume 0 is always positive.
	if ((strcmp(a.digits, b.digits) == 0) && a.thesign == b.thesign)	// 부호가 같고, 절댓값이 일치해야함.
		return true;
	return false;
}

bool operator!=(const inf_int& a, const inf_int& b)
{
	return !operator==(a, b);
}

bool operator>(const inf_int& a, const inf_int& b)
{
	bool result; //a>b ? true:false
	int i = 0;
	if (a.thesign == b.thesign) {
		if (a.length > b.length) { 
			result = true; //a>b
		}
		else if (a.length < b.length) { 
			result = false; //a<b
		}
		else { // a.length==b.length
			if (a == b)
				return false;

			//absolute number compare
			i = a.length-1;

			while (i >= 0) {
				if (a.digits[i] > b.digits[i]) {
					result = true;
					break;
				}
				else if (a.digits[i] < b.digits[i]) {
					result = false;
					break;
				}
				else //a.digits[i] == b.digits[i]
					i--;
			}
		}
		// 둘 다 양수일 경우 절댓값 비교한 것을 그대로 return
		if (a.thesign == true)
			return result;
		// 둘 다 음수일 경우 절댓값 비교의 것을 반전하여 return
		else
			return !result;
	}
	//부호가 다를 경우, a가 양수일 경우 b는 음수, a가 음수일 경우 b는 양수이기에 a의 부호진리값을 반환
	else
	{
		return a.thesign;
	}
}

bool operator<(const inf_int& a, const inf_int& b)
{
	if (operator>(a, b) || operator==(a, b)) {
		return false;
	}
	else {
		return true;
	}
}

const inf_int operator+(const inf_int& a, const inf_int& b)
{
	inf_int c;
	unsigned int i;

	if (a.thesign == b.thesign) {	// 이항의 부호가 같을 경우 + 연산자로 연산
		for (i = 0; i < a.length; i++) {
			c.Add(a.digits[i], i + 1);
		}
		for (i = 0; i < b.length; i++) {
			c.Add(b.digits[i], i + 1);
		}

		c.thesign = a.thesign;

		return c;
	}
	else {	// 이항의 부호가 다를 경우 - 연산자로 연산
		if (a.thesign == true) // a : positive, b : negative
		{
			c = b;
			c.thesign = a.thesign;
			return a - c;
		}
		else // a : negaive, b : positive
		{
			c = a;
			c.thesign = b.thesign;
			return b - c;
		}
		
	}
}


const inf_int operator-(const inf_int& a, const inf_int& b)
{
	inf_int c;
	unsigned int i;
	inf_int tempA, tempB;

	if (a.thesign == b.thesign) {
		tempA = a; tempA.thesign = true; 
		tempB = b; tempB.thesign = true; 
		//|a|<|b|
		if (tempA < tempB) {
			//c.digits=b.digits
			for (i = 0; i < b.length; i++) {
				c.Add(b.digits[i], i + 1);
			}
			//c.digits[i]- a.digits[i]
			for (i = 0; i < a.length; i++) {
				c.Sub(a.digits[i], i); 
			}
			c.thesign = false;
		}
		//|a|>=|b|
		else {
			//c.digits=a.digits
			for (i = 0; i < a.length; i++) {
				c.Add(a.digits[i], i + 1);
			}
			//c.digits[i]- b.digits[i]
			for (i = 0; i < b.length; i++) {
				c.Sub(b.digits[i], i); 
			}
			c.thesign = true;
		}

		return c;
	}
	else {
		c = b;
		c.thesign = a.thesign; //|b|

		return a + c;
	}
}

const inf_int operator*(const inf_int& a, const inf_int& b)
{
	inf_int c;
	inf_int temp;

	int pow = 0;
	for (unsigned int i = 0; i < b.length; i++)
	{
		temp = a;
		temp.Mult(b.digits[i]);
		for (int i = 0; i < pow; i++)
		{
			temp.Append('0');
		}
		pow++;
		c = c + temp;
	}

	if (a.thesign == b.thesign)
		c.thesign = true;
	else
		c.thesign = false;

	return c;
}

std::ostream& operator<<(std::ostream& out, const inf_int& a)
{
	int i;

	if (a.thesign == false) {
		out << '-';
	}

	if (a.length == 1)
		out << a.digits;
	else
	{
		bool firstDigitzero = true; //출력시 맨 앞에 나오는 0 제거 위한 변수
		for (i = a.length - 1; i >= 0; i--) {
			if (a.digits[i] == '0' && firstDigitzero) continue;
			out << a.digits[i];
			firstDigitzero = false;
		}
	}

	return out;
}

void inf_int::Add(const char num, const unsigned int index)	// a의 index 자리수에 n을 더한다. 0<=n<=9, ex) a가 391일때, Add(a, 2, 2)의 결과는 411
{
	/*메모리 할당*/
	if (this->length < index) {
		this->digits = (char*)realloc(this->digits, index + 1); //널 문자 자리도 포함

		if (this->digits == NULL) {		// 할당 실패 예외처리
			std::cout << "Memory reallocation failed, the program will terminate.\n";

			exit(0);
		}

		this->length = index;					// 길이 지정 , a와 같음
		this->digits[this->length] = '\0';	// 마지막에 널문자 삽입
	}

	if (this->digits[index - 1] < '0') {	// 연산 전에 '0'보다 작은 아스키값인 경우 0으로 채움. 쓰여지지 않았던 새로운 자리수일 경우 발생
		this->digits[index - 1] = '0';
	}

	/*값 연산*/
	this->digits[index - 1] += num - '0';
	/*올림*/
	if (this->digits[index - 1] > '9') {	// 자리올림이 발생할 경우
		this->digits[index - 1] -= 10;	// 현재 자릿수에서 (아스키값) 10을 빼고
		Add('1', index + 1);			// 윗자리에 1을 더한다
	}
}

void inf_int::Sub(const char num, const unsigned int index) {
	if (this->digits[index] < num) {
		Sub('1', index + 1);
		this->digits[index] += 10;
	}
	this->digits[index] -= num - '0';
}

void inf_int::Mult(const char num) 
{
	int n = num - '0';
	if (n == 0)
	{
		*this = "0";
		return;
	}
	int carry = 0;
	char temp[1000];
	int idx = 0;
	for (unsigned int i = 0; i < this->length; i++)
	{
		int res = (this->digits[i] - '0') * n;

		res = res + carry;
		if (res > 10) //carry 발생
		{
			carry = res / 10;
			res %= 10;
			temp[idx++] = res +'0';
		}
		else
		{
			carry = 0;
			temp[idx++] = res+'0';
		}
	}

	if (carry != 0)
		temp[idx++] = carry + '0';

	if ((unsigned)idx > this->length) //메모리 재할당
	{
		this->digits = (char*)realloc(this->digits, this->length + 2);
		this->length = this->length + 1;
		this->digits[this->length] = '\0';
		for (unsigned int i = 0; i < this->length; i++)
		{
			this->digits[i] = temp[i];
		}
	}
	else
	{
		for (unsigned int i = 0; i < this->length; i++)
		{
			this->digits[i] = temp[i];
		}
	}

	return;
}