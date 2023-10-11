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
	
	void loadDailyPlan(ifstream imputStream, DietPlan& newPlan);
	void loadDailyPlan(ifstream imputStream, ExercisePlan& newPlan);

	void loadWeeklyPlan(ifstream imputStream, WeeklyEPlan newPlan);
	void loadWeeklyPlan(ifstream imputStream, WeeklyDPlan newPlan);

private:
	WeeklyEPlan mWeeklyExercisePlan;
	WeeklyDPlan mWeeklyDietPlan;

	ifstream mImputEPlan;
	ifstream mImputDPlan;

	ofstream mOutputEPlan;
	ofstream mOutputDPlan;
};
