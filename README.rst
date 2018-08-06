=======================================
Free RTOS and LwIP simulating in Linux
=======================================

The project includes:

 * Free RTOS running under Linux;
 * LwIP runing under Free RTOS;

Useful for development of FreeRTOS with TCP/IP protocol support.

--------
FreeRTOS
--------

  Version 10.0.1.
  
::

   enter into freeRtos directory, and 'make' to built 'FreeRtos_demo'
   

-----------
LwIP 2.0
-----------

Usage:

::

      `make` to build library and 'simRate';
      './bin/start.sh' to initialize virtual TAP network device;
      'source ./bin/init.sh' to modify PATH;
      'simRate'
      
Testing:

::
      
      'ping 192.168.166.1'


  