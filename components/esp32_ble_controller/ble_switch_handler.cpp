#include "ble_switch_handler.h"

#ifdef USE_SWITCH

#include "esphome/core/log.h"

namespace esphome {
namespace esp32_ble_controller {

static const char *TAG = "ble_switch_handler";

// BLESwitchHandler::BLESwitchHandler(Switch* component, const BLECharacteristicInfoForHandler& characteristic_info)  : BLEComponentHandler(component, characteristic_info) 
// {
//   set_value(component->state); // do not send yet!
// }

void BLESwitchHandler::on_characteristic_written() {
  std::string value = get_characteristic()->getValue();
  if (value.length() == 1) {
    uint8_t on = value[0];
    ESP_LOGD(TAG, "Switch chracteristic written: %d", on);
    if (value==1)
      get_component()->turn_on();
    else
      get_component()->turn_off();
  }
}

} // namespace esp32_ble_controller
} // namespace esphome

#endif
