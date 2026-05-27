#!/bin/bash
logdir=/var/log/adtimer
mkdir -p $logdir
nohup /home/adarsh/Documents/dev/adtimer/adtimer $@ > $logdir/nohup.out 2>&1 &
