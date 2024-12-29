#pragma once

// =======================================================
// Cirque Trackpad Settings
// =======================================================
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP0
#define SPI_MOSI_PIN GP3
#define SPI_MISO_PIN GP1
#define POINTING_DEVICE_CS_PIN GP2
#undef CIRQUE_PINNACLE_DIAMETER_MM
#define CIRQUE_PINNACLE_DIAMETER_MM 40
#define CIRQUE_PINNACLE_CURVED_OVERLAY
//#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
//#define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE


// =======================================================
// Reset Settings
// =======================================================
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
