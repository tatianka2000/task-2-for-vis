#include "Sensor.h"
#include <iostream>
#include <vector>

int main()
{
    TemperatureSensor tSensor;
    tSensor.setData(1);
 
    WeightSensor wSensor;
    wSensor.setData(2);
    
    StrangeSensorWrapper sSensor(new StrangeSensor); 

    std::cout << tSensor.getName() << "\t" <<tSensor.getData() << std::endl;     
    std::cout << wSensor.getName() << "\t" <<wSensor.getData() << std::endl;
    std::cout << sSensor.getName() << "\t" <<sSensor.getData() << std::endl;

    return 0;
}