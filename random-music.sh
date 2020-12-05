#!/usr/bin/bash

# This script can be used in Termux (Android) to play random music in the Phone. 
# Need to install termux, clone this repo and install play-audio.

cd /data/data/com.termux/files/home/Playlist-para-programar/Soundtrack/ && play-audio $(ls | sort -R)
