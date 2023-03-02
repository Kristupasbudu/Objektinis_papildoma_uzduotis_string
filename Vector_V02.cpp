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
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(0, 10);
        for (int i = 0; i < 10; i++)
        {
            temp.paz.push_back(dist(gen));
        }
        temp.egz = dist(gen);
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
                try // tikrinamas ivestas nd simbolis yra skaicius
                {
                    int x = stoi(input);
                    if (x >= 0 && x <= 10) // tikrinimas ar nd skaicius yra [0;10]
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
            try // tikrinamas ar egzamino simbolis yra skaicius
            {
                int egz = stoi(egz_input);
                if (egz >= 0 && egz <= 10) // tikrinimas ar egzamino skaicius yra [0;10]
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

void bufer_nusk(string read_vardas, vector<studentas> &mas)
{
    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)

    std::stringstream my_buffer;
    std::ifstream input_file(read_vardas);
    if (!input_file.is_open())
    {
        throw std::runtime_error("Nepavyko atidaryti failo");
    }
    my_buffer << input_file.rdbuf();
    input_file.close();

    string line;
    getline(my_buffer, line);
    std::istringstream iss(line);
    int num_strings = std::count_if(std::istream_iterator<std::string>(iss),
                                    std::istream_iterator<std::string>(),
                                    [](const std::string &str)
                                    { return std::any_of(str.begin(), str.end(), [](char c)
                                                         { return !isspace(c); }); });

    while (getline(my_buffer, line))
    {
        std::istringstream iss(line);
        studentas tempas;

        iss >> tempas.vardas >> tempas.pavarde;

        for (int i = 0; i < num_strings - 3; i++)
        {
            int paz;
            iss >> paz;
            tempas.paz.push_back(paz);
        }
        tempas.sum = accumulate(tempas.paz.begin(), tempas.paz.end(), 0);

        iss >> tempas.egz;

        // galutinis balas
        double n = tempas.paz.size();
        tempas.gal = tempas.sum / n * 0.4 + tempas.egz * 0.6;

        //  mediana
        sort(tempas.paz.begin(), tempas.paz.end());
        if ((int)n % 2 == 0)
        {
            int middle = n / 2;
            tempas.med = 0.4 * ((tempas.paz[middle - 1] + tempas.paz[middle]) / 2.0) + 0.6 * tempas.egz;
        }
        else
        {
            tempas.med = 0.4 * (tempas.paz[n / 2]) + 0.6 * tempas.egz;
        }

        mas.push_back(tempas);
    }
    auto end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    cout << "Prog trukme: " << diff.count() << endl;
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
