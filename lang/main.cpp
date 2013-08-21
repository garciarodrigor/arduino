#include <Arduino.h>
#include <rgb.h>

//rgb black;
rgb_t black;

void setup()
{
    Serial.begin(9600);

    black = rgb_new(127, 200, 220);
}

void loop()
{
    /**
     * Black
     */
    Serial.print("Black: ");

    Serial.print(rgb_get_red(black));
    Serial.print(",");

    Serial.print(rgb_get_green(black));
    Serial.print(",");

    Serial.println(rgb_get_blue(black)); 
}
