#
#   Copyright (C) 2019 SCOD Organization <https://scod-lang.org>
#   All rights reserved.
#
#   Developed by: Philipp Paulweber
#                 Emmanuel Pescosta
#                 <https://github.com/scod-lang/scodc>
#
#   This file is part of scodc.
#
#   scodc is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#
#   scodc is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with scodc. If not, see <http://www.gnu.org/licenses/>.
#

TARGET = scodc

FORMAT  = src
FORMAT += src/*
FORMAT += etc
FORMAT += etc/*
FORMAT += etc/*/*

CONFIG  = ../../lib/stdhl
ifeq ($(wildcard $(CONFIG)/.cmake/.*),)
  CONFIG = lib/stdhl
  ifeq ($(wildcard $(CONFIG)/.cmake/.*),)
    $(shell git submodule update --init $(CONFIG) && git -C $(CONFIG) checkout master)
  endif
endif

INCLUDE = $(CONFIG)/.cmake/config.mk
include $(INCLUDE)
