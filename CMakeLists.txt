cmake_minimum_required(VERSION 3.22)
project(Lab_06c_Countdown)

set(CMAKE_C_STANDARD 99)

add_executable(countdown
        main.c countdown.h countdownMath.c countdownMath.h)
