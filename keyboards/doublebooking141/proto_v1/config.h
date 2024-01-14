// Copyright 2024 doublebooking141 (@doublebooking141)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define SPI_CS_PIN  GP0
#define SPI_SCK_PIN GP18
#define SPI_MISO_PIN GP16
#define SPI_MOSI_PIN GP19

#define I2C_DRIVER I2CD0
#define I2C1_SCL_PIN        GP9
#define I2C1_SDA_PIN        GP8
#define OLED_FONT_H "./lib/glcdfont.c"

#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 7
#define AUTO_MOUSE_TIME 800
#define AUTO_MOUSE_DELAY 500
#define AUTO_MOUSE_DEBOUNCE 80

#define ANALOG_JOY_STICK_XAXIS_PIN GP27
#define ANALOG_JOY_STICK_YAXIS_PIN GP28