#pragma once
#include "ExercisePlan.hpp"
#include "NodeEP.hpp"

class WeeklyEPlan
{
public:
	WeeklyEPlan(); //constructor
	
	~WeeklyEPlan(); //destructor

	//getter
	NodeEP* getpHead();

	bool insertAtEnd(const ExercisePlan newEplan);
	bool isEmpty();

private:
	NodeEP* mpHead;
	NodeEP* createNode(ExercisePlan newEPlan);

};