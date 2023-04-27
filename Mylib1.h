#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <string>
#include <limits>
#include <stdexcept>
#include <random> 
#include <iterator>
#include <numeric>


using std::cout;
using std::cin;
using std::endl;
using std::left;
using std::right;
using std::setw;
using std::setprecision;
using std::string;
using std::copy;
using std::vector;
using std::fixed;
using std::left;
using std::exception;


class studentas
{
private:
    string vardas, pavarde;
    vector<int> paz;
    double egz;
    double sum = 0;
    double gal;
    double med;
public:
    studentas() = default;

    void setVardas(string vardas_) { vardas = vardas_; }
    void setPavarde(string pavarde_) { pavarde = pavarde_; }
    void setPazymiai(vector<int> paz_) { paz = paz_; }
    void setEgzaminas(double egz_) { egz = egz_; }
    void setSum(double sum_) { sum = sum_; }
    void setGalutinis(double gal_) { gal = gal_; }
    void setMediana(double med_) { med = med_; }

    string getVardas() const { return vardas; }
    string getPavarde() const { return pavarde; }
    vector<int> getPazymiai() const { return paz; }
    double getEgzaminas() const { return egz; }
    double getSum() const { return sum; }
    double getGalutinis() const { return gal; }
    double getMediana() const { return med; }
    ~studentas () {paz.clear();}

};

void pild(studentas &temp);
void gen_file(double& diff1);
void bufer_nusk(string read_vardas, vector<studentas> &mas, double& diff2);
void write_to_file(vector<studentas>& studentai, const string& vargs_file, const string& kiet_file, double& diff3, double& diff4, double& diff5);
void print_student_info( studentas &temp);