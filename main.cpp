#include "vaccine.h"

int main(){
        vector <int> dosePopu1, dosePopu2, dosePopu3;
        cityVacRec city1 ("Cincinnati", 500);  //city 1
        city1.addVacDosePopu (1, 200);
        city1.addVacDosePopu (2, 300);
        city1.addVacDosePopu (2, 100);
        dosePopu1 = city1.addVacDosePopu (3, 400);

        //vector <int> dosePopu_2 = {300, 400, 0, 700};
        //cityVacRec city2 ("Dayton", dosePopu_2, 900, 4);  //city 2
        cityVacRec city2 ("Dayton", 300);  //city 1
        city2.addVacDosePopu (1, 100);
        city2.addVacDosePopu (2, 200);
        city2.addVacDosePopu (2, 300);
        dosePopu2 = city2.addVacDosePopu(5, 100);


        //vector <int> dosePopu_3 = {100, 0, 200, 300};
        //cityVacRec city3 ("Toledo", dosePopu_3, 100, 4); //city 3
        cityVacRec city3 ("Toledo", 200);  //city 1
        city3.addVacDosePopu (1, 100);
        city3.addVacDosePopu (2, 300);
        city3.addVacDosePopu (2, 200);
        dosePopu3 = city3.addVacDosePopu(3, 100);

        //The following is to test operatpr<
        vector <cityVacRec> cityVacRec1;
        cityVacRec1.push_back(city2);
        cityVacRec1.push_back(city3);
        int a = (city1 < cityVacRec1);
        cout << "a is " << a << endl;
        cout << "The dosing rate of City 1 is small than " << a << " cities" << endl;
        cout << endl;

        //The following is to test non-member function
        dosePopu1 = cityVacRec::getStateDosePopu();
        for (unsigned int i = 0; i < dosePopu1.size(); i++)
              cout << "doesPopu1 has " << dosePopu1[i] << endl;

        cout << "The sate dose rate is " << calStateDoseRate() << endl;



    return 0;
}
