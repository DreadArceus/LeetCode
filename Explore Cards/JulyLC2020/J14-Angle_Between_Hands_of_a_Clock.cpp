#include <iostream>
#include <cmath>
using namespace std;
double AbwHands(int hour, int minutes)
{
  double aMin = 6 * minutes, aHour = 30 * hour + 0.5 * minutes;
  if(hour == 12) //Upon further analysis, this part is not needed
  {
    aHour -= 360;
  }
  double angle = abs(aHour - aMin);
  if(angle > 180)
  {
    return 360 - angle;
  }
  return angle;
}
int main()
{
  int h, m;
  cin >> h >> m;
  double angle = AbwHands(h, m);
  cout << "The angle is: " << angle;
}
//1 minute is 6 degrees
//1 hour is 30 degrees + minutes/60 * 30 degrees
