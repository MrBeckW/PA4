//////////////
// PA4
// Beck Williams
// CPT_S 122
/////////////
#include "PA4.hpp"

int main()
{
	DietPlan mondayD, tuesdayD, wednesdayD, thursdayD, fridayD, saturdayD, sundayD;
	ExercisePlan mondayE, tuesdayE, wednesdayE, thursdayE, fridayE, saturdayE, sundayE;

	std::ifstream input;
	input.open("dietPlans.txt");
	input >> mondayD >> tuesdayD >> wednesdayD >> thursdayD >> fridayD >> saturdayD >> sundayD;
	cout << "Monday: " << mondayD << "\nTuesday: " << tuesdayD << "\nWednesday: " << wednesdayD << "\nThursday: " << thursdayD << "\nFriday: " << fridayD << "\nSaturday: " << saturdayD << "\nSunday: " << sundayD << std::endl << std::endl;
	input.close();

	input.open("exercisePlans.txt");
	input >> mondayE >> tuesdayE >> wednesdayE >> thursdayE >> fridayE >> saturdayE >> sundayE;
	cout << "Monday: " << mondayE << "\nTuesday: " << tuesdayE << "\nWednesday: " << wednesdayE << "\nThursday: " << thursdayE << "\nFriday: " << fridayE << "\nSaturday: " << saturdayE << "\nSunday: " << sundayE << std::endl;
	input.close();

	WeeklyPlan w1;

	w1.insertAtEnd(mondayE, mondayD);
	w1.insertAtEnd(tuesdayE, tuesdayD);

	Node* pCur = w1.getpHead();

	cout << "w1 ep: " << w1.getpHead()->getExercisePlan().getEPlanName();
	pCur = pCur->getpNext();
	cout << "w1 eptu: " << pCur->getExercisePlan().getEPlanName();


}