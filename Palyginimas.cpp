#include "vektorius.h"
#include <string>

using namespace std;

class zmogus {
protected:
    std::string vardas, pavarde;

public:
    zmogus() : vardas("Vardenis"), pavarde("Pavardenis") {}
    zmogus(std::string vardas_, std::string pavarde_) : vardas(vardas_), pavarde(pavarde_) {}

    virtual void print() = 0;  // pure virtual function

    std::string getVardas() const { return vardas; }
    std::string getPavarde() const { return pavarde; }

    void setVardas (const string& vardas);
    void setPavarde(const string& pavarde);
};

class studentas : public zmogus {
private:
    std::vector<int> paz;
    double egz;
    double sum = 0;
    double gal = 0;
    double med = 0;

public:
    studentas() : egz(0) {}
    studentas(std::string vardas_, std::string pavarde_) : zmogus(vardas_, pavarde_), egz(0) {}

    // Copy constructor
    studentas(const studentas &other)
        : zmogus(other.vardas, other.pavarde),
          paz(other.paz),
          egz(other.egz),
          sum(other.sum),
          gal(other.gal),
          med(other.med) {
        // std::cout << "Copy constructor called" << std::endl;
    }

    // Move constructor
    studentas(studentas &&other) noexcept
        : zmogus(std::move(other.vardas), std::move(other.pavarde)),
          paz(std::move(other.paz)),
          egz(std::move(other.egz)),
          sum(std::move(other.sum)),
          gal(std::move(other.gal)),
          med(std::move(other.med)) {
        // std::cout << "Move constructor called" << std::endl;
    }

    // Copy assignment operator
    studentas &operator=(const studentas &other) {
        if (this != &other) {
            zmogus::operator=(other);
            paz = other.paz;
            egz = other.egz;
            sum = other.sum;
            gal = other.gal;
            med = other.med;
            // std::cout << "Copy assignment operator called" << std::endl;
        }
        return *this;
    }

    // Move assignment operator
    studentas &operator=(studentas &&other) noexcept {
        if (this != &other) {
            zmogus::operator=(std::move(other));
            paz = std::move(other.paz);
            egz = std::move(other.egz);
            sum = std::move(other.sum);
            gal = std::move(other.gal);
            med = std::move(other.med);
            // std::cout << "Move assignment operator called" << std::endl;
        }
        return *this;
    }

    // Destructor
    ~studentas() {
        // std::cout << "Destructor called" << std::endl;
    }
    // Getters and setters
    void setVardas(string vardas_) { vardas = vardas_; }
    void setPavarde(string pavarde_) { pavarde = pavarde_; }
    void setPazymiai(std::vector<int> paz_) { paz = paz_; }
    void setEgzaminas(double egz_) { egz = egz_; }
    void setSum(double sum_) { sum = sum_; }
    void setGalutinis(double gal_) { gal = gal_; }
    void setMediana(double med_) { med = med_; }
    std::vector<int> &getPazymiai() { return paz; }
    // const std::vector<int> &getPazymiai() const { return paz; }
    double getEgzaminas() const { return egz; }
    double getSum() const { return sum; }
    double getGalutinis() const { return gal; }
    double getMediana() const { return med; }



    // friend std::ostream &operator<<(std::ostream &os, const studentas &stud)
    // {
    //     os << std::left << std::setw(15) << stud.getVardas()
    //        << std::setw(20) << stud.getPavarde()
    //        << std::setw(10) << std::fixed << std::setprecision(2) << stud.getGalutinis()
    //        << '\n';
    //     return os;
    // }


    void print() override {
        std::cout << "Student: " << vardas << " " << pavarde << std::endl;
    }
};

void pild(studentas &temp);
void gen_file(double &diff1);
void bufer_nusk(string read_vardas, vector<studentas> &mas, double &diff2);
void write_to_file(vector<studentas> &studentai, const string &vargs_file, const string &kiet_file, double &diff3, double &diff4, double &diff5);
void print_student_info(studentas &temp);







int main()
{

    unsigned int sz = 10000000; // 100000, 1000000, 10000000, 100000000
    std::vector<int> v1;

    cout << "----------------------------------------------------------------------------" << endl;
    cout << "Vektorius su Int\n";
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






    std::vector<studentas> v3;
    Vektorius<studentas> v4;


    cout << "----------------------------------------------------------------------------" << endl;
    cout << "Vektorius su Studentas\n";
    auto start_3 = std::chrono::system_clock::now();
    for (int i = 1; i <= sz; ++i)
        v3.push_back(studentas());
    auto end_3 = std::chrono::system_clock::now();
    std::chrono::duration<double> diff_3 = end_3-start_3;

    cout << "\n> " << sz << " Elementu uzpildymas i std::vector: " << diff_3.count() << " sekundziu\n";

    auto start_4 = std::chrono::system_clock::now();
    for (int i = 1; i <= sz; ++i)
        v4.push_back(studentas());
    auto end_4 = std::chrono::system_clock::now();
    std::chrono::duration<double> diff_4 = end_4-start_4;

    cout << "\n> " << sz << " Elementu uzpildymas i Vektorius: " << diff_4.count() << " sekundziu\n";

    cout << "----------------------------------------------------------------------------" << endl;

    std::size_t finalCapacity_3 = v3.capacity();
    std::size_t reallocations_3 = (finalCapacity_3 > 1000000) ? (finalCapacity_3 / 1000000) - 1 : 0;


    v3.clear();
    v4.clear();




    // std::size_t sz = 100000000;

    // std::cout << "----------------------------------------------------------------------------" << std::endl;
    // std::cout << "Vektorius su int\n";

    // std::vector<int> v3;
    // std::size_t initialCapacity_3 = v3.capacity();
    // std::size_t reallocations_3 = 0;

    // auto start_3 = std::chrono::system_clock::now();
    // for (int i = 1; i <= sz; ++i) {
    //     v3.push_back(i);
    //     if (v3.capacity() > initialCapacity_3) {
    //         ++reallocations_3;
    //         initialCapacity_3 = v3.capacity();
    //     }
    // }
    // auto end_3 = std::chrono::system_clock::now();
    // std::chrono::duration<double> diff_3 = end_3 - start_3;

    // std::cout << "\n> " << sz << " Elementu uzpildymas i std::vector: " << diff_3.count() << " sekundziu\n";
    // std::cout << "Number of reallocations for std::vector: " << reallocations_3 << std::endl;

    // Vektorius<int> v4;
    // std::size_t initialCapacity_4 = v4.capacity();
    // std::size_t reallocations_4 = 0;

    // auto start_4 = std::chrono::system_clock::now();
    // for (int i = 1; i <= sz; ++i) {
    //     v4.push_back(i);
    //     if (v4.capacity() > initialCapacity_4) {
    //         ++reallocations_4;
    //         initialCapacity_4 = v4.capacity();
    //     }
    // }
    // auto end_4 = std::chrono::system_clock::now();
    // std::chrono::duration<double> diff_4 = end_4 - start_4;

    // std::cout << "\n> " << sz << " Elementu uzpildymas i Vektorius: " << diff_4.count() << " sekundziu\n";
    // std::cout << "Number of reallocations for Vektorius: " << reallocations_4 << std::endl;

    // std::cout << "----------------------------------------------------------------------------" << std::endl;

    // v3.clear();
    // v4.clear();


    return 0;

}
