#include "PA4.hpp"
#include "DietPlan.hpp"



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
DietPlan::DietPlan(const DietPlan& copy)
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

/// <summary>
/// allows the user to edit the goal calories
/// </summary>
void DietPlan::editGoal()
{
	int newCal;
	cout << "What is your new daily calorie goal?\n>";
	cin >> newCal;

	this->setCalories(newCal);

	cout << "Your New Plan: " << *this << std::endl;
}

//////////////////////
//Non-Member Functions

/// <summary>
/// insert stream operator DietPlan class
/// </summary>
/// <param name="lhs">stream to be inserted into</param>
/// <param name="rhs">DietPlan to be inserted</param>
/// <returns>the original stream</returns>
ostream& operator<<(ostream& lhs, DietPlan& rhs)
{
	lhs << rhs.getPlanName() << "\n" << rhs.getCalories() << "\n" << rhs.getDate();
	return lhs;
}

/// <summary>
/// stream extraction operator for DietPlan class
/// </summary>
/// <param name="stream">stream to extract from</param>
/// <param name="rhs">DietPlan to be extracted to</param>
/// <returns>the original stream</returns>
istream& operator>>(istream& stream, DietPlan& rhs)
{

	string name, date, calS, empty;

	std::getline(stream, name);
	std::getline(stream, calS);
	std::getline(stream, date);
	std::getline(stream, empty);

	rhs.setDPlanName(name);
	rhs.setCalories(stoi(calS));
	rhs.setDDate(date);

	return stream;
}