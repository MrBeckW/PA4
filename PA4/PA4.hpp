#pragma once

#include <iostream>
#include <string>


class DietPlan
{
public:
	DietPlan(); //defualt constructor
	
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

private:
	int mGoalCalories;
	std::string mPlanName;
	std::string mDate;

};

class ExercisePlan
{
public:
	ExercisePlan();//defualt constructor

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

private:
	int mGoalSteps;
	std::string mPlanName;
	std::string mDate;
};

class FitnessAppWrapper
{

};