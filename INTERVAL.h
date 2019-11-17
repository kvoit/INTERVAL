#pragma once

extern bool INTERVALcondMet;

// define INTERVAL
#define INTERVAL(runint,currenttime)                       \
{                                                          \
  /* Save current time to new variable in                  \
     in case currenttime is a function */                  \
  unsigned long ctime = currenttime;                       \
  /* Local static variable keeps last state                \
     Execution at first call */                            \
  static unsigned long lastTime = -runint;                 \
  /* Global variable carries info out of local env */      \
  INTERVALcondMet = ctime - lastTime >= runint;      \
  /* If condition met, reset  */                           \
  if(INTERVALcondMet) lastTime = ctime;                 \
}                                                          \
if(INTERVALcondMet)
// end define INTERVAL