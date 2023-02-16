#!/usr/bin/bash

scp -P 2022 cat/s21_cat grep/s21_grep send_copy.sh zero@134.0.106.127:/home/zero
ssh -p 2022 zero@134.0.106.127 'chmod +x send_copy.sh'
ssh -p 2022 zero@134.0.106.127 'bash send_copy.sh'

# ssh -p 2022 zero@134.0.106.127 mv s21_cat s21_grep /usr/local/bin

