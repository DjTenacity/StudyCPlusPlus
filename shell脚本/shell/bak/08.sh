#!/bin/bash

function myfun
{
	value=$[ $value * 2 ]
}

value=10
myfun
echo "value:$value"
