cmake_minimum_required(VERSION 3.5)

project(GymApplication LANGUAGES C)

add_executable(GymApplication main.c
    Gym.cpp
    Gym_Header.h)

include(GNUInstallDirs)
install(TARGETS GymApplication
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
