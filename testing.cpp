#include "vektorius.h"

int main()
{
    Vektorius<int> vector;

    cout << "----------------------------------------------------------------------------" << endl;
    cout << "Testuojama vektoriaus klase:\n"
         << endl;

    vector.push_back(10);
    vector.push_back(20);
    vector.push_back(30);
    vector.push_back(40);

    cout << "1.   Pries reserve(20) panaudojima: " << vector.capacity() << endl;
    vector.reserve(20);
    cout << "     Po reserve(20) panaudojima: " << vector.capacity() << endl;
    cout << "---" << endl;

    cout << "2.   Pries shrink_to_fit panaudojima: " << vector.capacity() << endl;
    vector.shrink_to_fit();
    cout << "     Po shrink_to_fit panaudojima: " << vector.capacity() << endl;
    cout << "---" << endl;

    cout << "Vektoriu sudaro: ";
    for (const auto &value : vector)
    {
        cout << value << " ";
    }
    cout << endl;
    cout << "---" << endl;

    cout << "3.   Ar vektorius yra tuscias? " << (vector.empty() ? "Taip" : "Ne") << endl;
    cout << "---" << endl;

    auto it = vector.begin(); // Iterator pointing to the third element
    vector.erase(it);
    cout << "4.   Vektoriu sudaro po erase(): ";
    for (int a = 0; a < vector.size(); a++)
        printf("%i ", vector[a]);
    cout << "\n---" << endl;

    vector.pop_back();
    cout << "5.   Vektoriu sudaro po pop_back(): ";
    for (int a = 0; a < vector.size(); a++)
        printf("%i ", vector[a]);

    cout << "\n----------------------------------------------------------------------------\n"
         << endl;

    std::vector<int> std_vektorius;

    cout << "Testuojama std::vector \n"
         << endl;

    std_vektorius.push_back(10);
    std_vektorius.push_back(20);
    std_vektorius.push_back(30);
    std_vektorius.push_back(40);

    cout << "1.   Pries reserve(20) panaudojima: " << std_vektorius.capacity() << endl;
    std_vektorius.reserve(20);
    cout << "     Po reserve(20) panaudojima: " << std_vektorius.capacity() << endl;
    cout << "---" << endl;

    cout << "2.   Pries shrink_to_fit panaudojima: " << std_vektorius.capacity() << endl;
    std_vektorius.shrink_to_fit();
    cout << "     Po shrink_to_fit panaudojima: " << std_vektorius.capacity() << endl;
    cout << "---" << endl;

    cout << "Vektoriu sudaro: ";
    for (const auto &value : std_vektorius)
    {
        cout << value << " ";
    }
    cout << endl;
    cout << "---" << endl;

    cout << "3.   Ar vektorius yra tuscias? " << (std_vektorius.empty() ? "Taip" : "Ne") << endl;
    cout << "---" << endl;

    std_vektorius.erase(std_vektorius.begin());
    printf("4.    Vektoriu sudaro po erase():");
    for (int a:std_vektorius) printf("%i ", a);
    cout<<endl;
    cout << "---" << endl;

    std_vektorius.pop_back();
    cout << "5.   Vektoriu sudaro po pop_back(): ";
    for (int a = 0; a < std_vektorius.size(); a++)
        printf("%i ", std_vektorius[a]);

    return 0;
}
