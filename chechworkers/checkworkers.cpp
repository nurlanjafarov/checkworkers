#include <iostream>
#include "models.h"

using namespace std;

void strCopy(char* dst, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

Employee* buildStaff(size_t count) {
    Employee* staff = new Employee[count];

    staff[0].kod = 1;
    strCopy(staff[0].ad, "Kamran");
    strCopy(staff[0].soyad, "Bagirov");
    staff[0].yas = 30;
    staff[0].maas = 2300;
    strCopy(staff[0].nomre, "+994709871234");

    staff[1].kod = 2;
    strCopy(staff[1].ad, "Sevinc");
    strCopy(staff[1].soyad, "Mustafayeva");
    staff[1].yas = 25;
    staff[1].maas = 1650;
    strCopy(staff[1].nomre, "+994559182345");

    staff[2].kod = 3;
    strCopy(staff[2].ad, "Orxan");
    strCopy(staff[2].soyad, "Ibrahimov");
    staff[2].yas = 33;
    staff[2].maas = 2750;
    strCopy(staff[2].nomre, "+994779293456");

    staff[3].kod = 4;
    strCopy(staff[3].ad, "Gulnar");
    strCopy(staff[3].soyad, "Nasibova");
    staff[3].yas = 27;
    staff[3].maas = 1500;
    strCopy(staff[3].nomre, "+994509384567");

    staff[4].kod = 5;
    strCopy(staff[4].ad, "Ruslan");
    strCopy(staff[4].soyad, "Ceferov");
    staff[4].yas = 29;
    staff[4].maas = 2050;
    strCopy(staff[4].nomre, "+994709475678");

    return staff;
}

Muessise* buildCompany(Employee* staff, size_t count) {
    Muessise* comp = new Muessise;
    comp->kod = rand() % 100;
    strCopy(comp->ad, "Absheron Solutions");
    strCopy(comp->unvan, "Hasan Aliyev 45");
    comp->heyat = staff;
    comp->sayi = count;
    return comp;
}

void printStaff(Employee* staff, size_t count) {
    for (size_t i = 0; i < count; i++) {
        cout << "Kod: " << staff[i].kod << " | " << staff[i].ad << " " << staff[i].soyad
            << " | Maas: " << staff[i].maas << " | Tel: " << staff[i].nomre << endl;
    }
}

void filterBySalary(Employee* staff, size_t count, float limit) {
    cout << "\nMaasi " << limit << "-den cox olanlar:\n";
    for (size_t i = 0; i < count; i++) {
        if (staff[i].maas >= limit) {
            cout << staff[i].ad << " " << staff[i].soyad << " - " << staff[i].maas << endl;
        }
    }
}

void filterByOperator(Employee* staff, size_t count) {
    cout << "\nNar istifadecileri:\n";
    for (size_t i = 0; i < count; i++) {
        if (strstr(staff[i].nomre, "+99470") != NULL || strstr(staff[i].nomre, "+99477") != NULL) {
            cout << staff[i].ad << ": " << staff[i].nomre << endl;
        }
    }
}

int main() {
    srand(time(0));
    size_t total = 5;

    Employee* staff = buildStaff(total);
    Muessise* comp = buildCompany(staff, total);

    cout << "Muessise: " << comp->ad << endl;
    printStaff(comp->heyat, comp->sayi);

    filterBySalary(staff, total, 1800);
    filterByOperator(staff, total);

    delete[] staff;
    delete comp;

    return 0;
}