#!/bin/bash -
#===============================================================================
#
#          FILE: travis_prepare_linux.sh
#
#         USAGE: ./travis_prepare_linux.sh
#
#   DESCRIPTION:  Prepare linux build environment on travis.
#
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: Always run with sudo permission.
#        AUTHOR: Dilawar Singh (), dilawars@ncbs.res.in
#  ORGANIZATION: NCBS Bangalore
#       CREATED: 01/02/2017 10:10:02 AM
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error
set +e  # Let installation fail in some command

apt-get install -qq make cmake
apt-get install -qq python3-dev
apt-get install -qq libboost-all-dev