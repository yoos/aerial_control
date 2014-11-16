#include <motor/esra_rocket_motor_mapper.hpp>

#include <array>

EsraRocketMotorMapper::EsraRocketMotorMapper() {
}

void EsraRocketMotorMapper::init() {
  PWMMotorMapper::init();
}

void EsraRocketMotorMapper::run(actuator_setpoint_t& input) {
  // Calculate output shifts
  std::array<float, 4> output_shifts = {
     1.0f * input.pitch_sp + 1.0f * input.roll_sp + 1.0f * input.yaw_sp, // front left
    -1.0f * input.pitch_sp + 1.0f * input.roll_sp - 1.0f * input.yaw_sp, // front right
    -1.0f * input.pitch_sp - 1.0f * input.roll_sp + 1.0f * input.yaw_sp, // back right
     1.0f * input.pitch_sp - 1.0f * input.roll_sp - 1.0f * input.yaw_sp  // back left
  };

  // Add throttle to shifts to get absolute output value
  std::array<float, 4> outputs = { 0 };
  for(int i = 0; i < 4; i++) {
    outputs[i] = input.throttle_sp + output_shifts[i];
  }

  setMotorSpeeds(outputs);
}