#include "Mylib3.h"

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

void gen_file(double &diff1)
{
    int sk;
    cout << "Kiek irasu tukstanciais faile turi buti?";
    cin >> sk;

    auto start1 = std::chrono::high_resolution_clock::now();

    // Aprasomas failo headeris bufferiui
    std::ofstream out("kursiokai" + std::to_string(sk) + "k.txt");
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 10);

    std::ostringstream vard_pav_str;
    vard_pav_str << std::left << std::setw(25) << "Vardas" << std::left << std::setw(25) << "Pavarde";
    std::string vard_pav = vard_pav_str.str();

    std::ostringstream nd_str;
    for (int i = 1; i <= 15; i++)
    {
        nd_str << std::left << std::setw(9) << "ND" + std::to_string(i);
    }
    std::string nd = nd_str.str();

    std::ostringstream egz_str;
    egz_str << std::left << std::setw(9) << "Egz.";
    std::string egz = egz_str.str();

    // naudojamas stringstream'as paruosti duomenis isvedinejimui
    std::stringstream str_buff;
    str_buff << vard_pav << nd << egz << std::endl;
    for (int i = 0; i < sk * 1000; i++)
    {
        str_buff << std::left << std::setw(25) << "Vardas" + std::to_string(i + 1) << std::left << std::setw(25) << "Pavarde" + std::to_string(i + 1);
        for (int j = 0; j < 15; j++)
        {
            str_buff << std::left << std::setw(9) << dist(gen);
        }
        str_buff << std::left << std::setw(9) << dist(gen) << std::endl;
    }

    // Vienu metu is buferio perkeliamas stringas i faila
    out << str_buff.str();
    out.close();

    auto end1 = std::chrono::high_resolution_clock::now();
    diff1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() / 1000000.0;
}

void bufer_nusk(string read_vardas, list<studentas> &mas, double &diff2)
{
    auto start2 = std::chrono::high_resolution_clock::now();

    std::stringstream my_buffer;
    std::ifstream input_file(read_vardas);
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

        mas.push_back(tempas);
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    diff2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() / 1000000.0;
}

void write_to_file( list<studentas> &studentai, const string &vargs_file, const string &kiet_file, double &diff3, double &diff4, double &diff5)
{
    std::ofstream vargs(vargs_file);
    std::ofstream kiet(kiet_file);
    vargs << left << setw(15) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << endl;
    kiet << left << setw(15) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << endl;

    list<studentas> vargsiukai;
    list<studentas> kietiakai;

    // Studentu sort'as
    auto start5 = std::chrono::high_resolution_clock::now();

    studentai.sort([](const studentas &a, const studentas &b) {
        return a.gal < b.gal;
    });

    auto end5 = std::chrono::high_resolution_clock::now();
    diff5 = std::chrono::duration_cast<std::chrono::microseconds>(end5 - start5).count() / 1000000.0;

    // Studentu rusiavimas i dvi grupes
    auto start3 = std::chrono::high_resolution_clock::now();

    for (const auto &s : studentai)
    {
        if (s.gal < 5)
        {
            vargsiukai.push_back(s);
        }
        else
        {
            kietiakai.push_back(s);
        }
    }

    auto end3 = std::chrono::high_resolution_clock::now();
    diff3 = std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3).count() / 1000000.0;


    char eilut[100];
    for (const auto &s : kietiakai)
    {
        snprintf(eilut, sizeof(eilut), "%-15s%-20s%-10.2f\n", s.vardas.c_str(), s.pavarde.c_str(), s.gal);
        kiet << eilut;
    }

    // // rasymas i vargsiukai faila
    // auto start4 = std::chrono::high_resolution_clock::now();

    for (const auto &s : vargsiukai)
    {
        snprintf(eilut, sizeof(eilut), "%-15s%-20s%-10.2f\n", s.vardas.c_str(), s.pavarde.c_str(), s.gal);
        vargs << eilut;
    }

    // auto end4 = std::chrono::high_resolution_clock::now();
    // diff4 = std::chrono::duration_cast<std::chrono::microseconds>(end4 - start4).count() / 1000000.0;

    vargs.close();
    kiet.close();
}
