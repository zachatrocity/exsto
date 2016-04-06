
#include "BlurBlur.h"

@implementation BlurBlur
  + (UIView *)createWithStyle:(int)style withFrame:(CGRect)frame {

    UIView *blurWindow = [[UIView alloc] initWithFrame:frame];
    blurWindow.backgroundColor = [UIColor blackColor];

    _UIBackdropView *blurView = [[_UIBackdropView alloc] initWithStyle:style];
    [blurView setBlurRadiusSetOnce:NO];
    [blurView setBlurRadius:4.0];
    [blurView setBlurHardEdges:2];
    [blurView setBlursWithHardEdges:YES];
    [blurView setBlurQuality:@"default"];
    [blurWindow addSubview:blurView];
    return blurWindow;
  }
@end