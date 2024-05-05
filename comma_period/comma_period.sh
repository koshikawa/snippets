#!/bin/sh
perl -pi -e 's/、/，/g; s/。/．/g;' $1
