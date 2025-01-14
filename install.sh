#!/bin/bash
sudo make clean
sudo rmmod nvidia_drm nvidia_modeset nvidia_uvm nvidia
set -e
CC=gcc-12 CXX=g++ sudo make modules -j$(nproc)
CC=gcc-12 CXX=g++ sudo make modules_install -j$(nproc)
sudo depmod
nvidia-smi
