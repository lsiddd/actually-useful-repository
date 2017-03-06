#This code doesn't do anything in partiular
#it's just to be used as base to build any other
#code, with the basic libraries and stuff.
#Do WTF you want with this.

import ns.core
import ns.network
import ns.internet
import ns.applications
import sys

cmd = ns.core.CommandLine()
cmd.verbose = "True"
cmd.AddValue("verbose", "Tell applications to log if true")
cmd.Parse(sys.argv)

verbose = cmd.verbose


#In the caso this is goint to be an echo App
if verbose == "True":
        ns.core.LogComponentEnable("UdpEchoClientApplication", ns.core.LOG_LEVEL_INFO)
        ns.core.LogComponentEnable("UdpEchoServerApplication", ns.core.LOG_LEVEL_INFO)



ns.core.Simulator.Run()
ns.core.Simulator.Destroy()
