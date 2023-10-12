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

	void loadDailyPlan(ifstream& imputStream, DietPlan& newPlan); 
	void loadDailyPlan(ifstream& imputStream, ExercisePlan& newPlan); 

	void loadWeeklyPlan(ifstream& imputStream, WeeklyEPlan& newPlan);
	void loadWeeklyPlan(ifstream& imputStream, WeeklyDPlan& newPlan);

	void displayDailyPlan(ExercisePlan EPlan) const;
	void displayDailyPlan(DietPlan DPlan) const;

	void displayWeeklyPlan(WeeklyEPlan& EPlan) const;
	void displayWeeklyPlan(WeeklyDPlan& DPlan) const;


	void displayMenu();


	WeeklyEPlan mWeeklyExercisePlan;
	WeeklyDPlan mWeeklyDietPlan;

	ifstream mImputEPlan;
	ifstream mImputDPlan;

	ofstream mOutputEPlan;
	ofstream mOutputDPlan;
};
