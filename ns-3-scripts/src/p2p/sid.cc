#include "ns3/core-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/network-module.h"
#include "ns3/applications-module.h"
#include "ns3/wifi-module.h"
#include "ns3/mobility-module.h"
#include "ns3/csma-module.h"
#include "ns3/internet-module.h"

 //        n1
 //      /    \
 //     /      \
 //    /        \
 //  n0----------n2

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("sid");

int main(int argc, char* argv[]){

  //Primeiro containet com os nós n0 e n1
  NodeContainer n0n1;
  n0n1.Create(2);

  //Segundo container com os nós n1 e n2
  NodeContainer n1n2;
  n1n2.Add(n0n1.Get(1));
  n1n2.Create(1);

  //Terceiro container com os nós n0 e n2
  NodeContainer n0n2;
  n0n2.Add(n0n1.Get(0));
  n0n2.Add(n1n2.Get(1));

  //p2p mais rápido
  PointToPointHelper FastLink;
  FastLink.SetDeviceAttribute("DataRate", StringValue("10Mbps"));
  FastLink.SetChannelAttribute("Delay", StringValue("1ms"));

  //Instalar o p2p mais rápido nos containers n0n1 e n1n2;
  NetDeviceContainer link0 = FastLink.Install(n0n1);
  NetDeviceContainer link1 = FastLink.Install(n1n2);

  //p2p mais lento
  PointToPointHelper SlowLink;
  SlowLink.SetDeviceAttribute("DataRate", StringValue("1Mbps"));
  SlowLink.SetChannelAttribute("Delay", StringValue("3ms"));

  //Instalar o p2p mais lento no container n0n2
  NetDeviceContainer link2 = SlowLink.Install(n0n2);

  InternetStackHelper Internet;
  Internet.InstallAll();

  Ipv4AddressHelper ipv4;
  ipv4.SetBase("10.97.1.0", "255.255.255.0");
  ipv4.Assign(link0);
  ipv4.SetBase("10.98.1.0", "255.255.255.0");
  ipv4.Assign(link1);
  ipv4.SetBase("10.99.1.0", "255.255.255.0");
  ipv4.Assign(link2);

  
}
