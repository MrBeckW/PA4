#include "PA4.hpp"
#include "FitnessAppWrapper.hpp"

FitnessAppWrapper::FitnessAppWrapper()
{
	mImputEPlan.open("exercisePlans.txt");
	mImputDPlan.open("dietPlans.txt");

	mOutputEPlan.open("exercisePlans.txt");
	mOutputDPlan.open("dietPlans.txt");
}

FitnessAppWrapper::~FitnessAppWrapper()
{
	mImputDPlan.close();
	mImputEPlan.close();
	mOutputDPlan.close();
	mOutputDPlan.close();
}

void FitnessAppWrapper::runApp(void)
{

}

void FitnessAppWrapper::loadDailyPlan(ifstream imputStream, DietPlan& newPlan)
{
	imputStream >> newPlan;
}

void FitnessAppWrapper::loadDailyPlan(ifstream imputStream, ExercisePlan& newPlan)
{
	imputStream >> newPlan;
}
