#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
// #include <vector>
#include <chrono>
#include <algorithm>
#include <string>
#include <limits>
#include <stdexcept>
#include <random>
#include <iterator>
#include <numeric>
#include "vektorius.h"

using std::cin;
using std::copy;
using std::cout;
using std::endl;
using std::exception;
using std::fixed;
using std::left;
using std::right;
using std::setprecision;
using std::setw;
using std::string;
// using std::vector;

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



    friend std::ostream &operator<<(std::ostream &os, const studentas &stud)
    {
        os << std::left << std::setw(15) << stud.getVardas()
           << std::setw(20) << stud.getPavarde()
           << std::setw(10) << std::fixed << std::setprecision(2) << stud.getGalutinis()
           << '\n';
        return os;
    }


    void print() override {
        std::cout << "Student: " << vardas << " " << pavarde << std::endl;
    }
};

void pild(studentas &temp);
void gen_file(double &diff1);
void bufer_nusk(string read_vardas, vector<studentas> &mas, double &diff2);
void write_to_file(vector<studentas> &studentai, const string &vargs_file, const string &kiet_file, double &diff3, double &diff4, double &diff5);
void print_student_info(studentas &temp);