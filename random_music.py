#!/usr/bin/python

# Also random music button without the Arduino. 

import RPi.GPIO as GPIO
import shlex, subprocess

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(10, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.setup(12, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
Play = False

while True:
    if GPIO.input(10) == GPIO.HIGH and Play == False:
        print("Playing music")
        Play = True
        Vlc_process = subprocess.Popen(shlex.split("vlc /home/pi/Playlist-para-programar/Soundtrack . -Z"))
    
    if GPIO.input(12) == GPIO.HIGH and Play == True:
        Play = False
        Vlc_process.terminate()
        print("Stopped music")
