//////////////
// PA4
// Beck Williams
// CPT_S 122
/////////////
#include "PA4.hpp"

int main()
{
	ExercisePlan p1(1000, "Sandwich", "01/01/2023"), p2(2000, "Banana", "01/02/2023");

	cout << "Plan 1: " << p1 << "\nPlan 2: " << p2 << std::endl;

	p2.editGoal();
}