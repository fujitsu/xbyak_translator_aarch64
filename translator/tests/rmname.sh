#!/bin/bash

cd expected_value 

for f in `ls`; do mv $f ${f/kawakami./}; done
   
for f in `ls`; do mv $f ${f/kurihara./}; done 

for f in `ls`; do mv $f ${f/kurume./}; done

for f in `ls`; do mv $f ${f/sakamoto./}; done
          
for f in `ls`; do mv $f ${f/qnet_nomoto./}; done 

for f in `ls`; do mv $f ${f/qnet_higuchi./}; done

for f in `ls`; do mv $f ${f/qnet_suzuki./}; done

