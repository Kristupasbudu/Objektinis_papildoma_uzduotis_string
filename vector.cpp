#include "Mylib.h"

struct studentas
{
    string vardas, pavarde;
    vector<int> paz;
    double egz;
    double sum = 0;
    double gal;
    double med;
};

void pild(studentas &temp)
{
    cout << "Iveskite varda ir pavarde: ";
    cin >> temp.vardas >> temp.pavarde;
    // Paklausiama vartotojo ar jis nori pats suvesti duomenis ar atsitiktinius
    char ats;
    cout << "Ar norite uzpildyti namu darbu ir egzamino pazymius rankiniu budu? (y/n)";
    cin >> ats;
    if (ats == 'n' || ats == 'N')
    {
        int num_pazymiai = rand() % 11; 
        for (int i = 0; i < num_pazymiai; i++)
        {
            temp.paz.push_back(rand() % 11); //atsitiktiniai namu darbu pazymiai
        }
        temp.egz = rand() % 11;  // atsitiktinis egzamino pazymys
    }
    else
    {
        // Ivedimas ir tikrinimas namu darbu pazymiu
        bool valid_input = false;
        while (!valid_input)
        {
            cout << "Iveskite namu darbu pazymius (paspasukite '.' baigti ): ";
            string input;
            while (cin >> input && input != ".")
            {
                try //tikrinamas ivestas nd simbolis yra skaicius
                {
                    int x = stoi(input);
                    if (x >= 0 && x <= 10) //tikrinimas ar nd skaicius yra [0;10]
                    {
                        temp.paz.push_back(x);
                    }
                    else
                    {
                        cout << "Klaida: reiksmes turi buti [0;10]." << endl;
                    }
                }
                catch (const exception &e) 
                {
                    cout << "Klaida: bandykite dar karta su skaiciais is intervalo [0;10]." << endl;
                }
            }
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (temp.paz.size() > 0)
            {
                valid_input = true;
            }
            else
            {
                cout << "Klaida: neivestas nei vienas pazymys" << endl;
            }
        }
        // tikrinamas egzamino pazymiu ivedimas
        bool egz_valid_input = false;
        while (!egz_valid_input)
        {
            cout << "Iveskite egzamino paz. ";
            string egz_input;
            cin >> egz_input;
            try //tikrinamas ar egzamino simbolis yra skaicius
            {
                int egz = stoi(egz_input);
                if (egz >= 0 && egz <= 10) //tikrinimas ar egzamino skaicius yra [0;10]
                {
                    temp.egz = egz;
                    egz_valid_input = true;
                }
                else
                {
                    cout << "Klaida: reiksmes turi buti [0;10]." << endl;
                }
            }
            catch (const exception &e)
            {
                cout << "Klaida: bandykite dar karta su skaiciais is intervalo [0;10]." << endl;
            }
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void spausd(studentas &temp)
{
    cout << setw(15) << temp.vardas << setw(15) << temp.pavarde; // surenkamas vardas, pavarde
    for (int i = 0; i < temp.paz.size(); i++)                    // suskaiciuojama pazymiu suma
    {
        temp.sum += temp.paz.at(i);
    }
    temp.gal = 0.4 * (temp.sum / temp.paz.size()) + 0.6 * temp.egz; // skaiciuojamas galutinis vidurkis
    // skaiciuoma galutine mediana
    sort(temp.paz.begin(), temp.paz.end());
    int n = temp.paz.size();
    if (n % 2 == 0)
    {
        int middle = n / 2;
        temp.med = 0.4 * ((temp.paz[middle - 1] + temp.paz[middle]) / 2.0) + 0.6 * temp.egz;
    }
    else
    {
        temp.med = 0.4 * (temp.paz[n / 2]) + 0.6 * temp.egz;
    }
    // isvedimas
    cout << left << fixed << setprecision(2) << setw(20) << temp.gal << left << setw(20) << temp.med << endl;
}

int main()
{
    vector<studentas> mas;
    studentas tempas;
    char uzkl = 'n';
    do
    {
        pild(tempas);
        mas.push_back(tempas);
        tempas.paz.clear();
        cout << "Baigti darba spauskite n, testi - bet koks klavisas";
        cin >> uzkl;
    } while (uzkl != 'n' && uzkl != 'N');    // Vartotojo uzklausa ar nori isvesti ivestus duomenis
    cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    for (auto &i : mas)
        spausd(i);
    for (auto &i : mas)
        i.paz.clear();
    mas.clear();
}
