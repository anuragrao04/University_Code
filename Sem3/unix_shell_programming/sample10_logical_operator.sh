#!/bin/sh

grep "sh" sample1.sh || echo "The substring sh not found in sample1.sh"

grep "sssh" sample1.sh || echo "The substring sssh not found in sample1.sh"

grep "sh" sample1.sh && echo "The substring sh is found in sample1.sh"