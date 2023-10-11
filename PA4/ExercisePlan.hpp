#pragma once
#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::ostream;
using std::istream;

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

ostream& operator<<(ostream& lhs, ExercisePlan& rhs);
istream& operator>>(istream& stream, ExercisePlan& rhs);