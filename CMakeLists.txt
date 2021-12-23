cmake_minimum_required(VERSION 3.21)
project(CPP2022)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(fmod)
include_directories(fmod/4.3)
include_directories(fmod/Developer)
include_directories("fmod/Developer/FMOD Programmers API Mac")
include_directories("fmod/Developer/FMOD Programmers API Mac/api")
include_directories("fmod/Developer/FMOD Programmers API Mac/api/inc")

add_executable(CPP2022
        fmod/4.3/fmod.h
        fmod/4.3/fmod.hpp
        fmod/4.3/fmod_codec.h
        fmod/4.3/fmod_dsp.h
        fmod/4.3/fmod_errors.h
        fmod/4.3/fmod_memoryinfo.h
        fmod/4.3/fmod_output.h
        fmod/4.3/fmodlinux.h
        "fmod/Developer/FMOD Programmers API Mac/api/inc/fmod.h"
        "fmod/Developer/FMOD Programmers API Mac/api/inc/fmod.hpp"
        "fmod/Developer/FMOD Programmers API Mac/api/inc/fmod_codec.h"
        "fmod/Developer/FMOD Programmers API Mac/api/inc/fmod_dsp.h"
        "fmod/Developer/FMOD Programmers API Mac/api/inc/fmod_errors.h"
        "fmod/Developer/FMOD Programmers API Mac/api/inc/fmod_memoryinfo.h"
        "fmod/Developer/FMOD Programmers API Mac/api/inc/fmod_output.h"
        Chasseur.cc
        Chasseur.h
        Environnement.h
        FireBall.h
        Gardien.h
        Labyrinthe.cc
        Labyrinthe.h
        MatriceOfCaracters.cpp
        MatriceOfCaracters.h
        Mover.h
        ReadFile.cpp
        ReadFile.h
        Sound.h)
