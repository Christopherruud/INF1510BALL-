INF1510BALL+
=============
Repository for the code written for B.A.L.L+ INF1510

B.A.L.L is both the word ball and an acronym:
Ball.Arduino.Leisure.Leather
(Ball, Arduino, Lek, Lær in norwegian)

Code used in the Ball+ - project at the University of Oslo,Institute of Informatics cource of INF1510, spring 2014. Project members are -Christopher Neuman Ruud -Ina Vangen -Harry Hermosa -Mette Sundal

The code coordinates an Arduino, a Skylab SKM53 GPS, a memory card reader/writer and a gyro/accelerometer.

Format for the logfile:
TIMESTAMP (millis),
GPS LATITUDE (2.6),
GPS LONGITUDE (2.6),
FILTERED ACC X (+-1,2),
FILTERED ACC Y (+-1,2),
FILTERED ACC Z (+-1,2)

Example: 175885,59.900570,10.803628,3.52,-3.44,4.87
