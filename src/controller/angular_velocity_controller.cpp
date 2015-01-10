#include "controller/angular_velocity_controller.hpp"

#include <algorithm>

#include "unit_config.hpp"

AngularVelocityController::AngularVelocityController()
  : rollVelPid(unit_config::ANGVEL_X_KP, unit_config::ANGVEL_X_KI, unit_config::ANGVEL_X_KD),
    pitchVelPid(unit_config::ANGVEL_Y_KP, unit_config::ANGVEL_Y_KI, unit_config::ANGVEL_Z_KD),
    yawVelPid(unit_config::ANGVEL_Z_KP, unit_config::ANGVEL_Z_KI, unit_config::ANGVEL_Z_KD) {
}

actuator_setpoint_t AngularVelocityController::run(const attitude_estimate_t& estimate, const angular_velocity_setpoint_t& input) {
  float rollActuatorSp = rollVelPid.calculate(input.roll_vel_sp, estimate.roll_vel, unit_config::DT);
  float pitchActuatorSp = pitchVelPid.calculate(input.pitch_vel_sp, estimate.pitch_vel, unit_config::DT);
  float yawActuatorSp = yawVelPid.calculate(input.yaw_vel_sp, estimate.yaw_vel, unit_config::DT);

  // Limit to maximum angular velocities
  rollActuatorSp = std::max(-unit_config::MAX_PITCH_ROLL_VEL, std::min(unit_config::MAX_PITCH_ROLL_VEL, rollActuatorSp));
  pitchActuatorSp = std::max(-unit_config::MAX_PITCH_ROLL_VEL, std::min(unit_config::MAX_PITCH_ROLL_VEL, pitchActuatorSp));

  actuator_setpoint_t setpoint {
    .roll_sp = rollActuatorSp,
    .pitch_sp = pitchActuatorSp,
    .yaw_sp = yawActuatorSp,
    .throttle_sp = input.throttle_sp
  };

  return setpoint;
}
