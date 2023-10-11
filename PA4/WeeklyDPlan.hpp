#pragma once
#include "DietPlan.hpp"
#include "NodeDP.hpp"

class WeeklyDPlan
{
public:
	WeeklyDPlan(); //constructor

	~WeeklyDPlan(); //destructor

	//getter
	NodeDP* getpHead();

	bool insertAtEnd(const DietPlan newDplan);
	bool isEmpty();

private:
	NodeDP* mpHead;
	NodeDP* createNode(DietPlan newEPlan);

};