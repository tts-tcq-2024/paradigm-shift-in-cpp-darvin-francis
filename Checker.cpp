#include <assert.h>
#include <iostream>
using namespace std;
bool batteryTempatureStatus(float temperature);
bool batteryChargeIndicator(float soc, float chargeRate);
bool batteryChargeRate(float chargeRate);

bool batteryIsOk(float temperature, float soc, float chargeRate)
{
 if (batteryTempatureStatus(temperature) && batteryChargeIndicator(soc, chargeRate))
 {
		return true;
 }
 else
 {
		return false;
 }
}

bool batteryTempatureStatus(float temperature)
{
 if (temperature < 0 || temperature > 45)
 {
		cout << "Temperature out of range!\n";
		return false;
 }
 else
 {
		return true;
 }
}

bool batteryChargeIndicator(float soc, float chargeRate)
{
 if (soc < 20 || soc > 80)
 {
		cout << "State of Charge out of range!\n";
		return false;
 }
 return batteryChargeRate(chargeRate);
 
}

bool batteryChargeRate(float chargeRate)
{
 if (chargeRate > 0.8)
 {
		cout << "Charge Rate out of range!\n";
		return false;
 }
 else
 {
		return true;
 }
}

int main()
{
 assert(batteryIsOk(25, 70, 0.7) == true);
 assert(batteryIsOk(50, 85, 0) == false);
}
