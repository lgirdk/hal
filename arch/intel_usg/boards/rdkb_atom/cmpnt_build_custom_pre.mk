#######################################################################
#   Copyright [2014] [Cisco Systems, Inc.]
# 
#   Licensed under the Apache License, Version 2.0 (the \"License\");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
# 
#       http://www.apache.org/licenses/LICENSE-2.0
# 
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an \"AS IS\" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.
#######################################################################

#
#  This makefile will be included in the main build script (bash) or makefile.
#  It provides the customized component list and arch/board specific ccsp global make definitions

#  Atom needs only wifi hal
BUILD_HAL_WIFI = 1
BUILD_HAL_MOCA = 0
BUILD_HAL_CM = 0
BUILD_HAL_MTA = 0
BUILD_API_DHCPV4C = 0
BUILD_HAL_PLATFORM = 0
BUILD_HAL_ETHSW = 0
BUILD_HAL_MSO_MGMT = 0
