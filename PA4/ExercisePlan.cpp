#include "PA4.hpp"
#include "ExercisePlan.hpp"


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

ostream& operator<<(ostream& lhs, ExercisePlan& rhs)
{
	lhs << "Plan Name: " << rhs.getEPlanName() << " Steps Goal: " << rhs.getSteps() << " Plan Date: " << rhs.getEDate();
	return lhs;
}

istream& operator>>(istream& stream, ExercisePlan& rhs)
{
	string name, date, stepsS, empty;

	std::getline(stream, name);
	std::getline(stream, stepsS);
	std::getline(stream, date);
	std::getline(stream, empty);


	rhs.setEPlanName(name);
	rhs.setSteps(stoi(stepsS));
	rhs.setEDate(date);

	return stream;
}