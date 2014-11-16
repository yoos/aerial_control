#include <input/ppm_input_source.hpp>

PPMInputSource::PPMInputSource()
  : state(PPMState::UNSYNCED),
    currentChannel(0),
    lastFrameStart(0) {
  icuInit();
  // icuStart(&ICUD1, ); // TODO
}

void PPMInputSource::trigger() {
  systime_t frameStart = chTimeNow();

  systime_t lastFrameWidth = frameStart - lastFrameStart;
  switch(state) {
    case PPMState::UNSYNCED:
      // If this frame looks like a start frame, ignore it and move to the
      // LOCKED state.
      if(lastFrameWidth > MIN_START_WIDTH) {
        state = PPMState::SYNCED;
      }

      break;
    case PPMState::SYNCED:
      if(lastFrameWidth > MIN_START_WIDTH) {
        // Start frame. Reset channel counter and flip the buffer.
        currentChannel = 0;
        channelBuffer = channelTempBuffer; // copy

        state = PPMState::SYNCED;
      } else if(lastFrameWidth > MIN_CHANNEL_WIDTH && lastFrameWidth < MAX_CHANNEL_WIDTH) {
        // Channel frame.
        channelTempBuffer[currentChannel] = lastFrameWidth;
        currentChannel++;
      } else {
        // Something went wrong. Reset to unsynced state.
        state = PPMState::UNSYNCED;
      }

      break;
  }

  lastFrameStart = frameStart;
}

controller_input_t PPMInputSource::read() {
  controller_input_t input = {
    .roll_sp = 0.0f,
    .pitch_sp = 0.0f,
    .yaw_sp = 0.0f,
    .throttle_sp = 0.0f
  };

  return input;
}