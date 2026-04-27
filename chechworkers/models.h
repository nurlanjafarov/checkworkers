#pragma once
#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>

using namespace std;

struct Employee {
    int kod;
    char ad[50];
    char soyad[50];
    int yas;
    char seher[50];
    char nomre[50];
    float maas;
};

struct Muessise {
    int kod;
    char ad[100];
    char unvan[100];
    Employee* heyat;
    size_t sayi;
};

void strCopy(char* dst, const char* src);
Employee* buildStaff(size_t count);
Muessise* buildCompany(Employee* staff, size_t count);
void printStaff(Employee* staff, size_t count);
void filterBySalary(Employee* staff, size_t count, float limit);
void filterByOperator(Employee* staff, size_t count);