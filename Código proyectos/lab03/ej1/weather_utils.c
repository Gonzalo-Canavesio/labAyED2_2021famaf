#include <stdio.h>
#include <stdlib.h>

#include "weather_utils.h"

int temp_min(WeatherTable array){
    int temp_min = 10000;
    for(int a=0; a <YEARS; ++a){
        for(int m=0; m <12; ++m){
            for(int d=0; d <DAYS; ++d){
                if(array[a][m][d]._min_temp < temp_min){
                    temp_min = array[a][m][d]._min_temp;
                };
            };
        };
    };
    return temp_min;
}

void mayor_temps_max(WeatherTable array, int  output[YEARS]){

    for(int a=0; a <YEARS; ++a){
        int temp_max_a = -10000;
        for(int m=0; m <12; ++m){
            for(int d=0; d <DAYS; ++d){
                if(array[a][m][d]._max_temp > temp_max_a){
                    temp_max_a= array[a][m][d]._max_temp;
                };
            };
        };
        output[a] = temp_max_a;
    };
}

unsigned int cant_prec_m(WeatherTable array, int year, month_t mes){
    unsigned int cant_prec = 0u;
    for(int d=0; d <DAYS; ++d){
        cant_prec += array[year][mes][d]._rainfall;
    };
    return cant_prec;
}

void mes_max_prec(WeatherTable array, month_t output[YEARS]){
    for(int a=0; a <YEARS; ++a){
        unsigned int max_prec_a = 0u;
        month_t mes_max_prec= january;
        for(int m=0; m <12; ++m){
            if(max_prec_a < cant_prec_m(array, a, m)){
                max_prec_a = cant_prec_m(array, a, m);
                mes_max_prec = m;
            };
        };
        output[a] = mes_max_prec;
    };
}