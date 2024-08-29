#include <assert.h>
#include <iostream>
using namespace std;

bool isBatteryTemperatureOk(float temperature)
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

bool isBatteryStateOfChargeOk(float soc)
{
 if (soc < 20 || soc > 80)
 {
		cout << "State of Charge out of range!\n";
		return false;
 }
	else
 {
	 return true;
 } 
}

bool isBatteryChargeRateOk(float chargeRate)
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

bool batteryIsOk(float temperature, float soc, float chargeRate)
{
    bool tempOk = isBatteryTemperatureOk(temperature);
    bool socOk = isBatteryStateOfChargeOk(soc);
    bool chargeRateOk = isBatteryChargeRateOk(chargeRate);
	  return (tempOk && socOk && chargeRateOk);
}

void testBatteryIsOk()
{
    assert(batteryIsOk(25, 70, 0.7) == true);
    assert(batteryIsOk(50, 85, 0) == false);
}

int main()
{
    testBatteryIsOk();
    return 0;
 
}
