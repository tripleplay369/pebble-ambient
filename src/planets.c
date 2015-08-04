#include "planets.h"
  
static const float DEGREES_PER_DAY[] = {
  4.092385f,
  1.602159f,
  0.9855931f,
  0.5240218f,
  0.08310024f,
  0.03333857f,
  0.01162075f,
  0.005916098f
};

static const float DEGREES_AT_REFERENCE[] = {
  281.18017f + 180.0f,
  20.17002f + 180.0f,
  333.58600f + 180.0f,
  73.77336f + 180.0f,
  292.64251f + 180.0f,
  8.91324f + 180.0f,
  298.87491f + 180.0f,
  297.58472f + 180.0f
};

static const float MOON_DEGREES_AT_REFERENCE = 280.36375f + 180.0f;
static const float MOON_DEGREES_PER_DAY = 13.17619501f;
  
static const time_t REFERENCE_TIME = 840931200;
static const int SECONDS_PER_DAY = 86400;

static int days_since_reference = 0;

void calculate_planet_time(time_t now)
{
  days_since_reference = (now - REFERENCE_TIME) / SECONDS_PER_DAY;
}
  
int32_t get_planet_angle(int index) {
  int degrees = (int)(DEGREES_AT_REFERENCE[index] + DEGREES_PER_DAY[index] * days_since_reference) % 360;
  return TRIG_MAX_ANGLE * degrees / 360;
}

int32_t get_moon_angle() {
  int degrees = (int)(MOON_DEGREES_AT_REFERENCE + MOON_DEGREES_PER_DAY * days_since_reference) % 360;
  return TRIG_MAX_ANGLE * degrees / 360;
}