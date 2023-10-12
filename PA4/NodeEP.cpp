#include "PA4.hpp"
#include "NodeEP.hpp"


NodeEP::NodeEP(ExercisePlan newEPlan, NodeEP* pNext)
{
	setpNext(pNext);
	setExercisePlan(newEPlan);
	//setDietPlan(newDPlan);
}

NodeEP::NodeEP(const NodeEP& copy)
{
	mpNext = copy.mpNext;
	mExercisePlan = copy.mExercisePlan;
	//mDietPlan = copy.mDietPlan;
}

NodeEP::~NodeEP()
{
}

NodeEP* NodeEP::getpNext()
{
	return mpNext;
}

ExercisePlan NodeEP::getExercisePlan()
{
	return mExercisePlan;
}

void NodeEP::setpNext(NodeEP* const nextNode)
{
	mpNext = nextNode;
}

void NodeEP::setExercisePlan(const ExercisePlan newEPlan)
{
	mExercisePlan = newEPlan;
}


