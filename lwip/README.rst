========================
LwIP and its extensions
========================

The project includes:

 * LwIP Core;
 * Port of Free RTOS under Linux;
 * Extension Protocols suits


------------
Directories
------------

^^^^
src
^^^^

 * LwIP Core


^^^^^^
ports
^^^^^^

 * Port to Free RTOS;
 

^^^^^^^^
project
^^^^^^^^
 
Main program and integrated LwIP, FreeRTOS under Linux



^^^^^
exts
^^^^^

Procotols suits based on RAW TCP/UDP connection, includes:

 * JSON parsing;

 * HTTP service, supports

  - Static web contents;
  - Dynamic web contents;
  - Web Socket;
  - HTTP POST file upload;
  - HTTP REST API, supports
  
    - GET Method;
    - POST Method;
     
 * PTP (Precesion Time Protocol)
 * TFTP Server;
 * MDNS (Multicast DNS) Server/Client;
 * Telnet;
 * ipperf
 

^^^^^
mkfs
^^^^^

Make static web pages into virtual file system in memory.
Only works in MinGW;


  