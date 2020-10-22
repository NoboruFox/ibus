#!/bin/sh
stm8flash -c stlinkv2 -p stm8s003?3 -w build/ibus.ihx
