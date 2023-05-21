#include "vektorius.h"

int main()
{

    unsigned int sz = 10000; // 100000, 1000000, 10000000, 100000000
    std::vector<int> v1;

    cout << "----------------------------------------------------------------------------" << endl;

    auto start_1 = std::chrono::system_clock::now();
    for (int i = 1; i <= sz; ++i)
        v1.push_back(i);
    auto end_1 = std::chrono::system_clock::now();
    std::chrono::duration<double> diff_1 = end_1-start_1;

    cout << "\n> " << sz << " Elementu uzpildymas i std::vector: " << diff_1.count() << " sekundziu\n";

    auto start_2 = std::chrono::system_clock::now();
    Vektorius<int> v2;
    for (int i = 1; i <= sz; ++i)
        v2.push_back(i);
    auto end_2 = std::chrono::system_clock::now();
    std::chrono::duration<double> diff_2 = end_2-start_2;

    cout << "\n> " << sz << " Elementu uzpildymas i Vektorius: " << diff_2.count() << " sekundziu\n";

    cout << "----------------------------------------------------------------------------" << endl;

    v1.clear();
    v2.clear();

    // unsigned int sz = 100000000;
    // std::vector<int> v1;

    // cout << "----------------------------------------------------------------------------" << endl;

    // auto start_1 = std::chrono::system_clock::now();
    // v1.reserve(sz); // Reserve capacity for sz elements
    // for (int i = 1; i <= sz; ++i)
    //     v1.push_back(i);
    // auto end_1 = std::chrono::system_clock::now();
    // std::chrono::duration<double> diff_1 = end_1 - start_1;

    // cout << "\n> " << sz << " Elementu uzpildymas i std::vector: " << diff_1.count() << " sekundziu\n";

    // cout << "std::vector reallocations: " << v1.capacity() - 1 << endl;

    // auto start_2 = std::chrono::system_clock::now();
    // Vektorius<int> v2;
    // v2.reserve(sz); // Reserve capacity for sz elements
    // for (int i = 1; i <= sz; ++i)
    //     v2.push_back(i);
    // auto end_2 = std::chrono::system_clock::now();
    // std::chrono::duration<double> diff_2 = end_2 - start_2;

    // cout << "\n> " << sz << " Elementu uzpildymas i Vektorius: " << diff_2.count() << " sekundziu\n";

    // cout << "Vektorius reallocations: " << v2.getReallocationCount() << endl;

    // cout << "----------------------------------------------------------------------------" << endl;

    // v1.clear();
    // v2.clear();
}
