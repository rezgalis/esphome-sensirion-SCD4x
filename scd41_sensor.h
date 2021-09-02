#include "esphome.h"
#include "SensirionI2CScd4x.h"

class scd41_sensor : public PollingComponent, public Sensor {
 public:

  SensirionI2CScd4x scd4x;
  Sensor *temperature_sensor = new Sensor();
  Sensor *humidity_sensor = new Sensor();
  Sensor *co2_sensor = new Sensor();

  scd41_sensor() : PollingComponent(60000) {}

  float get_setup_priority() const override { return esphome::setup_priority::BUS; }

  void setup() override {
    Wire.begin();
    scd4x.begin(Wire);
    scd4x.stopPeriodicMeasurement();
    scd4x.startPeriodicMeasurement();
  }
  
  void update() override {
    //char errorMessage[256];
    //uint16_t error;
    uint16_t co2;
    float temperature;
    float humidity;
    error = scd4x.readMeasurement(co2, temperature, humidity);
    if (error) {
   //     errorToString(error, errorMessage, 256);
   //     ESP_LOGE("custom", String(errorMessage));
    } else {
        temperature_sensor->publish_state(temperature);
        humidity_sensor->publish_state(humidity);
        co2_sensor->publish_state(co2);
    }
  }
};
