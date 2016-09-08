#!/bin/sh

##To Start Openvswitch
/etc/init.d/openvswitch-switch start


## Creating Interface and Waiting for interface to be up 
ifconfig brlan0 down
brctl delbr brlan0
sleep 5

##Delete existing ovs bridge
ovs-vsctl del-br brlan0
sleep 5

##Create ovs bridge
ovs-vsctl add-br brlan0

##Bridge Interface Finding
count=`ifconfig | grep brlan0 | wc -l`
echo "brlan-count=$count"

sleep 5
count=`ifconfig | grep brlan0 | wc -l`
echo "brlan-count=$count"

if [ $count != 0 ];then
echo "brlan0 interface exists"
fi

##eth3 Interface Finding
count=`ifconfig | grep eth3 | wc -l`                                       
echo "eth3-count=$count"                                                   
                                                                           
sleep 5                                                                    
count=`ifconfig | grep eth3 | wc -l`                                       
                                                                           
if [ $count != 0 ];then                                                    
echo "eth3 interface exists"                                               
ifconfig eth3 0 up                                                         
fi   

##eth2 Interface Finding
count=`ifconfig | grep eth2 | wc -l`
echo "eth2-count=$count"

sleep 5
count=`ifconfig | grep eth2 | wc -l`

if [ $count != 0 ];then
echo "eth2 interface exists"
ifconfig eth2 0 up
fi


##eth1 Interface Finding
count=`ifconfig | grep eth1 | wc -l`
echo "eth1count=$count"

sleep 5
count=`ifconfig | grep eth1 | wc -l`

if [ $count != 0 ];then
echo "eth1 interface exists"
ifconfig eth1 0 up
fi

##wlan0 Interface Finding
wifi=`ifconfig | grep wlan0 | wc -l`
echo "wlan0count=$wifi"

sleep 5
wifi=`ifconfig | grep wlan0 | wc -l`

if [ $wifi != 0 ];then
echo "wlan0 interface exists"
ifconfig wlan0 0 up
fi


## Set ip Address for Bridge interface for udhcpd server
if [ $count ] || [ $wifi ];then
INTERFACE=brlan0
DEFAULT_IP_ADDRESS=192.168.7.1
udhcpd_conf_file=/etc/udhcpd.conf
KEYWORD=router

#############################################################
#Set ipaddress for brlan0 interface
#############################################################

if [  -f $udhcpd_conf_file ];then
 echo "getting router ip address from $udhcpd_conf_file"
 router_ip_address=`grep $KEYWORD $udhcpd_conf_file | cut -d ' ' -f 3`
 echo "set ip address as $router_ip_address for $INTERFACE"
 ifconfig $INTERFACE $router_ip_address
else
 echo "set ip address as default $DEFAULT_IP_ADDRESS for $INTERFACE"
  ifconfig $INTERFACE $DEFAULT_IP_ADDRESS
fi

rm -f wifi_clients.txt

##############################
#Restart udhcpd service
##############################

systemctl restart udhcpd

################################
#Restart Hostapd
################################

systemctl restart hostapd
sleep 5
systemctl restart hostapd

fi
