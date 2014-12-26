#include <ch.hpp>
#include <hal.h>

#include <array> // TODO(kyle):
#include <protocol/protocol.hpp>
#include <protocol/messages.hpp>
#include <protocol/encoder.hpp>
#include <protocol/decoder.hpp>

#include <hal_config.hpp>
#include <platform_config.hpp>

// Misc
#include <communication.hpp>
#include <debugger.hpp>

static platform::HeartbeatThread heartbeatThread;
static CommunicationThread communicationThread(reinterpret_cast<BaseChannel *>(&SD1));
static Debugger debugger;

int main(void) {
  halInit();
  chibios_rt::System::init();

  // Start the background threads
  heartbeatThread.start(LOWPRIO);
  communicationThread.start(LOWPRIO);
  debugger.start(LOWPRIO);

  // Build and initialize the system
  platform::init();

  // Loop at a fixed rate forever
  // NOTE: If the deadline is ever missed then the loop will hang indefinitely.
  systime_t deadline = chTimeNow();
  while(true) {
    deadline += MS2ST(DT * 1000);

    platform::system.update();

    chibios_rt::BaseThread::sleepUntil(deadline);
  }

  return 0;
}
