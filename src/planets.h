#pragma once
  
#include <pebble.h>
  
static const uint8_t PLANET_COLORS[] = {
  GColorLightGrayARGB8,
  GColorIcterineARGB8,
  GColorCobaltBlueARGB8,
  GColorDarkCandyAppleRedARGB8,
  GColorWindsorTanARGB8,
  GColorPastelYellowARGB8,
  GColorCelesteARGB8,
  GColorBlueMoonARGB8
};

static const uint8_t PLANET_RADII[] = {
  2,
  2,
  2,
  2,
  4,
  4,
  3,
  3
};

#define N_PLANETS 8

static const uint8_t MOON_COLOR = GColorLightGrayARGB8;
static const uint8_t MOON_DIAMETER = 4;

void calculate_planet_time(time_t now);
int32_t get_planet_angle(int index);
int32_t get_moon_angle();