#import <Preferences/Preferences.h>
//#import <UIKit/UIKit.h>

@interface BetterPSSliderTableCell : PSSliderTableCell <UIAlertViewDelegate, UITextFieldDelegate> {
    UIAlertView * alert;
}
-(void)presentPopup;
-(void) typeMinus;
@end
