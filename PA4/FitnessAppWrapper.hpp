#pragma once
#include "PA4.hpp"
#include "WeeklyEPlan.hpp"
#include "WeeklyDPlan.hpp"

using std::fstream;
using std::ofstream;

class FitnessAppWrapper
{
public:
	
	~FitnessAppWrapper();//destructor

	void runApp(void);

private:

	void loadDailyPlan(fstream &inputStream, DietPlan& newPlan); 
	void loadDailyPlan(fstream &inputStream, ExercisePlan& newPlan); 

	void loadWeeklyPlan(fstream &inputStream, WeeklyEPlan& newPlan);
	void loadWeeklyPlan(fstream &inputStream, WeeklyDPlan& newPlan);

	void storeDailyPlan(fstream& outputStream, DietPlan& DPlan);
	void storeDailyPlan(fstream& outputStream, ExercisePlan& EPlan);

	void storeWeeklyPlan(fstream& outputStream, WeeklyDPlan& DPlans);
	void storeWeeklyPlan(fstream& outputStream, WeeklyEPlan& EPlans);

	void displayDailyPlan(ExercisePlan EPlan) const;
	void displayDailyPlan(DietPlan DPlan) const;

	void displayWeeklyPlan(WeeklyEPlan& EPlan) const;
	void displayWeeklyPlan(WeeklyDPlan& DPlan) const;

	void editDailyPlan(WeeklyDPlan& DPlans);
	void editDailyPlan(WeeklyEPlan& EPlans);

	void displayMenu();
	void endApp();

	WeeklyEPlan mWeeklyExercisePlan;
	WeeklyDPlan mWeeklyDietPlan;

	fstream mInputEPlan;
	fstream mIputDPlan;
};


