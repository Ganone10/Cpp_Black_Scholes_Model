cmake_minimum_required(VERSION 3.21)
project(volatility_options)

set(CMAKE_CXX_STANDARD 14)

add_executable(volatility_options main.cpp black_scholes.h.cpp black_scholes.h bs_prices.h black_scholes.cpp newton_raphson.h)
