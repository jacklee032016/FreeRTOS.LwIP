# Makefile for Atmel version
# dependent on RTOS
#


include $(RULE_DIR)/Rules.mak


###################################################################
# define directory for object files
###################################################################

#	$(LWIP_HOME)/ports/sam \


CODE_SUBDIRS = \
	cmn	\
	http	\
	udpCmd	\
	mdns	\
	mqtt \
	nnmos	\
	others \
	ptp \


# 
CFLAGS += \
	$(LWIP_FLAGS) \
	$(LWIP_HEADER) \
	$(CPACK_FLAGS) \
	$(RTOS_FLAGS) \
	$(RTOS_HEADER) \
	$(CPACK_FLAGS) \
	$(APP_HEADER) \
	


###################################################################
# define source files
###################################################################



OTHERS_SRC += \
	others/tftpServer.c \
	others/lwiperf.c \
	others/extTelnetd.c \

#	src/lwip/jsonUtils.c \




MDNS_SRC += \
	mdns/extMdns.c \
	mdns/extMdnsClient.c \


HTTP_SRC += \
	http/extHttpPost.c \
	http/extHttpFs.c \
	http/extHttpConns.c \
	http/extHttpRequest.c \
	http/extHttpResponseFile.c \
	http/extHttpSend.c \
	http/extHttpWebSocket.c \
	http/extHttpWebPages.c \
	http/extHttpMain.c \


CMN_SRC += \
	cmn/extCmnUtils.c	\
	cmn/extCmnJsonUtils.c \
	cmn/extCmnSysConfig.c \
	cmn/extUploadFile.c \
	cmn/jsmn.c \
	cmn/extLwipUtils.c \



NNMOS_SRC += \
	nnmos/extNmosHttp.c \
	nnmos/extNmosHttpErrors.c \
	nnmos/extNmosPost.c \
	nnmos/extNmosNode.c \
	nnmos/extNmosConn.c \
	nnmos/extNmosUtils.c \
	nnmos/extNmosInit.c \
	nnmos/extNmosSdp.c \


UDPCMD_SRC += \
	udpCmd/extUdpCmdRequest.c \
	udpCmd/extUdpCmdResponses.c \
	udpCmd/extUdpCmdExecs.c \
	udpCmd/extUdpCmdSetup.c \
	udpCmd/extUdpCmdMain.c \
	


SRC += \
	$(OTHERS_SRC) \
	$(MDNS_SRC) \
	$(HTTP_SRC) \
	$(NNMOS_SRC) \
	$(CMN_SRC) \
	$(UDPCMD_SRC) \
	base64.c \
	extStart.c \

#	lwip/frozen.c \
	$(MUX_SRC) \


TARGET_LIB:=libLwipExts

TARGET_LIB_SHARED:=$(TARGET_LIB).so
TARGET_LIB_STATIC:=$(TARGET_LIB).a
		 
LOCAL_ALL:=

include $(ROOT_DIR)/Makefile.post
