#!/bin/sh

########## Creating Interface and Waiting for interface to be up ####################
brctl addbr brlan0

count=`ifconfig | grep brlan0 | wc -l`
echo "brlan-count=$count"

sleep 5
count=`ifconfig | grep brlan0 | wc -l`
echo "brlan-count=$count"

if [ $count != 0 ];then
echo "brlan0 interface exists"
fi


count=`ifconfig | grep eth2 | wc -l`
echo "eth2-count=$count"

sleep 5
count=`ifconfig | grep eth2 | wc -l`

if [ $count != 0 ];then
echo "eth2 interface exists"
#ifconfig eth2 192.168.56.101 up
fi


count=`ifconfig | grep eth1 | wc -l`
echo "eth1count=$count"

sleep 5
count=`ifconfig | grep eth1 | wc -l`

if [ $count != 0 ];then
echo "eth1 interface exists"
##### Add Wired Interface to Bridge interface ##############################
#ifconfig eth1 192.168.1.115 up
brctl addif brlan0 eth1
fi

wifi=`ifconfig | grep wlan0 | wc -l`
echo "wlan0count=$wifi"

sleep 5
wifi=`ifconfig | grep wlan | wc -l`

INTERFACE_2G=`cat /etc/hostapd_2.4G.conf | grep -w interface | head -1 | cut -d '=' -f2`
if [ $wifi != 0 ];then                                                      
echo "wlan0 interface exists"                                                                           
######### Add Wireless interface to Bridge interface ######################
#ifconfig wlan0 192.168.1.120 up                                                     
iw dev $INTERFACE_2G set 4addr on                                   
brctl addif brlan0 $INTERFACE_2G                                                        
fi  

if [ $count ] || [ $wifi ];then
########### Set ip Address for Bridge interface for udhcpd server##########
INTERFACE=brlan0
DEFAULT_IP_ADDRESS=10.0.0.1
dnsmasq_conf_file=/etc/dnsmasq.conf
KEYWORD=dhcp-range
#############################################################
#Set ipaddress for brlan0 interface
#############################################################


if [  -f $dnsmasq_conf_file ];then
 echo "getting router ip address from $dnsmasq_conf_file"
 router_ip_address=`cat $dnsmasq_conf_file | grep -w $KEYWORD | cut -d ',' -f2 | cut -d '.' -f1-3`
 echo "set ip address as $router_ip_address for $INTERFACE"
 ifconfig $INTERFACE $router_ip_address.1 netmask 255.255.255.0
else
 echo "set ip address as default $DEFAULT_IP_ADDRESS for $INTERFACE"
  ifconfig $INTERFACE $DEFAULT_IP_ADDRESS netmask 255.255.255.0
fi

rm -f wifi_clients.txt

fi

################### Getting wlan0_0 mac Address(public wifi) #############
sh /lib/rdk/Getting_wlan0_0_mac.sh wlan0

############################ iptables-restore ########################
iptables-restore < /etc/iptables/rules.v4

###############################CcspTR069pa#########################
touch /var/tmp/tr069paready         
cp /version.txt /fss/gw/version.txt

############################## Webpa Component ################################

brctl addbr br0
ifconfig br0 up
sleep 2
ifconfig br0 192.168.101.3 up

WEBPA_FILE="/etc/webpa_cfg.json"
if [ -f "$WEBPA_FILE" ]; then
        echo "webpa_cfg.json file exists"
        cp -fr /etc/webpa_cfg.json /nvram/webpa_cfg.json
        sed -i 's/erouter0/eth0/g'  /nvram/webpa_cfg.json
fi

DEVICE_PROPERTIES_FILE="/etc/device.properties"
if [ -f "$DEVICE_PROPERTIES_FILE" ]; then
        echo "device.properties file exists"
        WEBPA_COUNT=`cat /etc/device.properties | grep ATOM_INTERFACE | wc -l`
        if [ $WEBPA_COUNT == 0 ]; then
        echo "ATOM_INTERFACE="br0"" >> /etc/device.properties
        echo "ATOM_INTERFACE_IP=192.168.101.3" >> /etc/device.properties
        echo "PARODUS_URL=tcp://127.0.0.1:6666" >> /etc/device.properties
        fi
fi

