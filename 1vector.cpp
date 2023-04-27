#include "Mylib1.h"

int main()
{
    char atsakymas;
    int kol = 0;
    string failas;
    vector<studentas> mas;
    double diff1, diff2, diff4, diff3, diff5, diff;
    cout << "Ar norite, nuskaityti duomenis is failo '1', jei ne - bet koks klavisas ";
    cin >> atsakymas;
    cout << "-------------------------------------------------------------------------------" << endl;
    if (atsakymas == '1')
    {
        do
        {
            char ats_kurti;
            bool flag = false;
            cout << "Ar norite naudoti jau esamus failus '1', sukurti faila bet koks kitas mygtukas?";
            cin >> ats_kurti;

            if (ats_kurti != '1')
            {
                cout << "Kuriamas failas: " << endl;
                gen_file(diff1);
                flag = true;
            }

            cout << "-------------------------------------------------------------------------------" << endl;
            cout << "Jusu aplanke esantys failai: " << endl;
            system("dir /b kursiokai*.txt");
            cout << "-------------------------------------------------------------------------------" << endl;
            cout << "Is kokio failo norite nuskaityti duomenis? ";
            cin >> failas;
            cout << "-------------------------------------------------------------------------------" << endl;
            cout << "Vykdoma programa..." << endl;

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
                    throw std::runtime_error("Failas " + failas + " yra tuscias. Bandykite dar karta parasyti failo pavadinima.");
                }
                input_file.seekg(0, std::ios::beg);

                bufer_nusk(failas, mas, diff2);
                kol = 1;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << endl;
            }

            string vargs_file = "vargsiukai.txt";
            string kiet_file = "kietiakai.txt";
            write_to_file(mas, vargs_file, kiet_file, diff3, diff4, diff5);

            if (flag)
            {
                cout << "Failo " + failas + " kurimo laikas: " << diff1 << " (s)" << endl;
            }
            cout << "Failo " + failas + " nuskaitymo i bufferi laikas: " << diff2 << " (s)" << endl;
            cout << "Studentu sort'as: " << diff5 << " (s)" << endl;
            cout << "Studentu grupavimas i dvi grupes: " << diff3 << " (s)" << endl;
            // cout << "Studentu i vargsiukai faila irasymo laikas: " << diff4 << " (s)" << endl;
            diff = diff2 + diff3 + diff5;
            cout << "\n Pilnas programos veikimo laikas: " << diff << " (s)" << endl;
            cout << "-------------------------------------------------------------------------------" << endl;
        } while (kol != 1);
    }
    else
    {
        char uzkl = 'n';
        studentas tempas; // create a new student object outside the loop
        do
        {
            pild(tempas);
            mas.push_back(tempas);
            cout << "Baigti darba spauskite n, testi - bet koks klavisas" << endl;
            cin >> uzkl;
        } while (uzkl != 'n' && uzkl != 'N');

        cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        // for ( auto &student : mas)
        // {
        //     print_student_info(student);
        // }
        // for (auto &student : mas)
        // {
        //     student.getPazymiai().clear();
        // }
        mas.clear();
    }
    return 0;
}