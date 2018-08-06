# Makefile for Atmel version
# dependent on RTOS
#


include $(RULE_DIR)/Rules.mak


###################################################################
# define directory for object files
###################################################################

#	$(LWIP_HOME)/ports/sam \


CODE_SUBDIRS = \
	netif/ppp/polarssl \
	api \
	core/ipv4 \


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

LWIP_CORE_SRC += \
	core/def.c \
	core/dns.c \
	core/inet_chksum.c \
	core/mem.c \
	core/memp.c \
	core/netif.c \
	core/ip.c \
	core/pbuf.c \
	core/stats.c \
	core/sys.c \
	core/tcp.c \
	core/tcp_in.c \
	core/raw.c \
	core/tcp_out.c \
	core/udp.c \
	core/init.c \
	core/timeouts.c \

# timeouts.c replace timer.c
	#	src/core/timers.c \
	
LWIP_CORE_V4_SRC += \
	core/ipv4/autoip.c \
	core/ipv4/dhcp.c \
	core/ipv4/etharp.c \
	core/ipv4/icmp.c \
	core/ipv4/igmp.c \
	core/ipv4/ip4.c \
	core/ipv4/ip4_addr.c \
	core/ipv4/ip4_frag.c \

LWIP_API_SRC += \
	api/api_lib.c \
	api/api_msg.c \
	api/err.c \
	api/netbuf.c \
	api/netdb.c \
	api/tcpip.c \
	api/sockets.c \

LWIP_IF_SRC += \
	netif/ethernet.c \
	netif/ppp/polarssl/sha1.c \


#	lwip/frozen.c \

SRC += \
	$(LWIP_CORE_SRC) \
	$(LWIP_CORE_V4_SRC) \
	$(LWIP_API_SRC) \
	$(LWIP_IF_SRC) \


TARGET_LIB:=libLwip

TARGET_LIB_SHARED:=$(TARGET_LIB).so
TARGET_LIB_STATIC:=$(TARGET_LIB).a
		 
LOCAL_ALL:=

include $(ROOT_DIR)/Makefile.post
