#pragma once
#include "PA4.hpp"
#include "WeeklyEPlan.hpp"
#include "WeeklyDPlan.hpp"

using std::ifstream;
using std::ofstream;

class FitnessAppWrapper
{
public:
	FitnessAppWrapper();//defulat constructor
	
	~FitnessAppWrapper();//destructor

	void runApp(void);

private:

	void loadDailyPlan(ifstream &inputStream, DietPlan& newPlan); 
	void loadDailyPlan(ifstream &inputStream, ExercisePlan& newPlan); 

	void loadWeeklyPlan(ifstream &inputStream, WeeklyEPlan& newPlan);
	void loadWeeklyPlan(ifstream &inputStream, WeeklyDPlan& newPlan);

	void storeDailyPlan(ofstream& outputStream, DietPlan& DPlan);
	void storeDailyPlan(ofstream& outputStream, ExercisePlan& EPlan);

	void storeWeeklyPlan(ofstream& outputStream, WeeklyDPlan& DPlans);
	void storeWeeklyPlan(ofstream& outputStream, WeeklyEPlan& EPlans);

	void displayDailyPlan(ExercisePlan EPlan) const;
	void displayDailyPlan(DietPlan DPlan) const;

	void displayWeeklyPlan(WeeklyEPlan& EPlan) const;
	void displayWeeklyPlan(WeeklyDPlan& DPlan) const;

	void editDailyPlan(WeeklyDPlan& DPlans);
	void editDailyPlan(WeeklyEPlan& EPlans);

	void displayMenu();


	WeeklyEPlan mWeeklyExercisePlan;
	WeeklyDPlan mWeeklyDietPlan;

	ifstream mImputEPlan;
	ifstream mImputDPlan;

	ofstream mOutputEPlan;
	ofstream mOutputDPlan;
};


