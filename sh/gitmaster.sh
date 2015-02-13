#!/bin/sh
#By: isca
#Curitiba - 13/02/2014
#
#Git checkout all repositories and submodules to the master branch
#
git submodule foreach --recursive git checkout master
