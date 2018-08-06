
#ifndef	__LWIP_EXT_H__
#define	__LWIP_EXT_H__


#include "lwip/opt.h"  /* lwip/arch.h --> arch/cc.h --> #include "extSysParams.h" */

#include <string.h>

#include "lwip/def.h"
#include "lwip/ip_addr.h"
#include "lwip/ip6_addr.h"
#include "lwip/netif.h"
#include "lwip/priv/tcp_priv.h"
#include "lwip/udp.h"
#include "lwip/raw.h"
#include "lwip/snmp.h"
#include "lwip/igmp.h"
#include "lwip/etharp.h"
#include "lwip/stats.h"
#include "lwip/sys.h"
#include "lwip/ip.h"
#if ENABLE_LOOPBACK
#if LWIP_NETIF_LOOPBACK_MULTITHREADING
#include "lwip/tcpip.h"
#endif /* LWIP_NETIF_LOOPBACK_MULTITHREADING */
#endif /* ENABLE_LOOPBACK */

#include "netif/ethernet.h"

#if LWIP_AUTOIP
#include "lwip/autoip.h"
#endif /* LWIP_AUTOIP */
#if LWIP_DHCP
#include "lwip/dhcp.h"
#endif /* LWIP_DHCP */
#if LWIP_IPV6_DHCP6
#include "lwip/dhcp6.h"
#endif /* LWIP_IPV6_DHCP6 */
#if LWIP_IPV6_MLD
#include "lwip/mld6.h"
#endif /* LWIP_IPV6_MLD */
#if LWIP_IPV6
#include "lwip/nd6.h"
#endif

#include "lwip/ip_addr.h"
#include "lwip/inet.h"

#include "compact.h"

#include "extNmos.h"
#include "extHttp.h"

#ifndef	TRACE
	#define	TRACE()						printf(__FILE__", line %u\r\n", __LINE__)
#endif


void extLwipHttpSvrInit(void *data);

void mHttpSvrMain(void *data);

char extLwipStartup(struct netif *netif, EXT_RUNTIME_CFG *runCfg);
void extRawTelnetInit(EXT_RUNTIME_CFG *runCfg);



char	 extLwipGroupMgr(struct netif *netif, unsigned int gAddress, unsigned char isAdd);


void extLwipIp4DebugPrint(struct pbuf *p, const char *prompt);
void extLwipIgmpDebugPrint(const ip4_addr_t *groupaddr, const char isJoin);

char extNetMulticastIP4Mac(unsigned int	*ipAddress, EXT_MAC_ADDRESS *macAddress);


void extVideoConfigCopy(EXT_VIDEO_CONFIG *dest, EXT_VIDEO_CONFIG *src);


char	extNetIsGroupAddress(unsigned int	*ipAddress);




#define	NETIF_HWADDR_OFFSET()		\
			(offsetof(struct netif, hwaddr_len))


#define	EXT_LWIP_INT_TO_IP(ipAddr,  intAddr)	\
				((ipAddr)->addr = intAddr)

#define	EXT_LWIP_IPADD_TO_STR(ipAddr)		\
			inet_ntoa((*(struct in_addr *)(ipAddr)) )


#define	EXT_LWIP_DEBUG	0


#define	EXT_LWIP_DEBUG_NETIF(_netif)	\
			EXT_DEBUGF(EXT_DBG_ON, ("netif :%p; hwaddr_len:%d, offset:%d:%d:%d"EXT_NEW_LINE,  \
				(_netif), (_netif)->hwaddr_len, (offsetof(struct netif, rs_count)), (offsetof(struct netif, mtu)), NETIF_HWADDR_OFFSET() ) )


#define	EXT_LWIP_DEBUG_PBUF(_pbuf)	\
			EXT_DEBUGF(EXT_DBG_ON, ("pbuf :%p, size:%d, next:%p; payload:%p, total:%d, len:%d, type:%d, ref:%d"EXT_NEW_LINE,  \
				(_pbuf), sizeof(struct pbuf), _pbuf->next, _pbuf->payload, _pbuf->tot_len, _pbuf->len, _pbuf->type, _pbuf->ref ) )



#define	MDNS_SERVICE_NAME_SIZE		128

typedef	enum
{
	MDNS_CLIENT_S_INIT = 0,
	MDNS_CLIENT_S_PARSE_PTR,
	MDNS_CLIENT_S_PARSE_SRV,
	MDNS_CLIENT_S_PARSE_TXT,

	MDNS_CLIENT_S_REQUEST_API,
		
	MDNS_CLIENT_S_UNKNOWN,

}MDNS_CLIENT_STATE;

#include "lwip/apps/mdns.h"
#include "lwip/apps/mdns_priv.h"


#define	EXT_MDNS_CLIENT_DEBUG				EXT_DBG_OFF
#define	EXT_HTTPD_DEBUG						EXT_DBG_OFF

#define	EXT_HTTPD_DATA_DEBUG				EXT_DBG_OFF


typedef	struct 
{
	u16_t				txId;

	char					domainName[MDNS_DOMAIN_MAXLEN];

	char					service[MDNS_SERVICE_NAME_SIZE];
	u16_t				qType;

	unsigned	char			rdata[MDNS_DOMAIN_MAXLEN];

	unsigned char			state;
	
	struct udp_pcb		*udpPcb;
	struct mdns_packet	*pkt;

	ExtNmosNode			node;
	
	EXT_RUNTIME_CFG	*runCfg;
}mdns_client_t;


char mdnsClientInit(mdns_client_t *mdnsClient, EXT_RUNTIME_CFG *runCfg);
char mdnsClientParseAnswer(mdns_client_t *mdnsClient, struct mdns_packet *pkt);

struct ptptime_t
{
	s32_t	tv_sec;
	s32_t	tv_nsec;
};


char extUdpCmdConnect(EXT_RUNTIME_CFG  *runCfg);


char *extLwipIpAddress(void);

//void bspConsoleDumpMemory(uint8_t *buffer, uint32_t size, uint32_t address);


#endif

