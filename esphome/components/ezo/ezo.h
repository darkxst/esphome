#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/i2c/i2c.h"

namespace esphome {
namespace ezo {

/// This class implements support for the EZO circuits in i2c mode
class EZOSensor : public sensor::Sensor, public PollingComponent, public i2c::I2CDevice {
 public:
  void loop() override;
  void dump_config() override;
  void update() override;
  float get_setup_priority() const override { return setup_priority::DATA; };

  void set_tempcomp_value(float temp);
  void set_probe_type(float probe_type);
  void set_calibration_single(float value);
  void set_calibration_point(int point, float value);

 protected:
  uint32_t start_time_ = 0;
  uint32_t wait_time_ = 0;
  uint16_t state_ = 0;
  float tempcomp_;
  void set_probe_type(float probe_type);
  void set_calibration_single(float value);
  void set_calibration_point(int point, float value);
};

}  // namespace ezo
}  // namespace esphome
