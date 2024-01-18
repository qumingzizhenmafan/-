#pragma once
#include <iostream>

class ConstRef {
public:
	ConstRef(int ii);
private:
	int i;
	const int ci;
	int& ri;

};
inline ConstRef::ConstRef(int ii) : i(ii), ci(ii), ri(i){}

class Sales_data {
public:
	//��ί�й��캯��ʹ�ö�Ӧ��ʵ�γ�ʼ����Ա
	Sales_data(std::string s, unsigned cnt, double price):
		bookNo(s) , units_sold(cnt) , revenue(cnt * price) {}
	//���๹�캯��ȫ��ί�и���һ�����캯��
	Sales_data() : Sales_data("" , 0 , 0) {}
	Sales_data(std::string s) : Sales_data(s , 0 , 0) {}
	Sales_data(std::istream &is) : Sales_data() {/* read(is , *this) */ }

private:

	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};