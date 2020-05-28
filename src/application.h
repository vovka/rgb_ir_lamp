#include <Arduino.h>
#include <LowPower.h>
#include "effects/basic_effect.h"
#include "effects/red_effect.h"
#include "effects/green_effect.h"
#include "effects/blue_effect.h"
#include "effects/police_effect.h"
#include "effects/rainbow_effect.h"
#include "effects/smooth_transition_effect.h"
#include "effects/white_effect.h"
#include "effects/manual_effect.h"
#include "effects/harmonic_transition_effect.h"
#include "effects/smooth_rainbow_effect.h"
#include "effects/flame_effect.h"
#include "ir_controller.h"
#include "logger.h"

class Application {
  int effects_amount = 12;
  Effect* effects[12] = {
    new RedEffect(),
    new FlameEffect(),
    new SmoothRainbowEffect(),
    new GreenEffect(),
    new PoliceEffect(),
    new BlueEffect(),
    new ManualEffect(),
    new BasicEffect(),
    new RainbowEffect(),
    new SmoothTransitionEffect(),
    new HarmonicTransitionEffect(),
    new WhiteEffect()
  };
  Effect* currentEffect;
  int red_pin_number, green_pin_number, blue_pin_number, battery_indicator_pin_number;
  volatile int currentEffectNumber;
  // int debounceTime;
  IRController irController;
  static const int onPowerActionNumber = 1,
      onVolumeUpActionNumber = 2,
      onVolumeDownActionNumber = 3,
      onChannelUpActionNumber = 4,
      onChannelDownActionNumber = 5,
      onButton0ActionNumber = 6,
      onButton1ActionNumber = 7,
      onButton2ActionNumber = 8,
      onButton3ActionNumber = 9,
      onButton4ActionNumber = 10,
      onButton5ActionNumber = 11,
      onButton6ActionNumber = 12,
      onButton7ActionNumber = 13,
      onButton8ActionNumber = 14,
      onButton9ActionNumber = 15,
      onUpActionNumber = 16,
      onDownActionNumber = 17,
      onInfoActionNumber = 18;
  static void wakeUp();

public:
  Application();
  Application(int, int, int, int, int);
  void tick();
  void changeEffect(int);
  void pollIR();
  void onPower();
  void onUp();
  void onDown();
  void onVolumeUp();
  void onVolumeDown();
  void onChannelUp();
  void onChannelDown();
  void onButton0();
  void onButton1();
  void onButton2();
  void onButton3();
  void onButton4();
  void onButton5();
  void onButton6();
  void onButton7();
  void onButton8();
  void onButton9();
  void onInfo();
  static Logger logger;
};
