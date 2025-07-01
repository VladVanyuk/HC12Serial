# HC12 Serial Communication Library
# https://github.com/VladVanyuk/HC12Serial

cmake_minimum_required(VERSION 3.5)

idf_component_register(SRCS "HC12Serial.cpp"
                       INCLUDE_DIRS "."
                       REQUIRES arduino)

project(HC12Serial)