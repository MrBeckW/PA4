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
	void setPlanName(const std::string name);
	void setDate(const std::string date);

private:
	int mGoalCalories;
	std::string mPlanName;
	std::string mDate;

};

class ExercisePlan
{

};

class FitnessAppWrapper
{

};