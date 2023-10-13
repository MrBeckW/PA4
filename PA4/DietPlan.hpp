#pragma once

#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::ostream;
using std::istream;


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

ostream& operator<<(ostream& lhs, DietPlan& rhs);
istream& operator>>(istream& stream, DietPlan& rhs);