#include "PA4.hpp"
#include "FitnessAppWrapper.hpp"

/// <summary>
/// destructor for FitnessApp, closes any open files
/// </summary>
FitnessAppWrapper::~FitnessAppWrapper()
{
	if (mIputDPlan.is_open())
	{
		mIputDPlan.close();
	}
	if (mInputEPlan.is_open())
	{
		mInputEPlan.close();
	}
}

/// <summary>
/// collects users menu option. then executes the desired function.
/// </summary>
/// <param name="">void</param>
void FitnessAppWrapper::runApp(void)
{
	int num = 0;
	while (num != 9)
	{
		displayMenu();
		cin >> num;
		switch (num)
		{
		case 1:
			loadWeeklyPlan(mIputDPlan, mWeeklyDietPlan);
			break;
		case 2:
			loadWeeklyPlan(mInputEPlan, mWeeklyExercisePlan);
			break;
		case 3:
			storeWeeklyPlan(mIputDPlan, mWeeklyDietPlan);
			break;
		case 4:
			storeWeeklyPlan(mInputEPlan, mWeeklyExercisePlan);
			break;
		case 5:
			displayWeeklyPlan(mWeeklyDietPlan);
			break;
		case 6:
			displayWeeklyPlan(mWeeklyExercisePlan);
			break;
		case 7:
			editDailyPlan(mWeeklyDietPlan);
			break;
		case 8:
			editDailyPlan(mWeeklyExercisePlan);
			break;
		case 9:
			endApp();
			break;
		default:
			cout << "Selection out of bounds!\n";
			break;
		}
	}
}


/////////////////////////////////////////
// private member functions

/// <summary>
/// Extracts a single DietPlan from an fstream, called from loadWeeklyPlan
/// </summary>
/// <param name="imputStream">member fstream</param>
/// <param name="newPlan">Diet Plan to be inserted into</param>
void FitnessAppWrapper::loadDailyPlan(fstream& imputStream, DietPlan& newPlan)
{
	imputStream >> newPlan;
}

/// <summary>
/// Extracts a single ExercisePlan from an fstream, called from loadWeeklyPlan
/// </summary>
/// <param name="imputStream">member fstream</param>
/// <param name="newPlan">ExercisePlan to be inserted into</param>
void FitnessAppWrapper::loadDailyPlan(fstream& imputStream, ExercisePlan& newPlan)
{
	imputStream >> newPlan;
}

/// <summary>
/// opens exercisePlans.txt and extracts its contents into a linked list called WeeklyEPlan, closes file at the end of the funciton
/// </summary>
/// <param name="inputStream">member fstream</param>
/// <param name="newPlan">member linked list</param>
void FitnessAppWrapper::loadWeeklyPlan(fstream& inputStream, WeeklyEPlan& newPlan)
{
	inputStream.open("exercisePlans.txt", std::ios::in);
	if (mInputEPlan.is_open())
	{
		while (!mInputEPlan.eof())
		{
			ExercisePlan temp;
			loadDailyPlan(mInputEPlan, temp);
			newPlan.insertAtEnd(temp);
		}
	}
	inputStream.close();
}

/// <summary>
/// opens dietPlans.txt and extracts its contents into a linked list called WeeklyDPlan, closes file at the end of the funciton
/// </summary>
/// <param name="inputStream">member fstream</param>
/// <param name="newPlan">member linked list</param>
void FitnessAppWrapper::loadWeeklyPlan(fstream& inputStream, WeeklyDPlan& newPlan)
{
	inputStream.open("dietPlans.txt", std::ios::in);
	if (mIputDPlan.is_open())
	{
		while (!inputStream.eof())
		{
			DietPlan temp;
			loadDailyPlan(inputStream, temp);
			newPlan.insertAtEnd(temp);
		}
	}
	inputStream.close();
}

/// <summary>
/// writes a single DietPlan and two end lines to a file
/// </summary>
/// <param name="outputStream">member fstream</param>
/// <param name="DPlan">DietPlan to be written, contained in a NodeDP</param>
void FitnessAppWrapper::storeDailyPlan(fstream& outputStream, DietPlan& DPlan)
{
	outputStream << DPlan << std::endl << std::endl;
}

/// <summary>
/// writes a single ExercisePlan and two end lines to a file
/// </summary>
/// <param name="outputStream">member fstream</param>
/// <param name="DPlan">ExercisePlan to be written, contained in a NodeEP</param>
void FitnessAppWrapper::storeDailyPlan(fstream& outputStream, ExercisePlan& EPlan)
{
	outputStream << EPlan << std::endl << std::endl;
}

/// <summary>
/// opens dietPlans.txt in write mode, and writes the DietPlans contained in the linked list to a file.
/// </summary>
/// <param name="outputStream">member fstream</param>
/// <param name="DPlans">member linked list</param>
void FitnessAppWrapper::storeWeeklyPlan(fstream& outputStream, WeeklyDPlan& DPlans)
{
	outputStream.open("dietPlans.txt", std::ios::out);
	if (!DPlans.isEmpty() && outputStream.is_open())
	{
		NodeDP* pCur = DPlans.getpHead();

		for(int i = 0; i < 6; i++)//itterates to the end of the list - 1 node, this is so the file is formatted correctly(no endlines at the end)
		{
			storeDailyPlan(outputStream, pCur->getDietPlan());
			pCur = pCur->getpNext();
		}
		outputStream << pCur->getDietPlan();
	}
	else
	{
		cout << "ERROR! list is either empty or txt file failed to open!\n";
	}
	if (outputStream.is_open())
	{
		outputStream.close();
	}
	
}

/// <summary>
/// opens exercisePlans.txt in write mode, and writes the ExercisePlans contained in the linked list to a file.
/// </summary>
/// <param name="outputStream">member fstream</param>
/// <param name="DPlans">member linked list</param>
void FitnessAppWrapper::storeWeeklyPlan(fstream& outputStream, WeeklyEPlan& EPlans)
{
	outputStream.open("exercisePlans.txt", std::ios::out);
	if (!EPlans.isEmpty())
	{
		NodeEP* pCur = EPlans.getpHead();

		for (int i = 0; i < 6; i++)//itterates to the end of the list - 1 node, this is so the file is formatted correctly(no endlines at the end)
		{
			storeDailyPlan(outputStream, pCur->getExercisePlan()); 
			pCur = pCur->getpNext();
		}
		outputStream << pCur->getExercisePlan();
	}
	else
	{
		cout << "ERROR! list is either empty or txt file failed to open!\n";
	}
	if (outputStream.is_open())
	{
		outputStream.close();
	}
}

/// <summary>
/// displays a single ExercisePlan and two endlines to the console
/// </summary>
/// <param name="EPlan">ExersicePlan to be displayed</param>
void FitnessAppWrapper::displayDailyPlan(ExercisePlan EPlan) const
{
	cout << EPlan << std::endl << std::endl;
}

/// <summary>
/// displays a single DietPlan and two endlines to the console
/// </summary>
/// <param name="EPlan">DietPlan to be displayed</param>
void FitnessAppWrapper::displayDailyPlan(DietPlan DPlan) const
{
	cout << DPlan << std::endl << std::endl;
}

/// <summary>
/// Displays all ExercisePlans contained in WeeklyEPlan linked list by calling displayDailyPlan repeatedly
/// </summary>
/// <param name="EPlan">member linked list</param>
void FitnessAppWrapper::displayWeeklyPlan(WeeklyEPlan& EPlan) const
{
	if (!EPlan.isEmpty())
	{
		NodeEP* pCur = EPlan.getpHead();

		for (int i = 0; i < 7; i++)
		{
			displayDailyPlan(pCur->getExercisePlan());
			pCur = pCur->getpNext();
		}
	}
	else
	{
		cout << "Weekly plan is empty and must be loaded!" << std::endl;
	}
}

/// <summary>
/// Displays all DietPlans contained in WeeklyDPlan linked list by calling displayDailyPlan repeatedly
/// </summary>
/// <param name="EPlan">member linked list</param>
void FitnessAppWrapper::displayWeeklyPlan(WeeklyDPlan& DPlan) const
{
	if (!DPlan.isEmpty())
	{
		NodeDP* pCur = DPlan.getpHead();

		for (int i = 0; i < 7; i++)
		{
			displayDailyPlan(pCur->getDietPlan());
			pCur = pCur->getpNext();
		}
	}
	else
	{
		cout << "Weekly plan is empty and must be loaded!" << std::endl;
	}
}

/// <summary>
/// Allows user to edit their goal for a given day of the week
/// </summary>
/// <param name="DPlans">member linked list</param>
void FitnessAppWrapper::editDailyPlan(WeeklyDPlan& DPlans)
{
	int selection = 0;
	NodeDP* pCur = DPlans.getpHead();

	while (selection != 8)
	{
		cout << "For which day of the week you wish to edit?\nSelect [1-7] or 8 to exit.\n";
		cin >> selection;
		if (selection > 0 && selection < 8)//checks for out of bounds selections
		{
			if (selection != 1)//skips itteration through list if selection is the first node
			{
				for (int i = 1; i < selection; i++)
				{
					pCur = pCur->getpNext();
				}
			}
			pCur->getDietPlan().editGoal();
			pCur = DPlans.getpHead();//resets pCur to mpHead
		}
		else if (selection != 8)
		{
			cout << "Selection out of bounds!\n";
		}
	}
	cout << "Exiting...\n";
}

/// <summary>
/// Allows user to edit their goal for a given day of the week
/// </summary>
/// <param name="DPlans">member linked list</param>
void FitnessAppWrapper::editDailyPlan(WeeklyEPlan& EPlans)
{
	int selection = 0;
	NodeEP* pCur = EPlans.getpHead();

	while (selection != 8)
	{
		cout << "For which day of the week you wish to edit?\nSelect [1-7] or 8 to exit.\n";
		cin >> selection;
		if (selection > 0 && selection < 8)//checks for out of bounds selections
		{
			if (selection != 1)//skips itteration through list if selection is the first node
			{
				for (int i = 1; i < selection; i++)
				{
					pCur = pCur->getpNext();
				}
			}
			pCur->getExercisePlan().editGoal();
			pCur = EPlans.getpHead();//resets pCur to mpHead
		}
		else if (selection != 8)
		{
			cout << "Selection out of bounds!\n";
		}
	}
	cout << "Exiting...\n";
}

/// <summary>
/// displays the apps main menu
/// </summary>
void FitnessAppWrapper::displayMenu()
{
	cout << "---Menu---\n"
		<< "1. Load weekly diet plan from file.\n"
		<< "2. Load weekly exercise plan from file.\n"
		<< "3. Store weekly diet plan to file.\n"
		<< "4. Store weekly exercise plan to file.\n"
		<< "5. Display weekly diet plan.\n"
		<< "6. Display weekly exercise plan.\n"
		<< "7. Edit daily diet plan.\n"
		<< "8. Edit daily exercse plan.\n"
		<< "9. Exit.\n"
		<< "\nENTER YOUR SELECTION > ";
}

/// <summary>
/// writes any active list to their respective files. called when the app is closed
/// </summary>
void FitnessAppWrapper::endApp()
{
	if (mWeeklyDietPlan.getpHead() != nullptr)
	{
		storeWeeklyPlan(mIputDPlan, mWeeklyDietPlan);
	}
	if (mWeeklyExercisePlan.getpHead() != nullptr)
	{
		storeWeeklyPlan(mInputEPlan, mWeeklyExercisePlan);
	}
}





