# -*- coding: utf-8 -*-
"""
Created on Mon Mar  1 01:43:18 2021

@author: בצלאל אברהמי
"""

places = ['Berlin', 'Cape Town', 'Sydney', 'Moscow']

with open('list.txt', 'w') as filehandle:
    for listitem in places:
        filehandle.write('%s\n' % listitem)