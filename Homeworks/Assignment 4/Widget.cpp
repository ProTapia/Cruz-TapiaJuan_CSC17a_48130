/* 
 * File:   Widget.cpp
 * Author: Juan Cruz Tapia
 * 
 * Created on November 18, 2014, 1:03 AM
 */

#include "Widget.h"

Widget::Widget()
{
    shiftHours = 16;   //Declaring shift hours to 16
    widgetHour = 10;   //Declaring the widgets per hour to 10
    widgetOrder = 0;   //Declaring the order to 0
    days = 0;          //Declaring the days of manufacture to 0
}

//Mutator to get the number of widgets ordered
void Widget::getWidgets(float order) { widgetOrder = order; }

//Accessor to calculate the days
float Widget::getDays()
{
    //Calculating the days to complete the order
    days = widgetOrder / (shiftHours * widgetHour);
    
    //Returning result
    return days;
}

