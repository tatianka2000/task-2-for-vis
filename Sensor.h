#include <string>

// simple Sensor interface
class Sensor
{
protected: 
    std::string m_name;   

public:
    const std::string& getName() { return m_name; }
    virtual int getData() = 0; 
    virtual void setData(int) = 0; 
};

// concrete sensor with Sensor interface
class WeightSensor: public Sensor
{
private:
    int m_weight;
    // etc
public: 
    WeightSensor() { m_name = "WeightSensor"; }

    int getData() { return m_weight; }
    void setData(int data) { m_weight = data; }
};

// concrete sensor with Sensor interface
class TemperatureSensor: public Sensor
{
private:
    int m_temp;

public:
    TemperatureSensor() { m_name = "TemperatureSensor"; }

    int getData() { return m_temp; }
    void setData(int data) { m_temp = data; }
};

// another sensor
class StrangeSensor
{
private:
    std::string m_sensorName;
    std::string m_databuf;
public:
    StrangeSensor()
    {
        m_sensorName = "StrangeSensor";
        m_databuf = "12";
    }
    std::string getBuf() { return m_databuf; }
    std::string getSensorName() { return m_sensorName; }
};

// we want to access StrangeSensor data by Sensor interfase... 
class StrangeSensorWrapper : public Sensor
{
private:
    StrangeSensor *m_sensor;
public:
    StrangeSensorWrapper(StrangeSensor * sensor)
    {
        m_sensor = sensor;
        m_name = sensor->getSensorName();
    }

    void setData(int data){}

    int getData()
    {
        return atoi(m_sensor->getBuf().c_str());
    }
};