#include "Mylib1.h"

void pild(studentas &temp)
{
    string vardas, pavarde;
    cout << "Iveskite varda ir pavarde: ";
    cin >> vardas >> pavarde;
    temp.setVardas(vardas);
    temp.setPavarde(pavarde);
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
            temp.getPazymiai().push_back(dist(gen));
        }
        temp.setEgzaminas(dist(gen));
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
                        temp.getPazymiai().push_back(x);
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
            if (temp.getPazymiai().size() > 0)
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
                    temp.setEgzaminas(egz);
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

void bufer_nusk(string read_vardas, vector<studentas> &mas, double &diff2)
{
    auto start2 = std::chrono::high_resolution_clock::now();

    std::stringstream my_buffer;
    std::ifstream input_file(read_vardas);
    my_buffer << input_file.rdbuf();
    input_file.close();

    string line;
    getline(my_buffer, line);
    std::istringstream iss(line);
    int num_strings = std::count_if(
        std::istream_iterator<std::string>(iss),
        std::istream_iterator<std::string>(),
        [](const std::string &str)
        { return std::any_of(str.begin(), str.end(), [](char c)
                             { return !isspace(c); }); });

    while (getline(my_buffer, line))
    {
        std::istringstream iss(line);
        studentas tempas;

        string temp_vardas, temp_pavarde;
        iss >> temp_vardas >> temp_pavarde;
        tempas.setVardas(temp_vardas);
        tempas.setPavarde(temp_pavarde);

        for (int i = 0; i < num_strings - 3; i++)
        {
            int paz;
            iss >> paz;
            tempas.getPazymiai().push_back(paz);
        }

        tempas.setSum(accumulate(tempas.getPazymiai().begin(), tempas.getPazymiai().end(), 0));

        double egz;
        iss >> egz;
        tempas.setEgzaminas(egz);

        // galutinis balas
        double n = tempas.getPazymiai().size();
        tempas.setGalutinis(tempas.getSum() / n * 0.4 + tempas.getEgzaminas() * 0.6);

        mas.push_back(tempas);
    }

    auto end2 = std::chrono::high_resolution_clock::now();
    diff2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() / 1000000.0;
}

void write_to_file(vector<studentas> &studentai, const string &vargs_file, const string &kiet_file, double &diff3, double &diff4, double &diff5)
{
    vector<studentas> vargsiukai;

    // Studentu sort'as
    auto start5 = std::chrono::high_resolution_clock::now();

    sort(studentai.begin(), studentai.end(),
         [](const studentas &a, const studentas &b)
         { return a.getGalutinis() < b.getGalutinis(); });

    auto end5 = std::chrono::high_resolution_clock::now();
    diff5 = std::chrono::duration_cast<std::chrono::microseconds>(end5 - start5).count() / 1000000.0;

    // Studentu grupavimas i dvi grupes

    auto start3 = std::chrono::high_resolution_clock::now();

    auto it = remove_if(studentai.begin(), studentai.end(), [](const studentas &s)
                        { return s.getGalutinis() < 5; });
    vargsiukai.assign(it, studentai.end());
    studentai.erase(it, studentai.end());

    auto end3 = std::chrono::high_resolution_clock::now();
    diff3 = std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3).count() / 1000000.0;
}

void print_student_info(const studentas &student)
{
    double galutinis_vidurkis = 0.4 * (student.getSum() / student.getPazymiai().size()) + 0.6 * student.getEgzaminas();
    double galutine_mediana = 0;
    vector<int> pazymiai = student.getPazymiai();
    sort(pazymiai.begin(), pazymiai.end());
    int n = pazymiai.size();
    if (n % 2 == 0)
    {
        int middle = n / 2;
        galutine_mediana = 0.4 * ((pazymiai[middle - 1] + pazymiai[middle]) / 2.0) + 0.6 * student.getEgzaminas();
    }
    else
    {
        galutine_mediana = 0.4 * pazymiai[n / 2] + 0.6 * student.getEgzaminas();
    }
    cout << setw(15) << student.getVardas() << setw(15) << student.getPavarde()
         << left << fixed << setprecision(2) << setw(20) << galutinis_vidurkis
         << left << setw(20) << galutine_mediana << endl;
}
