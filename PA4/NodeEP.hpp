#pragma once
#include "ExercisePlan.hpp"


class NodeEP
{
public:
	NodeEP(ExercisePlan newEPlan, NodeEP* pNext = nullptr);//constructor
	NodeEP(const NodeEP& copy);//copy constructor
	~NodeEP(); //destructor

	//getters
	NodeEP* getpNext();
	ExercisePlan getExercisePlan();
	

	//setters
	void setpNext(NodeEP* const nextNode);
	void setExercisePlan(const ExercisePlan newEPlan);
	

private:
	NodeEP* mpNext;
	ExercisePlan mExercisePlan;
	
};

