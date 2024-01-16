#include "blink.h"

LEDCUBE_NAMESPACE_BEGIN

Blink::Blink() {
  //
}

void Blink::tick() {
  Log.info("toggle");
  print_to_serial();
  update(ALL_CUBE, TOGGLE);
}

int Blink::frequency() { return 1000; }

LEDCUBE_NAMESPACE_END