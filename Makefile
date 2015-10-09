#export THEOS_DEVICE_IP=192.168.0.103
export THEOS_DEVICE_IP=10.3.5.232
export ARCHS = armv7 armv7s arm64
include theos/makefiles/common.mk
export GO_EASY_ON_ME := 1

ADDITIONAL_CFLAGS = -fobjc-arc
TWEAK_NAME = Exsto
Exsto_FILES = Tweak.xm EXSTOCircleMenuView.m 
Exsto_FRAMEWORKS = UIKit CoreGraphics Foundation QuartzCore
Exsto_LIBRARIES = mobilegestalt z


include $(THEOS_MAKE_PATH)/tweak.mk
#THEOS_PACKAGE_BASE_VERSION = 0.0.1-1
#_THEOS_INTERNAL_PACKAGE_VERSION = 0.0.1-1

after-install::
	install.exec "killall -9 SpringBoard"
	#install.exec "killall -9 Preferences"
SUBPROJECTS += exsto
include $(THEOS_MAKE_PATH)/aggregate.mk
