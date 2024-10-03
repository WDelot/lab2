#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;
//���� ���˲����� ������ ����� �ᒺ��� ����� �����. ���� �����
//������ ������� ������, �����, �����������, �� �������, �������
//�������.�������� ����� ���� �� �������� ������,
//������, ������������, ����� �������.

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
        cout << "�����: " << prizvyscheAvtora << ", �����: " << nazva
            << ", �����������: " << vydavnytstvo << ", г� �������: " << rikVydannya
            << ", ʳ������ �������: " << kilkistStor << endl;
    }
};


class Biblioteka {
private:
    vector<Kniga> knyhy;

public:
    //���� ���˲����� ������ ����� �ᒺ��� ����� �����. ���� �����
//������ ������� ������, �����, �����������, �� �������, �������
//�������.�������� ����� ���� �� �������� ������,
//������, ������������, ����� �������.
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

    // ��������� ����
    biblioteka.dodatyKnigu(Kniga("������", "1984", "Penguin Books", 1949, 328));
    biblioteka.dodatyKnigu(Kniga("�������", "������ � ����", "Charles Scribner's Sons", 1952, 127));
    biblioteka.dodatyKnigu(Kniga("ʳ��", "�����", "Doubleday", 1977, 447));
    biblioteka.dodatyKnigu(Kniga("����", "���� ������ � ������������ �����", "Bloomsbury", 1997, 223));
    biblioteka.dodatyKnigu(Kniga("Գ����������", "������� �����", "Scribner", 1925, 180));
    biblioteka.dodatyKnigu(Kniga("�������", "451 ������ �� �����������", "Ballantine Books", 1953, 256));
    biblioteka.dodatyKnigu(Kniga("�����", "������� ������: ���������� ������", "Allen & Unwin", 1954, 423));
    biblioteka.dodatyKnigu(Kniga("�����", "������� ������: �� ���", "Allen & Unwin", 1954, 352));
    biblioteka.dodatyKnigu(Kniga("�����", "������� ������: ���������� ������", "Allen & Unwin", 1955, 416));

    int choice;
    cout << "������� ��� ������:\n";
    cout << "1 - ����� �� �������� ������\n";
    cout << "2 - ����� �� ������\n";
    cout << "3 - ����� �� ������������\n";
    cout << "4 - ����� �� ����� �������\n";
    cout << "��� ����: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        string prizvysche;
        cout << "������ ������� ������: ";
        cin.ignore(); 
        getline(cin, prizvysche);
        biblioteka.poshukZaAvtorom(prizvysche);
        break;
    }
    case 2: {
        string nazva;
        cout << "������ ����� �����: ";
        cin.ignore(); 
        getline(cin, nazva);
        biblioteka.poshukZaNazvoyu(nazva);
        break;
    }
    case 3: {
        string vydavnytstvo;
        cout << "������ ����� �����������: ";
        cin.ignore();  
        getline(cin, vydavnytstvo);
        biblioteka.poshukZaVydavnytstvom(vydavnytstvo);
        break;
    }
    case 4: {
        int rik;
        cout << "������ �� �������: ";
        cin >> rik;
        biblioteka.poshukZaRokomVydannya(rik);
        break;
    }
    default:
        cout << "������� ����!" << endl;
    }

    return 0;
}
