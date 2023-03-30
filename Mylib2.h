#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <chrono>
#include <algorithm>
#include <string>
#include <limits>
#include <stdexcept>
#include <random> 
#include <iterator>
#include <deque>


using std::cout;
using std::cin;
using std::endl;
using std::left;
using std::right;
using std::setw;
using std::setprecision;
using std::string;
using std::copy;
using std::fixed;
using std::left;
using std::exception;
using std::deque;


struct studentas
{
    string vardas, pavarde;
    deque<int> paz;
    double egz;
    double sum = 0;
    double gal;
    double med;
};

void pild(studentas &temp);
void gen_file(double& diff1);
void bufer_nusk(string read_vardas, deque<studentas> &mas, double& diff2);
void write_to_file(deque<studentas>& studentai, const string& vargs_file, const string& kiet_file, double& diff3, double& diff4, double& diff5);
void spausd(studentas &temp);