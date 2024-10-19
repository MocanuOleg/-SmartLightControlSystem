# -SmartLightControlSystem
The Smart Light Control System is a project that automates the lighting in a room using a combination of sensors and manual controls. The system uses a motion sensor, light sensor, and manual buttons to turn the lights on or off, depending on the ambient light conditions and the presence of people in the room.
Components Used:
Arduino, PIR Motion Sensor, LDR, LED, 2 Push Buttons, LCD Display.
How It Works
    When motion is detected and the ambient light level is below the set threshold, the light automatically turns on.
    If the room is bright enough (ambient light level above threshold), the light will stay off even if motion is detected.
    The system can also be manually controlled using the buttons:
    Button 1 manually toggles the light ON/OFF.
    Button 2 adjusts the light threshold for automatic light control.
