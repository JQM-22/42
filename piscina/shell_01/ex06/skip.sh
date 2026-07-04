#!/bin/sh

ls -la | awk 'NR % 2 == 1'
