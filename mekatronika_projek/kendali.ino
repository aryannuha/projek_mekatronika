void logikaFuzzy(){
  if (mapPh >= 9){
    basa.write(180);
    asam.write(0);
  }else if (mapPh >= 7.5 && mapPh < 9){
    basa.write(90);
    asam.write(0);
  }else if (mapPh < 7.5 && mapPh >= 6.5){
    basa.write(0);
    asam.write(0);
  }else if(mapPh < 6.5 && mapPh >= 4){
    asam.write(90);
    basa.write(0);
  }else if(mapPh < 4){
    asam.write(180);
    basa.write(0);
  }
}