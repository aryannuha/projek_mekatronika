void baca_turbidity(){
  turbidityValue = analogRead(turbidity);
  mapT = map(turbidityValue, 610, 0, 0, 100);
  Serial.print("Turbidity: ");
  Serial.print(mapT);
}

void baca_ph(){
  phValue = analogRead(ph);
  voltage = phValue * (vref / adc_res);
  mapPh = ph_scale * voltage + ph_offset;
  Serial.print(" | Ph: ");
  Serial.println(mapPh);
}
