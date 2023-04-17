#ifndef VACCINE_H
#define VACCINE_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <sstream>

using namespace std;

class cityVacRec{
    private:
        string cityName;
        vector <int> dosePopulation;
        int cityPopulation;
        int totalDoseNum;
        static vector <int> stateDosePopu;
        static int stateTotalDoses;
        static int stateTotalPopu;
        void updateStateData();
    public:
        cityVacRec(string city_name, int city_population);
        vector <int> addVacDosePopu (int vacDoseNum, int numPeople);
        double vacDoseRate();
        int operator< (vector <cityVacRec> vecCityVacRec);
        static vector <int> getStateDosePopu(){
            return stateDosePopu;
        }
        static int getStateTotalPopu(){
            return stateTotalPopu;
        }

};

double calStateDoseRate();

#endif // VACCINE_H
