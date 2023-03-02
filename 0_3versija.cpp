#include "Mylib.h"

int main()
{
    char atsakymas;
    int kol = 0;
    string failas;
    studentas tempas;
    vector<studentas> mas;
    cout << "Ar norite, nuskaityti duomenis is failo '1', jei ne - bet koks klavisas ";
    cin >> atsakymas;
    if (atsakymas == '1')
    {
        do
        {
            cout << "Is kokio failo norite nuskaityti duomenis? ";
            cin >> failas;

            try
            {
                std::ifstream input_file(failas);
                if (!input_file.good())
                {
                    throw std::runtime_error("Failas " + failas + " neegzistuoja. Bandykite dar karta parasyti failo pavadinima.");
                }
                input_file.seekg(0, std::ios::end);
                if (input_file.tellg() == 0)
                {
                    throw std::runtime_error("Failas " + failas + " yra tuscias.Bandykite dar karta parasyti failo pavadinima.");
                }
                input_file.seekg(0, std::ios::beg);

                bufer_nusk(failas, mas);
                kol = 1;
            }
            catch (const exception &e)
            {
                std::cerr << e.what() << endl;
            }

            std::sort(mas.begin(), mas.end(), [](const studentas &a, const studentas &b) //sortas
                      { return a.vardas < b.vardas; });

            std::ofstream output_file("kursiokai_isvedimas2.txt");
            output_file << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
            for (const auto &s : mas)
            {
                output_file << left << setw(15) << s.vardas << setw(15) << s.pavarde << fixed << setprecision(2) << setw(20) << s.gal << setprecision(2) << setw(20) << s.med << endl;
            }
            output_file.close();

        } while (kol != 1);
    }
    else
    {
        char uzkl = 'n';
        do
        {
            pild(tempas);
            mas.push_back(tempas);
            tempas.paz.clear();
            cout << "Baigti darba spauskite n, testi - bet koks klavisas";
            cin >> uzkl;
        } while (uzkl != 'n' && uzkl != 'N'); // Vartotojo uzklausa ar nori isvesti ivestus duomenis
        cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        for (auto &i : mas)
            spausd(i);
        for (auto &i : mas)
            i.paz.clear();
        mas.clear();
    }
    return 0;
}
