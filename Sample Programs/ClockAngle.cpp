#include <iostream>
#include <algorithm>

using namespace std;

int calcAngle(int h, int m)
{
    // validate the input
    if (h <0 || m < 0 || h >12 || m > 60)
        cout<<"Wrong input"<<endl;
	
	
    if (h == 12) h = 0;
    if (m == 60) m = 0;

    // Calculate the angles moved by hour and minute hands 
    // with reference to 12:00
    int hour_angle = 0.5 * (h*60 + m);  //[for 12 hrs hours hand will go 360deg => (h/12)*360] + [In 60 min hours hand will go (1/12)*360 => In m mins it will be (m/60)*(1/12)*360]
    int minute_angle = 6*m;// in 60 min minutes hand will go to 360, in m minutes (m/60)* 360

    // Find the difference between two angles
    int angle = abs(hour_angle - minute_angle);

    // Return the smaller angle of two possible angles
    angle = min(360-angle, angle);

    return angle;
}

// Driver program to test above function
int main()
{
    cout<<calcAngle(9, 60)<<endl;
    cout<<calcAngle(3, 30)<<endl;
    return 0;
}