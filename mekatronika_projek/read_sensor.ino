void baca_turbidity(){
  turbidityValue = analogRead(turbidity);
  mapT = map(turbidityValue, 610, 0, 0, 100);
  Serial.println(mapT);
}

void baca_ph(){
  phValue = analogRead(ph);
  Serial.println(phValue);
}