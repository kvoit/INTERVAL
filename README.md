# INTERVAL

## Description

Precompiler directive for short and elegant interval timing. 

    INTERVAL(1000,millis()) {
        mycode();
    }

executes `mycode` every 1000 milliseconds starting at first invocation.

The precompiler directive creates a static local variable in a block before the code in question and then carries out the information with a single global variable, allowing arbitrarily many INTERVAL blocks.

## Credits

This is mostly an MIT reimplementation of the [INTERVAL library](https://forum.arduino.cc/index.php?topic=413734.0) published by user combie on https://forum.arduino.cc.

Notable differences include:

* Code is executed at first invocation, instead of after one interval period
* Time function is passed to the INTERVAL() directive as a second argument, which removes the Arduino dependency and allows for any time function that can be saved into unsigned int variables (micros(), clock_cycles ...).
* Time function is only invoked once, which allows for slighly more precise timing (which if at all probably only matters mit timing by cycles)