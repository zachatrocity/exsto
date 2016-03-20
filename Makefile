export THEOS_DEVICE_IP=192.168.0.102
#export THEOS_DEVICE_IP=10.3.27.5
export ARCHS = armv7 armv7s arm64
include theos/makefiles/common.mk
export GO_EASY_ON_ME := 1

ADDITIONAL_CFLAGS = -fobjc-arc
TWEAK_NAME = Exsto
Exsto_FILES = Tweak.xm EXSTOCircleMenuView.m DFContinuousForceTouchGestureRecognizer.m
Exsto_FRAMEWORKS = UIKit CoreGraphics Foundation QuartzCore
Exsto_LIBRARIES = substrate
Exsto_LDFLAGS += -Wl,-segalign,4000
Exsto_CODESIGN_FLAGS = -Sentitlements.xml

include $(THEOS_MAKE_PATH)/tweak.mk
THEOS_PACKAGE_BASE_VERSION = 0.0.0.2-1
_THEOS_INTERNAL_PACKAGE_VERSION = 0.0.0.2-1


after-install::
	install.exec "killall -9 SpringBoard"
	#install.exec "killall -9 Preferences"
SUBPROJECTS += exsto
include $(THEOS_MAKE_PATH)/aggregate.mk
