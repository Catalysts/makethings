int dist_table[][2] = { // calibration table cm to analog value
  {5, 630}, {10, 500}, {15, 340}, {20, 250}, {25, 200}, 
  {30, 180}, {35, 170}, {40, 140}, {50, 120}, {55, 115}, 
  {60, 106}, {65, 102}, {70, 98}, {75, 94}, {80, 90}
};
int filter(int prev, int curr) { // filter function
  const float filterVal = 0.1;
  return (int)((float)curr * filterVal + (float)prev * (1 - filterVal));
}
int distance(int pin) { // get current distance from sensor
  const int tries = 10, ms = 1;
  int val = analogRead(pin);
  for (int i = 1; i < tries; i++) { // approximate several values taken with delay
    val = filter(val, analogRead(pin));
    delay(ms);
  }
  int len = sizeof(dist_table) / sizeof(dist_table[0]);
  for (int i = 0; i <= len; i++) { // find closest value in table and interpolate if possible
    if (val >= dist_table[i][1]) {
      if (i > 0) {
        return map(val, dist_table[i][1], dist_table[i-1][1], dist_table[i][0], dist_table[i-1][0]);
      } else {
        return dist_table[i][0];
      }
    }
  }
  return dist_table[len - 1][0];
}
void setup() { 
  pinMode(A0, INPUT);
  Serial.begin(9600);
} 
void loop() { 
  delay(500);
  int curr_dist = distance(A0);
  Serial.println(analogRead(A0));
  Serial.print(curr_dist);
  Serial.println("cm");
}
