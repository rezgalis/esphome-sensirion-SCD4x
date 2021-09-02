# HA esphome-sensirion-SCD4x
Script &amp; config to enable in Home Assistant ESPHome SCD4x CO2 sensor by Sensirion

## Setup steps:
1. Copy script `scd41_sensor.h` into `/config/esphome/`
2. Create a new sensor in ESPHome and use `sensor.yaml` as example; make sure to update (at least) sections with `CHANGEME` and change pin assignment or features as necessary
3. Upload and enjoy

## *TODO:*
1. Add pictures/schematic for hardware setup & wiring 
2. Add proper error output (see commented lines in `scd41_sensor.h`)
4. Add flexibility to post data (via parameters and/or [ESPHome HTTP Request](https://esphome.io/components/http_request.html))
