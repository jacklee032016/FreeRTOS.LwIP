#
# $Author$
#


include $(RULE_DIR)/Rules.mak

CODE_SUBDIRS = \
		.


CFLAGS += \
	$(RTOS_FLAGS) \
	$(RTOS_HEADER) \
	$(LWIP_HEADER) \
	$(CPACK_FLAGS) \
	$(APP_HEADER) \

		
SRC += \
		simRtos.c \
		tapif.c \
		freeTimerJobs.c \


LOCAL_ALL := \
		simRtos \


include $(ROOT_DIR)/Makefile.post

LDFLAGS := -L$(BIN_DIR)/lib 

ifeq ($(ARCH),arm)
LDFLAGS += 
else
LDFLAGS += -ldl
endif

LDFLAGS += -lLwipSys -lLwipExts -lLwip -lRtos -lpthread

#  -nostartfiles 
simRtos:$(OBJS)
	$(CC) -s -static -o $@ $^ $(LDFLAGS) 
	$(MOVE) $@ $(BIN_DIR)/usr/bin  

