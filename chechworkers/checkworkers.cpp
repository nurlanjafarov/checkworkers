#include <iostream>
#include "models.h"
using namespace std;
void m_strcpy(char* hara, const char* haradan) {
    int i = 0;
    while (haradan[i] != '\0') {
        hara[i] = haradan[i];
        i++;
    }
    hara[i] = '\0';
}
void showWorkers(Worker* isciler, size_t say) {
    for (size_t i = 0; i < say; i++) {
        cout << "ID: " << isciler[i].id
            << " | " << isciler[i].name << " " << isciler[i].surname
            << " | Yas: " << isciler[i].age
            << " | Sheher: " << isciler[i].city
            << " | Maas: " << isciler[i].salary
            << " | Tel: " << isciler[i].phone << endl;
    }
}

Worker* createWorkers(size_t say) {
    const char* adlar[]     = { "Nuray", "Medine", "Ismayil", "Nermin", "Tural", "Aytac", "Kamran", "Leyla" };
    const char* soyadlar[]  = { "Quliyev", "Adigozelli", "Kerimova", "Eliyeva", "Mammadov", "Hasanov", "Rzayev", "Babayev" };
    const char* sheherler[] = { "Baki", "Gence", "Sumqayit", "Lankaran", "Mingechevir", "Naxcivan" };
    const char* prefiksler[]= { "+99450", "+99451", "+99455", "+99470", "+99477" };

    Worker* yeniIsciler = new Worker[say];

    for (size_t i = 0; i < say; i++) {
        yeniIsciler[i].id = i + 1;
        m_strcpy(yeniIsciler[i].name,    adlar[rand() % 8]);
        m_strcpy(yeniIsciler[i].surname, soyadlar[rand() % 8]);
        m_strcpy(yeniIsciler[i].city,    sheherler[rand() % 6]);
        yeniIsciler[i].age    = 18 + rand() % 23;       // 18-40
        yeniIsciler[i].salary = 800 + rand() % 2201;    // 800-3000

        char tel[20];
        m_strcpy(tel, prefiksler[rand() % 5]);
        for (int j = 6; j < 13; j++) {
            tel[j] = '0' + rand() % 10;
        }
        tel[13] = '\0';
        m_strcpy(yeniIsciler[i].phone, tel);
    }

    return yeniIsciler;
}

Company* createCompany(Worker* isciler, size_t say) {
    Company* c = new Company;
    c->id = rand() % 100;
    m_strcpy(c->name, "Omega & Go ");
    m_strcpy(c->address, "Cellabad kucesi 92");
    c->workers = isciler;
    c->size = say;
    return c;
}

void salaryGreaterThan(Worker* isciler, size_t say, float limitMaas) {
    cout << "\nMaas " << limitMaas << "-dan cox olanlar\n";
    for (size_t i = 0; i < say; i++) {
        if (isciler[i].salary >= limitMaas) {
            cout << isciler[i].name << " " << isciler[i].surname
                << " - " << isciler[i].salary << endl;
        }
    }
}
void checkNarPhoneNumber(Worker* isciler, size_t say) {
    cout << "\nNar nomre istifadecileri:\n";
    for (size_t i = 0; i < say; i++) {
        if (strstr(isciler[i].phone, "+99470") != NULL ||
            strstr(isciler[i].phone, "+99477") != NULL) {
            cout << isciler[i].name << ": " << isciler[i].phone << endl;
        }
    }
}

int main() {
    srand(time(0));
    size_t isciSayi = 5;
    Worker* butunIsciler = createWorkers(isciSayi);
    Company* sirket = createCompany(butunIsciler, isciSayi);
    cout << "Sirket: " << sirket->name << "\nUnvan: " << sirket->address << "\n\n";
    showWorkers(sirket->workers, sirket->size);
    salaryGreaterThan(butunIsciler, isciSayi, 1300);
    checkNarPhoneNumber(butunIsciler, isciSayi);
    delete[] butunIsciler;
    delete sirket;
    return 0;
}
