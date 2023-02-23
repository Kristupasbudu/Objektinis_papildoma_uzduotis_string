#include "Mylib.h"

struct studentas
{
    string vardas, pavarde;
    int *paz;
    int egz;
    int track;
    double sum;
    double gal;
    double med;
};

void pild(studentas &temp)
{
    cout << "Iveskite varda ir pavarde: ";
    cin >> temp.vardas >> temp.pavarde;
    char choice;
    cout << "Ar norite ivesti duomenis ranka? (y/n): ";
    cin >> choice;
    if (choice == 'n')
    {
        // atsitiktiniu skaiciu generavimas
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(0, 10);
        int capacity = 10;
        temp.paz = new int[capacity];
        temp.track = 10;
        for (int i = 0; i < temp.track; i++)
        {
            temp.paz[i] = dist(gen);
        }
        temp.egz = dist(gen);
    }
    else
    {
        // ranka rasomi duomenys:
        int capacity = 10;
        temp.paz = new int[capacity];
        int paz_count = 0;
        cout << "Iveskite pazymius. Jei norite baigti, iveskite '.'" << endl;
        while (true)
        {
            if (paz_count == capacity)
            { // Jei masyvas yra pilnas, yra sukuriamas ndvigubai didesnis
                int *new_paz = new int[capacity * 2];
                for (int i = 0; i < capacity; i++)
                {
                    new_paz[i] = temp.paz[i];
                }
                delete[] temp.paz;
                temp.paz = new_paz;
                capacity *= 2;
            }
            string input;
            cin >> input;
            if (input == ".")
            {
                if (paz_count == 0) // patikrinama ar ivestas bent vienas namu darbas
                {
                    cout << "Prasome ivesti bent viena skaiciu. Bandykite dar karta: " << endl;
                    continue;
                }
                else
                {
                    break;
                }
            }
            try
            { // tikrinamas ivestas nd simbolis yra skaicius
                int pazymys = stoi(input);
                if (pazymys >= 0 && pazymys <= 10)
                { // tikrinimas ar nd skaicius yra [0;10]
                    temp.paz[paz_count] = pazymys;
                    paz_count++;
                }
                else
                {
                    cout << "Reiksmes turi buti intervale [0;10]." << endl;
                }
            }
            catch (const exception &e)
            {
                cout << "Bandykite dar karta su skaiciais is intervalo [0;10]." << endl;
            }
        }
        temp.track = paz_count;
        cout << "Iveskite egzamino pazymi: ";
        while (true)
        {
            string input;
            cin >> input;
            try
            { // tikrinamas ar egzamino simbolis yra skaicius
                int pazymys = stoi(input);
                if (pazymys >= 0 && pazymys <= 10)
                { // tikrinimas ar egzamino skaicius yra [0;10]
                    temp.egz = pazymys;
                    break;
                }
                else
                {
                    cout << "Reiksmes turi buti intervale [0;10]. ";
                }
            }
            catch (const exception &e)
            {
                cout << "Bandykite dar karta su skaiciais is intervalo [0;10]." << endl;
                cout << "Iveskite egzamino pazymi: ";
            }
        }
    }
}

double gal(studentas &temp)
{ // galutinis ivertinimas su vidurkiu
    double avg = 0.0;
    for (int i = 0; i < temp.track; i++)
    {
        avg += temp.paz[i];
    }
    avg /= temp.track;
    temp.gal = 0.4 * avg + 0.6 * temp.egz;
    return temp.gal;
}

double med(int paz[], int n)
{ // galutinis ivertinimas su mediana
    std::sort(paz, paz + n);
    if (n % 2 == 0)
    {
        return (paz[n / 2 - 1] + paz[n / 2]) / 2.0;
    }
    else
    {
        return paz[n / 2];
    }
}

void spausd(studentas &temp)
{
    double mediana = med(temp.paz, temp.track);
    temp.med = 0.4 * mediana + 0.6 * temp.egz;
    cout << left << setw(15) << temp.vardas << setw(15) << temp.pavarde;
    cout << fixed << setw(20) << setprecision(2) << temp.gal << setw(20) << temp.med << endl;
    delete[] temp.paz;
}

int main()
{
    studentas studentu_masyvas[1000];
    int studentu_kiekis = 0;
    string pasirinkimas;
    do
    {
        pild(studentu_masyvas[studentu_kiekis]);
        studentu_kiekis++;
        cout << "Ar norite prideti dar viena studenta? Jei taip spauskite 'y', nutraukti - bet koks klavisas. ";
        cin >> pasirinkimas;
    } while (pasirinkimas == "y" || pasirinkimas == "Y");

    cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
    cout << "-------------------------------------------------------------" << endl;
    for (int i = 0; i < studentu_kiekis; i++)
    {
        gal(studentu_masyvas[i]);
        spausd(studentu_masyvas[i]);
    }
    return 0;
}