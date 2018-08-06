
# Docker file for FreeRTOS+LwIP simulator in Linux
# Jack Lee(jacklee032016@gmail.com), Auguest 6th, 2018

FROM scratch

MAINTAINER Jack Lee

#ADD hello.sh /
#CMD ["/hello.sh"]

ADD simRate /
CMD ["/simRate"]


