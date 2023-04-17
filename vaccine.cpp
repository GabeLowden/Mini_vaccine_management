#include <iostream>
#include "vaccine.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <sstream>

using namespace std;

int cityVacRec::stateTotalDoses = 0;
int cityVacRec::stateTotalPopu = 0;
vector<int> cityVacRec::stateDosePopu;

cityVacRec::cityVacRec(string city_name, int city_population) {

    cityName = city_name;
    cityPopulation = city_population;
    stateTotalPopu += cityPopulation;
    totalDoseNum = 0;
}
void cityVacRec::updateStateData(){

    if (totalDoseNum > stateTotalDoses) {
        for (int i = stateTotalDoses; i < totalDoseNum; ++i){
            stateDosePopu.push_back(0);
            stateTotalDoses++;
        }
    }

}

vector <int> cityVacRec::addVacDosePopu (int vacDoseNum, int numPeople) {
    int len = dosePopulation.size();

    if (vacDoseNum > len){
        for (int i = len; i < (vacDoseNum); i++){
            dosePopulation.push_back(0);
            totalDoseNum++;
        }
    }

    updateStateData();
    int indx = vacDoseNum - 1;

    dosePopulation[indx] = numPeople + dosePopulation[indx];
    stateDosePopu[indx] = numPeople + stateDosePopu[indx];

    /*
    cout << "vacDoseNum = " << vacDoseNum << endl;
    cout << "numPeople = " << numPeople << endl;
    cout << "stateTotalDoses = " << vacDoseNum << endl;
    */

    for (int i = 0; i < len; i++){
       cout << "dosePopulation = " << dosePopulation[i] << endl;
    }

    return dosePopulation;
}

double cityVacRec::vacDoseRate(){
    double rate;
    double sum = 0;
    int len = dosePopulation.size();
    for(int i = 0; i < len; i++){
        sum += dosePopulation[i];
    }
    rate = (sum / (stateTotalDoses)) / cityPopulation;
    return rate;
}

int cityVacRec::operator<(vector <cityVacRec> vecCityVacRec){
   int len = vecCityVacRec.size();
   double rate = vacDoseRate();
   int counter = 0;
   for (int i = 0; i < len; ++i){
       if (vecCityVacRec[i].vacDoseRate() > rate){
           counter++;
       }
   }
   return counter;
}

double calStateDoseRate(){
    double rate;
    double sum = 0;
    vector <int> stateDosePopu = cityVacRec::getStateDosePopu();
    int stateTotalPopu = cityVacRec::getStateTotalPopu();

    int len = stateDosePopu.size();
    for (int i = 0; i < len; ++i){
        sum += stateDosePopu[i];
    }
    rate = (sum / len) / stateTotalPopu;
    return rate;


}
