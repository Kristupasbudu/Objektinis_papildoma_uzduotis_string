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
#include <stdio.h>

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


struct studentas
{
    string vardas, pavarde;
    vector<int> paz;
    double egz;
    double sum = 0;
    double gal;
    double med;
};

void pild(studentas &temp);
void bufer_nusk(string read_vardas, vector<studentas> &mas);
void spausd(studentas &temp);