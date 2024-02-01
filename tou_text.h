#pragma once
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct Salas_data{
    //构造函数
    Salas_data() = default;
    Salas_data(const std::string& s) : bookNo(s) {}
    Salas_data(const std::string& s , unsigned n , double p) : bookNo(s) , units_sold(n) , revenue(p* n) {}
    Salas_data(std::istream&);

    //成员函数
    std::string isbn() const { return bookNo; }
    Salas_data& combine(const Salas_data&);
    double avg_price() const;
    static int tri() { return i; }

    //数据成员
    static int i;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

};
int Salas_data::i = 10;



extern const int size = 100;


