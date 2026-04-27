#pragma once
#pragma warning(disable: 4996)
#include <iostream>
using namespace std;

struct Worker {
    int id;
    char name[50];
    char surname[50];
    int age;
    char city[50];
    char phone[50];
    float salary;
};
struct Company {
    int id;
    char name[100];
    char address[100];
    Worker* workers;
    size_t size;
};
void m_strcpy(char* hara, const char* haradan);
Worker* createWorkers(size_t say);
Company* createCompany(Worker* isciler, size_t say);
void showWorkers(Worker* isciler, size_t say);
void salaryGreaterThan(Worker* isciler, size_t say, float limitMaas);
void checkNarPhoneNumber(Worker* isciler, size_t say);
