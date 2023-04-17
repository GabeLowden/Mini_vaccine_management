# Mini_vaccine_management
This project implements a mini-vaccine management system for a city (state) to keep track of the population who have finished each dose of vaccine for the city (state). The system consists of a cityVacRec class, which contains several member functions and variables to manage vaccine data.

cityVacRec class
The cityVacRec class contains the following private member variables:

cityName: the name of a city
dosePopulation: a vector of integers representing the number of population who have finished each dose, e.g., dosePopulation[0] contains the number of people who finished dose 1.
cityPopulation: the population of a city.
totalDoseNum: the total number of doses used for a city.
stateDosePopu: a static vector of integers representing the number of people who already finished each dose in the state.
stateTotalDoses: the number of doses used so far for the state.
stateTotalPopu: the sum of populations for all cities in a state.
The cityVacRec class contains the following public member functions:

cityVacRec(string city_name, int city_population)
This is a constructor to initialize the city_name and city_population for a city object created. This function adds the city_population to stateTotalPopu.

vector <int> addVacDosePopu(int vacDoseNum, int numPeople)
This function adds numPeople into dosePopulation[vacDoseNum – 1] and then returns the entire dosePopulation vector of the city to the caller function. This function also updates the stateDosePopu vector (static data) of the state.

double vacDoseRate()
This function is used to compute the rate of vaccine dosing for a city (object). The rate can be computed by:

((Sum of all dosePopulations) / (stateTotalDoses)) / cityPopulation.

The function returns the rate to the caller function.

int operator<(vector<cityVacRec> vecCityVacRec)
This function overloads the < operator and is used to compare the vaccine dosing rates of different cities. It returns the index of the city with the lowest dosing rate in the vecCityVacRec vector.

static vector<int> getStateDosePopu()
This function returns the stateDosePopu vector.

static int getStateTotalPopu()
This function returns the stateTotalPopu variable.

Conclusion
The cityVacRec class provides a simple yet effective way to manage vaccine data for a city (state). By keeping track of the population who have finished each dose of vaccine, the system can calculate the vaccine dosing rate and compare it with other cities in the state. This information can be used to make data-driven decisions and improve vaccination efforts in the state.
