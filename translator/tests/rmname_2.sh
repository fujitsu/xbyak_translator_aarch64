#!/bin/bash

cd expected_value 

#for f in `ls`; do mv $f ${f/kawakami./}; done
   
#for f in `ls`; do mv $f ${f/kurihara./}; done 

#for f in `ls`; do mv $f ${f/kurume./}; done

#for f in `ls`; do mv $f ${f/sakamoto./}; done
          
#for f in `ls`; do mv $f ${f/qnet_nomoto./}; done 

#for f in `ls`; do mv $f ${f/qnet_higuchi./}; done

#for f in `ls`; do mv $f ${f/qnet_suzuki./}; done

find -name "*kawakami*" -exec rm {} \;
find -name "*kurihara*" -exec rm {} \;
find -name "*sakamoto*" -exec rm {} \;
find -name "*qnet_nomoto*" -exec rm {} \;
find -name "*qnet_higuchi*" -exec rm {} \;
find -name "*qnet_suzuki*" -exec rm {} \;
find -name "*aarch64*" -exec rm {} \;

for f in `ls`; do mv $f ${f/kurume./}; done
