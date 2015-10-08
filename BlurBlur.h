// UIBackdropView header
@interface _UIBackdropView : UIView
	- (id)initWithFrame:(CGRect)arg1 autosizesToFitSuperview:(BOOL)arg2 settings:(id)arg3;
	- (id)initWithPrivateStyle:(int)arg1;
	- (id)initWithSettings:(id)arg1;
	- (id)initWithStyle:(int)arg1;
	
	- (void)setBlurFilterWithRadius:(float)arg1 blurQuality:(id)arg2 blurHardEdges:(int)arg3;
	- (void)setBlurFilterWithRadius:(float)arg1 blurQuality:(id)arg2;
	- (void)setBlurHardEdges:(int)arg1;
	- (void)setInputSettings:(id)arg1;
	- (void)setBlurQuality:(id)arg1;
	- (void)setBlurRadius:(float)arg1;
	- (void)setBlurRadiusSetOnce:(BOOL)arg1;
	- (void)setBlursBackground:(BOOL)arg1;
	- (void)setBlursWithHardEdges:(BOOL)arg1;
@end

@interface _UIBackdropViewSettings : NSObject
	+ (id)settingsForStyle:(int)arg1;
@end

//BlurBlur header
@interface BlurBlur : NSObject
  - (void)create;
@end