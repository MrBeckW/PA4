#pragma once

#include <iostream>
#include <string>

using std::ostream;
using std::cout;
using std::cin;
using std::string;

class DietPlan
{
public:
	DietPlan(int newCalories = 0, string newName = "No Name", string newdate = "01/01/0001"); //defualt constructor
	
	DietPlan(const DietPlan& copy);//copy constructor

	~DietPlan(); //destructor

	//getters
	int getCalories();
	std::string getPlanName();
	std::string getDate();

	//setters
	void setCalories(const int calories);
	void setDPlanName(const std::string name);
	void setDDate(const std::string date);

	void editGoal();

private:
	int mGoalCalories;
	std::string mPlanName;
	std::string mDate;

};

class ExercisePlan
{
public:
	ExercisePlan(int newSteps = 0, string newName = "No Name", string newdate = "01/01/0001");//defualt constructor

	ExercisePlan(const ExercisePlan& copy);//copy constructor

	~ExercisePlan(); //destructor

	//getters
	int getSteps();
	std::string getEPlanName();
	std::string getEDate();

	//setters
	void setSteps(const int goalSteps);
	void setEPlanName(const std::string PlanName);
	void setEDate(const std::string Date);

	void editGoal();

private:
	int mGoalSteps;
	std::string mPlanName;
	std::string mDate;
};

class FitnessAppWrapper
{

};

ostream& operator<<(ostream& lhs, DietPlan& rhs);
ostream& operator<<(ostream& lhs, ExercisePlan& rhs);