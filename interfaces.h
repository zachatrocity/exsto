#import <QuartzCore/QuartzCore.h>
#import <QuartzCore/CAFilter.h>
#import <QuartzCore/CABackdropLayer.h>
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <objc/runtime.h>
#import <substrate.h>
#import "EXSTOCircleMenuView.h"
// #import "DFContinuousForceTouchGestureRecognizer.h"
#import "BlurBlur.h"

#define log(z) NSLog(@"[Exsto] %@", z)
#define prefsID CFSTR("com.atrocity.exsto")

#define TWEAK_NAME @"exsto"
#define TWEAK_BUNDLE_PATH [NSString stringWithFormat:@"/Library/PreferenceBundles/%@.bundle", TWEAK_NAME]

// #define TWEAK_PREFS_COLOR [UIColor colorWithRed:0.08f green:0.75f blue:0.85f alpha:1.f]



@interface SBIconController : NSObject
-(id)contentView;
+(id)sharedInstance;
-(void)_launchIcon:(id)icon;
-(void)openFolder:(id)folder animated:(BOOL)animated;
-(NSArray *)anglesBetweenPointA:(CGPoint)a pointB:(CGPoint)b pointC:(CGPoint)c;
-(BOOL)point:(CGPoint)c isOnLineFromPointA:(CGPoint)a toPointB:(CGPoint)b;
-(CGFloat)distanceFromPoint:(CGPoint)a toPointB:(CGPoint)b;
-(NSArray *)pointsAtIntersectWithLineFromOrigin:(CGPoint)origin toTarget:(CGPoint)target withCenter:(CGPoint)center withRadius:(double)radius;
-(CGFloat)checkAndCalculateAngleBetweenPoints:(NSArray *)points center:(CGPoint)center;
-(void)updateEXSTOContextPosition:(CGPoint)center withIconCount:(int)count;
-(NSDictionary *)optionsDictionary;
-(void)removeExstoView;
-(void)iconHandleLongPress:(id)press;
-(EXSTOCircleMenuView *)circleMenuView;
-(void)setCircleMenuView:(EXSTOCircleMenuView *)value;
-(NSMutableArray *)EXSTOImages;
-(void)setEXSTOImages:(NSMutableArray *)value;
-(NSMutableArray *)EXSTOFolderApplications;
-(void)setEXSTOFolderApplications:(NSMutableArray *)value;
-(UILongPressGestureRecognizer *)EXSTORecognizer;
-(void)setEXSTORecognizer:(UILongPressGestureRecognizer *)value;
//-(DFContinuousForceTouchGestureRecognizer *)EXSTOForceRecognizer;
//-(void)setEXSTOForceRecognizer:(DFContinuousForceTouchGestureRecognizer *)value;
@end

@interface SBIconViewMap : NSObject

@end

@interface SBIconImageView : UIView
-(id)contentsImage;
@end

@interface SBAlertItemsController : NSObject
- (void)activateAlertItem:(id)item;
@end

@interface SBLockScreenManager : NSObject
-(void)lockUIFromSource:(int)arg1 withOptions:(id)arg2;
@end

@interface SBIcon : NSObject
- (void)launchFromLocation:(int)arg1; // iOS 7 & 8
- (void)launchFromLocation:(int)arg1 context:(id)arg2; // iOS 8.3
- (id)applicationBundleID;
- (id)displayName;
- (NSInteger)badgeValue;
- (id)application;
- (id)getIconImage:(int)arg1;
- (id)generateIconImage:(int)arg1;
@end

@interface SBApplication : NSObject
-(id)displayName;
@end

@interface SBIconView : UIView
@property (nonatomic, retain) id delegate;
- (id)initWithDefaultSize;
- (void)_setIcon:(SBIcon*)icon animated:(BOOL)animated;
@end

@interface SBIconListModel : NSObject
-(id)iconAtIndex:(unsigned)index;
-(id)icons;
-(unsigned)numberOfIcons;
@end

@interface SBFolder : NSObject
-(id)allIcons; // returns an NSMutableSet
-(id)visibleIcons; // returns an NSMutableSet
-(id)lists;
@property(copy, nonatomic) NSString *displayName;
@end

@interface SBFolderIconView : UIView
-(id)folder;
-(id)initWithFrame:(CGRect)frame;
-(BOOL)isInDock;
@end