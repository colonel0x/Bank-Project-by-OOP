#include <iostream>
#include "ShowLoginScreen.h"
#include "Global.h"
using namespace std;







int main()
{
	
	while (FailLogin)
	{
		clsLoginScreen::ShowLoginScreen();
	};
	
	return 0;
}