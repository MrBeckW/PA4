#include "PA4.hpp"

/////////////////////
//DietPlan Member-Functions

/// <summary>
/// Defualt constructor for DietPlan class
/// </summary>
DietPlan::DietPlan(int newCalories, string newName, string newdate)
{
	mGoalCalories = newCalories;
	mPlanName = newName;
	mDate = newdate;//Month/day/year
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

/// <summary>
/// Member function of DietPlan class: getter for mGoalCalories value
/// </summary>
/// <returns>int mGoalCalories</returns>
int DietPlan::getCalories()
{
	return mGoalCalories;
}

/// <summary>
/// Member function of DietPlan class: getter for mPlanName value
/// </summary>
/// <returns>str::string mPlanName</returns>
std::string DietPlan::getPlanName()
{
	return mPlanName;
}

/// <summary>
/// Member function of DietPlan class: getter for mDate value
/// </summary>
/// <returns>str::string mDate </returns>
std::string DietPlan::getDate()
{
	return mDate;
}

/// <summary>
/// Member funciton of DietPlan class: setter for mGoalCalories / validates number is larger than zero.
/// </summary>
/// <param name="calories">integer number representing goal calories.</param>
void DietPlan::setCalories(const int calories)
{
	if (calories > 0)
	{
		mGoalCalories = calories;
	}
	else
	{
		std::cout << "-Error- calories value out of bounds.\n";
	}
	
}

/// <summary>
/// Member funciton of DietPlan class: setter for mPlanName 
/// </summary>
/// <param name="name">string representing the name of the fitness plan</param>
void DietPlan::setDPlanName(const std::string name)
{
	mPlanName = name;
}

/// <summary>
/// Member funciton of DietPlan class: setter for mPlanName 
/// </summary>
/// <param name="date">string representing the name of the date</param>
void DietPlan::setDDate(const std::string date)
{
	mDate = date;
}

void DietPlan::editGoal()
{
	int newCal;
	cout << "What is your new daily calorie goal?\n>";
	cin >> newCal;

	this->setCalories(newCal);

	cout << "Your New Plan: " << *this << std::endl;
}


/////////////////////
//ExercisePlan Member-Functions

/// <summary>
/// Defulat constructor for ExercisePlan class.
/// </summary>
ExercisePlan::ExercisePlan(int newSteps, string newName, string newdate)
{
	mGoalSteps = newSteps;
	mPlanName = newName;
	mDate = newdate; //Month/Day/Year
}

/// <summary>
/// Copy Constructor for ExercisePlan class.
/// </summary>
/// <param name="copy"></param>
ExercisePlan::ExercisePlan(const ExercisePlan& copy)
{
	mGoalSteps = copy.mGoalSteps;
	mPlanName = copy.mPlanName;
	mDate = copy.mDate;
}

/// <summary>
/// destructor for ExercisePlan class
/// </summary>
ExercisePlan::~ExercisePlan()
{

}

/// <summary>
/// Member function of ExercisePlan: getter for mGoalSteps
/// </summary>
/// <returns>int mGoalSteps</returns>
int ExercisePlan::getSteps()
{
	return mGoalSteps;
}

/// <summary>
/// Member function of ExercisePlan: getter for mPlanName
/// </summary>
/// <returns>std::string mPlanName</returns>
std::string ExercisePlan::getEPlanName()
{
	return mPlanName;
}

/// <summary>
/// Member function of ExercisePlan: getter for mDate
/// </summary>
/// <returns>std::string mDate</returns>
std::string ExercisePlan::getEDate()
{
	return mDate;
}

/// <summary>
/// Member function of ExercisePlan: setter for mGoalSteps / validates argument for values larger than 0;
/// </summary>
/// <param name="goalSteps">const int representing goal daily steps</param>
void ExercisePlan::setSteps(const int goalSteps)
{
	if (goalSteps > 0)
	{
		mGoalSteps = goalSteps;
	}
	else
	{
		std::cout << "-Error- steps value out of bounds.\n";
	}
	
}

/// <summary>
/// Member function of ExercisePlan: setter for mPlanName
/// </summary>
/// <param name="PlanName">std::string representing the name of the exercise plan</param>
void ExercisePlan::setEPlanName(const std::string PlanName)
{
	mPlanName = PlanName;
}

/// <summary>
/// Member function of ExercisePlan: setter for mDate
/// </summary>
/// <param name="Date">std::string representing the date for which the plan is intended for.</param>
void ExercisePlan::setEDate(const std::string Date)
{
	mDate = Date;
}

void ExercisePlan::editGoal()
{
	int newSteps;
	cout << "What is your new daily steps goal?\n>";
	cin >> newSteps;

	this->setSteps(newSteps);

	cout << "Your New Plan: " << *this << std::endl;
}

////////////////////////////////
//Non-Member Functions

ostream& operator<<(ostream& lhs, DietPlan& rhs)
{
	lhs << "Plan Name: " << rhs.getPlanName() << " Max Calories: " << rhs.getCalories() << " Plan Date: " << rhs.getDate();
	return lhs;
}

ostream& operator<<(ostream& lhs, ExercisePlan& rhs)
{
	lhs << "Plan Name: " << rhs.getEPlanName() << " Steps Goal: " << rhs.getSteps() << " Plan Date: " << rhs.getEDate();
	return lhs;
}
