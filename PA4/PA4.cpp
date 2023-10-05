#include "PA4.hpp"

/////////////////////
//DietPlan Member-Functions

/// <summary>
/// Defualt constructor for DietPlan class
/// </summary>
DietPlan::DietPlan()
{
	mGoalCalories = 0;
	mPlanName = "No Name";
	mDate = "01/01/0001";//Month/day/year
}

/// <summary>
/// Copy constructor for DietPlan Class
/// </summary>
/// <param name="copy">The DietPlan object that is to be copied. passed by reference.</param>
DietPlan::DietPlan(const DietPlan &copy)
{
	mGoalCalories = copy.mGoalCalories;
	mPlanName = copy.mPlanName;
	mDate = copy.mDate;
}

/// <summary>
/// Destructor for DietPlan
/// </summary>
DietPlan::~DietPlan()
{

}

int DietPlan::getCalories()
{
	return mGoalCalories;
}

std::string DietPlan::getPlanName()
{
	return mPlanName;
}

std::string DietPlan::getDate()
{
	return mDate;
}

void DietPlan::setCalories(const int calories)
{
	mGoalCalories = calories;
}

void DietPlan::setPlanName(const std::string name)
{
	mPlanName = name;
}

void DietPlan::setDate(const std::string date)
{
	mDate = date;
}