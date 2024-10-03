#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;
//Клас БІБЛІОТЕКА містить масив об’єктів класу КНИГА. Клас КНИГА
//містить прізвище автора, назву, видавництво, рік видання, кількість
//сторінок.Здійснити пошук книг за прізвищем автора,
//назвою, видавництвом, роком видання.

class Kniga {
private:
    string prizvyscheAvtora;
    string nazva;
    string vydavnytstvo;
    int rikVydannya;
    int kilkistStor;

public:

    Kniga(string prizvysche, string nazva, string vydavnytstvo, int rik, int stor)
        : prizvyscheAvtora(prizvysche), nazva(nazva), vydavnytstvo(vydavnytstvo), rikVydannya(rik), kilkistStor(stor) {}


    string getPrizvyscheAvtora() const { return prizvyscheAvtora; }
    string getNazva() const { return nazva; }
    string getVydavnytstvo() const { return vydavnytstvo; }
    int getRikVydannya() const { return rikVydannya; }
    int getKilkistStor() const { return kilkistStor; }


    void info() const {
        cout << "Автор: " << prizvyscheAvtora << ", Назва: " << nazva
            << ", Видавництво: " << vydavnytstvo << ", Рік видання: " << rikVydannya
            << ", Кількість сторінок: " << kilkistStor << endl;
    }
};


class Biblioteka {
private:
    vector<Kniga> knyhy;

public:
    //Клас БІБЛІОТЕКА містить масив об’єктів класу КНИГА. Клас КНИГА
//містить прізвище автора, назву, видавництво, рік видання, кількість
//сторінок.Здійснити пошук книг за прізвищем автора,
//назвою, видавництвом, роком видання.
    void dodatyKnigu(const Kniga& kniga) {
        knyhy.push_back(kniga);
    }

    void poshukZaAvtorom(const string& prizvysche) const {
        for (const auto& kniga : knyhy) {
            if (kniga.getPrizvyscheAvtora() == prizvysche) {
                kniga.info();
            }
        }
    }


    void poshukZaNazvoyu(const string& nazva) const {
        for (const auto& kniga : knyhy) {
            if (kniga.getNazva() == nazva) {
                kniga.info();
            }
        }
    }


    void poshukZaVydavnytstvom(const string& vydavnytstvo) const {
        for (const auto& kniga : knyhy) {
            if (kniga.getVydavnytstvo() == vydavnytstvo) {
                kniga.info();
            }
        }
    }


    void poshukZaRokomVydannya(int rik) const {
        for (const auto& kniga : knyhy) {
            if (kniga.getRikVydannya() == rik) {
                kniga.info();
            }
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Biblioteka biblioteka;

    // Додавання книг
    biblioteka.dodatyKnigu(Kniga("Орвелл", "1984", "Penguin Books", 1949, 328));
    biblioteka.dodatyKnigu(Kniga("Гемінґвей", "Старий і море", "Charles Scribner's Sons", 1952, 127));
    biblioteka.dodatyKnigu(Kniga("Кінг", "Сяйво", "Doubleday", 1977, 447));
    biblioteka.dodatyKnigu(Kniga("Ролінґ", "Гаррі Поттер і філософський камінь", "Bloomsbury", 1997, 223));
    biblioteka.dodatyKnigu(Kniga("Фітцджеральд", "Великий Гетсбі", "Scribner", 1925, 180));
    biblioteka.dodatyKnigu(Kniga("Бредбері", "451 градус за Фаренгейтом", "Ballantine Books", 1953, 256));
    biblioteka.dodatyKnigu(Kniga("Толкін", "Володар перснів: Братерство персня", "Allen & Unwin", 1954, 423));
    biblioteka.dodatyKnigu(Kniga("Толкін", "Володар перснів: Дві вежі", "Allen & Unwin", 1954, 352));
    biblioteka.dodatyKnigu(Kniga("Толкін", "Володар перснів: Повернення короля", "Allen & Unwin", 1955, 416));

    int choice;
    cout << "Виберіть тип пошуку:\n";
    cout << "1 - Пошук за прізвищем автора\n";
    cout << "2 - Пошук за назвою\n";
    cout << "3 - Пошук за видавництвом\n";
    cout << "4 - Пошук за роком видання\n";
    cout << "Ваш вибір: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        string prizvysche;
        cout << "Введіть прізвище автора: ";
        cin.ignore(); 
        getline(cin, prizvysche);
        biblioteka.poshukZaAvtorom(prizvysche);
        break;
    }
    case 2: {
        string nazva;
        cout << "Введіть назву книги: ";
        cin.ignore(); 
        getline(cin, nazva);
        biblioteka.poshukZaNazvoyu(nazva);
        break;
    }
    case 3: {
        string vydavnytstvo;
        cout << "Введіть назву видавництва: ";
        cin.ignore();  
        getline(cin, vydavnytstvo);
        biblioteka.poshukZaVydavnytstvom(vydavnytstvo);
        break;
    }
    case 4: {
        int rik;
        cout << "Введіть рік видання: ";
        cin >> rik;
        biblioteka.poshukZaRokomVydannya(rik);
        break;
    }
    default:
        cout << "Невірний вибір!" << endl;
    }

    return 0;
}
