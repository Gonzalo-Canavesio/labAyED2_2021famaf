#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H

#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"
#include "weather.h"

int temp_min(WeatherTable array);

void mayor_temps_max(WeatherTable array, int res[YEARS]);

unsigned int cant_prec_m(WeatherTable array, int year, month_t mes);

void mes_max_prec(WeatherTable array, month_t res[YEARS]);

#endif